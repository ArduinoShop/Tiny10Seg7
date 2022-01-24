#include "Seg7.h"

uint8_t msk; // decode mask

void Seg7_init() {
  pMode( MAX7219_Din, OUTPUT);
  pMode( MAX7219_CS,  OUTPUT);
  pMode( MAX7219_Clk, OUTPUT);

  output(DisplayTEST_REG,  0x0);  //  turn TEST mode OFF
  output(ShutDown_REG,     0x1);  //  Start UP MAX7219
  output(BrightNESS_REG,    0 );  //  Brightness to minimum
  output(DecodeMODE_REG,  0xFF);  //  all digits to BCD mode
  output(ScanlIMIT_REG,   NUM_DIGITS-1); //  Display all digits  

}

void Seg7_dec( uint16_t nm, uint8_t p )  {
	
  uint8_t x = 0;
  char    stg[5];
  stg[ 0 ] = ( nm/1000 ) | 0x30; nm = nm % 1000;
  stg[ 1 ] = ( nm/100 ) | 0x30;  nm = nm % 100;
  stg[ 2 ] = ( nm/10 ) | 0x30;   nm = nm % 10;
  stg[ 3 ] = nm;
  stg[ 4 ] = 0;

  while( stg[x] ) {

	output( p, stg[x] );

  x++; p--;
			}
		}

void Seg7_hex( uint16_t nm, uint8_t p )  {
uint8_t Seg7font[6] = { 0x77, 0x1F, 0x4E, 0x3D, 0x4F, 0x47 };
  uint8_t x = 0;
  uint8_t stg[5];
if( nm < 256 ) {
  stg[ 0 ] = ((nm & 0xF0) >> 4) | 0x30;
  stg[ 1 ] = ( nm & 0xF )       | 0x30;
  stg[ 2 ] = 0;
				}
else {  
  stg[ 0 ] = ((nm & 0xF000) >> 12) | 0x30;
  stg[ 1 ] = ((nm & 0xF00 ) >> 8 ) | 0x30;
  stg[ 2 ] = ((nm & 0xF0 )  >> 4 ) | 0x30;
  stg[ 3 ] = (nm & 0xF) | 0x30;
  stg[ 4 ] = 0;
				}

  while( stg[x] ) { stg[x] = stg[x] & 0xF;
	  if( stg[x] > 9 ) {
			 msk &= ~( 1<<( 7-p ) );
		   	 output( DecodeMODE_REG, msk );
         output( 8-p, Seg7font[ stg[x]-10 ] );
		    }
     else {
       output( 8-p, stg[x] );
		  }
  
 x++; p++;
				}
	}

/****  the Arduino shiftOut function is not available in the Core10 package  **/
void shift_out( uint8_t dta )
  {
    for( uint8_t x = 0; x < 8; x++ )
    {  
      dWrite( MAX7219_Din, dta & 0x80 );  delay( 1 );
      dWrite( MAX7219_Clk, HIGH ); delay( 1 );
      dWrite( MAX7219_Clk, LOW  );
      dta = dta << 1; 
    }
  }
	
void Seg7_clear( uint8_t p ) {

	int x;
	output(DecodeMODE_REG, 0xFF ); msk = 0xFF;
	for( x=8-p; x>0; x-- ) { output( x, 0xF ); }

	}

void Seg7_brightness( uint8_t b ) {
	output( BrightNESS_REG, b );
								}
	
void output( uint8_t address, uint8_t data) {

  dWrite( MAX7219_CS, LOW );
  shift_out( address);
  shift_out( data   );
  dWrite( MAX7219_CS, HIGH );

}

	
	
