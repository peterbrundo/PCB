#purpose
    #Use Pserial to establish a Serial connection to Arduino
    #Use Arduino to read capactive touch sensor (captouchdemo.ino)
    #Use Tkinter to generate a GUI
#instructions
    #use the captouchdemo.ino
    #use 115200 baudrate, 
    #use only Serial.print(reports[1]); *See improvements
    
#Resources
    #dev board          https://www.mouser.com/datasheet/2/198/IS31SE5100_EB-1950035.pdf
    #sensor datasheet   https://www.mouser.com/datasheet/2/198/IS31SE5100_DS-1950146.pdf


#improvements
    #1) add functionality for both State Register 1
        #-> Currently utilizing State Register 2 for demonstration (State changes, not action states)
    #2) draw circles instead of arcs
    #3) add labels for button states
    #3) clean up code redundancies, add comments, etc.

import os
import sys
import time
import serial
import string
import random
import threading
import serial.tools.list_ports
import tkinter as tk
from tkinter import ttk
def threadstart():
    while 1:
        start()
    return
def start():
    write_read()
    return
def write_read():
    data = 0
    while ser.in_waiting:
        data = ser.readline()
        if (int(data.decode('utf-8')) < 256):
            print(int(data.decode('utf-8')))
            #print(data.decode('utf-8'))
            #populatedata(data.decode('utf-8'))
            populatedata(data)
        return
def populatedata(d):
    print("Start def populatedata()")
    abc = int(d)
    print(d)
    print(bin(abc))
    abitmask_0 = 1
    abitmask_1 = 2
    abitmask_2 = 4
    abitmask_3 = 8
    abitmask_4 = 16
    abitmask_5 = 32
    abitmask_6 = 64
    abitmask_7 = 128
    abitmask_list = [abitmask_0,abitmask_1,abitmask_2,abitmask_3,abitmask_4,abitmask_5,abitmask_6,abitmask_7]
    populatedresult = [0,0,0,0,0,0,0,0]
    zz = 0
    for v in abitmask_list:
        if (abc & v):
            populatedresult[zz] = 1
        else:
            populatedresult[zz] = 0
        print(populatedresult[zz])
        zz = zz + 1
    
    var.set(str(bin(abc)))
    if populatedresult[0] == 1:
        c1.create_arc((2,2,152,152), fill="#FAF402", start=prop(0), extent = prop(999))
    else:
        c1.create_arc((2,2,152,152), fill ="#FFFFFF",start=prop(0), extent = prop(999)) 
    if populatedresult[1] == 1:
        c2.create_arc((2,2,152,152), fill="#FAF402", start=prop(0), extent = prop(999))
    else:
        c2.create_arc((2,2,152,152), fill ="#FFFFFF", start=prop(0), extent = prop(999))
    if populatedresult[2] == 1:
        c3.create_arc((2,2,152,152), fill="#FAF402", start=prop(0), extent = prop(999))
    else:
        c3.create_arc((2,2,152,152), fill ="#FFFFFF", start=prop(0), extent = prop(999)) 
    if populatedresult[3] == 1:
        c4.create_arc((2,2,152,152), fill="#FAF402", start=prop(0), extent = prop(999))
    else:
        c4.create_arc((2,2,152,152), fill ="#FFFFFF", start=prop(0), extent = prop(999)) 
    if populatedresult[4] == 1:
        c5.create_arc((2,2,152,152), fill="#FAF402", start=prop(0), extent = prop(999))
    else:
        c5.create_arc((2,2,152,152), fill ="#FFFFFF", start=prop(0), extent = prop(999))
    if populatedresult[5] == 1:
        c6.create_arc((2,2,152,152), fill="#FAF402", start=prop(0), extent = prop(999))
    else:
        c6.create_arc((2,2,152,152), fill ="#FFFFFF", start=prop(0), extent = prop(999))
        threadstart
    if populatedresult[6] == 1:
        c7.create_arc((2,2,152,152), fill="#FAF402", start=prop(0), extent = prop(999))
    else:
        c7.create_arc((2,2,152,152), fill ="#FFFFFF", start=prop(0), extent = prop(999))    
    if populatedresult[7] == 1:
        c8.create_arc((2,2,152,152), fill="#FAF402", start=prop(0), extent = prop(999))
    else:
        c8.create_arc((2,2,152,152), fill ="#FFFFFF", start=prop(0), extent = prop(999))
    return
    c1.grid(column=7, row=3, padx=5, pady=5)
    c2.grid(column=6, row=3, padx=5, pady=5)
    c3.grid(column=5, row=3, padx=5, pady=5)
    c4.grid(column=4, row=3, padx=5, pady=5)
    c5.grid(column=3, row=3, padx=5, pady=5)
    c6.grid(column=2, row=3, padx=5, pady=5)
    c7.grid(column=1, row=3, padx=5, pady=5)
    c8.grid(column=0, row=3, padx=5, pady=5)

    
###
def prop(n):
    return 360.0 * n / 1000
###

print('Search...')
ports = serial.tools.list_ports.comports(include_links=False)
for port in ports :
    print('Find port '+ port.device)
ser = serial.Serial(port.device)
if ser.isOpen():
    ser.close()
ser = serial.Serial(port.device, 115200, timeout=0.050)
ser.flushInput()
ser.flushOutput()
print('Connect ' + ser.name)
time.sleep(1)
root = tk.Tk()
root.title("IS31SE5100 8-CH CAPACITIVE TOUCH SENSOR ")

f = ttk.Frame(root);
f.grid()
c1= tk.Canvas(width=154, height=154)
c2= tk.Canvas(width=154, height=154)
c3= tk.Canvas(width=154, height=154)
c4= tk.Canvas(width=154, height=154)
c5= tk.Canvas(width=154, height=154)
c6= tk.Canvas(width=154, height=154)
c7= tk.Canvas(width=154, height=154) 
c8= tk.Canvas(width=154, height=154) 

displaynumber = 0
displaybuttonaction = ""
result_list = [0,0,0,0,0,0,0,0]

var = tk.StringVar()
var.set(str(bin(displaynumber)))
var2 = tk.StringVar()
var2.set(displaybuttonaction)


c1.grid(column=7, row=3, padx=5, pady=5)
c2.grid(column=6, row=3, padx=5, pady=5)
c3.grid(column=5, row=3, padx=5, pady=5)
c4.grid(column=4, row=3, padx=5, pady=5)
c5.grid(column=3, row=3, padx=5, pady=5)
c6.grid(column=2, row=3, padx=5, pady=5)
c7.grid(column=1, row=3, padx=5, pady=5)
c8.grid(column=0, row=3, padx=5, pady=5)


ttk.Label(root, textvariable = var).grid(column=3, row=4)
ttk.Label(root, textvariable = var2).grid(column=3, row=5)


ttk.Label(root, text = "Reg_0").grid(column=7, row=0)
ttk.Label(root, text = "Reg_1").grid(column=6, row=0)
ttk.Label(root, text = "Reg_2").grid(column=5, row=0)
ttk.Label(root, text = "Reg_3").grid(column=4, row=0)
ttk.Label(root, text = "Reg_4").grid(column=3, row=0)
ttk.Label(root, text = "Reg_5").grid(column=2, row=0)
ttk.Label(root, text = "Reg_6").grid(column=1, row=0)
ttk.Label(root, text = "Reg_7").grid(column=0, row=0)

b = ttk.Button(text="Start!", command=threading.Thread(target=threadstart).start())
b.grid(column=1, row=4, padx=5, pady=5)

root.mainloop()
