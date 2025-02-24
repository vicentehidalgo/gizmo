////// Copyright 2016 by Sean Luke
////// Licensed under the Apache 2.0 License




////// ALL.H
//////
////// This is just distributing #include file.  Everyone #includes All.h

// This little dance allows me to test for Uno code while on a Mega, in case I don't
// have an Uno around, simply by by commenting out the #define __MEGA__ line
#if defined (__AVR_ATmega2560__)
#define __MEGA__
#endif

#if defined (__AVR_ATmega328P__)
#define __UNO__
#endif


// You'll see GLOBAL here and there.  It means nothing -- but it makes it easy
// for me to grep for global variables.
#define GLOBAL

// If this is set, then gizmo will start up in bypass mode initially, AND
// every time you leave the toplevel menu and enter an application, gizmo
// will always exit bypass mode even if you had manually set it.
//
// If this is UNSET, then gizmo will not start up in bypass mode initially,
// and will not toy with bypass mode at all in the toplevel -- it stays as you set it.
#define TOPLEVEL_BYPASS


// If you don't want to use the SparkFun MIDI Shield, and perhaps use some other
// compatible MIDI shield without the buttons and pots, you can turn on these defines.
// Don't turn BOTH of them on at the same time!
//
// IF you turn on this define and then run the code on the Arduino, it will reset the options,
// display the splash screen, then display RSET and nothing else.  This makes it possible to do
// a reset without holding the three buttons down (because you have no buttons!) 
//#define HEADLESS_RESET
//
// If you turn on this define, Gizmo will eliminate the option of OFF for its MIDI Control so you
// can't possibly lock yourself out by accident.  You can then control Gizmo entirely via NRPN
// without ever touching the knobs or buttons (which you might not have).
//#define HEADLESS



/////// SETTABLE APPLICATIONS AND FEATURES
///
/// The following applications, options, and additional features can be turned on or off depending
/// on your space needs.  However in order to modify the applications and options you will ALSO need
/// to modify certain menu arrays so they match properly.


// -- APPLICATIONS --
// Note that if you include or exclude certain of these you must also take care to set up the menuItems array
// correctly in STATE_ROOT (see roughly lines 1023--1029 of TopLevel.cpp)
// 
// INCLUDE_ARPEGGIATOR				Include the "basic" Arpeggiator application (the one which appears in the Uno)
// INCLUDE_EXTENDED_ARPEGGIATOR		Include the "full" Arpeggiator application (the one which appears in the Mega)
// INCLUDE_STEP_SEQUENCER			Include the "basic" Step Sequencer application (the one which appears in the Uno)
// INCLUDE_EXTENDED_STEP_SEQUENCER	Include the "full" Step Sequencer application (the one which appears in the Mega)
// INCLUDE_RECORDER					Include the "basic" note recorder application (the one which appears in the Uno)
// INCLUDE_EXTENDED_RECORDER		Include the "full" note recorder application (the one which appears in the Mega)
// INCLUDE_GAUGE					Include the "basic" MIDI Gauge application
// INCLUDE_EXTENDED_GAUGE			Include the "full" MIDI Gauge application, with the Raw CC option
// INCLUDE_CONTROLLER				Include the "basic" Controller application (the one which appears in the Uno)
// INCLUDE_EXTENDED_CONTROLLER		Include the "full" Controller application (the one which appears in the Mega)
// INCLUDE_SPLIT					Include the Keyboard Split application
// INCLUDE_THRU						Include the Thru application
// INCLUDE_MEASURE					Include the Measure Counter application


// -- ADDITIONAL OPTIONS MENU CHOICES --
// Note that if you include or exclude certain of these you must also take care to set up the menuItems array
// correctly in STATE_OPTIONS (see roughly lines 1349--1366 of TopLevel.cpp)
//
// INCLUDE_OPTIONS_TRANSPOSE_AND_VOLUME		Include transpose and volume on MIDI Out
// INCLUDE_OPTIONS_MIDI_CLOCK_DIVIDE		Include clock division
// INCLUDE_OPTIONS_MENU_DELAY				Include the menu delay option


// -- ADDITIONAL FEATURES --
// NOTE that INCLUDE_THRU automatically turns on INCLUDE_ENTER_CHORD
// NOTE that INCLUDE_THRU, INCLUDE_SPLIT, and INCLUDE_ENTER_CHORD automatically turn on INCLUDE_EXTENDED_GLYPH_TABLE
// NOTE that INCLUDE_WAVES automatically turns on INCLUDE_EXTENDED_FONT
// NOTE that INCLUDE_EXTENDED_GAUGE automatically turns on INCLUDE_PROVIDE_RAW_CC
//
// You can turn these on manually yourself
// INCLUDE_MIDDLE_BUTTON_INCREMENTS_MENU	When in menus, does the middle button increment through them?
// INCLUDE_CLOCK_IN_OPTIONS					When in the options menu, can I manipulate the clock via buttons?
// INCLUDE_CC_CONTROL						Can you control Gizmo via CC in addition to NRPN?
// INCLUDE_TOPLEVEL_BYPASS					Can the user specify how bypass is handled in the top-level menus as an option?
//
// These are turned on as a consequence of other features -- they're probably not useful to turn on yourself.
// INCLUDE_ENTER_CHORD						Should the stateEnterChord() function (Utility.h) be made available?
// INCLUDE_PROVIDE_RAW_CC					When an application such as Gauge, can you optionally gauge raw CC rather than cooked (for NRPN etc.)?
// INCLUDE_EXTENDED_GLYPH_TABLE				Should the extended glyph table be made available? 
// INCLUDE_EXTENDED_FONT					Should the extended font be made available?
// INCLUDE_SEND_NULL_RPN					Should we terminate NRPN/RPN messages with two additional CCs?  Better but slower.

// -- EXPERIMENTAL JUNK --
// INCLUDE_CONTROL_BY_NOTE					[In development] Should we allow control of Gizmo by playing notes on the Control channel?
// INCLUDE_WAVES							[In development] Should we include LFO waves?  Don't turn this on yet.
// INCLUDE_STEP_SEQUENCER_CC_MUTE_TOGGLES	[In development] Should we toggle mutes in the step sequencer?


// -- OPTIONS --
// USE_ALL_NOTES_OFF						These define how Gizmo kills all sounds.  The Blofeld's Arpeggiated sounds do not respond properly 
// USE_ALL_SOUNDS_OFF						to All Notes Off.  But other hardware, such as the Kawai K4, doesn't properly respond to ALL Sounds 
//											Off.  :-(  You can set one, or both, of these.

#define USE_ALL_SOUNDS_OFF					// see Mega below, it uses both


/// Here are the standard values for the MEGA and for the UNO

#if defined(__MEGA__)
#define INCLUDE_EXTENDED_ARPEGGIATOR
#define INCLUDE_EXTENDED_STEP_SEQUENCER
#define INCLUDE_EXTENDED_RECORDER
#define INCLUDE_EXTENDED_GAUGE
#define INCLUDE_EXTENDED_CONTROLLER
#define INCLUDE_SPLIT
#define INCLUDE_THRU
#define INCLUDE_SYNTH
#define INCLUDE_MEASURE
#define INCLUDE_OPTIONS_TRANSPOSE_AND_VOLUME
#define INCLUDE_OPTIONS_MIDI_CLOCK_DIVIDE
#define INCLUDE_OPTIONS_MENU_DELAY
#define INCLUDE_MIDDLE_BUTTON_INCREMENTS_MENU
#define INCLUDE_CLOCK_CONTINUE_IN_OPTIONS
#define INCLUDE_PROVIDE_RAW_CC
#define INCLUDE_CC_CONTROL
#define INCLUDE_CLOCK_IN_OPTIONS
#define INCLUDE_BUFFERED_CURSOR_X_POS

//// NOTE: To include the Sysex dump facility, you not only uncomment the INCLUDE_SYSEX line below, but
//// you ALSO must go into the "midi_Settings.h" file in the Forty Seven Effects MIDI library and change the line 
////    static const unsigned SysExMaxSize = 1;		// this should never be 0 due to a library bug
//// to
////	static const unsigned SysExMaxSize = 787;   // the size of the MIDI Dump of a Slot

//#define INCLUDE_SYSEX


#endif






#if defined(__UNO__)

// This is a useful set
#define INCLUDE_ARPEGGIATOR
#define INCLUDE_STEP_SEQUENCER
#define INCLUDE_RECORDER
#define INCLUDE_CONTROLLER


// You can include these but one or more other items will have to be jettisoned as a result.
// IMPORTANT NOTE: If you include another application or a different one will also have to modify 
// The menu array on around Line 616 of TopLevel.cpp, where it states which applications are available.
// You need to make sure that the array length stays correct (for example, it says menuItems[5],
// and if you remove an app, it needs to say menuItems[4]).  Similarly, the second argument in doMenuDisplay(...)
// (currently a 5) would need to change to a 4.
//
// Whatever applications you install need to be ordered in this order in that menu:
// Arpeggiator, Step Sequencer, Recorder, Gauge, Controller, Split, Thru, Synth, Measure, Sysex, [Options]

// --- Additional applications
// #define INCLUDE_GAUGE
// #define INCLUDE_SPLIT
// #define INCLUDE_THRU
// #define INCLUDE_SYNTH
// #define INCLUDE_MEASURE

// -- Extended versions of applications
// #define INCLUDE_EXTENDED_ARPEGGIATOR
// #define INCLUDE_EXTENDED_STEP_SEQUENCER
// #define INCLUDE_EXTENDED_RECORDER
// #define INCLUDE_EXTENDED_GAUGE
// #define INCLUDE_EXTENDED_CONTROLLER

// -- Additional Options features
// #define INCLUDE_OPTIONS_TRANSPOSE_AND_VOLUME
// #define INCLUDE_OPTIONS_MIDI_CLOCK_DIVIDE
// #define INCLUDE_OPTIONS_MENU_DELAY

// -- Additional Global features
// #define INCLUDE_MIDDLE_BUTTON_INCREMENTS_MENU
// #define INCLUDE_CLOCK_CONTINUE_IN_OPTIONS
// #define INCLUDE_PROVIDE_RAW_CC
// #define INCLUDE_CC_CONTROL
// #define INCLUDE_CLOCK_IN_OPTIONS
// #define INCLUDE_BUFFERED_CURSOR_X_POS

// Sysex isn't an available option on the Uno: it doesn't have enough memory

#endif




// Below are dependencies

#ifdef INCLUDE_EXTENDED_ARPEGGIATOR
#define INCLUDE_ARPEGGIATOR
#define INCLUDE_IMMEDIATE_RETURN
#define INCLUDE_ARPEGGIATOR_CC
#endif

#ifdef INCLUDE_EXTENDED_STEP_SEQUENCER
#define INCLUDE_STEP_SEQUENCER
#define INCLUDE_EXTENDED_CONTROL_SIGNALS
#define INCLUDE_EXTENDED_MENU_DEFAULTS
#define INCLUDE_STEP_SEQUENCER_CC
#define INCLUDE_CC_LEFT_POT_PARAMETER_EQUIVALENTS
#define INCLUDE_EXTENDED_GLYPH_TABLE
#define INCLUDE_IMMEDIATE_RETURN
#define INCLUDE_OPTIONS_TRANSPOSE_AND_VOLUME
#endif

#ifdef INCLUDE_EXTENDED_RECORDER
#define INCLUDE_RECORDER
#define INCLUDE_IMMEDIATE_RETURN
#endif

#ifdef INCLUDE_EXTENDED_CONTROLLER
#define INCLUDE_CONTROLLER
#define INCLUDE_EXTENDED_CONTROL_SIGNALS
#define INCLUDE_EXTENDED_GLYPH_TABLE
#endif

#ifdef INCLUDE_EXTENDED_GAUGE
#define INCLUDE_GAUGE
#define INCLUDE_PROVIDE_RAW_CC
#endif

#ifdef INCLUDE_THRU
#define INCLUDE_ENTER_CHORD
#define INCLUDE_EXTENDED_GLYPH_TABLE  // for GLYPH_PLAY
#endif

#ifdef INCLUDE_SPLIT
#define INCLUDE_EXTENDED_GLYPH_TABLE  // for GLYPH_FADE
#endif

#ifdef INCLUDE_ENTER_CHORD
#define INCLUDE_EXTENDED_GLYPH_TABLE // for GLYPH_CHORD
#endif

#ifdef INCLUDE_WAVES
#define INCLUDE_EXTENDED_FONT
#endif



#ifdef INCLUDE_SYNTH
#define INCLUDE_SYNTH_WALDORF_BLOFELD
#define INCLUDE_SYNTH_KAWAI_K4
#define INCLUDE_SYNTH_KAWAI_K5
#define INCLUDE_SYNTH_OBERHEIM_MATRIX_1000
#define INCLUDE_SYNTH_KORG_MICROSAMPLER
#define INCLUDE_SYNTH_YAMAHA_TX81Z
#endif







#include <Arduino.h>
#include <EEPROM.h>
#include <MIDI.h>
#include <SoftReset.h>
#include "MidiInterface.h"
#include "Utility.h"
#include "TopLevel.h"
#include "MidiShield.h"
#include "LEDDisplay.h"
#include "Division.h"
#include "Timing.h"
#include "Control.h"
#include "Storage.h"
#include "Arpeggiator.h"
#include "Recorder.h"
#include "Options.h"
#include "StepSequencer.h"
#include "Gauge.h"
#include "Split.h"
#include "Thru.h"
#include "Measure.h"
#include "Synth.h"

// This lets everyone have access to the MIDI global, not just
// the .ino file
extern midi::MidiInterface<HardwareSerial> MIDI; 

