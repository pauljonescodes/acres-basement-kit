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
	
	//mMainComponent.getMixerComponent()->setGains(this->audioProcessor.getSampleGains()[0]);
	
	mMainComponent.getDrumComponent()->setOnDrumMidiButtonClicked([this](int midiNote) -> void {
		audioProcessor.noteOnSynthesiser(midiNote);
		});

	mMainComponent.getMixerComponent()->setOnInstrumentChanged([this](int index) -> void {
		std::string parameterName = constants::samplesNames[index] + "-in-" + constants::microphoneNames[0] + "-mic-gain";
		this->mMainComponent.getMixerComponent()->attachKickSlider(this->audioProcessor.mParameterValueTreeState, parameterName);

		parameterName = constants::samplesNames[index] + "-in-" + constants::microphoneNames[1] + "-mic-gain";
		this->mMainComponent.getMixerComponent()->attachSnareSlider(this->audioProcessor.mParameterValueTreeState, parameterName);

		parameterName = constants::samplesNames[index] + "-in-" + constants::microphoneNames[2] + "-mic-gain";
		this->mMainComponent.getMixerComponent()->attachHiHatSlider(this->audioProcessor.mParameterValueTreeState, parameterName);

		parameterName = constants::samplesNames[index] + "-in-" + constants::microphoneNames[3] + "-mic-gain";
		this->mMainComponent.getMixerComponent()->attachFloorTomSlider(this->audioProcessor.mParameterValueTreeState, parameterName);

		parameterName = constants::samplesNames[index] + "-in-" + constants::microphoneNames[4] + "-mic-gain";
		this->mMainComponent.getMixerComponent()->attachRackTomSlider(this->audioProcessor.mParameterValueTreeState, parameterName);

		parameterName = constants::samplesNames[index] + "-in-" + constants::microphoneNames[5] + "-mic-gain";
		this->mMainComponent.getMixerComponent()->attachRideSlider(this->audioProcessor.mParameterValueTreeState, parameterName);

		parameterName = constants::samplesNames[index] + "-in-" + constants::microphoneNames[6] + "-mic-gain";
		this->mMainComponent.getMixerComponent()->attachOverheadLeftSlider(this->audioProcessor.mParameterValueTreeState, parameterName);

		parameterName = constants::samplesNames[index] + "-in-" + constants::microphoneNames[7] + "-mic-gain";
		this->mMainComponent.getMixerComponent()->attachOverheadRightSlider(this->audioProcessor.mParameterValueTreeState, parameterName);
		});

	this->mMainComponent.getPanningComponent()->attachKickSlider(this->audioProcessor.mParameterValueTreeState, constants::microphoneNames[0] + "-mic-panning");
	this->mMainComponent.getPanningComponent()->attachSnareSlider(this->audioProcessor.mParameterValueTreeState, constants::microphoneNames[1] + "-mic-panning");
	this->mMainComponent.getPanningComponent()->attachHiHatSlider(this->audioProcessor.mParameterValueTreeState, constants::microphoneNames[2] + "-mic-panning");
	this->mMainComponent.getPanningComponent()->attachFloorTomSlider(this->audioProcessor.mParameterValueTreeState, constants::microphoneNames[3] + "-mic-panning");
	this->mMainComponent.getPanningComponent()->attachRackTomSlider(this->audioProcessor.mParameterValueTreeState, constants::microphoneNames[4] + "-mic-panning");
	this->mMainComponent.getPanningComponent()->attachRideSlider(this->audioProcessor.mParameterValueTreeState, constants::microphoneNames[5] + "-mic-panning");
	this->mMainComponent.getPanningComponent()->attachOverheadLeftSlider(this->audioProcessor.mParameterValueTreeState, constants::microphoneNames[6] + "-mic-panning");
	this->mMainComponent.getPanningComponent()->attachOverheadRightSlider(this->audioProcessor.mParameterValueTreeState, constants::microphoneNames[7] + "-mic-panning");
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
