# Tiny10Seg7
7 Segment LED display for ATtiny10 debugging

This is a mod of my Seg7 librry to use a 7segment LED tube based on the MAX7219.  It is not a library per se - it needs to have the minimum of code to work on an ATtiny10.

To use it put the Seg7_Tiny10.ino and Seg7.h files into the same subdirectory where you ATtiny10 Arduino sketch is located.

An example file is included in which the ATtiny10 is used as a rendom number generator to drive a 74HC595 shift register to do some pretty flashing LEDs.

I used <a href="https://github.com/technoblogy/attiny10core" target="_blank"> technoblogy's </a> excellent boards package fore the ATtiny10 family of MCUs.

I have small development boards for the ATtiny10 on my store - 

An 8 digit 7 segment LED tube is available at

I also have USBasps with the updated firmware to program the ATtiny10 directly.

Comment and questions are always welcome..
