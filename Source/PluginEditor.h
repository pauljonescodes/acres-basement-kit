/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Components/MainComponent.h"

//==============================================================================
/**
*/
class AcresBasementKitAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
	AcresBasementKitAudioProcessorEditor(AcresBasementKitAudioProcessor&);
	~AcresBasementKitAudioProcessorEditor() override;

	//==============================================================================
	void paint(juce::Graphics&) override;
	void resized() override;
	bool isResizable() const noexcept { return true; }

	AcresBasementKitAudioProcessor& audioProcessor;
	MainComponent mMainComponent;

private:
	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AcresBasementKitAudioProcessorEditor)
};
