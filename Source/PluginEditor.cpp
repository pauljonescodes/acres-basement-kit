/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Constants.h"

//==============================================================================
AcresBasementKitAudioProcessorEditor::AcresBasementKitAudioProcessorEditor(AcresBasementKitAudioProcessor& p)
	: AudioProcessorEditor(&p), audioProcessor(p)
{
	// Make sure that before the constructor has finished, you've set the
	// editor's size to whatever you need it to be.
	addAndMakeVisible(mMainComponent);
	setSize(600, 600);
	setResizable(true, true);
	mMainComponent.getMixerComponent()->setGains(this->audioProcessor.getSampleGains()[0]);
	
	mMainComponent.getDrumComponent()->setOnDrumMidiButtonClicked([this](int midiNote) -> void {
		audioProcessor.noteOnSynthesiser(midiNote);
		});

	mMainComponent.getMixerComponent()->setOnInstrumentChanged([this](int index) -> void {
		mMainComponent.getMixerComponent()->setGains(this->audioProcessor.getSampleGains()[index]);
		});
}

AcresBasementKitAudioProcessorEditor::~AcresBasementKitAudioProcessorEditor()
{
}

//==============================================================================
void AcresBasementKitAudioProcessorEditor::paint(juce::Graphics& g)
{
	mMainComponent.setBounds(0, 0, getWidth(), getHeight());

}

void AcresBasementKitAudioProcessorEditor::resized()
{
	// This is generally where you'll want to lay out the positions of any
	// subcomponents in your editor..
}
