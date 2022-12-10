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

//[Headers] You can add your own extra header files here...
#include "../Constants.h"
//[/Headers]

#include "DrumComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
DrumComponent::DrumComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__kickButton.reset (new juce::TextButton ("kick_button"));
    addAndMakeVisible (juce__kickButton.get());
    juce__kickButton->setButtonText (TRANS("Kick C1"));
    juce__kickButton->addListener (this);

    juce__snareButton.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (juce__snareButton.get());
    juce__snareButton->setButtonText (TRANS("Snare D1"));
    juce__snareButton->addListener (this);

    juce__snareButton->setBounds (8, 128, 152, 72);

    juce__rackTomButton.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (juce__rackTomButton.get());
    juce__rackTomButton->setButtonText (TRANS("Rack tom D2"));
    juce__rackTomButton->addListener (this);

    juce__rackTomButton->setBounds (168, 72, 104, 48);

    juce__floorTomButton.reset (new juce::TextButton ("floorTomButton"));
    addAndMakeVisible (juce__floorTomButton.get());
    juce__floorTomButton->setButtonText (TRANS("Floor tom G1"));
    juce__floorTomButton->addListener (this);

    juce__floorTomButton->setBounds (328, 128, 100, 152);

    juce__rideBellButton.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (juce__rideBellButton.get());
    juce__rideBellButton->setButtonText (TRANS("Ride bell F2"));
    juce__rideBellButton->addListener (this);

    juce__rideBellButton->setBounds (280, 48, 144, 32);

    juce__rideCymbalButton.reset (new juce::TextButton ("rideCymbalButton"));
    addAndMakeVisible (juce__rideCymbalButton.get());
    juce__rideCymbalButton->setButtonText (TRANS("Ride cymbal Eb2"));
    juce__rideCymbalButton->addListener (this);

    juce__rideCymbalButton->setBounds (280, 88, 144, 32);

    juce__sideStickButton.reset (new juce::TextButton ("snareSideStickButton"));
    addAndMakeVisible (juce__sideStickButton.get());
    juce__sideStickButton->setButtonText (TRANS("Side stick C#1"));
    juce__sideStickButton->addListener (this);

    juce__sideStickButton->setBounds (8, 208, 152, 32);

    juce__crash1Button.reset (new juce::TextButton ("crash1Button"));
    addAndMakeVisible (juce__crash1Button.get());
    juce__crash1Button->setButtonText (TRANS("Crash-1 C#2"));
    juce__crash1Button->addListener (this);

    juce__crash1Button->setBounds (8, 8, 150, 32);

    juce__crash2Button.reset (new juce::TextButton ("crash2Button"));
    addAndMakeVisible (juce__crash2Button.get());
    juce__crash2Button->setButtonText (TRANS("Crash-2 A2"));
    juce__crash2Button->addListener (this);

    juce__crash2Button->setBounds (280, 8, 142, 32);

    juce__hiHatPedalButton.reset (new juce::TextButton ("Hi-hat pedal"));
    addAndMakeVisible (juce__hiHatPedalButton.get());
    juce__hiHatPedalButton->setButtonText (TRANS("Hi-hat pedal Ab1"));
    juce__hiHatPedalButton->addListener (this);

    juce__hiHatPedalButton->setBounds (8, 248, 152, 32);

    juce__hiHatClosedButton.reset (new juce::TextButton ("Hi-hat closed"));
    addAndMakeVisible (juce__hiHatClosedButton.get());
    juce__hiHatClosedButton->setButtonText (TRANS("Hi-hat closed F#1"));
    juce__hiHatClosedButton->addListener (this);

    juce__hiHatClosedButton->setBounds (8, 88, 152, 32);

    juce__hiHatOpenButton.reset (new juce::TextButton ("Hi-hat open"));
    addAndMakeVisible (juce__hiHatOpenButton.get());
    juce__hiHatOpenButton->setButtonText (TRANS("Hi-hat open Bb1"));
    juce__hiHatOpenButton->addListener (this);

    juce__hiHatOpenButton->setBounds (8, 48, 152, 32);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 300);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

DrumComponent::~DrumComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__kickButton = nullptr;
    juce__snareButton = nullptr;
    juce__rackTomButton = nullptr;
    juce__floorTomButton = nullptr;
    juce__rideBellButton = nullptr;
    juce__rideCymbalButton = nullptr;
    juce__sideStickButton = nullptr;
    juce__crash1Button = nullptr;
    juce__crash2Button = nullptr;
    juce__hiHatPedalButton = nullptr;
    juce__hiHatClosedButton = nullptr;
    juce__hiHatOpenButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void DrumComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void DrumComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    juce__kickButton->setBounds (244 - (152 / 2), 204 - (152 / 2), 152, 152);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void DrumComponent::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == juce__kickButton.get())
    {
        //[UserButtonCode_juce__kickButton] -- add your button handler code here..
        if (mOnDrumMidiButtonClicked.has_value()) {
            mOnDrumMidiButtonClicked.value()(constants::bassDrumMidiNote);
        }
        //[/UserButtonCode_juce__kickButton]
    }
    else if (buttonThatWasClicked == juce__snareButton.get())
    {
        //[UserButtonCode_juce__snareButton] -- add your button handler code here..
        if (mOnDrumMidiButtonClicked.has_value()) {
            mOnDrumMidiButtonClicked.value()(constants::snareMidiNote);
        }
        //[/UserButtonCode_juce__snareButton]
    }
    else if (buttonThatWasClicked == juce__rackTomButton.get())
    {
        //[UserButtonCode_juce__rackTomButton] -- add your button handler code here..
        if (mOnDrumMidiButtonClicked.has_value()) {
            mOnDrumMidiButtonClicked.value()(constants::rackTomMidiNote);
        }
        //[/UserButtonCode_juce__rackTomButton]
    }
    else if (buttonThatWasClicked == juce__floorTomButton.get())
    {
        //[UserButtonCode_juce__floorTomButton] -- add your button handler code here..
        if (mOnDrumMidiButtonClicked.has_value()) {
            mOnDrumMidiButtonClicked.value()(constants::floorTomMidiNote);
        }
        //[/UserButtonCode_juce__floorTomButton]
    }
    else if (buttonThatWasClicked == juce__rideBellButton.get())
    {
        //[UserButtonCode_juce__rideBellButton] -- add your button handler code here..
        if (mOnDrumMidiButtonClicked.has_value()) {
            mOnDrumMidiButtonClicked.value()(constants::rideBellMidiNote);
        }
        //[/UserButtonCode_juce__rideBellButton]
    }
    else if (buttonThatWasClicked == juce__rideCymbalButton.get())
    {
        //[UserButtonCode_juce__rideCymbalButton] -- add your button handler code here..
        if (mOnDrumMidiButtonClicked.has_value()) {
            mOnDrumMidiButtonClicked.value()(constants::rideCymbalMidiNote);
        }
        //[/UserButtonCode_juce__rideCymbalButton]
    }
    else if (buttonThatWasClicked == juce__sideStickButton.get())
    {
        //[UserButtonCode_juce__sideStickButton] -- add your button handler code here..
        if (mOnDrumMidiButtonClicked.has_value()) {
            mOnDrumMidiButtonClicked.value()(constants::sideStickMidiNote);
        }
        //[/UserButtonCode_juce__sideStickButton]
    }
    else if (buttonThatWasClicked == juce__crash1Button.get())
    {
        //[UserButtonCode_juce__crash1Button] -- add your button handler code here..
        if (mOnDrumMidiButtonClicked.has_value()) {
            mOnDrumMidiButtonClicked.value()(constants::crashCymbal1MidiNote);
        }
        //[/UserButtonCode_juce__crash1Button]
    }
    else if (buttonThatWasClicked == juce__crash2Button.get())
    {
        //[UserButtonCode_juce__crash2Button] -- add your button handler code here..
        if (mOnDrumMidiButtonClicked.has_value()) {
            mOnDrumMidiButtonClicked.value()(constants::crashCymbal2MidiNote);
        }
        //[/UserButtonCode_juce__crash2Button]
    }
    else if (buttonThatWasClicked == juce__hiHatPedalButton.get())
    {
        //[UserButtonCode_juce__hiHatPedalButton] -- add your button handler code here..
        if (mOnDrumMidiButtonClicked.has_value()) {
            mOnDrumMidiButtonClicked.value()(constants::pedalHiHatMidiNote);
        }
        //[/UserButtonCode_juce__hiHatPedalButton]
    }
    else if (buttonThatWasClicked == juce__hiHatClosedButton.get())
    {
        //[UserButtonCode_juce__hiHatClosedButton] -- add your button handler code here..
        if (mOnDrumMidiButtonClicked.has_value()) {
            mOnDrumMidiButtonClicked.value()(constants::closedHiHatMidiNote);
        }
        //[/UserButtonCode_juce__hiHatClosedButton]
    }
    else if (buttonThatWasClicked == juce__hiHatOpenButton.get())
    {
        //[UserButtonCode_juce__hiHatOpenButton] -- add your button handler code here..
        if (mOnDrumMidiButtonClicked.has_value()) {
            mOnDrumMidiButtonClicked.value()(constants::openHiHatMidiNote);
        }
        //[/UserButtonCode_juce__hiHatOpenButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void DrumComponent::setOnDrumMidiButtonClicked(std::optional<std::function<void(int)>> callback) {
    mOnDrumMidiButtonClicked = callback;
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DrumComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="300">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTBUTTON name="kick_button" id="7509bc91ce1408dd" memberName="juce__kickButton"
              virtualName="" explicitFocusOrder="0" pos="244c 204c 152 152"
              buttonText="Kick C1" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="e11024f0728789f0" memberName="juce__snareButton"
              virtualName="" explicitFocusOrder="0" pos="8 128 152 72" buttonText="Snare D1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="fe96731aa1f650b3" memberName="juce__rackTomButton"
              virtualName="" explicitFocusOrder="0" pos="168 72 104 48" buttonText="Rack tom D2"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="floorTomButton" id="4cb4a1aed8d93f23" memberName="juce__floorTomButton"
              virtualName="" explicitFocusOrder="0" pos="328 128 100 152" buttonText="Floor tom G1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="c7e23455c583f701" memberName="juce__rideBellButton"
              virtualName="" explicitFocusOrder="0" pos="280 48 144 32" buttonText="Ride bell F2"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="rideCymbalButton" id="6167a03f041bdfb4" memberName="juce__rideCymbalButton"
              virtualName="" explicitFocusOrder="0" pos="280 88 144 32" buttonText="Ride cymbal Eb2"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="snareSideStickButton" id="87297e327e043866" memberName="juce__sideStickButton"
              virtualName="" explicitFocusOrder="0" pos="8 208 152 32" buttonText="Side stick C#1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="crash1Button" id="f9b7a2e66396ebc3" memberName="juce__crash1Button"
              virtualName="" explicitFocusOrder="0" pos="8 8 150 32" buttonText="Crash-1 C#2"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="crash2Button" id="f4ae963d6408edd8" memberName="juce__crash2Button"
              virtualName="" explicitFocusOrder="0" pos="280 8 142 32" buttonText="Crash-2 A2"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Hi-hat pedal" id="46597dbc4d5d6b1e" memberName="juce__hiHatPedalButton"
              virtualName="" explicitFocusOrder="0" pos="8 248 152 32" buttonText="Hi-hat pedal Ab1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Hi-hat closed" id="b50f7a3777a87428" memberName="juce__hiHatClosedButton"
              virtualName="" explicitFocusOrder="0" pos="8 88 152 32" buttonText="Hi-hat closed F#1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Hi-hat open" id="be645c42f11819f5" memberName="juce__hiHatOpenButton"
              virtualName="" explicitFocusOrder="0" pos="8 48 152 32" buttonText="Hi-hat open Bb1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

