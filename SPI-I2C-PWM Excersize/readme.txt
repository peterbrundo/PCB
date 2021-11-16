Project title: 
	"SPI-I2C-PWM EXCERCISE"

Initial Goals: 
	Prototype out development board for SPI-I2C protocols across multiple MCUs including PWM interupts delivering 1 byte messages derived from input analog potentiometer
	Layout a decent sized board for Soldering practice
	
	
Concept
	User selects 
		SPI, I2C, or PWM
		8 bit input using potentiometer
		reciver chip
	Users presses a transmit button
	Sender MCU
		Outputs 8 bit message to shift register LED array
		Sends 8 bit message
	Reciever MCU 
		indicates the protocol using an LED
		outputs 8 bit input to shift regsiter LED array

Resources: 
	Arudino i2c library 
	myshift register bit banging library

Reach Goals: 
	Develop custom firmware to support I2C handles
	Clean up board past prototype
		SMD parts
		Fix reworks
Status: 
	SPI communication works
	
Next Step:
	I2C implementation


Thoughts/reflections:
	-Should've included pinouts for UART communication
	-Pinouts for a USB COM port, JTAG or ICSP would've made programing much faster
	-Don't trust random schematics for pinouts, consult the datasheet (rework to cut traces / add cap from AREF to GND)