/*
  ==============================================================================

	DrumSample.h
	Created: 9 Dec 2022 2:21:22am
	Author:  paulm

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class DrumSamplerSound : public juce::SynthesiserSound
{
public:
	//==============================================================================
	/** Creates a sampled sound from an audio reader.

		This will attempt to load the audio from the source into memory and store
		it in this object.

		@param name         a name for the sample
		@param source       the audio to load. This object can be safely deleted by the
							caller after this constructor returns
		@param midiNotes    the set of midi keys that this sound should be played on. This
							is used by the SynthesiserSound::appliesToNote() method
		@param midiNoteForNormalPitch   the midi note at which the sample should be played
										with its natural rate. All other notes will be pitched
										up or down relative to this one
		@param attackTimeSecs   the attack (fade-in) time, in seconds
		@param releaseTimeSecs  the decay (fade-out) time, in seconds
		@param maxSampleLengthSeconds   a maximum length of audio to read from the audio
										source, in seconds
	*/
	DrumSamplerSound(const juce::String& soundName,
		juce::AudioFormatReader& source,
		const juce::BigInteger& notes,
		juce::RangedAudioParameter* gain,
		juce::RangedAudioParameter* panning,
		int midiNoteForNormalPitch,
		double attackTimeSecs,
		double releaseTimeSecs,
		double maxSampleLengthSeconds);

	/** Destructor. */
	~DrumSamplerSound() override;

	//==============================================================================
	/** Returns the sample's name */
	const juce::String& getName() const noexcept { return name; }

	/** Returns the audio sample data.
		This could return nullptr if there was a problem loading the data.
	*/
	juce::AudioBuffer<float>* getAudioData() const noexcept { return data.get(); }


	//==============================================================================
	/** Changes the parameters of the ADSR envelope which will be applied to the sample. */
	void setEnvelopeParameters(juce::ADSR::Parameters parametersToUse) { params = parametersToUse; }

	//==============================================================================
	bool appliesToNote(int midiNoteNumber) override;
	bool appliesToChannel(int midiChannel) override;

	juce::RangedAudioParameter* mGainParameter;
	juce::RangedAudioParameter* mPanningParameter;

private:
	//==============================================================================
	friend class DrumSamplerVoice;

	juce::String name;
	std::unique_ptr<juce::AudioBuffer<float>> data;
	double sourceSampleRate;
	juce::BigInteger midiNotes;
	int length = 0;
	int midiRootNote = 0;
	

	juce::ADSR::Parameters params;

	JUCE_LEAK_DETECTOR(DrumSamplerSound)
};


//==============================================================================
/**
	A subclass of SynthesiserVoice that can play a DrumSamplerSound.

	To use it, create a Synthesiser, add some DrumSamplerVoice objects to it, then
	give it some SampledSound objects to play.

	@see DrumSamplerSound, Synthesiser, SynthesiserVoice

	@tags{Audio}
*/
class DrumSamplerVoice : public juce::SynthesiserVoice
{
public:
	//==============================================================================
	/** Creates a DrumSamplerVoice. */
	DrumSamplerVoice();

	/** Destructor. */
	~DrumSamplerVoice() override;

	//==============================================================================
	bool canPlaySound(juce::SynthesiserSound*) override;

	void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound*, int pitchWheel) override;
	void stopNote(float velocity, bool allowTailOff) override;

	void pitchWheelMoved(int newValue) override;
	void controllerMoved(int controllerNumber, int newValue) override;

	void renderNextBlock(juce::AudioBuffer<float>&, int startSample, int numSamples) override;
	using SynthesiserVoice::renderNextBlock;

private:
	//==============================================================================
	double mPitchRatio = 0;
	double mSourceSamplePosition = 0;
	float mLeftGain = 0;
	float mRightGain = 0;

	juce::ADSR adsr;

	JUCE_LEAK_DETECTOR(DrumSamplerVoice)
};
