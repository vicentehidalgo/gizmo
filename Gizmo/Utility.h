////// Copyright 2016 by Sean Luke
////// Licensed under the Apache 2.0 License


////// UTILITY
//////
////// Utility.h/.cpp define various utility functions used by a variety of applications
////// 

#ifndef __UTILITY_H__
#define __UTILITY_H__





///// DEBUGGING FACILITY
/////
///// When using MIDI you can't print out to Serial.  But you CAN print to the
///// LED matrix.  These functions will do this.

/// Print an integer (-9999 to 19999) to the LED, and pause for 1/4 sec 
uint8_t debug(int16_t val);

/// Print a maximum TWO-character string to the LED, along with an integer from -99...127, and pause for 1/4 sec 
uint8_t debug(const char* str, int8_t val);

/// Print two integers, each from -99...127, and pause for 1/4 sec 
uint8_t debug(int8_t val1, int8_t val2);



///// NOTES

/// Indicates no note (in various contexts)
#define NO_NOTE 128

// perform a click track
void doClick();





///// DRAWING SUPPORT

//// Draws a MIDI channel value of the bottom row of the left LED, using drawRange(...)
void drawMIDIChannel(uint8_t channel);

//// GLYPHS available to WRITE 3x5 GLYPHS, which writes 4 glyphs filling the whole screen
#define GLYPH_OFF 0                                    	// ----
#define GLYPH_OMNI 1                                    // ALLC
#define GLYPH_DEFAULT 2                                 // DFLT
#define GLYPH_DECREMENT 3                               // DECR
#define GLYPH_INCREMENT 4                                                               // INCR
#define GLYPH_FREE 5                                    // FREE
#define GLYPH_NOTE 6                                    // NOTE
#define GLYPH_SYSEX 7                                   // SYSX
#define GLYPH_SONG_POSITION 8                           // SPOS
#define GLYPH_SONG_SELECT 9                             // SSEL
#define GLYPH_TUNE_REQUEST 10                           // TREQ
#define GLYPH_START 11                                  // STRT
#define GLYPH_CONTINUE 12                               // CONT
#define GLYPH_STOP 13                                   // STOP
#define GLYPH_SYSTEM_RESET 14                           // RSET

#ifdef INCLUDE_EXTENDED_GLYPH_TABLE
#define GLYPH_FADE 15									// FADE
#define GLYPH_PLAY 16									// PLAY
#define GLYPH_CHORD 17									// CHRD
#define GLYPH_HIGH 18									// HIGH
#endif

#define GLYPH_OTHER (254)	// reserved to represent "use this glyph instead"
#define GLYPH_NONE	(255)	// reserved to represent "no glyph"

// Writes any of the above glyph sets to the screen
void write3x5Glyphs(uint8_t index);

// Clears the screen buffers.
void clearScreen();




#ifdef INCLUDE_OPTIONS_MENU_DELAY
// SET MENU DELAY
// Changes the menu delay to a desired value (between 0: no menu delay, and 11: infinite menu delay).  The default is 5
void setMenuDelay(uint8_t index);

#endif

// The index values passed into setMenuDelay correspond to the following delays (but these
// constants may NOT be passed into setMenuDelay).

#define DEFAULT_SHORT_DELAY (60 >> 3)
#define NO_MENU_DELAY  (DEFAULT_SHORT_DELAY)
#define EIGHTH_MENU_DELAY (109 >> 3)
#define QUARTER_MENU_DELAY (205 >> 3)
#define THIRD_MENU_DELAY (269 >> 3)
#define HALF_MENU_DELAY (397 >> 3)
#define DEFAULT_MENU_DELAY (781 >> 3)
#define DOUBLE_MENU_DELAY (1549 >> 3)
#define TREBLE_MENU_DELAY (2317 >> 3)
#define QUADRUPLE_MENU_DELAY (3085 >> 3)
#define EIGHT_TIMES_MENU_DELAY (6157 >> 3)
#define HIGH_MENU_DELAY  (NO_SCROLLING)







///// STATE UTILITIES

///// Call this repeatedly from your SAVE state to query the user to save the current data.
///// backState          where we should go after the user has cancelled or saved.
void stateSave(uint8_t backState);


///// Call this repeatedly from your LOAD state to query the user to load the current data,
/////     or optionally to initialize the data.  You may want to customize this method to add
/////     your own initialization or unpacking code.
///// selectedState     where we should go after the user has loaded.
///// initState                 where we should go after the user has initialized new (not loaded).
///// backState                 where we should go after the user has cancelled.
///// defaultState              when we cancel and go back, what should we indicate as the default state?
void stateLoad(uint8_t selectedState, uint8_t initState, uint8_t backState, uint8_t defaultState);


///// Call this repeatedly from your SURE? state to query the user about whether he really wants
///// to do something (typically to cancel via clicking the back button)
///// selectedState             where we should go after the user has pressed the SELECT button,
/////                                   typically indicating that he DOESN'T want to go back.
///// backState                 where we should go after the user has pressed the BACK button,
/////                                   typically indicating that he WANTS to go back.
void stateSure(uint8_t selectedState, uint8_t backState);


///// Call this repeatedly from your notional "please enter a note" state to query the user about what note he'd like.
///// The value returned is either NO_NOTE, indicating that the user has not entered a note yet,
///// or it is a note pitch, which the user has chosen.  The velocity of the note is stored in
///// the global variable stateEnterNoteVelocity.  
///// backState                 where we should go after the user has cancelled                         
extern uint8_t stateEnterNoteVelocity;
uint8_t stateEnterNote(uint8_t backState);


#ifdef INCLUDE_ENTER_CHORD
///// Call this repeatedly from your notional "please enter a chord" state to query the user about what chord he'd like.
///// You pass in an array CHORD of size MAXCHORDNOTES.
///// The value returned is either NO_NOTE, indicating that the user has not entered a (full) chord yet,
///// or it is the number of notes in the chord the user played (up to MAXCHORDNOTES).  This value will never
///// be ZERO.  The velocity of the LAST NEW note entered is stored in the global variable 
///// stateEnterNoteVelocity.  The notes are stored, sorted, in CHORD.  Note that if the user cancels his 
///// chord (that is, we go to backState), the values in the chord array will be undefined.
///// chord                     Notes are stored here.
///// backState                 where we should go after the user has cancelled                         
uint8_t stateEnterChord(uint8_t* chord, uint8_t maxChordNotes, uint8_t backState);
#endif


///// Increments playing notes from an application (such as a step sequencer or arpeggiator).
///// This method is used in various states to keep playing even while wandering through a menu etc. 
void playApplication();


//// Goes to the given state, setting entry to true and no default state
void goDownState(uint8_t nextState);


//// Goes to the given state, setting entry to true and no default state,
//// and ALSO backs up options.
void goDownStateWithBackup(uint8_t _nextState);


//// Goes to the given state, setting entry to true and the default state to the current state
void goUpState(uint8_t nextState);


//// Goes to the given state, setting entry to true and the default state to the current state,
//// and ALSO backs up options.
void goUpStateWithBackup(uint8_t _nextState);

///// GENERAL UTILITIES

///// bounds n to between min and max inclusive, returning the result
uint8_t bound(uint8_t n, uint8_t min, uint8_t max);

///// increments n, then if it EQUALS or EXCEEDS max, sets it to 0, returning the result
uint8_t incrementAndWrap(uint8_t n, uint8_t max);

/// Computes the median of three values.
#define MEDIAN_OF_THREE(a,b,c) (((a) <= (b)) ? (((b) <= (c)) ? (b) : (((a) < (c)) ? (c) : (a))) : (((a) <= (c)) ? (a) : (((b) < (c)) ? (c) : (b))))

/// Computes the median of five values.  [Presently unused]
uint16_t medianOfFive(uint16_t array[]);





#endif __UTILITY_H__
