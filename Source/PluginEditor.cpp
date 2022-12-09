/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Constants.h"

//==============================================================================
AcresBasementKitAudioProcessorEditor::AcresBasementKitAudioProcessorEditor (AcresBasementKitAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible(drumComponent);
    setSize (480, 320);

    drumComponent.setOnDrumMidiButtonClicked([this](int midiNote) -> void {
        audioProcessor.noteOnSynthesiser(midiNote);
    });
}

AcresBasementKitAudioProcessorEditor::~AcresBasementKitAudioProcessorEditor()
{
}

//==============================================================================
void AcresBasementKitAudioProcessorEditor::paint (juce::Graphics& g)
{
    drumComponent.setBounds(0, 0, getWidth(), getHeight());

}

void AcresBasementKitAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
