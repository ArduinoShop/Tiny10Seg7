# Tiny10Seg7
7 Segment LED display for ATtiny10 debugging

This is a mod of my Seg7 librry to use a 7segment LED tube based on the MAX7219.  It is not a library per se - it needs to have the minimum of code to work on an ATtiny10.

To use it put the Seg7_Tiny10.ino and Seg7.h files into the same subdirectory where you ATtiny10 Arduino sketch is located.

An example file is included in which the ATtiny10 is used as a rendom number generator to drive a 74HC595 shift register to do some pretty flashing LEDs.

I used <a href="https://github.com/technoblogy/attiny10core" target="_blank"> technoblogy's </a> excellent boards package fore the ATtiny10 family of MCUs.

I have small development boards for the ATtiny10 on my store - [10LED](https://arduinoshop.ca/attiny/attiny10led)
                                                              - [10Rst](https://arduinoshop.ca/attiny/attiny10rst)
                                                              - [10spi](https://arduinoshop.ca/attiny/attiny10spi)

An 8 digit 7 segment LED tube is available [here](https://arduinoshop.ca/attiny/debug10)

I also have an [USBasp](https://arduinoshop.ca/accs/usbasp) with the updated firmware to program the ATtiny10 using TPI.

Comments and questions are always welcome..
