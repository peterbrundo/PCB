TO DO:
Fix typos, yikes!
Upload code and test
Finish soldering 0201 (0603) capacitors

Project Purpose:

The purpose of the project is to create a buisness card on a printed circuit board with some keyboard functionality! With this project I've had a few key goals in mind

	1) Learn and experiment with USB 2.0 protoco (hardware and software)
	2) Design a PCB to plug directly into a USB port
	3) Develop a working PCB CAD library with associated 3d .stp files
	4) Look and serve as a buisness card (with some style!)
	5) Use 0201 (0603 metric) sized components as a soldering challenge!
	6) Polish up on some documentation skills! (github and this readme for example)

Inspiration:

The main inspiration of this project is definetley this "Stylophone buisness card" project I saw on youtube (https://mitxela.com/projects/stylocard & https://youtu.be/zHVrY_xLM3c). I had been making PCBs at work and at home, and I thought it would be an interesting side project to do in my free time.  I liked the idea because it would be easy to present a buisness card to my friends and family.  To add my own personalized spin, I decided to make it also work as a keyboard. I think there's all sorts of possible applications such as streamdecks, custom macrobased push buttons, numpads, support for non-standard ASCII charecters, or just as a clumsy keyboard alternative. One of my favorite ideas was to have a keyboard to create keybindings for a favorite game of mine, counter strike global offensive.  Each button would correspond to in game items and equipment in the buy menu.  I could even feature some artwork on the pcb to include icons from the game itself as reference. 

V-USB

With a buisness card in mind, I needed to select a microcontroller.  Traditionally I've used Arduino UNO and MEGAs (ATMEGA family) as a starting point but they don't include USB hardware. That's when I found the V-USB library and thought it was a unique way to provide USB functionality to different ATMEGA microncontrollers.  In hindsight, I could also have chosen an Arduino Leonardo or another ATMEGA with hardware usb.  


PCB design:

To make the PCB look like a buisness card, I used a 3.5 x 2.0 inch dimension as a constraint.  I wanted the USB header to fit within these dimensions at the center of the 45 degree bend at the top right corner. 
I wanted the header centered along the curve without exceeding the 3.5 x 2.0 inch dimensions.  First I created a new eagle library and created a USB-A header following the USB 2.0 specification for the required dimenions and pinouts, even including a USB logo as best I could!  With the part in hand, I brushed up my trig to create the 45 degree bend with my USB header centered at the midddle (math included on the "47 Measures layer"). 

I then copied the V-USB circuit schmeatic from the website.  I wanted to give myself a challenge so I included 0201 (0603 Metric) sized capacitors as a soldering challenege!  Those buggers are near impossible to solder with a heat gun, so it's almost a necessiaty to have a microscope on hand.  I did order a stencil and solderpaste for this, but next time I'd rather do it by hand with a soldering iron.  Perhaps i'll include a surface mount version of the ATMEGA8 for more drag soldering practice.

For my personal info, I decided to play around with the different copper and soldermask layers to create some neat effects. The email is incorrect, and I may decide to take the rest of my contact info out from the design files later, but oh well.  

I then created my own eagle components for the rest of the parts from the V-USB schematic and included 3d .step files for everything.  I think there may be a few things that i've used from other libraries, such as the GND and +5V, but it's been a long time!

more info at http://www.obdev.at/vusb/