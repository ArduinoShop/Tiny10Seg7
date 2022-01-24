#include <util/delay.h>
#include "Seg7.h"

#define ADC0  0
#define ADC1  1
#define ADC2  2
#define ADC3  3


//Pin connected to ST_CP of 74HC595 = 12 = RCLK
#define latchPin B2
//Pin connected to SH_CP of 74HC595 = 11 = SRCLK
#define clockPin B0
////Pin connected to DS of 74HC595  = 14 = SER
#define dataPin  B1

void setup() {
	
  ADMUX |= ADC3;  //  <<MUX0;            // choose ADC
  ADCSRA  = 1<<ADEN | 3<<ADPS0;    // Enable ADC, 125kHz clock
 
  Seg7_init();   //  this will set B0, B1, B2 to OUTPUT for both the Seg7 and the 74HC595

  DIDR0 = 0x0F;

 Seg7_clear( 0 );	   //		Cleat the Seg7 display starting at position 0
 Seg7_hex( 0xA3, 1 );  // write the value 0xA3 to the display - we will be displaying the value of ADC3
 dWrite( MAX7219_Clk, LOW  ); // start the 595 clock low
}

void loop() {

  uint8_t x, d = 0;
  dWrite(latchPin, LOW);  //  keep the 595 latch/load pin LOW

  ADCSRA = ADCSRA | 1<<ADSC;  // Start ADC
  while (ADCSRA & 1<<ADSC);   // Wait while conversion in progress
   _delay_ms( 2 );

 d = ( ADCL ) & 1;  //  we are only interested in the lowest order bit of ADC3 for use as a random 1 or 0

 Seg7_hex( d,  5 ); //  display the value of d at position 5
_delay_ms( 250 );   //  update every 1/4 second

}
