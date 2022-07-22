#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jun 23 08:44:22 2022

@author: oleg
"""
import serial
import time
import os 
import io
# from tkinter import *
import tkinter as tk
#%%
os.system('dmesg | grep ttyUSB')
#%%
# yesil = serial.Serial('/dev/ttyUSB1')
kahve = serial.Serial('/dev/ttyUSB0',timeout=1)
#%%
def kml_send(data):
    if type(data=='str'):    
        data = data.encode()
        kahve.write(data)
#%%
def kml_send_tkinter(data):
    if type(data=='str'):    
        data = data.encode()
        kahve.write(data)
        # txt.insert(tk.END,kml_receive())
        # text_area.insert(tk.END,kml_receive())
        a = kml_receive()
        text_area.insert(tk.INSERT,a)
        print(a)
#%%
def kml_receive():
    # print(sio.readline())
    # return (kahve.read(20).decode())
    return (kahve.read(1000).hex())
#%%
# message = "ADA"
# kml_send(message)
# a = kml_receive()
# print(a)
# print('\nişlemtamam')
#%%

message = "ADA"

import tkinter as tk
from tkinter import scrolledtext
root = tk.Tk()
root.geometry("600x300")
# root.minsize(600,300)
# root.maxsize(600,300)
  
reader_label = tk.Label(root, text ='EPROM_READER_V1', font = "100") 

reader_label.grid(row=0,column=0,pady=20,padx=20)


  
rd_but = tk.Button(root,text ="READ_EPROM", fg ="black",command=lambda: kml_send_tkinter(message))
rd_but.grid(row=1,column=0,sticky=tk.W,padx=20)



text_area = scrolledtext.ScrolledText(root,
                            width = 30, 
                            height = 8, 
                            font = ("Times New Roman",
                                    15))
  
text_area.grid(row=3,column = 0, pady = 10, padx = 10)
  

root.mainloop()
    


