# Buisness Card Project
## Status
- PCB hardware is complete, software is a little messsy, need to upload pictures and stp files
- Project will now include a capactive touch board
## TO DO:
- [ ] Upload 3d step files
- [ ] Upload pictures of rework
- [ ] Upload pictures of 0204 caps soldered
- [ ] Upload new firmware
- [x] Learn how to spell business
- [x] Upload code and test
- [x] 
~~- Finish soldering 0201 (0603 Metric) caps~~ (See rework notes) 


# Project Purpose:

I wanted to create buisness card on a printed circuit board with some USB keyboard functionality! 

## Key goals

	1) Experiment with USB 2.0 protocol (hardware layout and software)
	2) PCB to plug directly into USB port
	3) PCB CAD library from scratch with 3d .stp files (not from scratch)
	4) Use 0201 (0603 metric) sized components
	5) Buisness card look and feel
	6) Flash firmware  via ICSP via Atmel Studio 7 ICE 

## Inspiration:

The main inspiration of this project comes from this "Stylophone buisness card" project (https://mitxela.com/projects/stylocard & https://youtu.be/zHVrY_xLM3c). I liked the idea of a USB plug integrated into the PCB.  I think there's all sorts of interesting appliactions, including streamdecks, numberpads and more.  I looked into a few Arduino based solutions with hardware USB (ATMEGA16U2), but settled on a V-USB firmware based design ([See hidkeys here from Objective Development Software GmbH](https://www.obdev.at/products/vusb/hidkeys.html))

# PCB design:

To make the PCB look like a buisness card, I used a 3.5 x 2.0 dimension constraints (See 47 Measures layer).  I made a USB-A header component following the USB 2.0 spec and placed it at the center of a 45 degree bend at the top right corner.

I then copied the V-USB circuit schmeatic from the website.  I gave myself a challenge by including 0201 (0603 Metric) sized capacitors.  Using a hot air gun I got them soldered properly, but I decided to remove them and opt with a rework so as to not have any quality issues.

For my personal info, I decided to play around with the different copper and soldermask layers to create some neat effects.  

I then created my own eagle components for the rest of the parts from the V-USB schematic and included 3d .step files for everything. 

# Thoughts and reflections

This was a fun project that forced me to learn Atmel Studio 7 environments.  There were a few work arounds including
