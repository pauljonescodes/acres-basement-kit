/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AcresBasementKitAudioProcessor::AcresBasementKitAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    mFormatManager.registerBasicFormats();

    for (int i = 0; i < 12; i++) {
        juce::SamplerVoice *voice = new juce::SamplerVoice();
        mSynthesiser.addVoice(voice);
    }

    addSampleToSynthesiser("bassdrumkickmic_wav", 36);
    addSampleToSynthesiser("acousticsnaresnaremic_wav", 38);
    addSampleToSynthesiser("sidesticksnaremic_wav", 37);
    addSampleToSynthesiser("racktomracktommic_wav", 50);
    addSampleToSynthesiser("floortomfloortommic_wav", 43);
    addSampleToSynthesiser("pedalhihathihatmic_wav", 44);
    addSampleToSynthesiser("closedhihathihatmic_wav", 42);
    addSampleToSynthesiser("openhihathihatmic_wav", 46);
    addSampleToSynthesiser("ridebellridemic_wav", 53);
    addSampleToSynthesiser("ridecymbalridemic_wav", 51);
    addSampleToSynthesiser("crashcymbalohleftmic_wav", 49);
    addSampleToSynthesiser("crashcymbalohrightmic_wav", 57);
}

AcresBasementKitAudioProcessor::~AcresBasementKitAudioProcessor()
{
    mSynthesiser.clearSounds();
}

//==============================================================================
const juce::String AcresBasementKitAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AcresBasementKitAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AcresBasementKitAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AcresBasementKitAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double AcresBasementKitAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AcresBasementKitAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AcresBasementKitAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AcresBasementKitAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String AcresBasementKitAudioProcessor::getProgramName (int index)
{
    return {};
}

void AcresBasementKitAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void AcresBasementKitAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    mSynthesiser.setCurrentPlaybackSampleRate(sampleRate);
}



void AcresBasementKitAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AcresBasementKitAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void AcresBasementKitAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());

    mSynthesiser.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

void AcresBasementKitAudioProcessor::addSampleToSynthesiser(const char *resourceName, int midiNote)
{
    int dataSizeInBytes;
    const char* sourceData = BinaryData::getNamedResource(resourceName, dataSizeInBytes);
    auto memoryInputStream = std::make_unique<juce::MemoryInputStream>(sourceData, dataSizeInBytes, false);

    juce::AudioFormatReader* reader = mFormatManager.createReaderFor(std::move(memoryInputStream));
    if (reader)
    {
        juce::BigInteger range;
        range.setRange(midiNote, 1, true);
        mSynthesiser.addSound(new juce::SamplerSound(resourceName, *reader, range, midiNote, 0, 10, 5));
    }
}

//==============================================================================
bool AcresBasementKitAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* AcresBasementKitAudioProcessor::createEditor()
{
    return new AcresBasementKitAudioProcessorEditor (*this);
}

//==============================================================================
void AcresBasementKitAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void AcresBasementKitAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AcresBasementKitAudioProcessor();
}
