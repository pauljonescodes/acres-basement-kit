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

#include "PanningComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PanningComponent::PanningComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__kickPanSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__kickPanSlider.get());
    juce__kickPanSlider->setRange (-1, 1, 0);
    juce__kickPanSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__kickPanSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    juce__kickPanSlider->addListener (this);

    juce__kickPanSlider->setBounds (16, 24, 384, 24);

    juce__kickLabel.reset (new juce::Label ("new label",
                                            TRANS("Kick\n")));
    addAndMakeVisible (juce__kickLabel.get());
    juce__kickLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__kickLabel->setJustificationType (juce::Justification::centredLeft);
    juce__kickLabel->setEditable (false, false, false);
    juce__kickLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__kickLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__kickLabel->setBounds (400, 24, 150, 24);

    juce__snarePanSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__snarePanSlider.get());
    juce__snarePanSlider->setRange (-1, 1, 0);
    juce__snarePanSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__snarePanSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    juce__snarePanSlider->addListener (this);

    juce__snarePanSlider->setBounds (16, 58, 384, 24);

    juce__snareLabel.reset (new juce::Label ("new label",
                                             TRANS("Snare")));
    addAndMakeVisible (juce__snareLabel.get());
    juce__snareLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__snareLabel->setJustificationType (juce::Justification::centredLeft);
    juce__snareLabel->setEditable (false, false, false);
    juce__snareLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__snareLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__snareLabel->setBounds (400, 58, 150, 24);

    juce__hihatPanSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__hihatPanSlider.get());
    juce__hihatPanSlider->setRange (-1, 1, 0);
    juce__hihatPanSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__hihatPanSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    juce__hihatPanSlider->addListener (this);

    juce__hihatPanSlider->setBounds (16, 88, 384, 24);

    juce__hihatLabel.reset (new juce::Label ("new label",
                                             TRANS("Hi hat")));
    addAndMakeVisible (juce__hihatLabel.get());
    juce__hihatLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__hihatLabel->setJustificationType (juce::Justification::centredLeft);
    juce__hihatLabel->setEditable (false, false, false);
    juce__hihatLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__hihatLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__hihatLabel->setBounds (400, 88, 150, 24);

    juce__rackTomPanSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__rackTomPanSlider.get());
    juce__rackTomPanSlider->setRange (-1, 1, 0);
    juce__rackTomPanSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__rackTomPanSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    juce__rackTomPanSlider->addListener (this);

    juce__rackTomPanSlider->setBounds (16, 119, 384, 24);

    juce__rackTomLabel.reset (new juce::Label ("new label",
                                               TRANS("Rack tom")));
    addAndMakeVisible (juce__rackTomLabel.get());
    juce__rackTomLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__rackTomLabel->setJustificationType (juce::Justification::centredLeft);
    juce__rackTomLabel->setEditable (false, false, false);
    juce__rackTomLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__rackTomLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__rackTomLabel->setBounds (400, 119, 150, 24);

    juce__floorTomPanSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__floorTomPanSlider.get());
    juce__floorTomPanSlider->setRange (-1, 1, 0);
    juce__floorTomPanSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__floorTomPanSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    juce__floorTomPanSlider->addListener (this);

    juce__floorTomPanSlider->setBounds (16, 150, 384, 24);

    juce__floorTomLabel.reset (new juce::Label ("new label",
                                                TRANS("Floor tom")));
    addAndMakeVisible (juce__floorTomLabel.get());
    juce__floorTomLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__floorTomLabel->setJustificationType (juce::Justification::centredLeft);
    juce__floorTomLabel->setEditable (false, false, false);
    juce__floorTomLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__floorTomLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__floorTomLabel->setBounds (400, 150, 150, 24);

    juce__ridePanSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__ridePanSlider.get());
    juce__ridePanSlider->setRange (-1, 1, 0);
    juce__ridePanSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__ridePanSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    juce__ridePanSlider->addListener (this);

    juce__ridePanSlider->setBounds (16, 182, 384, 24);

    juce__rideLabel.reset (new juce::Label ("new label",
                                            TRANS("Ride")));
    addAndMakeVisible (juce__rideLabel.get());
    juce__rideLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__rideLabel->setJustificationType (juce::Justification::centredLeft);
    juce__rideLabel->setEditable (false, false, false);
    juce__rideLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__rideLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__rideLabel->setBounds (400, 182, 150, 24);

    juce__overheadLeftPanSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__overheadLeftPanSlider.get());
    juce__overheadLeftPanSlider->setRange (-1, 1, 0);
    juce__overheadLeftPanSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__overheadLeftPanSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    juce__overheadLeftPanSlider->addListener (this);

    juce__overheadLeftPanSlider->setBounds (16, 214, 384, 24);

    juce__overheadLeftLabel.reset (new juce::Label ("new label",
                                                    TRANS("Overhead left")));
    addAndMakeVisible (juce__overheadLeftLabel.get());
    juce__overheadLeftLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__overheadLeftLabel->setJustificationType (juce::Justification::centredLeft);
    juce__overheadLeftLabel->setEditable (false, false, false);
    juce__overheadLeftLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__overheadLeftLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__overheadLeftLabel->setBounds (400, 214, 150, 24);

    juce__overheadRightPanSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__overheadRightPanSlider.get());
    juce__overheadRightPanSlider->setRange (-1, 1, 0);
    juce__overheadRightPanSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__overheadRightPanSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    juce__overheadRightPanSlider->addListener (this);

    juce__overheadRightPanSlider->setBounds (16, 247, 384, 24);

    juce__overheadRightLabel.reset (new juce::Label ("new label",
                                                     TRANS("Overhead right")));
    addAndMakeVisible (juce__overheadRightLabel.get());
    juce__overheadRightLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__overheadRightLabel->setJustificationType (juce::Justification::centredLeft);
    juce__overheadRightLabel->setEditable (false, false, false);
    juce__overheadRightLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__overheadRightLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__overheadRightLabel->setBounds (400, 244, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PanningComponent::~PanningComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__kickPanSlider = nullptr;
    juce__kickLabel = nullptr;
    juce__snarePanSlider = nullptr;
    juce__snareLabel = nullptr;
    juce__hihatPanSlider = nullptr;
    juce__hihatLabel = nullptr;
    juce__rackTomPanSlider = nullptr;
    juce__rackTomLabel = nullptr;
    juce__floorTomPanSlider = nullptr;
    juce__floorTomLabel = nullptr;
    juce__ridePanSlider = nullptr;
    juce__rideLabel = nullptr;
    juce__overheadLeftPanSlider = nullptr;
    juce__overheadLeftLabel = nullptr;
    juce__overheadRightPanSlider = nullptr;
    juce__overheadRightLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PanningComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PanningComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PanningComponent::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == juce__kickPanSlider.get())
    {
        //[UserSliderCode_juce__kickPanSlider] -- add your slider handling code here..
        mKickValue = juce__kickPanSlider->getValue();
        //[/UserSliderCode_juce__kickPanSlider]
    }
    else if (sliderThatWasMoved == juce__snarePanSlider.get())
    {
        //[UserSliderCode_juce__snarePanSlider] -- add your slider handling code here..
        mSnareValue = juce__snarePanSlider->getValue();
        //[/UserSliderCode_juce__snarePanSlider]
    }
    else if (sliderThatWasMoved == juce__hihatPanSlider.get())
    {
        //[UserSliderCode_juce__hihatPanSlider] -- add your slider handling code here..
        mHiHatValue = juce__hihatPanSlider->getValue();
        //[/UserSliderCode_juce__hihatPanSlider]
    }
    else if (sliderThatWasMoved == juce__rackTomPanSlider.get())
    {
        //[UserSliderCode_juce__rackTomPanSlider] -- add your slider handling code here..
        mRackTomValue = juce__rackTomPanSlider->getValue();
        //[/UserSliderCode_juce__rackTomPanSlider]
    }
    else if (sliderThatWasMoved == juce__floorTomPanSlider.get())
    {
        //[UserSliderCode_juce__floorTomPanSlider] -- add your slider handling code here..
        mFloorTomValue = juce__floorTomPanSlider->getValue();
        //[/UserSliderCode_juce__floorTomPanSlider]
    }
    else if (sliderThatWasMoved == juce__ridePanSlider.get())
    {
        //[UserSliderCode_juce__ridePanSlider] -- add your slider handling code here..
        mRideValue = juce__ridePanSlider->getValue();
        //[/UserSliderCode_juce__ridePanSlider]
    }
    else if (sliderThatWasMoved == juce__overheadLeftPanSlider.get())
    {
        //[UserSliderCode_juce__overheadLeftPanSlider] -- add your slider handling code here..
        mOverheadLeftValue = juce__overheadLeftPanSlider->getValue();
        //[/UserSliderCode_juce__overheadLeftPanSlider]
    }
    else if (sliderThatWasMoved == juce__overheadRightPanSlider.get())
    {
        //[UserSliderCode_juce__overheadRightPanSlider] -- add your slider handling code here..
        mOverheadRightValue = juce__overheadRightPanSlider->getValue();
        //[/UserSliderCode_juce__overheadRightPanSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void PanningComponent::attachKickSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID) {
    mKickValue = stateToUse.getParameterAsValue(parameterID);
    juce__kickPanSlider->setValue(mKickValue.getValue(), juce::dontSendNotification);
}
void PanningComponent::attachSnareSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID) {
    mSnareValue = stateToUse.getParameterAsValue(parameterID);
    juce__snarePanSlider->setValue(mSnareValue.getValue(), juce::dontSendNotification);
}

void PanningComponent::attachHiHatSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID) {
    mHiHatValue = stateToUse.getParameterAsValue(parameterID);
    juce__hihatPanSlider->setValue(mHiHatValue.getValue(), juce::dontSendNotification);
}

void PanningComponent::attachRackTomSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID) {
    mRackTomValue = stateToUse.getParameterAsValue(parameterID);
    juce__floorTomPanSlider->setValue(mRackTomValue.getValue(), juce::dontSendNotification);
}

void PanningComponent::attachFloorTomSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID) {
    mFloorTomValue = stateToUse.getParameterAsValue(parameterID);
    juce__rackTomPanSlider->setValue(mFloorTomValue.getValue(), juce::dontSendNotification);
}

void PanningComponent::attachRideSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID) {
    mRideValue = stateToUse.getParameterAsValue(parameterID);
    juce__ridePanSlider->setValue(mRideValue.getValue(), juce::dontSendNotification);
}

void PanningComponent::attachOverheadLeftSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID) {
    mOverheadLeftValue = stateToUse.getParameterAsValue(parameterID);
    juce__overheadLeftPanSlider->setValue(mOverheadLeftValue.getValue(), juce::dontSendNotification);
}

void PanningComponent::attachOverheadRightSlider(juce::AudioProcessorValueTreeState& stateToUse, const juce::String& parameterID) {
    mOverheadRightValue = stateToUse.getParameterAsValue(parameterID);
    juce__overheadRightPanSlider->setValue(mOverheadRightValue.getValue(), juce::dontSendNotification);
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PanningComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="new slider" id="a67911ebe7ffc8d1" memberName="juce__kickPanSlider"
          virtualName="" explicitFocusOrder="0" pos="16 24 384 24" min="-1.0"
          max="1.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="52710c0f6cf9b0e4" memberName="juce__kickLabel"
         virtualName="" explicitFocusOrder="0" pos="400 24 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Kick&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="7f47515ac908e4f2" memberName="juce__snarePanSlider"
          virtualName="" explicitFocusOrder="0" pos="16 58 384 24" min="-1.0"
          max="1.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="b019975bea4c4420" memberName="juce__snareLabel"
         virtualName="" explicitFocusOrder="0" pos="400 58 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Snare" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="8ed540576e1c6da0" memberName="juce__hihatPanSlider"
          virtualName="" explicitFocusOrder="0" pos="16 88 384 24" min="-1.0"
          max="1.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="c734b68cef23d684" memberName="juce__hihatLabel"
         virtualName="" explicitFocusOrder="0" pos="400 88 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Hi hat" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="a05f07ba44c78156" memberName="juce__rackTomPanSlider"
          virtualName="" explicitFocusOrder="0" pos="16 119 384 24" min="-1.0"
          max="1.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="2927e72ca165cfaf" memberName="juce__rackTomLabel"
         virtualName="" explicitFocusOrder="0" pos="400 119 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Rack tom" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="2516735dd3feb7b7" memberName="juce__floorTomPanSlider"
          virtualName="" explicitFocusOrder="0" pos="16 150 384 24" min="-1.0"
          max="1.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="e04373946ca0899b" memberName="juce__floorTomLabel"
         virtualName="" explicitFocusOrder="0" pos="400 150 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Floor tom" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="19bdec17365ad000" memberName="juce__ridePanSlider"
          virtualName="" explicitFocusOrder="0" pos="16 182 384 24" min="-1.0"
          max="1.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="a66138a14a4410f9" memberName="juce__rideLabel"
         virtualName="" explicitFocusOrder="0" pos="400 182 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Ride" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="6c30111321cd2edd" memberName="juce__overheadLeftPanSlider"
          virtualName="" explicitFocusOrder="0" pos="16 214 384 24" min="-1.0"
          max="1.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="68c44799c3885b20" memberName="juce__overheadLeftLabel"
         virtualName="" explicitFocusOrder="0" pos="400 214 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Overhead left" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="b237d39651b9871" memberName="juce__overheadRightPanSlider"
          virtualName="" explicitFocusOrder="0" pos="16 247 384 24" min="-1.0"
          max="1.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="fe3ec812cac46f80" memberName="juce__overheadRightLabel"
         virtualName="" explicitFocusOrder="0" pos="400 244 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Overhead right" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

