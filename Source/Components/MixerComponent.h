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
class MixerComponent  : public juce::Component,
                        public juce::Slider::Listener,
                        public juce::ComboBox::Listener
{
public:
    //==============================================================================
    MixerComponent ();
    ~MixerComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setOnInstrumentChanged(std::optional<std::function<void(int)>> callback);
    void setGains(std::vector<std::atomic<float>*> gains);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::vector<std::atomic<float>*> mGains;
    std::optional<std::function<void(int)>> mOnInstrumentChanged;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> juce__kickGainSlider;
    std::unique_ptr<juce::ComboBox> juce__instrumentComboBox;
    std::unique_ptr<juce::Slider> juce__snareGainSlider;
    std::unique_ptr<juce::Slider> juce__hiHatGainSlider;
    std::unique_ptr<juce::Slider> juce__floorTomGainSlider;
    std::unique_ptr<juce::Slider> juce__rackTomGainSlider;
    std::unique_ptr<juce::Slider> juce__rideGainSlider;
    std::unique_ptr<juce::Slider> juce__overheadLeftGainSlider;
    std::unique_ptr<juce::Slider> juce__overheadRightGainSlider;
    std::unique_ptr<juce::Label> juce__labelKick;
    std::unique_ptr<juce::Label> juce__labelSnare;
    std::unique_ptr<juce::Label> juce__labelHiHat;
    std::unique_ptr<juce::Label> juce__labelFloorTom;
    std::unique_ptr<juce::Label> juce__labelRackTom;
    std::unique_ptr<juce::Label> juce__labelRide;
    std::unique_ptr<juce::Label> juce__labelOverheadLeft;
    std::unique_ptr<juce::Label> juce__labelOverheadRight;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixerComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

