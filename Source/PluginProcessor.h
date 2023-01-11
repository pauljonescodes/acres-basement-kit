/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class AcresBasementKitAudioProcessor : public juce::AudioProcessor
#if JucePlugin_Enable_ARA
	, public juce::AudioProcessorARAExtension
#endif
{
public:
	//==============================================================================
	AcresBasementKitAudioProcessor();
	~AcresBasementKitAudioProcessor() override;

	//==============================================================================
	void prepareToPlay(double sampleRate, int samplesPerBlock) override;
	void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
	bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif

	void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

	//==============================================================================
	juce::AudioProcessorEditor* createEditor() override;
	bool hasEditor() const override;

	//==============================================================================
	const juce::String getName() const override;

	bool acceptsMidi() const override;
	bool producesMidi() const override;
	bool isMidiEffect() const override;
	double getTailLengthSeconds() const override;

	//==============================================================================
	int getNumPrograms() override;
	int getCurrentProgram() override;
	void setCurrentProgram(int index) override;
	const juce::String getProgramName(int index) override;
	void changeProgramName(int index, const juce::String& newName) override;

	//==============================================================================
	void getStateInformation(juce::MemoryBlock& destData) override;
	void setStateInformation(const void* data, int sizeInBytes) override;

	//===    
	void noteOnSynthesiser(int midiNoteNumber);
	std::vector< std::vector<juce::RangedAudioParameter*>> getSampleGains();

	std::atomic<bool> mShouldUpdate{ false };
	std::atomic<bool> mIsNotePlayed{ false };
	juce::Synthesiser mKickMicSynthesiser;
	juce::Synthesiser mSnareMicSynthesiser;
	juce::Synthesiser mHiHatMicSynthesiser;
	juce::Synthesiser mRackTomMicSynthesiser;
	juce::Synthesiser mFloorTomMicSynthesiser;
	juce::Synthesiser mRideMicSynthesiser;
	juce::Synthesiser mOverheadLeftMicSynthesiser;
	juce::Synthesiser mOverheadRightMicSynthesiser;
	juce::AudioFormatManager mFormatManager;
	std::atomic<int> mSampleCount{ 0 };

	juce::AudioProcessorValueTreeState mParameterValueTreeState;

	juce::RangedAudioParameter* mKickMicPanning = nullptr;
	juce::RangedAudioParameter* mSnareMicPanning = nullptr;
	juce::RangedAudioParameter* mHiHatMicPanning = nullptr;
	juce::RangedAudioParameter* mRackTomMicPanning = nullptr;
	juce::RangedAudioParameter* mFloorTomMicPanning = nullptr;
	juce::RangedAudioParameter* mRideMicPanning = nullptr;
	juce::RangedAudioParameter* mOverheadLeftMicPanning = nullptr;
	juce::RangedAudioParameter* mOverheadRightMicPanning = nullptr;

	juce::RangedAudioParameter* mKickInKickMicGain = nullptr;
	juce::RangedAudioParameter* mKickInSnareMicGain = nullptr;
	juce::RangedAudioParameter* mKickInHiHatMicGain = nullptr;
	juce::RangedAudioParameter* mKickInRackTomMicGain = nullptr;
	juce::RangedAudioParameter* mKickInFloorTomMicGain = nullptr;
	juce::RangedAudioParameter* mKickInRideMicGain = nullptr;
	juce::RangedAudioParameter* mKickInOverheadLeftMicGain = nullptr;
	juce::RangedAudioParameter* mKickInOverheadRightMicGain = nullptr;

	juce::RangedAudioParameter* mSnareInKickMicGain = nullptr;
	juce::RangedAudioParameter* mSnareInSnareMicGain = nullptr;
	juce::RangedAudioParameter* mSnareInHiHatMicGain = nullptr;
	juce::RangedAudioParameter* mSnareInRackTomMicGain = nullptr;
	juce::RangedAudioParameter* mSnareInFloorTomMicGain = nullptr;
	juce::RangedAudioParameter* mSnareInRideMicGain = nullptr;
	juce::RangedAudioParameter* mSnareInOverheadLeftMicGain = nullptr;
	juce::RangedAudioParameter* mSnareInOverheadRightMicGain = nullptr;

	juce::RangedAudioParameter* mSideStickInKickMicGain = nullptr;
	juce::RangedAudioParameter* mSideStickInSnareMicGain = nullptr;
	juce::RangedAudioParameter* mSideStickInHiHatMicGain = nullptr;
	juce::RangedAudioParameter* mSideStickInRackTomMicGain = nullptr;
	juce::RangedAudioParameter* mSideStickInFloorTomMicGain = nullptr;
	juce::RangedAudioParameter* mSideStickInRideMicGain = nullptr;
	juce::RangedAudioParameter* mSideStickInOverheadLeftMicGain = nullptr;
	juce::RangedAudioParameter* mSideStickInOverheadRightMicGain = nullptr;

	juce::RangedAudioParameter* mPedalHiHatInKickMicGain = nullptr;
	juce::RangedAudioParameter* mPedalHiHatInSnareMicGain = nullptr;
	juce::RangedAudioParameter* mPedalHiHatInHiHatMicGain = nullptr;
	juce::RangedAudioParameter* mPedalHiHatInRackTomMicGain = nullptr;
	juce::RangedAudioParameter* mPedalHiHatInFloorTomMicGain = nullptr;
	juce::RangedAudioParameter* mPedalHiHatInRideMicGain = nullptr;
	juce::RangedAudioParameter* mPedalHiHatInOverheadLeftMicGain = nullptr;
	juce::RangedAudioParameter* mPedalHiHatInOverheadRightMicGain = nullptr;

	juce::RangedAudioParameter* mClosedHiHatInKickMicGain = nullptr;
	juce::RangedAudioParameter* mClosedHiHatInSnareMicGain = nullptr;
	juce::RangedAudioParameter* mClosedHiHatInHiHatMicGain = nullptr;
	juce::RangedAudioParameter* mClosedHiHatInRackTomMicGain = nullptr;
	juce::RangedAudioParameter* mClosedHiHatInFloorTomMicGain = nullptr;
	juce::RangedAudioParameter* mClosedHiHatInRideMicGain = nullptr;
	juce::RangedAudioParameter* mClosedHiHatInOverheadLeftMicGain = nullptr;
	juce::RangedAudioParameter* mClosedHiHatInOverheadRightMicGain = nullptr;

	juce::RangedAudioParameter* mOpenHiHatInKickMicGain = nullptr;
	juce::RangedAudioParameter* mOpenHiHatInSnareMicGain = nullptr;
	juce::RangedAudioParameter* mOpenHiHatInHiHatMicGain = nullptr;
	juce::RangedAudioParameter* mOpenHiHatInRackTomMicGain = nullptr;
	juce::RangedAudioParameter* mOpenHiHatInFloorTomMicGain = nullptr;
	juce::RangedAudioParameter* mOpenHiHatInRideMicGain = nullptr;
	juce::RangedAudioParameter* mOpenHiHatInOverheadLeftMicGain = nullptr;
	juce::RangedAudioParameter* mOpenHiHatInOverheadRightMicGain = nullptr;

	juce::RangedAudioParameter* mRackTomInKickMicGain = nullptr;
	juce::RangedAudioParameter* mRackTomInSnareMicGain = nullptr;
	juce::RangedAudioParameter* mRackTomInHiHatMicGain = nullptr;
	juce::RangedAudioParameter* mRackTomInRackTomMicGain = nullptr;
	juce::RangedAudioParameter* mRackTomInFloorTomMicGain = nullptr;
	juce::RangedAudioParameter* mRackTomInRideMicGain = nullptr;
	juce::RangedAudioParameter* mRackTomInOverheadLeftMicGain = nullptr;
	juce::RangedAudioParameter* mRackTomInOverheadRightMicGain = nullptr;

	juce::RangedAudioParameter* mFloorTomInKickMicGain = nullptr;
	juce::RangedAudioParameter* mFloorTomInSnareMicGain = nullptr;
	juce::RangedAudioParameter* mFloorTomInHiHatMicGain = nullptr;
	juce::RangedAudioParameter* mFloorTomInRackTomMicGain = nullptr;
	juce::RangedAudioParameter* mFloorTomInFloorTomMicGain = nullptr;
	juce::RangedAudioParameter* mFloorTomInRideMicGain = nullptr;
	juce::RangedAudioParameter* mFloorTomInOverheadLeftMicGain = nullptr;
	juce::RangedAudioParameter* mFloorTomInOverheadRightMicGain = nullptr;

	juce::RangedAudioParameter* mRideBellInKickMicGain = nullptr;
	juce::RangedAudioParameter* mRideBellInSnareMicGain = nullptr;
	juce::RangedAudioParameter* mRideBellInHiHatMicGain = nullptr;
	juce::RangedAudioParameter* mRideBellInRackTomMicGain = nullptr;
	juce::RangedAudioParameter* mRideBellInFloorTomMicGain = nullptr;
	juce::RangedAudioParameter* mRideBellInRideMicGain = nullptr;
	juce::RangedAudioParameter* mRideBellInOverheadLeftMicGain = nullptr;
	juce::RangedAudioParameter* mRideBellInOverheadRightMicGain = nullptr;

	juce::RangedAudioParameter* mRideCymbalInKickMicGain = nullptr;
	juce::RangedAudioParameter* mRideCymbalInSnareMicGain = nullptr;
	juce::RangedAudioParameter* mRideCymbalInHiHatMicGain = nullptr;
	juce::RangedAudioParameter* mRideCymbalInRackTomMicGain = nullptr;
	juce::RangedAudioParameter* mRideCymbalInFloorTomMicGain = nullptr;
	juce::RangedAudioParameter* mRideCymbalInRideMicGain = nullptr;
	juce::RangedAudioParameter* mRideCymbalInOverheadLeftMicGain = nullptr;
	juce::RangedAudioParameter* mRideCymbalInOverheadRightMicGain = nullptr;

	juce::RangedAudioParameter* mCrashCymbal1InKickMicGain = nullptr;
	juce::RangedAudioParameter* mCrashCymbal1InSnareMicGain = nullptr;
	juce::RangedAudioParameter* mCrashCymbal1InHiHatMicGain = nullptr;
	juce::RangedAudioParameter* mCrashCymbal1InRackTomMicGain = nullptr;
	juce::RangedAudioParameter* mCrashCymbal1InFloorTomMicGain = nullptr;
	juce::RangedAudioParameter* mCrashCymbal1InRideMicGain = nullptr;
	juce::RangedAudioParameter* mCrashCymbal1InOverheadLeftMicGain = nullptr;
	juce::RangedAudioParameter* mCrashCymbal1InOverheadRightMicGain = nullptr;

	juce::RangedAudioParameter* mCrashCymbal2InInKickMicGain = nullptr;
	juce::RangedAudioParameter* mCrashCymbal2InInSnareMicGain = nullptr;
	juce::RangedAudioParameter* mCrashCymbal2InInHiHatMicGain = nullptr;
	juce::RangedAudioParameter* mCrashCymbal2InInRackTomMicGain = nullptr;
	juce::RangedAudioParameter* mCrashCymbal2InInFloorTomMicGain = nullptr;
	juce::RangedAudioParameter* mCrashCymbal2InInRideMicGain = nullptr;
	juce::RangedAudioParameter* mCrashCymbal2InInOverheadLeftMicGain = nullptr;
	juce::RangedAudioParameter* mCrashCymbal2InInOverheadRightMicGain = nullptr;

	std::vector< std::vector<juce::RangedAudioParameter*>> mSampleGains = {};

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AcresBasementKitAudioProcessor)
};
