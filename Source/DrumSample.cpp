/*
  ==============================================================================

	DrumSample.cpp
	Created: 9 Dec 2022 2:21:22am
	Author:  paulm

  ==============================================================================
*/

#include "DrumSample.h"

DrumSamplerSound::DrumSamplerSound(juce::String& name,
	juce::AudioFormatReader& source,
	const juce::BigInteger& midiNotes,
	int midiNoteForNormalPitch,
	double attackTimeSecs,
	double releaseTimeSecs,
	double maxSampleLengthSeconds): name(name), sourceSampleRate(source.sampleRate), midiNotes(midiNotes), midiRootNote(midiNoteForNormalPitch)
{
	if (sourceSampleRate > 0 && source.lengthInSamples > 0)
	{
		length = juce::jmin((int)source.lengthInSamples,
			(int)(maxSampleLengthSeconds * sourceSampleRate));

		data.reset(new juce::AudioBuffer<float>(juce::jmin(2, (int)source.numChannels), length + 4));

		source.read(data.get(), 0, length + 4, 0, true, true);

		params.attack = static_cast<float> (attackTimeSecs);
		params.release = static_cast<float> (releaseTimeSecs);
	}
}

DrumSamplerSound::~DrumSamplerSound()
{
}

bool DrumSamplerSound::appliesToNote(int midiNoteNumber)
{
	return midiNotes[midiNoteNumber];
}

bool DrumSamplerSound::appliesToChannel(int /*midiChannel*/)
{
	return true;
}

//==============================================================================
DrumSamplerVoice::DrumSamplerVoice() {}
DrumSamplerVoice::~DrumSamplerVoice() {}

bool DrumSamplerVoice::canPlaySound(juce::SynthesiserSound* sound)
{
	return dynamic_cast<const DrumSamplerSound*> (sound) != nullptr;
}

void DrumSamplerVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* s, int /*currentPitchWheelPosition*/)
{
	if (auto* sound = dynamic_cast<const DrumSamplerSound*> (s))
	{
		pitchRatio = std::pow(2.0, (midiNoteNumber - sound->midiRootNote) / 12.0)
			* sound->sourceSampleRate / getSampleRate();

		sourceSamplePosition = 0.0;

		adsr.setSampleRate(sound->sourceSampleRate);
		adsr.setParameters(sound->params);

		adsr.noteOn();
	}
	else
	{
		jassertfalse; // this object can only play DrumSamplerSounds!
	}
}

void DrumSamplerVoice::stopNote(float /*velocity*/, bool allowTailOff)
{
	if (allowTailOff)
	{
		adsr.noteOff();
	}
	else
	{
		clearCurrentNote();
		adsr.reset();
	}
}

void DrumSamplerVoice::pitchWheelMoved(int /*newValue*/) {}
void DrumSamplerVoice::controllerMoved(int /*controllerNumber*/, int /*newValue*/) {}

//==============================================================================
void DrumSamplerVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
	if (auto* playingSound = static_cast<DrumSamplerSound*> (getCurrentlyPlayingSound().get()))
	{
		auto& data = *playingSound->data;
		const float* const inL = data.getReadPointer(0);
		const float* const inR = data.getNumChannels() > 1 ? data.getReadPointer(1) : nullptr;

		float* outL = outputBuffer.getWritePointer(0, startSample);
		float* outR = outputBuffer.getNumChannels() > 1 ? outputBuffer.getWritePointer(1, startSample) : nullptr;

		while (--numSamples >= 0)
		{
			auto pos = (int)sourceSamplePosition;
			auto alpha = (float)(sourceSamplePosition - pos);
			auto invAlpha = 1.0f - alpha;

			// just using a very simple linear interpolation here..
			float l = (inL[pos] * invAlpha + inL[pos + 1] * alpha);
			float r = (inR != nullptr) ? (inR[pos] * invAlpha + inR[pos + 1] * alpha)
				: l;

			auto envelopeValue = adsr.getNextSample();

			l *= lgain * envelopeValue;
			r *= rgain * envelopeValue;

			if (outR != nullptr)
			{
				*outL++ += l;
				*outR++ += r;
			}
			else
			{
				*outL++ += (l + r) * 0.5f;
			}

			sourceSamplePosition += pitchRatio;

			if (sourceSamplePosition > playingSound->length)
			{
				stopNote(0.0f, false);
				break;
			}
		}
	}
}