#"SPI-I2C-PWM EXCERCISE"
	
##Initial Goals: 
	Development board for SPI-I2C protocols using multiple MCUs
	SMD soldering practice (SOIC and 0805,0603)
	R2R ladder approach for analog dipswitches
	Test out SPI/i2c protocols, PWM clock generation
	PDIP packages with thru hole sockets -swapable parts
	
##Basic Concept:
	Parent MCU send 8 bit messages to child MCUs
	User configruable paramters 
		communication protocol-SPI-i2c-PWM
		child rx
		8bit message 
		Additional features 
			10bit adc potentiometer
			additional commands - tx/rx
	8bit led shift regsiter displays (parent and child bit bang)
	Additional features selected by 10bit R2r ladder
##Resources: 
	Arudino i2c library 
	myshift register bit banging library

##Reach Goals: 
	Develop custom firmware to support I2C handles (somewhat out of scope)
	i2c bus arbitration (message priority)
	SPI child / parent swap
	Add UART(? - annoying reworks or new board)
	
##Thoughts/reflections:
	-Should've included pinouts for UART communication
	-Pinouts for a USB COM port, JTAG or ICSP (duh!)
	-Reworks are to make it work! Not to make it pretty!

*readme update 11-29-2021*
