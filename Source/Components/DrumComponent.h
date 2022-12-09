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
class DrumComponent  : public juce::Component,
                       public juce::Button::Listener
{
public:
    //==============================================================================
    DrumComponent ();
    ~DrumComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setOnDrumMidiButtonClicked(std::optional<std::function<void(int)>> callback);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    std::optional<std::function<void(int)>> mOnDrumMidiButtonClicked;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextButton> juce__kickButton;
    std::unique_ptr<juce::TextButton> juce__snareButton;
    std::unique_ptr<juce::TextButton> juce__rackTomButton;
    std::unique_ptr<juce::TextButton> juce__floorTomButton;
    std::unique_ptr<juce::TextButton> juce__rideBellButton;
    std::unique_ptr<juce::TextButton> juce__rideCymbalButton;
    std::unique_ptr<juce::TextButton> juce__sideStickButton;
    std::unique_ptr<juce::TextButton> juce__crash1Button;
    std::unique_ptr<juce::TextButton> juce__crash2Button;
    std::unique_ptr<juce::TextButton> juce__hiHatPedalButton;
    std::unique_ptr<juce::TextButton> juce__hiHatClosedButton;
    std::unique_ptr<juce::TextButton> juce__hiHatOpenButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DrumComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

