/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Constants.h"
#include "DrumSample.h"

//==============================================================================
AcresBasementKitAudioProcessor::AcresBasementKitAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
	: AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
		.withInput("Input", juce::AudioChannelSet::stereo(), true)
#endif
		.withOutput("#1 Kick mic out", juce::AudioChannelSet::mono(), true)
		.withOutput("#2 Snare mic out", juce::AudioChannelSet::mono(), true)
		.withOutput("#3 Hi-hat mic out", juce::AudioChannelSet::mono(), true)
		.withOutput("#4 Rack tom mic out", juce::AudioChannelSet::mono(), true)
		.withOutput("#5 Floor tom mic out", juce::AudioChannelSet::mono(), true)
		.withOutput("#6 Ride mic out", juce::AudioChannelSet::mono(), true)
		.withOutput("#7 Overhead left mic out", juce::AudioChannelSet::mono(), true)
		.withOutput("#8 Overhead right mic out", juce::AudioChannelSet::mono(), true)
#endif
	), mParameters(*this, nullptr, juce::Identifier("ABKParams"),
		{
std::make_unique<juce::AudioParameterFloat>("mKickInKickMicGain", "Kick In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mKickInSnareMicGain", "Kick In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mKickInHiHatMicGain", "Kick In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mKickInRackTomMicGain", "Kick In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mKickInFloorTomMicGain", "Kick In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mKickInRideMicGain", "Kick In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mKickInOverheadLeftMicGain", "Kick In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mKickInOverheadRightMicGain", "Kick In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("mSnareInKickMicGain", "Snare In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mSnareInSnareMicGain", "Snare In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mSnareInHiHatMicGain", "Snare In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mSnareInRackTomMicGain", "Snare In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mSnareInFloorTomMicGain", "Snare In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mSnareInRideMicGain", "Snare In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mSnareInOverheadLeftMicGain", "Snare In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mSnareInOverheadRightMicGain", "Snare In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("mSideStickInKickMicGain", "Side Stick In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mSideStickInSnareMicGain", "Side Stick In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mSideStickInHiHatMicGain", "Side Stick In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mSideStickInRackTomMicGain", "Side Stick In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mSideStickInFloorTomMicGain", "Side Stick In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mSideStickInRideMicGain", "Side Stick In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mSideStickInOverheadLeftMicGain", "Side Stick In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mSideStickInOverheadRightMicGain", "Side Stick In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("mPedalHiHatInKickMicGain", "Pedal Hi Hat In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mPedalHiHatInSnareMicGain", "Pedal Hi Hat In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mPedalHiHatInHiHatMicGain", "Pedal Hi Hat In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mPedalHiHatInRackTomMicGain", "Pedal Hi Hat In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mPedalHiHatInFloorTomMicGain", "Pedal Hi Hat In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mPedalHiHatInRideMicGain", "Pedal Hi Hat In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mPedalHiHatInOverheadLeftMicGain", "Pedal Hi Hat In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mPedalHiHatInOverheadRightMicGain", "Pedal Hi Hat In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("mClosedHiHatInKickMicGain", "ClosedHiHat In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mClosedHiHatInSnareMicGain", "ClosedHiHat In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mClosedHiHatInHiHatMicGain", "ClosedHiHat In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mClosedHiHatInRackTomMicGain", "ClosedHiHat In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mClosedHiHatInFloorTomMicGain", "ClosedHiHat In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mClosedHiHatInRideMicGain", "ClosedHiHat In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mClosedHiHatInOverheadLeftMicGain", "ClosedHiHat In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mClosedHiHatInOverheadRightMicGain", "ClosedHiHat In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("mOpenHiHatInKickMicGain", "Open Hi Hat In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mOpenHiHatInSnareMicGain", "Open Hi Hat In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mOpenHiHatInHiHatMicGain", "Open Hi Hat In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mOpenHiHatInRackTomMicGain", "Open Hi Hat In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mOpenHiHatInFloorTomMicGain", "Open Hi Hat In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mOpenHiHatInRideMicGain", "Open Hi Hat In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mOpenHiHatInOverheadLeftMicGain", "Open Hi Hat In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mOpenHiHatInOverheadRightMicGain", "Open Hi Hat In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("mRackTomInKickMicGain", "RackTom In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRackTomInSnareMicGain", "RackTom In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRackTomInHiHatMicGain", "RackTom In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRackTomInRackTomMicGain", "RackTom In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRackTomInFloorTomMicGain", "RackTom In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRackTomInRideMicGain", "RackTom In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRackTomInOverheadLeftMicGain", "RackTom In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRackTomInOverheadRightMicGain", "RackTom In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("mFloorTomInKickMicGain", "FloorTom In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mFloorTomInSnareMicGain", "FloorTom In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mFloorTomInHiHatMicGain", "FloorTom In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mFloorTomInRackTomMicGain", "FloorTom In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mFloorTomInFloorTomMicGain", "FloorTom In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mFloorTomInRideMicGain", "FloorTom In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mFloorTomInOverheadLeftMicGain", "FloorTom In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mFloorTomInOverheadRightMicGain", "FloorTom In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("mRideBellInKickMicGain", "Ride Bell In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRideBellInSnareMicGain", "Ride Bell In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRideBellInHiHatMicGain", "Ride Bell In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRideBellInRackTomMicGain", "Ride Bell In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRideBellInFloorTomMicGain", "Ride Bell In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRideBellInRideMicGain", "Ride Bell In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRideBellInOverheadLeftMicGain", "Ride Bell In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRideBellInOverheadRightMicGain", "Ride Bell In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("mRideCymbalInKickMicGain", "Ride Cymbal In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRideCymbalInSnareMicGain", "Ride Cymbal In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRideCymbalInHiHatMicGain", "Ride Cymbal In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRideCymbalInRackTomMicGain", "Ride Cymbal In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRideCymbalInFloorTomMicGain", "Ride Cymbal In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRideCymbalInRideMicGain", "Ride Cymbal In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRideCymbalInOverheadLeftMicGain", "Ride Cymbal In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mRideCymbalInOverheadRightMicGain", "Ride Cymbal In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("mCrashCymbal1InKickMicGain", "Crash Cymbal 1 In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mCrashCymbal1InSnareMicGain", "Crash Cymbal 1 In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mCrashCymbal1InHiHatMicGain", "Crash Cymbal 1 In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mCrashCymbal1InRackTomMicGain", "Crash Cymbal 1 In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mCrashCymbal1InFloorTomMicGain", "Crash Cymbal 1 In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mCrashCymbal1InRideMicGain", "Crash Cymbal 1 In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mCrashCymbal1InOverheadLeftMicGain", "Crash Cymbal 1 In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mCrashCymbal1InOverheadRightMicGain", "Crash Cymbal 1 In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("mCrashCymbal2InInKickMicGain", "Crash Cymbal 2 In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mCrashCymbal2InInSnareMicGain", "Crash Cymbal 2 In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mCrashCymbal2InInHiHatMicGain", "Crash Cymbal 2 In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mCrashCymbal2InInRackTomMicGain", "Crash Cymbal 2 In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mCrashCymbal2InInFloorTomMicGain", "Crash Cymbal 2 In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mCrashCymbal2InInRideMicGain", "Crash Cymbal 2 In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mCrashCymbal2InInOverheadLeftMicGain", "Crash Cymbal 2 In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("mCrashCymbal2InInOverheadRightMicGain", "Crash Cymbal 2 In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

		})
#endif
{
	mFormatManager.registerBasicFormats();

	mKickInKickMicGain = mParameters.getRawParameterValue("mKickInKickMicGain");
	mKickInSnareMicGain = mParameters.getRawParameterValue("mKickInSnareMicGain");
	mKickInHiHatMicGain = mParameters.getRawParameterValue("mKickInHiHatMicGain");
	mKickInRackTomMicGain = mParameters.getRawParameterValue("mKickInRackTomMicGain");
	mKickInFloorTomMicGain = mParameters.getRawParameterValue("mKickInFloorTomMicGain");
	mKickInRideMicGain = mParameters.getRawParameterValue("mKickInRideMicGain");
	mKickInOverheadLeftMicGain = mParameters.getRawParameterValue("mKickInOverheadLeftMicGain");
	mKickInOverheadRightMicGain = mParameters.getRawParameterValue("mKickInOverheadRightMicGain");

	mSnareInKickMicGain = mParameters.getRawParameterValue("mSnareInKickMicGain");
	mSnareInSnareMicGain = mParameters.getRawParameterValue("mSnareInSnareMicGain");
	mSnareInHiHatMicGain = mParameters.getRawParameterValue("mSnareInHiHatMicGain");
	mSnareInRackTomMicGain = mParameters.getRawParameterValue("mSnareInRackTomMicGain");
	mSnareInFloorTomMicGain = mParameters.getRawParameterValue("mSnareInFloorTomMicGain");
	mSnareInRideMicGain = mParameters.getRawParameterValue("mSnareInRideMicGain");
	mSnareInOverheadLeftMicGain = mParameters.getRawParameterValue("mSnareInOverheadLeftMicGain");
	mSnareInOverheadRightMicGain = mParameters.getRawParameterValue("mSnareInOverheadRightMicGain");

	mSideStickInKickMicGain = mParameters.getRawParameterValue("mSideStickInKickMicGain");
	mSideStickInSnareMicGain = mParameters.getRawParameterValue("mSideStickInSnareMicGain");
	mSideStickInHiHatMicGain = mParameters.getRawParameterValue("mSideStickInHiHatMicGain");
	mSideStickInRackTomMicGain = mParameters.getRawParameterValue("mSideStickInRackTomMicGain");
	mSideStickInFloorTomMicGain = mParameters.getRawParameterValue("mSideStickInFloorTomMicGain");
	mSideStickInRideMicGain = mParameters.getRawParameterValue("mSideStickInRideMicGain");
	mSideStickInOverheadLeftMicGain = mParameters.getRawParameterValue("mSideStickInOverheadLeftMicGain");
	mSideStickInOverheadRightMicGain = mParameters.getRawParameterValue("mSideStickInOverheadRightMicGain");

	mPedalHiHatInKickMicGain = mParameters.getRawParameterValue("mPedalHiHatInKickMicGain");
	mPedalHiHatInSnareMicGain = mParameters.getRawParameterValue("mPedalHiHatInSnareMicGain");
	mPedalHiHatInHiHatMicGain = mParameters.getRawParameterValue("mPedalHiHatInHiHatMicGain");
	mPedalHiHatInRackTomMicGain = mParameters.getRawParameterValue("mPedalHiHatInRackTomMicGain");
	mPedalHiHatInFloorTomMicGain = mParameters.getRawParameterValue("mPedalHiHatInFloorTomMicGain");
	mPedalHiHatInRideMicGain = mParameters.getRawParameterValue("mPedalHiHatInRideMicGain");
	mPedalHiHatInOverheadLeftMicGain = mParameters.getRawParameterValue("mPedalHiHatInOverheadLeftMicGain");
	mPedalHiHatInOverheadRightMicGain = mParameters.getRawParameterValue("mPedalHiHatInOverheadRightMicGain");

	mClosedHiHatInKickMicGain = mParameters.getRawParameterValue("mClosedHiHatInKickMicGain");
	mClosedHiHatInSnareMicGain = mParameters.getRawParameterValue("mClosedHiHatInSnareMicGain");
	mClosedHiHatInHiHatMicGain = mParameters.getRawParameterValue("mClosedHiHatInHiHatMicGain");
	mClosedHiHatInRackTomMicGain = mParameters.getRawParameterValue("mClosedHiHatInRackTomMicGain");
	mClosedHiHatInFloorTomMicGain = mParameters.getRawParameterValue("mClosedHiHatInFloorTomMicGain");
	mClosedHiHatInRideMicGain = mParameters.getRawParameterValue("mClosedHiHatInRideMicGain");
	mClosedHiHatInOverheadLeftMicGain = mParameters.getRawParameterValue("mClosedHiHatInOverheadLeftMicGain");
	mClosedHiHatInOverheadRightMicGain = mParameters.getRawParameterValue("mClosedHiHatInOverheadRightMicGain");

	mOpenHiHatInKickMicGain = mParameters.getRawParameterValue("mOpenHiHatInKickMicGain");
	mOpenHiHatInSnareMicGain = mParameters.getRawParameterValue("mOpenHiHatInSnareMicGain");
	mOpenHiHatInHiHatMicGain = mParameters.getRawParameterValue("mOpenHiHatInHiHatMicGain");
	mOpenHiHatInRackTomMicGain = mParameters.getRawParameterValue("mOpenHiHatInRackTomMicGain");
	mOpenHiHatInFloorTomMicGain = mParameters.getRawParameterValue("mOpenHiHatInFloorTomMicGain");
	mOpenHiHatInRideMicGain = mParameters.getRawParameterValue("mOpenHiHatInRideMicGain");
	mOpenHiHatInOverheadLeftMicGain = mParameters.getRawParameterValue("mOpenHiHatInOverheadLeftMicGain");
	mOpenHiHatInOverheadRightMicGain = mParameters.getRawParameterValue("mOpenHiHatInOverheadRightMicGain");

	mRackTomInKickMicGain = mParameters.getRawParameterValue("mRackTomInKickMicGain");
	mRackTomInSnareMicGain = mParameters.getRawParameterValue("mRackTomInSnareMicGain");
	mRackTomInHiHatMicGain = mParameters.getRawParameterValue("mRackTomInHiHatMicGain");
	mRackTomInRackTomMicGain = mParameters.getRawParameterValue("mRackTomInRackTomMicGain");
	mRackTomInFloorTomMicGain = mParameters.getRawParameterValue("mRackTomInFloorTomMicGain");
	mRackTomInRideMicGain = mParameters.getRawParameterValue("mRackTomInRideMicGain");
	mRackTomInOverheadLeftMicGain = mParameters.getRawParameterValue("mRackTomInOverheadLeftMicGain");
	mRackTomInOverheadRightMicGain = mParameters.getRawParameterValue("mRackTomInOverheadRightMicGain");

	mFloorTomInKickMicGain = mParameters.getRawParameterValue("mFloorTomInKickMicGain");
	mFloorTomInSnareMicGain = mParameters.getRawParameterValue("mFloorTomInSnareMicGain");
	mFloorTomInHiHatMicGain = mParameters.getRawParameterValue("mFloorTomInHiHatMicGain");
	mFloorTomInRackTomMicGain = mParameters.getRawParameterValue("mFloorTomInRackTomMicGain");
	mFloorTomInFloorTomMicGain = mParameters.getRawParameterValue("mFloorTomInFloorTomMicGain");
	mFloorTomInRideMicGain = mParameters.getRawParameterValue("mFloorTomInRideMicGain");
	mFloorTomInOverheadLeftMicGain = mParameters.getRawParameterValue("mFloorTomInOverheadLeftMicGain");
	mFloorTomInOverheadRightMicGain = mParameters.getRawParameterValue("mFloorTomInOverheadRightMicGain");

	mRideBellInKickMicGain = mParameters.getRawParameterValue("mRideBellInKickMicGain");
	mRideBellInSnareMicGain = mParameters.getRawParameterValue("mRideBellInSnareMicGain");
	mRideBellInHiHatMicGain = mParameters.getRawParameterValue("mRideBellInHiHatMicGain");
	mRideBellInRackTomMicGain = mParameters.getRawParameterValue("mRideBellInRackTomMicGain");
	mRideBellInFloorTomMicGain = mParameters.getRawParameterValue("mRideBellInFloorTomMicGain");
	mRideBellInRideMicGain = mParameters.getRawParameterValue("mRideBellInRideMicGain");
	mRideBellInOverheadLeftMicGain = mParameters.getRawParameterValue("mRideBellInOverheadLeftMicGain");
	mRideBellInOverheadRightMicGain = mParameters.getRawParameterValue("mRideBellInOverheadRightMicGain");

	mRideCymbalInKickMicGain = mParameters.getRawParameterValue("mRideCymbalInKickMicGain");
	mRideCymbalInSnareMicGain = mParameters.getRawParameterValue("mRideCymbalInSnareMicGain");
	mRideCymbalInHiHatMicGain = mParameters.getRawParameterValue("mRideCymbalInHiHatMicGain");
	mRideCymbalInRackTomMicGain = mParameters.getRawParameterValue("mRideCymbalInRackTomMicGain");
	mRideCymbalInFloorTomMicGain = mParameters.getRawParameterValue("mRideCymbalInFloorTomMicGain");
	mRideCymbalInRideMicGain = mParameters.getRawParameterValue("mRideCymbalInRideMicGain");
	mRideCymbalInOverheadLeftMicGain = mParameters.getRawParameterValue("mRideCymbalInOverheadLeftMicGain");
	mRideCymbalInOverheadRightMicGain = mParameters.getRawParameterValue("mRideCymbalInOverheadRightMicGain");

	mCrashCymbal1InKickMicGain = mParameters.getRawParameterValue("mCrashCymbal1InKickMicGain");
	mCrashCymbal1InSnareMicGain = mParameters.getRawParameterValue("mCrashCymbal1InSnareMicGain");
	mCrashCymbal1InHiHatMicGain = mParameters.getRawParameterValue("mCrashCymbal1InHiHatMicGain");
	mCrashCymbal1InRackTomMicGain = mParameters.getRawParameterValue("mCrashCymbal1InRackTomMicGain");
	mCrashCymbal1InFloorTomMicGain = mParameters.getRawParameterValue("mCrashCymbal1InFloorTomMicGain");
	mCrashCymbal1InRideMicGain = mParameters.getRawParameterValue("mCrashCymbal1InRideMicGain");
	mCrashCymbal1InOverheadLeftMicGain = mParameters.getRawParameterValue("mCrashCymbal1InOverheadLeftMicGain");
	mCrashCymbal1InOverheadRightMicGain = mParameters.getRawParameterValue("mCrashCymbal1InOverheadRightMicGain");

	mCrashCymbal2InInKickMicGain = mParameters.getRawParameterValue("mCrashCymbal2InInKickMicGain");
	mCrashCymbal2InInSnareMicGain = mParameters.getRawParameterValue("mCrashCymbal2InInSnareMicGain");
	mCrashCymbal2InInHiHatMicGain = mParameters.getRawParameterValue("mCrashCymbal2InInHiHatMicGain");
	mCrashCymbal2InInRackTomMicGain = mParameters.getRawParameterValue("mCrashCymbal2InInRackTomMicGain");
	mCrashCymbal2InInFloorTomMicGain = mParameters.getRawParameterValue("mCrashCymbal2InInFloorTomMicGain");
	mCrashCymbal2InInRideMicGain = mParameters.getRawParameterValue("mCrashCymbal2InInRideMicGain");
	mCrashCymbal2InInOverheadLeftMicGain = mParameters.getRawParameterValue("mCrashCymbal2InInOverheadLeftMicGain");
	mCrashCymbal2InInOverheadRightMicGain = mParameters.getRawParameterValue("mCrashCymbal2InInOverheadRightMicGain");

	std::vector<std::atomic<float>*> kickInGains = { mKickInKickMicGain, mKickInSnareMicGain, mKickInHiHatMicGain, mKickInRackTomMicGain, mKickInFloorTomMicGain,mKickInRideMicGain, mKickInOverheadLeftMicGain, mKickInOverheadRightMicGain };
	std::vector<std::atomic<float>*> snareInGains = { mSnareInKickMicGain, mSnareInSnareMicGain, mSnareInHiHatMicGain, mSnareInRackTomMicGain, mSnareInFloorTomMicGain,mSnareInRideMicGain, mSnareInOverheadLeftMicGain, mSnareInOverheadRightMicGain };
	std::vector<std::atomic<float>*> sideStickInGains = { mSideStickInKickMicGain, mSideStickInSnareMicGain, mSideStickInHiHatMicGain, mSideStickInRackTomMicGain, mSideStickInFloorTomMicGain,mSideStickInRideMicGain, mSideStickInOverheadLeftMicGain, mSideStickInOverheadRightMicGain };
	std::vector<std::atomic<float>*> pedalHiHatInGains = { mPedalHiHatInKickMicGain, mPedalHiHatInSnareMicGain, mPedalHiHatInHiHatMicGain, mPedalHiHatInRackTomMicGain, mPedalHiHatInFloorTomMicGain,mPedalHiHatInRideMicGain, mPedalHiHatInOverheadLeftMicGain, mPedalHiHatInOverheadRightMicGain };
	std::vector<std::atomic<float>*> closedHiHatInGains = { mClosedHiHatInKickMicGain, mClosedHiHatInSnareMicGain, mClosedHiHatInHiHatMicGain, mClosedHiHatInRackTomMicGain, mClosedHiHatInFloorTomMicGain,mClosedHiHatInRideMicGain, mClosedHiHatInOverheadLeftMicGain, mClosedHiHatInOverheadRightMicGain };
	std::vector<std::atomic<float>*> openHiHatInGains = { mOpenHiHatInKickMicGain, mOpenHiHatInSnareMicGain, mOpenHiHatInHiHatMicGain, mOpenHiHatInRackTomMicGain, mOpenHiHatInFloorTomMicGain,mOpenHiHatInRideMicGain, mOpenHiHatInOverheadLeftMicGain, mOpenHiHatInOverheadRightMicGain };
	std::vector<std::atomic<float>*> rackTomInGains = { mRackTomInKickMicGain, mRackTomInSnareMicGain, mRackTomInHiHatMicGain, mRackTomInRackTomMicGain, mRackTomInFloorTomMicGain,mRackTomInRideMicGain, mRackTomInOverheadLeftMicGain, mRackTomInOverheadRightMicGain };
	std::vector<std::atomic<float>*> floorTomInGains = { mFloorTomInKickMicGain, mFloorTomInSnareMicGain, mFloorTomInHiHatMicGain, mFloorTomInRackTomMicGain, mFloorTomInFloorTomMicGain,mFloorTomInRideMicGain, mFloorTomInOverheadLeftMicGain, mFloorTomInOverheadRightMicGain };
	std::vector<std::atomic<float>*> rideBellInGains = { mRideBellInKickMicGain, mRideBellInSnareMicGain, mRideBellInHiHatMicGain, mRideBellInRackTomMicGain, mRideBellInFloorTomMicGain,mRideBellInRideMicGain, mRideBellInOverheadLeftMicGain, mRideBellInOverheadRightMicGain };
	std::vector<std::atomic<float>*> rideCymbalInGains = { mRideCymbalInKickMicGain, mRideCymbalInSnareMicGain, mRideCymbalInHiHatMicGain, mRideCymbalInRackTomMicGain, mRideCymbalInFloorTomMicGain,mRideCymbalInRideMicGain, mRideCymbalInOverheadLeftMicGain, mRideCymbalInOverheadRightMicGain };
	std::vector<std::atomic<float>*> crashCymbal1InGains = { mCrashCymbal1InKickMicGain, mCrashCymbal1InSnareMicGain, mCrashCymbal1InHiHatMicGain, mCrashCymbal1InRackTomMicGain, mCrashCymbal1InFloorTomMicGain,mCrashCymbal1InRideMicGain, mCrashCymbal1InOverheadLeftMicGain, mCrashCymbal1InOverheadRightMicGain };
	std::vector<std::atomic<float>*> crashCymbal2InInGains = { mCrashCymbal2InInKickMicGain, mCrashCymbal2InInSnareMicGain, mCrashCymbal2InInHiHatMicGain, mCrashCymbal2InInRackTomMicGain, mCrashCymbal2InInFloorTomMicGain,mCrashCymbal2InInRideMicGain, mCrashCymbal2InInOverheadLeftMicGain, mCrashCymbal2InInOverheadRightMicGain };
	mSampleGains = { 
		snareInGains, 
		kickInGains, 
		closedHiHatInGains,
		crashCymbal1InGains, 
		crashCymbal2InInGains, 
		floorTomInGains, 
		openHiHatInGains, 
		pedalHiHatInGains,
		rackTomInGains,
		rideBellInGains, 
		rideCymbalInGains,
		sideStickInGains, 
	};

	for (int sampleIndex = 0; sampleIndex < constants::samplesSize; sampleIndex++) {
		std::string sampleName = constants::samplesNames[sampleIndex];
		int midiNote = constants::samplesMidiNotes[sampleIndex];
		auto micGains = mSampleGains[sampleIndex];

		for (int microphoneIndex = 0; microphoneIndex < constants::microphonesSize; microphoneIndex++) {
			std::string microphoneName = constants::microphoneNames[microphoneIndex];
			std::string resourceName = sampleName + microphoneName + "mic_wav";
			auto voice = new DrumSamplerVoice();
			auto micGain = micGains[microphoneIndex];

			int dataSizeInBytes;
			const char* sourceData = BinaryData::getNamedResource(resourceName.c_str(), dataSizeInBytes);
			auto memoryInputStream = std::make_unique<juce::MemoryInputStream>(sourceData, dataSizeInBytes, false);

			juce::AudioFormatReader* reader = mFormatManager.createReaderFor(std::move(memoryInputStream));
			if (reader)
			{
				juce::BigInteger range;
				range.setRange(midiNote, 1, true);
				DrumSamplerSound* sound = new DrumSamplerSound(juce::String(resourceName), *reader, range, micGain, midiNote, 0.0, 10.0, 5.0);

				switch (microphoneIndex)
				{
				case 0:
					
					mKickMicSynthesiser.addSound(sound);
					mKickMicSynthesiser.addVoice(new DrumSamplerVoice());
					break;
				case 1:
					mSnareMicSynthesiser.addSound(sound);
					mSnareMicSynthesiser.addVoice(new DrumSamplerVoice());
					break;
				case 2:
					mHiHatMicSynthesiser.addSound(sound);
					mHiHatMicSynthesiser.addVoice(new DrumSamplerVoice());
					break;
				case 3:
					mRackTomMicSynthesiser.addSound(sound);
					mRackTomMicSynthesiser.addVoice(new DrumSamplerVoice());
					break;
				case 4:
					mFloorTomMicSynthesiser.addSound(sound);
					mFloorTomMicSynthesiser.addVoice(new DrumSamplerVoice());
					break;
				case 5:
					mRideMicSynthesiser.addSound(sound);
					mRideMicSynthesiser.addVoice(new DrumSamplerVoice());
					break;
				case 6:
					mOverheadLeftMicSynthesiser.addSound(sound);
					mOverheadLeftMicSynthesiser.addVoice(new DrumSamplerVoice());
					break;
				case 7:
					mOverheadRightMicSynthesiser.addSound(sound);
					mOverheadRightMicSynthesiser.addVoice(new DrumSamplerVoice());
					break;
				default:
					break;
				}
			}
		}
	}
}

AcresBasementKitAudioProcessor::~AcresBasementKitAudioProcessor()
{
	//mSynthesiser.clearSounds();
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

void AcresBasementKitAudioProcessor::setCurrentProgram(int index)
{
}

const juce::String AcresBasementKitAudioProcessor::getProgramName(int index)
{
	return {};
}

void AcresBasementKitAudioProcessor::changeProgramName(int index, const juce::String& newName)
{
}

//==============================================================================
void AcresBasementKitAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
	mKickMicSynthesiser.setCurrentPlaybackSampleRate(sampleRate);
	mSnareMicSynthesiser.setCurrentPlaybackSampleRate(sampleRate);
	mHiHatMicSynthesiser.setCurrentPlaybackSampleRate(sampleRate);
	mRackTomMicSynthesiser.setCurrentPlaybackSampleRate(sampleRate);
	mFloorTomMicSynthesiser.setCurrentPlaybackSampleRate(sampleRate);
	mRideMicSynthesiser.setCurrentPlaybackSampleRate(sampleRate);
	mOverheadLeftMicSynthesiser.setCurrentPlaybackSampleRate(sampleRate);
	mOverheadRightMicSynthesiser.setCurrentPlaybackSampleRate(sampleRate);
}



void AcresBasementKitAudioProcessor::releaseResources()
{
	// When playback stops, you can use this as an opportunity to free up any
	// spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AcresBasementKitAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
	juce::ignoreUnused(layouts);
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
	if (layouts.getMainOutputChannelSet() != layouts.getMaInputChannelSet())
		return false;
#endif

	return true;
#endif
}
#endif

void AcresBasementKitAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
	juce::ScopedNoDenormals noDenormals;
	auto totalNumInputChannels = getTotalNumInputChannels();
	auto totalNumOutputChannels = getTotalNumOutputChannels();


	for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
		buffer.clear(i, 0, buffer.getNumSamples());

	auto busCount = getBusCount(false);
	for (int i = 0; i < busCount; i++) {
		auto busBuffer = getBusBuffer(buffer, false, i);
		auto numSamples = busBuffer.getNumSamples();
		switch (i)
		{
		case 0:
			mKickMicSynthesiser.renderNextBlock(busBuffer, midiMessages, 0, numSamples);
			break;
		case 1:
			mSnareMicSynthesiser.renderNextBlock(busBuffer, midiMessages, 0, numSamples);
			break;
		case 2:
			mHiHatMicSynthesiser.renderNextBlock(busBuffer, midiMessages, 0, numSamples);
			break;
		case 3:
			mRackTomMicSynthesiser.renderNextBlock(busBuffer, midiMessages, 0, numSamples);
			break;
		case 4:
			mFloorTomMicSynthesiser.renderNextBlock(busBuffer, midiMessages, 0, numSamples);
			break;
		case 5:
			mRideMicSynthesiser.renderNextBlock(busBuffer, midiMessages, 0, numSamples);
			break;
		case 6:
			mOverheadLeftMicSynthesiser.renderNextBlock(busBuffer, midiMessages, 0, numSamples);
			break;
		case 7:
			mOverheadRightMicSynthesiser.renderNextBlock(busBuffer, midiMessages, 0, numSamples);
			break;
		default:
			break;
		}
	}
}

void AcresBasementKitAudioProcessor::noteOnSynthesiser(int midiNoteNumber) {
	mKickMicSynthesiser.noteOn(10, midiNoteNumber, 1.0f);
	mSnareMicSynthesiser.noteOn(10, midiNoteNumber, 1.0f);
	mHiHatMicSynthesiser.noteOn(10, midiNoteNumber, 1.0f);
	mRackTomMicSynthesiser.noteOn(10, midiNoteNumber, 1.0f);
	mFloorTomMicSynthesiser.noteOn(10, midiNoteNumber, 1.0f);
	mRideMicSynthesiser.noteOn(10, midiNoteNumber, 1.0f);
	mOverheadLeftMicSynthesiser.noteOn(10, midiNoteNumber, 1.0f);
	mOverheadRightMicSynthesiser.noteOn(10, midiNoteNumber, 1.0f);
}

std::vector<std::vector<std::atomic<float>*>> AcresBasementKitAudioProcessor::getSampleGains() {
	return mSampleGains;
}

//==============================================================================
bool AcresBasementKitAudioProcessor::hasEditor() const
{
	return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* AcresBasementKitAudioProcessor::createEditor()
{
	return new AcresBasementKitAudioProcessorEditor(*this);
}

//==============================================================================
void AcresBasementKitAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
	auto state = mParameters.copyState();
	std::unique_ptr<juce::XmlElement> xml(state.createXml());
	copyXmlToBinary(*xml, destData);
}

void AcresBasementKitAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
	std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

	if (xmlState.get() != nullptr)
		if (xmlState->hasTagName(mParameters.state.getType()))
			mParameters.replaceState(juce::ValueTree::fromXml(*xmlState));
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new AcresBasementKitAudioProcessor();
}
