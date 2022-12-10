#include <string>
#ifndef CONSTANTS_H
#define CONSTANTS_H

// define your own namespace to hold constants
namespace constants
{
	constexpr int bassDrumMidiNote = 36;
	constexpr int snareMidiNote = 38;
	constexpr int sideStickMidiNote = 37;
	constexpr int rackTomMidiNote = 50;
	constexpr int floorTomMidiNote = 43;
	constexpr int pedalHiHatMidiNote = 44;
	constexpr int closedHiHatMidiNote = 42;
	constexpr int openHiHatMidiNote = 46;
	constexpr int rideBellMidiNote = 53;
	constexpr int rideCymbalMidiNote = 51;
	constexpr int crashCymbal1MidiNote = 49;
	constexpr int crashCymbal2MidiNote = 57;

	static const size_t samplesSize = 12;
	static const std::string samplesNames[samplesSize] = { "acousticsnare", "bassdrum", "closedhihat", "crashcymbal1", "crashcymbal2", "floortom", "openhihat", "pedalhihat", "racktom", "ridebell", "ridecymbal", "sidestick" };
	static const int samplesMidiNotes[samplesSize] = { snareMidiNote, bassDrumMidiNote, closedHiHatMidiNote, crashCymbal1MidiNote, crashCymbal2MidiNote, floorTomMidiNote, openHiHatMidiNote, pedalHiHatMidiNote, rackTomMidiNote, rideBellMidiNote, rideCymbalMidiNote, sideStickMidiNote };

	static const size_t microphonesSize = 8;
	static const std::string microphoneNames[microphonesSize] = { "kick", "snare", "hihat", "floortom", "racktom", "ride", "ohleft" , "ohright", };

}


#endif