/*  Based on Mozzi examples.
  
    Demonstrates the use of Oscil to play a wavetable.
  
    Circuit: Audio output on digital pin 9 (on a Uno or similar)
*/

#include <MozziGuts.h>
#include <Oscil.h> // oscillator template
#include <tables/sin2048_int8.h> // sine table for oscillator

// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);

// use #define for CONTROL_RATE, not a constant
#define CONTROL_RATE 64 // powers of 2 please

// PINS
const char VOLUME_POT_PIN = 0;

//
// State variables
//

// Record the volume from the volume pot
unsigned char g_volume = 0;

void setup(){
  Serial.begin(115200); // set up the Serial output so we can look at the input values

  startMozzi(CONTROL_RATE); // set a control rate of 64 (powers of 2 please)
  aSin.setFreq(440); // set the frequency
}


void updateControl(){
  // Read and set volume
  int sensor_value = mozziAnalogRead(VOLUME_POT_PIN); // value is 0-1023
  g_volume = map(sensor_value, 0, 1023, 0, 255); // (comment from example) map it to an 8 bit range for efficient calculations in updateAudio 
  
  // print the value to the Serial monitor for debugging
  Serial.print("volume = ");
  Serial.println((int)g_volume);
}


int updateAudio(){
  return ((int)aSin.next() * g_volume)>>8; // (comment from example) shift back into range after multiplying by 8 bit value
}

void loop(){
  audioHook(); // required here
}



