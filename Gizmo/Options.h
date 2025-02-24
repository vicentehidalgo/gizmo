////// Copyright 2016 by Sean Luke
////// Licensed under the Apache 2.0 License



#ifndef __OPTIONS_H__
#define __OPTIONS_H__

#include "All.h"

// last timestamp for time tempo
extern uint32_t lastTempoTapTime;



////// Options struct data type.  At present, 35 bytes.
//
// ON THE UNO    We have 78 bytes available
// ON THE MEGA   We have only 36 bytes available!  We will need to eliminate a slot.
// Alternatively we could merge a bunch of these: stuff like recorderRepeat is 1 bit
// and screenBrightness is 4 bits and channelIn is 4 bits etc.  But it'd require complex
// math and would increase the code size and right now code size is our problem.

struct _options
    {
    // 16-bit stuff first
    uint16_t tempo ;                             // in Beats Per Minute

#ifdef INCLUDE_CONTROLLER
    uint16_t leftKnobControlNumber;
    uint16_t rightKnobControlNumber; 
    uint16_t middleButtonControlNumber;
    uint16_t selectButtonControlNumber;
    uint16_t middleButtonControlOn ;                            // 0 is off, n is value n+1, and 129 is "decrement" (128)
    uint16_t middleButtonControlOff  ;                          // 0 is off, n is value n+1, and 129 is "decrement" (128)
    uint16_t selectButtonControlOn ;                            // 0 is off, n is value n+1, and 129 is "increment" (128)
    uint16_t selectButtonControlOff ;                           // 0 is off, n is value n+1, and 129 is "increment" (128)
#endif

#ifdef INCLUDE_EXTENDED_CONTROLLER
    uint16_t waveControlNumber;
    uint16_t randomControlNumber;
	uint16_t a2ControlNumber;
	uint16_t a3ControlNumber;
#endif

    // then 8-bit stuff
    uint8_t screenBrightness;
    uint8_t clock ;                     // Chosen option for handling the MIDI clock
    uint8_t noteSpeedType ;             // Type of note speed the user has chosen (see LEDDisplay.h for a list of them)
    uint8_t swing;
    uint8_t channelIn ;                          // MIDI Channel I'm listening on.  0 means no channel in.  17 means ALL CHANNELS (OMNI).
    uint8_t channelOut ;                         // MIDI Channel I'm sending to by default.    0 means no default channel out.
    uint8_t channelControl ;                     // MIDI Channel to control the device via NRPN messages etc.  0 means no control channel.  16 means Channel In

#ifdef INCLUDE_CONTROLLER
    uint8_t leftKnobControlType ;
    uint8_t rightKnobControlType  ;
    uint8_t middleButtonControlType ;
    uint8_t selectButtonControlType ;
#endif

#ifdef INCLUDE_EXTENDED_CONTROLLER
	uint8_t waveEnvelope[16];
	uint8_t envelopeMode;
	uint8_t controlModulationClocked;
    uint8_t waveControlType ;
	uint8_t randomMode;
	uint8_t randomRange;
	uint8_t randomLength;
	uint8_t randomInitialValue;
	uint8_t controlRandomClocked;
    uint8_t randomControlType ;
	uint8_t a2ControlType;
	uint8_t a3ControlType;
#endif

    uint8_t noteLength;
    
#ifdef INCLUDE_ARPEGGIATOR
    uint8_t arpeggiatorPlayOctaves;
    uint8_t arpeggiatorPlayVelocity;
    uint8_t arpeggiatorLatch;  
#endif

#ifdef INCLUDE_EXTENDED_ARPEGGIATOR
    uint8_t arpeggiatorPlayAlongChannel;
#endif

#ifdef INCLUDE_RECORDER
    //uint8_t recorderRepeat;
#endif
    uint8_t click;
    uint8_t clickVelocity;

#ifdef INCLUDE_OPTIONS_MIDI_CLOCK_DIVIDE
	uint8_t clockDivisor;
#endif

#ifdef INCLUDE_OPTIONS_MENU_DELAY
    uint8_t menuDelay;
#endif

#ifdef INCLUDE_IMMEDIATE_RETURN
    uint8_t autoReturnInterval;
#endif

#ifdef INCLUDE_OPTIONS_TRANSPOSE_AND_VOLUME
    int8_t transpose;
    uint8_t volume;
#endif

#ifdef INCLUDE_SPLIT
    uint8_t splitControls;                                          // = 0 by default, SPLIT_RIGHT
    uint8_t splitChannel;
    uint8_t splitNote;
    uint8_t splitLayerNote;
#endif

#ifdef INCLUDE_THRU
    uint8_t thruExtraNotes;
    uint8_t thruNumDistributionChannels;
    uint8_t thruChordMemory[MAX_CHORD_MEMORY_NOTES];
    uint8_t thruChordMemorySize;
    uint8_t thruDebounceMilliseconds;
//    uint8_t thruCCToNRPN;
    uint8_t thruMergeChannelIn;
    uint8_t thruBlockOtherChannels;
#endif

#ifdef INCLUDE_MEASURE
    uint8_t measureBeatsPerBar;
    uint8_t measureBarsPerPhrase;
#endif

#ifdef INCLUDE_EXTENDED_STEP_SEQUENCER
    uint8_t stepSequencerNoEcho;
    uint8_t stepSequencerSendClock;
	int8_t stepSequencerPlayAlongChannel;
#endif

#ifdef INCLUDE_EXTENDED_RECORDER
	uint8_t recorderRepeat;
#endif

#ifdef INCLUDE_GAUGE
#ifdef INCLUDE_PROVIDE_RAW_CC
	uint8_t gaugeMidiInProvideRawCC;
#endif
#endif
    };

// The options struct which is saved and loaded and used
extern struct _options options;

// Before modifying the options struct, you should back it up here.
// Then if you want to revert (cancel) the changes the user has made,
// You only need to set options = backupOptions
extern struct _options backupOptions;

// Loads the current options from flash.
void loadOptions();

// Saves the current options to flash.
void saveOptions();

// resets the current options in memory to default values(does not save them).
void resetOptions();

#endif

