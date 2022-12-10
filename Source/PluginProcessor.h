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
	std::vector< std::vector<std::atomic<float>*>> getSampleGains();


private:
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

	juce::AudioProcessorValueTreeState mParameters;

	std::atomic<float>* mKickInKickMicGain = nullptr;
	std::atomic<float>* mKickInSnareMicGain = nullptr;
	std::atomic<float>* mKickInHiHatMicGain = nullptr;
	std::atomic<float>* mKickInRackTomMicGain = nullptr;
	std::atomic<float>* mKickInFloorTomMicGain = nullptr;
	std::atomic<float>* mKickInRideMicGain = nullptr;
	std::atomic<float>* mKickInOverheadLeftMicGain = nullptr;
	std::atomic<float>* mKickInOverheadRightMicGain = nullptr;

	std::atomic<float>* mSnareInKickMicGain = nullptr;
	std::atomic<float>* mSnareInSnareMicGain = nullptr;
	std::atomic<float>* mSnareInHiHatMicGain = nullptr;
	std::atomic<float>* mSnareInRackTomMicGain = nullptr;
	std::atomic<float>* mSnareInFloorTomMicGain = nullptr;
	std::atomic<float>* mSnareInRideMicGain = nullptr;
	std::atomic<float>* mSnareInOverheadLeftMicGain = nullptr;
	std::atomic<float>* mSnareInOverheadRightMicGain = nullptr;

	std::atomic<float>* mSideStickInKickMicGain = nullptr;
	std::atomic<float>* mSideStickInSnareMicGain = nullptr;
	std::atomic<float>* mSideStickInHiHatMicGain = nullptr;
	std::atomic<float>* mSideStickInRackTomMicGain = nullptr;
	std::atomic<float>* mSideStickInFloorTomMicGain = nullptr;
	std::atomic<float>* mSideStickInRideMicGain = nullptr;
	std::atomic<float>* mSideStickInOverheadLeftMicGain = nullptr;
	std::atomic<float>* mSideStickInOverheadRightMicGain = nullptr;

	std::atomic<float>* mPedalHiHatInKickMicGain = nullptr;
	std::atomic<float>* mPedalHiHatInSnareMicGain = nullptr;
	std::atomic<float>* mPedalHiHatInHiHatMicGain = nullptr;
	std::atomic<float>* mPedalHiHatInRackTomMicGain = nullptr;
	std::atomic<float>* mPedalHiHatInFloorTomMicGain = nullptr;
	std::atomic<float>* mPedalHiHatInRideMicGain = nullptr;
	std::atomic<float>* mPedalHiHatInOverheadLeftMicGain = nullptr;
	std::atomic<float>* mPedalHiHatInOverheadRightMicGain = nullptr;

	std::atomic<float>* mClosedHiHatInKickMicGain = nullptr;
	std::atomic<float>* mClosedHiHatInSnareMicGain = nullptr;
	std::atomic<float>* mClosedHiHatInHiHatMicGain = nullptr;
	std::atomic<float>* mClosedHiHatInRackTomMicGain = nullptr;
	std::atomic<float>* mClosedHiHatInFloorTomMicGain = nullptr;
	std::atomic<float>* mClosedHiHatInRideMicGain = nullptr;
	std::atomic<float>* mClosedHiHatInOverheadLeftMicGain = nullptr;
	std::atomic<float>* mClosedHiHatInOverheadRightMicGain = nullptr;

	std::atomic<float>* mOpenHiHatInKickMicGain = nullptr;
	std::atomic<float>* mOpenHiHatInSnareMicGain = nullptr;
	std::atomic<float>* mOpenHiHatInHiHatMicGain = nullptr;
	std::atomic<float>* mOpenHiHatInRackTomMicGain = nullptr;
	std::atomic<float>* mOpenHiHatInFloorTomMicGain = nullptr;
	std::atomic<float>* mOpenHiHatInRideMicGain = nullptr;
	std::atomic<float>* mOpenHiHatInOverheadLeftMicGain = nullptr;
	std::atomic<float>* mOpenHiHatInOverheadRightMicGain = nullptr;

	std::atomic<float>* mRackTomInKickMicGain = nullptr;
	std::atomic<float>* mRackTomInSnareMicGain = nullptr;
	std::atomic<float>* mRackTomInHiHatMicGain = nullptr;
	std::atomic<float>* mRackTomInRackTomMicGain = nullptr;
	std::atomic<float>* mRackTomInFloorTomMicGain = nullptr;
	std::atomic<float>* mRackTomInRideMicGain = nullptr;
	std::atomic<float>* mRackTomInOverheadLeftMicGain = nullptr;
	std::atomic<float>* mRackTomInOverheadRightMicGain = nullptr;

	std::atomic<float>* mFloorTomInKickMicGain = nullptr;
	std::atomic<float>* mFloorTomInSnareMicGain = nullptr;
	std::atomic<float>* mFloorTomInHiHatMicGain = nullptr;
	std::atomic<float>* mFloorTomInRackTomMicGain = nullptr;
	std::atomic<float>* mFloorTomInFloorTomMicGain = nullptr;
	std::atomic<float>* mFloorTomInRideMicGain = nullptr;
	std::atomic<float>* mFloorTomInOverheadLeftMicGain = nullptr;
	std::atomic<float>* mFloorTomInOverheadRightMicGain = nullptr;

	std::atomic<float>* mRideBellInKickMicGain = nullptr;
	std::atomic<float>* mRideBellInSnareMicGain = nullptr;
	std::atomic<float>* mRideBellInHiHatMicGain = nullptr;
	std::atomic<float>* mRideBellInRackTomMicGain = nullptr;
	std::atomic<float>* mRideBellInFloorTomMicGain = nullptr;
	std::atomic<float>* mRideBellInRideMicGain = nullptr;
	std::atomic<float>* mRideBellInOverheadLeftMicGain = nullptr;
	std::atomic<float>* mRideBellInOverheadRightMicGain = nullptr;

	std::atomic<float>* mRideCymbalInKickMicGain = nullptr;
	std::atomic<float>* mRideCymbalInSnareMicGain = nullptr;
	std::atomic<float>* mRideCymbalInHiHatMicGain = nullptr;
	std::atomic<float>* mRideCymbalInRackTomMicGain = nullptr;
	std::atomic<float>* mRideCymbalInFloorTomMicGain = nullptr;
	std::atomic<float>* mRideCymbalInRideMicGain = nullptr;
	std::atomic<float>* mRideCymbalInOverheadLeftMicGain = nullptr;
	std::atomic<float>* mRideCymbalInOverheadRightMicGain = nullptr;

	std::atomic<float>* mCrashCymbal1InKickMicGain = nullptr;
	std::atomic<float>* mCrashCymbal1InSnareMicGain = nullptr;
	std::atomic<float>* mCrashCymbal1InHiHatMicGain = nullptr;
	std::atomic<float>* mCrashCymbal1InRackTomMicGain = nullptr;
	std::atomic<float>* mCrashCymbal1InFloorTomMicGain = nullptr;
	std::atomic<float>* mCrashCymbal1InRideMicGain = nullptr;
	std::atomic<float>* mCrashCymbal1InOverheadLeftMicGain = nullptr;
	std::atomic<float>* mCrashCymbal1InOverheadRightMicGain = nullptr;

	std::atomic<float>* mCrashCymbal2InInKickMicGain = nullptr;
	std::atomic<float>* mCrashCymbal2InInSnareMicGain = nullptr;
	std::atomic<float>* mCrashCymbal2InInHiHatMicGain = nullptr;
	std::atomic<float>* mCrashCymbal2InInRackTomMicGain = nullptr;
	std::atomic<float>* mCrashCymbal2InInFloorTomMicGain = nullptr;
	std::atomic<float>* mCrashCymbal2InInRideMicGain = nullptr;
	std::atomic<float>* mCrashCymbal2InInOverheadLeftMicGain = nullptr;
	std::atomic<float>* mCrashCymbal2InInOverheadRightMicGain = nullptr;


	std::vector< std::vector<std::atomic<float>*>> mSampleGains = {};


	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AcresBasementKitAudioProcessor)
};
