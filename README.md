# eprom_reader
just a simple M27C1001 reader (perhaps start of a more comprehensive reader and writer)

I have used microchip's explorer16/32 dev. board and dspic33EP512MU810. 
Essential part of the hardware is to configure parallel master port of the dspic. 

First off all a "read" command is sent to the dspic through serial port by eprom_rw.py . 
When hardware detects "read" command PMP module starts incrementing address automatically and outputs EPROM data to the PMDIN register. 
After reading of one memory location of EPROM , data is immediately sent to the python application through serial port in which inserted into a tkinter text box.  

(sorry for the sound issue in video)


https://user-images.githubusercontent.com/30715872/180448787-f0b75b9a-a588-44a0-a512-32a8c543aa17.mp4



