#ifndef __Seg_7_H__
#define __Seg_7_H__

// #include <inttypes.h>
// #include <Arduino.h>

#define delay( x ) _delay_ms( x )

#define MAX7219_Din B1
#define MAX7219_CS  B0
#define MAX7219_Clk B2

#define NUM_DIGITS  8

    
  #define HIGH 1
  #define LOW  0
  #define delay( x ) _delay_ms( x )

#define DecodeMODE_REG	0x09
#define BrightNESS_REG	0x0A
#define ScanlIMIT_REG	0x0B
#define ShutDown_REG	0x0C
#define DisplayTEST_REG	0x0F

#endif
