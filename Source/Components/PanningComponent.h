/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.3

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PanningComponent  : public juce::Component,
                          public juce::Slider::Listener
{
public:
    //==============================================================================
    PanningComponent ();
    ~PanningComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void attachKickSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID);
    void attachSnareSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID);
    void attachHiHatSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID);
    void attachRackTomSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID);
    void attachFloorTomSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID);
    void attachRideSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID);
    void attachOverheadLeftSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID);
    void attachOverheadRightSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID);

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    juce::Value mKickValue;
    juce::Value mSnareValue;
    juce::Value mHiHatValue;
    juce::Value mRackTomValue;
    juce::Value mFloorTomValue;
    juce::Value mRideValue;
    juce::Value mOverheadLeftValue;
    juce::Value mOverheadRightValue;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> juce__kickPanSlider;
    std::unique_ptr<juce::Label> juce__kickLabel;
    std::unique_ptr<juce::Slider> juce__snarePanSlider;
    std::unique_ptr<juce::Label> juce__snareLabel;
    std::unique_ptr<juce::Slider> juce__hihatPanSlider;
    std::unique_ptr<juce::Label> juce__hihatLabel;
    std::unique_ptr<juce::Slider> juce__rackTomPanSlider;
    std::unique_ptr<juce::Label> juce__rackTomLabel;
    std::unique_ptr<juce::Slider> juce__floorTomPanSlider;
    std::unique_ptr<juce::Label> juce__floorTomLabel;
    std::unique_ptr<juce::Slider> juce__ridePanSlider;
    std::unique_ptr<juce::Label> juce__rideLabel;
    std::unique_ptr<juce::Slider> juce__overheadLeftPanSlider;
    std::unique_ptr<juce::Label> juce__overheadLeftLabel;
    std::unique_ptr<juce::Slider> juce__overheadRightPanSlider;
    std::unique_ptr<juce::Label> juce__overheadRightLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PanningComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

