moosemodular
============

I've become fascinated by modular synthesizers, specifically homebrew ones. I've built/am building a few kits, but wanted to experiement with many of the principles directly -- hence this project.

The goal here is to create a simple modular synth with much of the processing handled by Arduino boards running Mozzi, with a longer term goal of swapping out parts with analog components.

Initially, the plan is to make modules that all fit in a popular mint brand's tin. Connections would be made using 1/4" audio cables (because I have a bunch of them already sitting around from guitar work).

The goal is to use the 0-5V CV standard.

CV Generator
============

This circuit generates a continuous voltage between 0-5V. It consists of:

- A 7805 5V voltage regulator 
- A pot that adjusts the generated voltage
- DC in jack
- 1/4" output jack
- LED power indicator
- LED CV indicator
- SPST switch to toggle the CV on/off

Panel diagram and schematic are included.

VCO
==============

The VCO is driven off an Arduino Nano board running customn code using the Mozzi sound library. 

Components:
- Arduino nano
- 100K Audio Pot
- DC In Jack
- 1/4" jack x2
- Momentary pushbutton
- 4 LEDS

The VCO takes an input voltage of 0-5V and uses it to set the frequency of an oscillator, which is then output on the output CV jack. 4 wave forms -- sin, square, triangle and sawtooth -- are available. A pushbutton toggles between them, and LEDs indicate which is active.

TO ADD:
- Activity LED (blinks with freq)
- Power LED 
- Octave control
- Pulse width control?

Other modules (eventually)
==========================
- LFO
- VCF
- VCA
- Mixer
