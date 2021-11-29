# SPI-I2C-PWM EXCERCISE
	
## Initial Motivation and goals: 
- Development board for SPI-I2C protocols using multiple MCUs
- R2R ladder approach for analog dipswitches
- SMD soldering practice (SOIC and 0805,0603)
- PDIP packages with thru hole sockets -swapable parts
- Include right angle receptacles to reuse "Shift Register Excersize" boards
- - Reduce, Reuse, Recycle!
	
## Basic Concept:
- Parent MCU sends 8 bit messages to child MCUs
- 8bit led shift regsiter displays message (parent and child)
	- User configruable paramters 
	- Communication protocol-SPI-i2c-PWM
	- Child rx
	- 8bit messages
	- 10bit adc potentiometer
	- additional display visualazations (in development)

## Resources: 
- Arudino i2c library 
- "bitbang_shift_register" (See [PCB/Shift Register Excersize/](https://github.com/peterbrundo/PCB/tree/master/Shift%20Register%20Excersize)

## Reach Goals: 
- Develop custom firmware to support I2C handles (somewhat out of scope)
- i2c bus arbitration (message priority)
- child / parent swap (SPI)
- Add UART(? - annoying reworks)
- Compile and flash firmware as .hex file within Atmel Studio 7
	
## Thoughts/reflections:
- Should've included pinouts for UART communication
- Pinouts for a USB COM port, JTAG or ICSP (duh!)
- Reworks are to make it work! Not to make it pretty!

*readme update 11-29-2021*
