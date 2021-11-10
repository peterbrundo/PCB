
#include <ShiftregC1.h>
Shiftreg76 shiftRegister;
//LED PINS
#define SPI_LED 5
#define I2C_LED 6
#define PWM_LED 7

//I2C PINS
#define SDA 4
#define SCL 5

//CS PINS
#define P_CS1 2
#define P_CS2 1
#define P_CS3 0
#define C_CS 2

//SPI PINS
#define MOSI_PIN 3
#define SCK_PIN 5
//R2R PINS
#define INPUT_LADDER 3
#define COM_SELECT_LADDER 2
#define CS_SELECT_LADDER 1

uint8_t low = 0;
uint8_t high = 0;

void setup(){
	
	//SETUP leds
			//no LEDS

	//Initialize SPI
		P_SPI_INIT();
	//CLEAR SHIFT REGISTER
		shiftRegister.clearBoard();
	//inITIALIZE A2D
		a2d_init();
}

void main(){

	for (i = 0;i<255;i++){
		shiftRegister.forwards(i);
		P_SPI_transmit(i);
		delay(1000);

	}
	/*
	INPUT_LADDER
	ADMUX = (1<<REFS0) | (INPUT_LADDER);
	ADCSRA = (1<<ADEN)|(1<<ADSC);
			while(ADCSRA & ((1<<ADSC)));
			low  = ADCL;
			high = ADCH;
			reading = int((high << 8) | low); //from arduino wiring_analog.c library
	if (reading > 200){
		P_SPI_transmit(255);
	}
	*/
	
}
void P_SPI_INIT(){
	
	/* Set MOSI and SCK output, all others input */
	PORTB = (1<<MOSI_PIN)|(1<<SCK_PIN);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
byte P_SPI_transmit(){
		/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
	;
}
void a2d_init(){
		//setup adc adps are prescales
	ADCSRA = (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);
	//16000000/128=125000 Hz
	
}



