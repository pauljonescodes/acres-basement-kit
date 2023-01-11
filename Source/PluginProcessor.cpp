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
		.withOutput("#1 Kick mic out", juce::AudioChannelSet::stereo(), true)
		.withOutput("#2 Snare mic out", juce::AudioChannelSet::stereo(), true)
		.withOutput("#3 Hi-hat mic out", juce::AudioChannelSet::stereo(), true)
		.withOutput("#4 Rack tom mic out", juce::AudioChannelSet::stereo(), true)
		.withOutput("#5 Floor tom mic out", juce::AudioChannelSet::stereo(), true)
		.withOutput("#6 Ride mic out", juce::AudioChannelSet::stereo(), true)
		.withOutput("#7 Overhead left mic out", juce::AudioChannelSet::stereo(), true)
		.withOutput("#8 Overhead right mic out", juce::AudioChannelSet::stereo(), true)
#endif
	), mParameterValueTreeState(*this, nullptr, juce::Identifier("ABKParams"),
		{

std::make_unique<juce::AudioParameterFloat>("kick-mic-panning", "Kick Mic Panning", -1.0f, 1.0f, 0.0f),
std::make_unique<juce::AudioParameterFloat>("snare-mic-panning", "Snare Mic Panning", -1.0f, 1.0f, -0.25f),
std::make_unique<juce::AudioParameterFloat>("hihat-mic-panning", "Hi Hat Mic Panning", -1.0f, 1.0f, -0.25f),
std::make_unique<juce::AudioParameterFloat>("racktom-mic-panning", "Rack Tom Mic Panning", -1.0f, 1.0f, 0.25f),
std::make_unique<juce::AudioParameterFloat>("floortom-mic-panning", "Floor Tom Mic Panning", -1.0f, 1.0f, 0.5f),
std::make_unique<juce::AudioParameterFloat>("ride-mic-panning", "Ride Mic Panning", -1.0f, 1.0f, 0.5f),
std::make_unique<juce::AudioParameterFloat>("ohleft-mic-panning", "Overhead Left Mic Panning", -1.0f, 1.0f, -1.0f),
std::make_unique<juce::AudioParameterFloat>("ohright-mic-panning", "Overhead Right Mic Panning", -1.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("bassdrum-in-kick-mic-gain", "Kick In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("bassdrum-in-snare-mic-gain", "Kick In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("bassdrum-in-hihat-mic-gain", "Kick In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("bassdrum-in-racktom-mic-gain", "Kick In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("bassdrum-in-floortom-mic-gain", "Kick In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("bassdrum-in-ride-mic-gain", "Kick In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("bassdrum-in-ohleft-mic-gain", "Kick In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("bassdrum-in-ohright-mic-gain", "Kick In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("acousticsnare-in-kick-mic-gain", "Snare In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("acousticsnare-in-snare-mic-gain", "Snare In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("acousticsnare-in-hihat-mic-gain", "Snare In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("acousticsnare-in-racktom-mic-gain", "Snare In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("acousticsnare-in-floortom-mic-gain", "Snare In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("acousticsnare-in-ride-mic-gain", "Snare In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("acousticsnare-in-ohleft-mic-gain", "Snare In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("acousticsnare-in-ohright-mic-gain", "Snare In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("sidestick-in-kick-mic-gain", "Side Stick In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("sidestick-in-snare-mic-gain", "Side Stick In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("sidestick-in-hihat-mic-gain", "Side Stick In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("sidestick-in-racktom-mic-gain", "Side Stick In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("sidestick-in-floortom-mic-gain", "Side Stick In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("sidestick-in-ride-mic-gain", "Side Stick In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("sidestick-in-ohleft-mic-gain", "Side Stick In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("sidestick-in-ohright-mic-gain", "Side Stick In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("pedalhihat-in-kick-mic-gain", "Pedal Hi Hat In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("pedalhihat-in-snare-mic-gain", "Pedal Hi Hat In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("pedalhihat-in-hihat-mic-gain", "Pedal Hi Hat In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("pedalhihat-in-racktom-mic-gain", "Pedal Hi Hat In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("pedalhihat-in-floortom-mic-gain", "Pedal Hi Hat In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("pedalhihat-in-ride-mic-gain", "Pedal Hi Hat In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("pedalhihat-in-ohleft-mic-gain", "Pedal Hi Hat In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("pedalhihat-in-ohright-mic-gain", "Pedal Hi Hat In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("closedhihat-in-kick-mic-gain", "ClosedHiHat In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("closedhihat-in-snare-mic-gain", "ClosedHiHat In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("closedhihat-in-hihat-mic-gain", "ClosedHiHat In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("closedhihat-in-racktom-mic-gain", "ClosedHiHat In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("closedhihat-in-floortom-mic-gain", "ClosedHiHat In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("closedhihat-in-ride-mic-gain", "ClosedHiHat In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("closedhihat-in-ohleft-mic-gain", "ClosedHiHat In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("closedhihat-in-ohright-mic-gain", "ClosedHiHat In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("openhihat-in-kick-mic-gain", "Open Hi Hat In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("openhihat-in-snare-mic-gain", "Open Hi Hat In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("openhihat-in-hihat-mic-gain", "Open Hi Hat In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("openhihat-in-racktom-mic-gain", "Open Hi Hat In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("openhihat-in-floortom-mic-gain", "Open Hi Hat In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("openhihat-in-ride-mic-gain", "Open Hi Hat In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("openhihat-in-ohleft-mic-gain", "Open Hi Hat In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("openhihat-in-ohright-mic-gain", "Open Hi Hat In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("racktom-in-kick-mic-gain", "RackTom In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("racktom-in-snare-mic-gain", "RackTom In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("racktom-in-hihat-mic-gain", "RackTom In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("racktom-in-racktom-mic-gain", "RackTom In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("racktom-in-floortom-mic-gain", "RackTom In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("racktom-in-ride-mic-gain", "RackTom In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("racktom-in-ohleft-mic-gain", "RackTom In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("racktom-in-ohright-mic-gain", "RackTom In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("floortom-in-kick-mic-gain", "FloorTom In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("floortom-in-snare-mic-gain", "FloorTom In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("floortom-in-hihat-mic-gain", "FloorTom In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("floortom-in-racktom-mic-gain", "FloorTom In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("floortom-in-floortom-mic-gain", "FloorTom In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("floortom-in-ride-mic-gain", "FloorTom In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("floortom-in-ohleft-mic-gain", "FloorTom In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("floortom-in-ohright-mic-gain", "FloorTom In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("ridebell-in-kick-mic-gain", "Ride Bell In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("ridebell-in-snare-mic-gain", "Ride Bell In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("ridebell-in-hihat-mic-gain", "Ride Bell In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("ridebell-in-racktom-mic-gain", "Ride Bell In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("ridebell-in-floortom-mic-gain", "Ride Bell In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("ridebell-in-ride-mic-gain", "Ride Bell In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("ridebell-in-ohleft-mic-gain", "Ride Bell In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("ridebell-in-ohright-mic-gain", "Ride Bell In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("ridecymbal-in-kick-mic-gain", "Ride Cymbal In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("ridecymbal-in-snare-mic-gain", "Ride Cymbal In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("ridecymbal-in-hihat-mic-gain", "Ride Cymbal In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("ridecymbal-in-racktom-mic-gain", "Ride Cymbal In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("ridecymbal-in-floortom-mic-gain", "Ride Cymbal In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("ridecymbal-in-ride-mic-gain", "Ride Cymbal In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("ridecymbal-in-ohleft-mic-gain", "Ride Cymbal In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("ridecymbal-in-ohright-mic-gain", "Ride Cymbal In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("crashcymbal1-in-kick-mic-gain", "Crash Cymbal 1 In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("crashcymbal1-in-snare-mic-gain", "Crash Cymbal 1 In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("crashcymbal1-in-hihat-mic-gain", "Crash Cymbal 1 In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("crashcymbal1-in-racktom-mic-gain", "Crash Cymbal 1 In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("crashcymbal1-in-floortom-mic-gain", "Crash Cymbal 1 In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("crashcymbal1-in-ride-mic-gain", "Crash Cymbal 1 In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("crashcymbal1-in-ohleft-mic-gain", "Crash Cymbal 1 In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("crashcymbal1-in-ohright-mic-gain", "Crash Cymbal 1 In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),

std::make_unique<juce::AudioParameterFloat>("crashcymbal2-in-kick-mic-gain", "Crash Cymbal 2 In Kick Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("crashcymbal2-in-snare-mic-gain", "Crash Cymbal 2 In Snare Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("crashcymbal2-in-hihat-mic-gain", "Crash Cymbal 2 In Hi Hat Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("crashcymbal2-in-racktom-mic-gain", "Crash Cymbal 2 In Rack Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("crashcymbal2-in-floortom-mic-gain", "Crash Cymbal 2 In Floor Tom Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("crashcymbal2-in-ride-mic-gain", "Crash Cymbal 2 In Ride Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("crashcymbal2-in-ohleft-mic-gain", "Crash Cymbal 2 In Overhead Left Mic Gain", 0.0f, 1.0f, 1.0f),
std::make_unique<juce::AudioParameterFloat>("crashcymbal2-in-ohright-mic-gain", "Crash Cymbal 2 In Overhead Right Mic Gain", 0.0f, 1.0f, 1.0f),


		})
#endif
{
	mFormatManager.registerBasicFormats();

	mKickMicPanning = mParameterValueTreeState.getParameter("kick-mic-panning");
	mSnareMicPanning = mParameterValueTreeState.getParameter("snare-mic-panning");
	mHiHatMicPanning = mParameterValueTreeState.getParameter("hihat-mic-panning");
	mRackTomMicPanning = mParameterValueTreeState.getParameter("racktom-mic-panning");
	mFloorTomMicPanning = mParameterValueTreeState.getParameter("floortom-mic-panning");
	mRideMicPanning = mParameterValueTreeState.getParameter("ride-mic-panning");
	mOverheadLeftMicPanning = mParameterValueTreeState.getParameter("ohleft-mic-panning");
	mOverheadRightMicPanning = mParameterValueTreeState.getParameter("ohright-mic-panning");

	mKickInKickMicGain = mParameterValueTreeState.getParameter("bassdrum-in-kick-mic-gain");
	mKickInSnareMicGain = mParameterValueTreeState.getParameter("bassdrum-in-snare-mic-gain");
	mKickInHiHatMicGain = mParameterValueTreeState.getParameter("bassdrum-in-hihat-mic-gain");
	mKickInRackTomMicGain = mParameterValueTreeState.getParameter("bassdrum-in-racktom-mic-gain");
	mKickInFloorTomMicGain = mParameterValueTreeState.getParameter("bassdrum-in-floortom-mic-gain");
	mKickInRideMicGain = mParameterValueTreeState.getParameter("bassdrum-in-ride-mic-gain");
	mKickInOverheadLeftMicGain = mParameterValueTreeState.getParameter("bassdrum-in-ohleft-mic-gain");
	mKickInOverheadRightMicGain = mParameterValueTreeState.getParameter("bassdrum-in-ohright-mic-gain");

	mSnareInKickMicGain = mParameterValueTreeState.getParameter("acousticsnare-in-kick-mic-gain");
	mSnareInSnareMicGain = mParameterValueTreeState.getParameter("acousticsnare-in-snare-mic-gain");
	mSnareInHiHatMicGain = mParameterValueTreeState.getParameter("acousticsnare-in-hihat-mic-gain");
	mSnareInRackTomMicGain = mParameterValueTreeState.getParameter("acousticsnare-in-racktom-mic-gain");
	mSnareInFloorTomMicGain = mParameterValueTreeState.getParameter("acousticsnare-in-floortom-mic-gain");
	mSnareInRideMicGain = mParameterValueTreeState.getParameter("acousticsnare-in-ride-mic-gain");
	mSnareInOverheadLeftMicGain = mParameterValueTreeState.getParameter("acousticsnare-in-ohleft-mic-gain");
	mSnareInOverheadRightMicGain = mParameterValueTreeState.getParameter("acousticsnare-in-ohright-mic-gain");

	mSideStickInKickMicGain = mParameterValueTreeState.getParameter("sidestick-in-kick-mic-gain");
	mSideStickInSnareMicGain = mParameterValueTreeState.getParameter("sidestick-in-snare-mic-gain");
	mSideStickInHiHatMicGain = mParameterValueTreeState.getParameter("sidestick-in-hihat-mic-gain");
	mSideStickInRackTomMicGain = mParameterValueTreeState.getParameter("sidestick-in-racktom-mic-gain");
	mSideStickInFloorTomMicGain = mParameterValueTreeState.getParameter("sidestick-in-floortom-mic-gain");
	mSideStickInRideMicGain = mParameterValueTreeState.getParameter("sidestick-in-ride-mic-gain");
	mSideStickInOverheadLeftMicGain = mParameterValueTreeState.getParameter("sidestick-in-ohleft-mic-gain");
	mSideStickInOverheadRightMicGain = mParameterValueTreeState.getParameter("sidestick-in-ohright-mic-gain");

	mPedalHiHatInKickMicGain = mParameterValueTreeState.getParameter("pedalhihat-in-kick-mic-gain");
	mPedalHiHatInSnareMicGain = mParameterValueTreeState.getParameter("pedalhihat-in-snare-mic-gain");
	mPedalHiHatInHiHatMicGain = mParameterValueTreeState.getParameter("pedalhihat-in-hihat-mic-gain");
	mPedalHiHatInRackTomMicGain = mParameterValueTreeState.getParameter("pedalhihat-in-racktom-mic-gain");
	mPedalHiHatInFloorTomMicGain = mParameterValueTreeState.getParameter("pedalhihat-in-floortom-mic-gain");
	mPedalHiHatInRideMicGain = mParameterValueTreeState.getParameter("pedalhihat-in-ride-mic-gain");
	mPedalHiHatInOverheadLeftMicGain = mParameterValueTreeState.getParameter("pedalhihat-in-ohleft-mic-gain");
	mPedalHiHatInOverheadRightMicGain = mParameterValueTreeState.getParameter("pedalhihat-in-ohright-mic-gain");

	mClosedHiHatInKickMicGain = mParameterValueTreeState.getParameter("closedhihat-in-kick-mic-gain");
	mClosedHiHatInSnareMicGain = mParameterValueTreeState.getParameter("closedhihat-in-snare-mic-gain");
	mClosedHiHatInHiHatMicGain = mParameterValueTreeState.getParameter("closedhihat-in-hihat-mic-gain");
	mClosedHiHatInRackTomMicGain = mParameterValueTreeState.getParameter("closedhihat-in-racktom-mic-gain");
	mClosedHiHatInFloorTomMicGain = mParameterValueTreeState.getParameter("closedhihat-in-floortom-mic-gain");
	mClosedHiHatInRideMicGain = mParameterValueTreeState.getParameter("closedhihat-in-ride-mic-gain");
	mClosedHiHatInOverheadLeftMicGain = mParameterValueTreeState.getParameter("closedhihat-in-ohleft-mic-gain");
	mClosedHiHatInOverheadRightMicGain = mParameterValueTreeState.getParameter("closedhihat-in-ohright-mic-gain");

	mOpenHiHatInKickMicGain = mParameterValueTreeState.getParameter("openhihat-in-kick-mic-gain");
	mOpenHiHatInSnareMicGain = mParameterValueTreeState.getParameter("openhihat-in-snare-mic-gain");
	mOpenHiHatInHiHatMicGain = mParameterValueTreeState.getParameter("openhihat-in-hihat-mic-gain");
	mOpenHiHatInRackTomMicGain = mParameterValueTreeState.getParameter("openhihat-in-racktom-mic-gain");
	mOpenHiHatInFloorTomMicGain = mParameterValueTreeState.getParameter("openhihat-in-floortom-mic-gain");
	mOpenHiHatInRideMicGain = mParameterValueTreeState.getParameter("openhihat-in-ride-mic-gain");
	mOpenHiHatInOverheadLeftMicGain = mParameterValueTreeState.getParameter("openhihat-in-ohleft-mic-gain");
	mOpenHiHatInOverheadRightMicGain = mParameterValueTreeState.getParameter("openhihat-in-ohright-mic-gain");

	mRackTomInKickMicGain = mParameterValueTreeState.getParameter("racktom-in-kick-mic-gain");
	mRackTomInSnareMicGain = mParameterValueTreeState.getParameter("racktom-in-snare-mic-gain");
	mRackTomInHiHatMicGain = mParameterValueTreeState.getParameter("racktom-in-hihat-mic-gain");
	mRackTomInRackTomMicGain = mParameterValueTreeState.getParameter("racktom-in-racktom-mic-gain");
	mRackTomInFloorTomMicGain = mParameterValueTreeState.getParameter("racktom-in-floortom-mic-gain");
	mRackTomInRideMicGain = mParameterValueTreeState.getParameter("racktom-in-ride-mic-gain");
	mRackTomInOverheadLeftMicGain = mParameterValueTreeState.getParameter("racktom-in-ohleft-mic-gain");
	mRackTomInOverheadRightMicGain = mParameterValueTreeState.getParameter("racktom-in-ohright-mic-gain");

	mFloorTomInKickMicGain = mParameterValueTreeState.getParameter("floortom-in-kick-mic-gain");
	mFloorTomInSnareMicGain = mParameterValueTreeState.getParameter("floortom-in-snare-mic-gain");
	mFloorTomInHiHatMicGain = mParameterValueTreeState.getParameter("floortom-in-hihat-mic-gain");
	mFloorTomInRackTomMicGain = mParameterValueTreeState.getParameter("floortom-in-racktom-mic-gain");
	mFloorTomInFloorTomMicGain = mParameterValueTreeState.getParameter("floortom-in-floortom-mic-gain");
	mFloorTomInRideMicGain = mParameterValueTreeState.getParameter("floortom-in-ride-mic-gain");
	mFloorTomInOverheadLeftMicGain = mParameterValueTreeState.getParameter("floortom-in-ohleft-mic-gain");
	mFloorTomInOverheadRightMicGain = mParameterValueTreeState.getParameter("floortom-in-ohright-mic-gain");

	mRideBellInKickMicGain = mParameterValueTreeState.getParameter("ridebell-in-kick-mic-gain");
	mRideBellInSnareMicGain = mParameterValueTreeState.getParameter("ridebell-in-snare-mic-gain");
	mRideBellInHiHatMicGain = mParameterValueTreeState.getParameter("ridebell-in-hihat-mic-gain");
	mRideBellInRackTomMicGain = mParameterValueTreeState.getParameter("ridebell-in-racktom-mic-gain");
	mRideBellInFloorTomMicGain = mParameterValueTreeState.getParameter("ridebell-in-floortom-mic-gain");
	mRideBellInRideMicGain = mParameterValueTreeState.getParameter("ridebell-in-ride-mic-gain");
	mRideBellInOverheadLeftMicGain = mParameterValueTreeState.getParameter("ridebell-in-ohleft-mic-gain");
	mRideBellInOverheadRightMicGain = mParameterValueTreeState.getParameter("ridebell-in-ohright-mic-gain");

	mRideCymbalInKickMicGain = mParameterValueTreeState.getParameter("ridecymbal-in-kick-mic-gain");
	mRideCymbalInSnareMicGain = mParameterValueTreeState.getParameter("ridecymbal-in-snare-mic-gain");
	mRideCymbalInHiHatMicGain = mParameterValueTreeState.getParameter("ridecymbal-in-hihat-mic-gain");
	mRideCymbalInRackTomMicGain = mParameterValueTreeState.getParameter("ridecymbal-in-racktom-mic-gain");
	mRideCymbalInFloorTomMicGain = mParameterValueTreeState.getParameter("ridecymbal-in-floortom-mic-gain");
	mRideCymbalInRideMicGain = mParameterValueTreeState.getParameter("ridecymbal-in-ride-mic-gain");
	mRideCymbalInOverheadLeftMicGain = mParameterValueTreeState.getParameter("ridecymbal-in-ohleft-mic-gain");
	mRideCymbalInOverheadRightMicGain = mParameterValueTreeState.getParameter("ridecymbal-in-ohright-mic-gain");

	mCrashCymbal1InKickMicGain = mParameterValueTreeState.getParameter("crashcymbal1-in-kick-mic-gain");
	mCrashCymbal1InSnareMicGain = mParameterValueTreeState.getParameter("crashcymbal1-in-snare-mic-gain");
	mCrashCymbal1InHiHatMicGain = mParameterValueTreeState.getParameter("crashcymbal1-in-hihat-mic-gain");
	mCrashCymbal1InRackTomMicGain = mParameterValueTreeState.getParameter("crashcymbal1-in-racktom-mic-gain");
	mCrashCymbal1InFloorTomMicGain = mParameterValueTreeState.getParameter("crashcymbal1-in-floortom-mic-gain");
	mCrashCymbal1InRideMicGain = mParameterValueTreeState.getParameter("crashcymbal1-in-ride-mic-gain");
	mCrashCymbal1InOverheadLeftMicGain = mParameterValueTreeState.getParameter("crashcymbal1-in-ohleft-mic-gain");
	mCrashCymbal1InOverheadRightMicGain = mParameterValueTreeState.getParameter("crashcymbal1-in-ohright-mic-gain");

	mCrashCymbal2InInKickMicGain = mParameterValueTreeState.getParameter("crashcymbal2-in-kick-mic-gain");
	mCrashCymbal2InInSnareMicGain = mParameterValueTreeState.getParameter("crashcymbal2-in-snare-mic-gain");
	mCrashCymbal2InInHiHatMicGain = mParameterValueTreeState.getParameter("crashcymbal2-in-hihat-mic-gain");
	mCrashCymbal2InInRackTomMicGain = mParameterValueTreeState.getParameter("crashcymbal2-in-racktom-mic-gain");
	mCrashCymbal2InInFloorTomMicGain = mParameterValueTreeState.getParameter("crashcymbal2-in-floortom-mic-gain");
	mCrashCymbal2InInRideMicGain = mParameterValueTreeState.getParameter("crashcymbal2-in-ride-mic-gain");
	mCrashCymbal2InInOverheadLeftMicGain = mParameterValueTreeState.getParameter("crashcymbal2-in-ohleft-mic-gain");
	mCrashCymbal2InInOverheadRightMicGain = mParameterValueTreeState.getParameter("crashcymbal2-in-ohright-mic-gain");

	std::vector<juce::RangedAudioParameter*> kickInGains = { mKickInKickMicGain, mKickInSnareMicGain, mKickInHiHatMicGain, mKickInRackTomMicGain, mKickInFloorTomMicGain,mKickInRideMicGain, mKickInOverheadLeftMicGain, mKickInOverheadRightMicGain };
	std::vector<juce::RangedAudioParameter*> snareInGains = { mSnareInKickMicGain, mSnareInSnareMicGain, mSnareInHiHatMicGain, mSnareInRackTomMicGain, mSnareInFloorTomMicGain,mSnareInRideMicGain, mSnareInOverheadLeftMicGain, mSnareInOverheadRightMicGain };
	std::vector<juce::RangedAudioParameter*> sideStickInGains = { mSideStickInKickMicGain, mSideStickInSnareMicGain, mSideStickInHiHatMicGain, mSideStickInRackTomMicGain, mSideStickInFloorTomMicGain,mSideStickInRideMicGain, mSideStickInOverheadLeftMicGain, mSideStickInOverheadRightMicGain };
	std::vector<juce::RangedAudioParameter*> pedalHiHatInGains = { mPedalHiHatInKickMicGain, mPedalHiHatInSnareMicGain, mPedalHiHatInHiHatMicGain, mPedalHiHatInRackTomMicGain, mPedalHiHatInFloorTomMicGain,mPedalHiHatInRideMicGain, mPedalHiHatInOverheadLeftMicGain, mPedalHiHatInOverheadRightMicGain };
	std::vector<juce::RangedAudioParameter*> closedHiHatInGains = { mClosedHiHatInKickMicGain, mClosedHiHatInSnareMicGain, mClosedHiHatInHiHatMicGain, mClosedHiHatInRackTomMicGain, mClosedHiHatInFloorTomMicGain,mClosedHiHatInRideMicGain, mClosedHiHatInOverheadLeftMicGain, mClosedHiHatInOverheadRightMicGain };
	std::vector<juce::RangedAudioParameter*> openHiHatInGains = { mOpenHiHatInKickMicGain, mOpenHiHatInSnareMicGain, mOpenHiHatInHiHatMicGain, mOpenHiHatInRackTomMicGain, mOpenHiHatInFloorTomMicGain,mOpenHiHatInRideMicGain, mOpenHiHatInOverheadLeftMicGain, mOpenHiHatInOverheadRightMicGain };
	std::vector<juce::RangedAudioParameter*> rackTomInGains = { mRackTomInKickMicGain, mRackTomInSnareMicGain, mRackTomInHiHatMicGain, mRackTomInRackTomMicGain, mRackTomInFloorTomMicGain,mRackTomInRideMicGain, mRackTomInOverheadLeftMicGain, mRackTomInOverheadRightMicGain };
	std::vector<juce::RangedAudioParameter*> floorTomInGains = { mFloorTomInKickMicGain, mFloorTomInSnareMicGain, mFloorTomInHiHatMicGain, mFloorTomInRackTomMicGain, mFloorTomInFloorTomMicGain,mFloorTomInRideMicGain, mFloorTomInOverheadLeftMicGain, mFloorTomInOverheadRightMicGain };
	std::vector<juce::RangedAudioParameter*> rideBellInGains = { mRideBellInKickMicGain, mRideBellInSnareMicGain, mRideBellInHiHatMicGain, mRideBellInRackTomMicGain, mRideBellInFloorTomMicGain,mRideBellInRideMicGain, mRideBellInOverheadLeftMicGain, mRideBellInOverheadRightMicGain };
	std::vector<juce::RangedAudioParameter*> rideCymbalInGains = { mRideCymbalInKickMicGain, mRideCymbalInSnareMicGain, mRideCymbalInHiHatMicGain, mRideCymbalInRackTomMicGain, mRideCymbalInFloorTomMicGain,mRideCymbalInRideMicGain, mRideCymbalInOverheadLeftMicGain, mRideCymbalInOverheadRightMicGain };
	std::vector<juce::RangedAudioParameter*> crashCymbal1InGains = { mCrashCymbal1InKickMicGain, mCrashCymbal1InSnareMicGain, mCrashCymbal1InHiHatMicGain, mCrashCymbal1InRackTomMicGain, mCrashCymbal1InFloorTomMicGain,mCrashCymbal1InRideMicGain, mCrashCymbal1InOverheadLeftMicGain, mCrashCymbal1InOverheadRightMicGain };
	std::vector<juce::RangedAudioParameter*> crashCymbal2InInGains = { mCrashCymbal2InInKickMicGain, mCrashCymbal2InInSnareMicGain, mCrashCymbal2InInHiHatMicGain, mCrashCymbal2InInRackTomMicGain, mCrashCymbal2InInFloorTomMicGain,mCrashCymbal2InInRideMicGain, mCrashCymbal2InInOverheadLeftMicGain, mCrashCymbal2InInOverheadRightMicGain };


	for (int sampleIndex = 0; sampleIndex < constants::samplesSize; sampleIndex++) {
		std::string sampleName = constants::samplesNames[sampleIndex];
		int midiNote = constants::samplesMidiNotes[sampleIndex];

		for (int microphoneIndex = 0; microphoneIndex < constants::microphonesSize; microphoneIndex++) {
			std::string microphoneName = constants::microphoneNames[microphoneIndex];
			std::string resourceName = sampleName + microphoneName + "mic_wav";
			std::string micGainParameterName = sampleName + "-in-" + microphoneName + "-mic-gain";
			std::string micPanningParameterName = microphoneName + "-mic-panning";
			auto voice = new DrumSamplerVoice();
			auto gainParameter = mParameterValueTreeState.getParameter(micGainParameterName);
			auto panningParameter = mParameterValueTreeState.getParameter(micPanningParameterName);

			int dataSizeInBytes;
			const char* sourceData = BinaryData::getNamedResource(resourceName.c_str(), dataSizeInBytes);
			auto memoryInputStream = std::make_unique<juce::MemoryInputStream>(sourceData, dataSizeInBytes, false);

			juce::AudioFormatReader* reader = mFormatManager.createReaderFor(std::move(memoryInputStream));
			if (reader)
			{
				juce::BigInteger range;
				range.setRange(midiNote, 1, true);
				bool isOpenHiHat = sampleIndex == 6; // 0.1, 0.1, 10.0
				double releaseTimeSecs = isOpenHiHat ? 0.1 : 10.0;

				DrumSamplerSound* sound = new DrumSamplerSound(juce::String(resourceName), *reader, range, gainParameter, panningParameter, midiNote, 0.0, releaseTimeSecs, 5.0);

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
	auto state = mParameterValueTreeState.copyState();
	std::unique_ptr<juce::XmlElement> xml(state.createXml());
	copyXmlToBinary(*xml, destData);
}

void AcresBasementKitAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
	std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

	if (xmlState.get() != nullptr)
		if (xmlState->hasTagName(mParameterValueTreeState.state.getType()))
			mParameterValueTreeState.replaceState(juce::ValueTree::fromXml(*xmlState));
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new AcresBasementKitAudioProcessor();
}
