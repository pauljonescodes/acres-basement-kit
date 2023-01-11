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
//[/Headers]

#include "MixerComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MixerComponent::MixerComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__kickGainSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__kickGainSlider.get());
    juce__kickGainSlider->setRange (0, 1, 0.01);
    juce__kickGainSlider->setSliderStyle (juce::Slider::LinearVertical);
    juce__kickGainSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__kickGainSlider->addListener (this);

    juce__kickGainSlider->setBounds (8, 32, 30, 453);

    juce__instrumentComboBox.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (juce__instrumentComboBox.get());
    juce__instrumentComboBox->setEditableText (false);
    juce__instrumentComboBox->setJustificationType (juce::Justification::centredLeft);
    juce__instrumentComboBox->setTextWhenNothingSelected (TRANS("select sample"));
    juce__instrumentComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    juce__instrumentComboBox->addItem (TRANS("snare"), 1);
    juce__instrumentComboBox->addItem (TRANS("kick"), 2);
    juce__instrumentComboBox->addItem (TRANS("closedHiHat"), 3);
    juce__instrumentComboBox->addItem (TRANS("crashCymbal1"), 4);
    juce__instrumentComboBox->addItem (TRANS("crashCymbal2In"), 5);
    juce__instrumentComboBox->addItem (TRANS("floorTom"), 6);
    juce__instrumentComboBox->addItem (TRANS("openHiHat"), 7);
    juce__instrumentComboBox->addItem (TRANS("pedalHiHat"), 8);
    juce__instrumentComboBox->addItem (TRANS("rackTom"), 9);
    juce__instrumentComboBox->addItem (TRANS("rideBell"), 10);
    juce__instrumentComboBox->addItem (TRANS("rideCymbal"), 11);
    juce__instrumentComboBox->addItem (TRANS("sideStick"), 12);
    juce__instrumentComboBox->addListener (this);

    juce__instrumentComboBox->setBounds (8, 8, 150, 24);

    juce__snareGainSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__snareGainSlider.get());
    juce__snareGainSlider->setRange (0, 1, 0.01);
    juce__snareGainSlider->setSliderStyle (juce::Slider::LinearVertical);
    juce__snareGainSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__snareGainSlider->addListener (this);

    juce__snareGainSlider->setBounds (64, 32, 30, 453);

    juce__hiHatGainSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__hiHatGainSlider.get());
    juce__hiHatGainSlider->setRange (0, 1, 0.01);
    juce__hiHatGainSlider->setSliderStyle (juce::Slider::LinearVertical);
    juce__hiHatGainSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__hiHatGainSlider->addListener (this);

    juce__hiHatGainSlider->setBounds (120, 32, 30, 453);

    juce__floorTomGainSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__floorTomGainSlider.get());
    juce__floorTomGainSlider->setRange (0, 1, 0.01);
    juce__floorTomGainSlider->setSliderStyle (juce::Slider::LinearVertical);
    juce__floorTomGainSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__floorTomGainSlider->addListener (this);

    juce__floorTomGainSlider->setBounds (168, 32, 30, 453);

    juce__rackTomGainSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__rackTomGainSlider.get());
    juce__rackTomGainSlider->setRange (0, 1, 0.01);
    juce__rackTomGainSlider->setSliderStyle (juce::Slider::LinearVertical);
    juce__rackTomGainSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__rackTomGainSlider->addListener (this);

    juce__rackTomGainSlider->setBounds (216, 32, 30, 453);

    juce__rideGainSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__rideGainSlider.get());
    juce__rideGainSlider->setRange (0, 1, 0.01);
    juce__rideGainSlider->setSliderStyle (juce::Slider::LinearVertical);
    juce__rideGainSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__rideGainSlider->addListener (this);

    juce__rideGainSlider->setBounds (264, 32, 30, 453);

    juce__overheadLeftGainSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__overheadLeftGainSlider.get());
    juce__overheadLeftGainSlider->setRange (0, 1, 0.01);
    juce__overheadLeftGainSlider->setSliderStyle (juce::Slider::LinearVertical);
    juce__overheadLeftGainSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__overheadLeftGainSlider->addListener (this);

    juce__overheadLeftGainSlider->setBounds (312, 32, 30, 453);

    juce__overheadRightGainSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__overheadRightGainSlider.get());
    juce__overheadRightGainSlider->setRange (0, 1, 0.01);
    juce__overheadRightGainSlider->setSliderStyle (juce::Slider::LinearVertical);
    juce__overheadRightGainSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__overheadRightGainSlider->addListener (this);

    juce__overheadRightGainSlider->setBounds (360, 32, 30, 453);

    juce__labelKick.reset (new juce::Label ("new label",
                                            TRANS("Kick")));
    addAndMakeVisible (juce__labelKick.get());
    juce__labelKick->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__labelKick->setJustificationType (juce::Justification::centredLeft);
    juce__labelKick->setEditable (false, false, false);
    juce__labelKick->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__labelKick->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__labelKick->setBounds (8, 496, 40, 24);

    juce__labelSnare.reset (new juce::Label ("new label",
                                             TRANS("Snare")));
    addAndMakeVisible (juce__labelSnare.get());
    juce__labelSnare->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__labelSnare->setJustificationType (juce::Justification::centredLeft);
    juce__labelSnare->setEditable (false, false, false);
    juce__labelSnare->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__labelSnare->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__labelSnare->setBounds (56, 496, 40, 24);

    juce__labelHiHat.reset (new juce::Label ("new label",
                                             TRANS("Hihat")));
    addAndMakeVisible (juce__labelHiHat.get());
    juce__labelHiHat->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__labelHiHat->setJustificationType (juce::Justification::centredLeft);
    juce__labelHiHat->setEditable (false, false, false);
    juce__labelHiHat->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__labelHiHat->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__labelHiHat->setBounds (112, 496, 40, 24);

    juce__labelFloorTom.reset (new juce::Label ("new label",
                                                TRANS("Floor tom")));
    addAndMakeVisible (juce__labelFloorTom.get());
    juce__labelFloorTom->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__labelFloorTom->setJustificationType (juce::Justification::centredLeft);
    juce__labelFloorTom->setEditable (false, false, false);
    juce__labelFloorTom->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__labelFloorTom->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__labelFloorTom->setBounds (168, 488, 40, 40);

    juce__labelRackTom.reset (new juce::Label ("new label",
                                               TRANS("Rack tom")));
    addAndMakeVisible (juce__labelRackTom.get());
    juce__labelRackTom->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__labelRackTom->setJustificationType (juce::Justification::centredLeft);
    juce__labelRackTom->setEditable (false, false, false);
    juce__labelRackTom->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__labelRackTom->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__labelRackTom->setBounds (216, 496, 40, 32);

    juce__labelRide.reset (new juce::Label ("new label",
                                            TRANS("Ride")));
    addAndMakeVisible (juce__labelRide.get());
    juce__labelRide->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__labelRide->setJustificationType (juce::Justification::centredLeft);
    juce__labelRide->setEditable (false, false, false);
    juce__labelRide->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__labelRide->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__labelRide->setBounds (264, 496, 40, 32);

    juce__labelOverheadLeft.reset (new juce::Label ("new label",
                                                    TRANS("OH left")));
    addAndMakeVisible (juce__labelOverheadLeft.get());
    juce__labelOverheadLeft->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__labelOverheadLeft->setJustificationType (juce::Justification::centredLeft);
    juce__labelOverheadLeft->setEditable (false, false, false);
    juce__labelOverheadLeft->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__labelOverheadLeft->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__labelOverheadLeft->setBounds (312, 496, 40, 32);

    juce__labelOverheadRight.reset (new juce::Label ("new label",
                                                     TRANS("OH right")));
    addAndMakeVisible (juce__labelOverheadRight.get());
    juce__labelOverheadRight->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__labelOverheadRight->setJustificationType (juce::Justification::centredLeft);
    juce__labelOverheadRight->setEditable (false, false, false);
    juce__labelOverheadRight->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__labelOverheadRight->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__labelOverheadRight->setBounds (360, 496, 40, 32);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

    //[/Constructor]
}

MixerComponent::~MixerComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__kickGainSlider = nullptr;
    juce__instrumentComboBox = nullptr;
    juce__snareGainSlider = nullptr;
    juce__hiHatGainSlider = nullptr;
    juce__floorTomGainSlider = nullptr;
    juce__rackTomGainSlider = nullptr;
    juce__rideGainSlider = nullptr;
    juce__overheadLeftGainSlider = nullptr;
    juce__overheadRightGainSlider = nullptr;
    juce__labelKick = nullptr;
    juce__labelSnare = nullptr;
    juce__labelHiHat = nullptr;
    juce__labelFloorTom = nullptr;
    juce__labelRackTom = nullptr;
    juce__labelRide = nullptr;
    juce__labelOverheadLeft = nullptr;
    juce__labelOverheadRight = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MixerComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MixerComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MixerComponent::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == juce__kickGainSlider.get())
    {
        //[UserSliderCode_juce__kickGainSlider] -- add your slider handling code here..
        mKickValue = juce__kickGainSlider->getValue();
        //[/UserSliderCode_juce__kickGainSlider]
    }
    else if (sliderThatWasMoved == juce__snareGainSlider.get())
    {
        //[UserSliderCode_juce__snareGainSlider] -- add your slider handling code here..
        mSnareValue = juce__snareGainSlider->getValue();
        //[/UserSliderCode_juce__snareGainSlider]
    }
    else if (sliderThatWasMoved == juce__hiHatGainSlider.get())
    {
        //[UserSliderCode_juce__hiHatGainSlider] -- add your slider handling code here..
        mHiHatValue = juce__hiHatGainSlider->getValue();
        //[/UserSliderCode_juce__hiHatGainSlider]
    }
    else if (sliderThatWasMoved == juce__floorTomGainSlider.get())
    {
        //[UserSliderCode_juce__floorTomGainSlider] -- add your slider handling code here..
        mRackTomValue = juce__floorTomGainSlider->getValue();
        //[/UserSliderCode_juce__floorTomGainSlider]
    }
    else if (sliderThatWasMoved == juce__rackTomGainSlider.get())
    {
        //[UserSliderCode_juce__rackTomGainSlider] -- add your slider handling code here..
        mFloorTomValue = juce__rackTomGainSlider->getValue();
        //[/UserSliderCode_juce__rackTomGainSlider]
    }
    else if (sliderThatWasMoved == juce__rideGainSlider.get())
    {
        //[UserSliderCode_juce__rideGainSlider] -- add your slider handling code here..
        mRideValue = juce__rideGainSlider->getValue();
        //[/UserSliderCode_juce__rideGainSlider]
    }
    else if (sliderThatWasMoved == juce__overheadLeftGainSlider.get())
    {
        //[UserSliderCode_juce__overheadLeftGainSlider] -- add your slider handling code here..
        mOverheadLeftValue = juce__overheadLeftGainSlider->getValue();
        //[/UserSliderCode_juce__overheadLeftGainSlider]
    }
    else if (sliderThatWasMoved == juce__overheadRightGainSlider.get())
    {
        //[UserSliderCode_juce__overheadRightGainSlider] -- add your slider handling code here..
        mOverheadRightValue = juce__overheadRightGainSlider->getValue();
        //[/UserSliderCode_juce__overheadRightGainSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MixerComponent::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == juce__instrumentComboBox.get())
    {
        //[UserComboBoxCode_juce__instrumentComboBox] -- add your combo box handling code here..
        if (mOnInstrumentChanged.has_value()) {
            mOnInstrumentChanged.value()(comboBoxThatHasChanged->getSelectedItemIndex());
        }
        //[/UserComboBoxCode_juce__instrumentComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MixerComponent::setOnInstrumentChanged(std::optional<std::function<void(int)>> callback) {
    mOnInstrumentChanged = callback;
}

void MixerComponent::attachKickSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID) {
    mKickValue = stateToUse.getParameterAsValue(parameterID);
    juce__kickGainSlider->setValue(mKickValue.getValue(), juce::dontSendNotification);
}
void MixerComponent::attachSnareSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID) {
    mSnareValue = stateToUse.getParameterAsValue(parameterID);
    juce__snareGainSlider->setValue(mSnareValue.getValue(), juce::dontSendNotification);
}

void MixerComponent::attachHiHatSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID) {
    mHiHatValue = stateToUse.getParameterAsValue(parameterID);
    juce__hiHatGainSlider->setValue(mHiHatValue.getValue(), juce::dontSendNotification);
}

void MixerComponent::attachRackTomSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID) {
    mRackTomValue = stateToUse.getParameterAsValue(parameterID);
    juce__floorTomGainSlider->setValue(mRackTomValue.getValue(), juce::dontSendNotification);
}

void MixerComponent::attachFloorTomSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID) {
    mFloorTomValue = stateToUse.getParameterAsValue(parameterID);
    juce__rackTomGainSlider->setValue(mFloorTomValue.getValue(), juce::dontSendNotification);
}

void MixerComponent::attachRideSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID) {
    mRideValue = stateToUse.getParameterAsValue(parameterID);
    juce__rideGainSlider->setValue(mRideValue.getValue(), juce::dontSendNotification);
}

void MixerComponent::attachOverheadLeftSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID) {
    mOverheadLeftValue = stateToUse.getParameterAsValue(parameterID);
    juce__overheadLeftGainSlider->setValue(mOverheadLeftValue.getValue(), juce::dontSendNotification);
}

void MixerComponent::attachOverheadRightSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID) {
    mOverheadRightValue = stateToUse.getParameterAsValue(parameterID);
    juce__overheadRightGainSlider->setValue(mOverheadRightValue.getValue(), juce::dontSendNotification);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MixerComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="new slider" id="177f410471e09c4c" memberName="juce__kickGainSlider"
          virtualName="" explicitFocusOrder="0" pos="8 32 30 453" min="0.0"
          max="1.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <COMBOBOX name="new combo box" id="617b4cb1f261989a" memberName="juce__instrumentComboBox"
            virtualName="" explicitFocusOrder="0" pos="8 8 150 24" editable="0"
            layout="33" items="snare&#10;kick&#10;closedHiHat&#10;crashCymbal1&#10;crashCymbal2In&#10;floorTom&#10;openHiHat&#10;pedalHiHat&#10;rackTom&#10;rideBell&#10;rideCymbal&#10;sideStick"
            textWhenNonSelected="select sample" textWhenNoItems="(no choices)"/>
  <SLIDER name="new slider" id="3d2d101604db757c" memberName="juce__snareGainSlider"
          virtualName="" explicitFocusOrder="0" pos="64 32 30 453" min="0.0"
          max="1.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="6fd26aff5632e6c4" memberName="juce__hiHatGainSlider"
          virtualName="" explicitFocusOrder="0" pos="120 32 30 453" min="0.0"
          max="1.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="1504fdd90e0cd513" memberName="juce__floorTomGainSlider"
          virtualName="" explicitFocusOrder="0" pos="168 32 30 453" min="0.0"
          max="1.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="ff452bcd3d343620" memberName="juce__rackTomGainSlider"
          virtualName="" explicitFocusOrder="0" pos="216 32 30 453" min="0.0"
          max="1.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="a35cc6c66bbf5916" memberName="juce__rideGainSlider"
          virtualName="" explicitFocusOrder="0" pos="264 32 30 453" min="0.0"
          max="1.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="7cbce8c1d02dee79" memberName="juce__overheadLeftGainSlider"
          virtualName="" explicitFocusOrder="0" pos="312 32 30 453" min="0.0"
          max="1.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="8d6f895c958862c5" memberName="juce__overheadRightGainSlider"
          virtualName="" explicitFocusOrder="0" pos="360 32 30 453" min="0.0"
          max="1.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="4397ad04fe5bd082" memberName="juce__labelKick"
         virtualName="" explicitFocusOrder="0" pos="8 496 40 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Kick" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a86edecc027b700b" memberName="juce__labelSnare"
         virtualName="" explicitFocusOrder="0" pos="56 496 40 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Snare" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="d7a35c685d37fe60" memberName="juce__labelHiHat"
         virtualName="" explicitFocusOrder="0" pos="112 496 40 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Hihat" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="4c31b524c6a4ba88" memberName="juce__labelFloorTom"
         virtualName="" explicitFocusOrder="0" pos="168 488 40 40" edTextCol="ff000000"
         edBkgCol="0" labelText="Floor tom" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="d35d358a3c444482" memberName="juce__labelRackTom"
         virtualName="" explicitFocusOrder="0" pos="216 496 40 32" edTextCol="ff000000"
         edBkgCol="0" labelText="Rack tom" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="365c68daea2be08c" memberName="juce__labelRide"
         virtualName="" explicitFocusOrder="0" pos="264 496 40 32" edTextCol="ff000000"
         edBkgCol="0" labelText="Ride" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="8e8ce80ce0c033d9" memberName="juce__labelOverheadLeft"
         virtualName="" explicitFocusOrder="0" pos="312 496 40 32" edTextCol="ff000000"
         edBkgCol="0" labelText="OH left" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="876695154b349881" memberName="juce__labelOverheadRight"
         virtualName="" explicitFocusOrder="0" pos="360 496 40 32" edTextCol="ff000000"
         edBkgCol="0" labelText="OH right" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

