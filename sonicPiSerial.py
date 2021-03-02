'''
this python code will listen for serial messages, 
and pass that trigger on to SonicPi (code below) as an OSC message, triggering a sound
'''

from pythonosc import osc_message_builder
from pythonosc import udp_client
import serial
import sys
import time

#select the correct port and baud rate 


ser = serial.Serial('/dev/cu.usbserial-1120', 9600)

modeTime = 0
b = 1
c = 0.3

while True:
    try:
        ser_bytes = ser.readline()
        line = ser_bytes.split()
        print(line)

        # only runs this if the serial input is in the correct form
        if len(line) == 5:
            
            modeTime = int(line[4])
            modeSave = line[2]
            modeSoundLight = line[3] 

            xVal = int(line[0])
            yVal = int(line[1])  
       
            if modeSoundLight == "0" and modeSave == "0":

                if xVal >= 3500 and b < 2:
                    b+=0.1
                elif xVal < 500 and b > 0.5:
                    b-=0.1
            

                if yVal> 3500 and c < 1.2:
                    c+=0.1
                elif xVal < 500 and c > 0.3:
                    c-=0.1
                  

                #figure out range of values for b and c
                sender = udp_client.SimpleUDPClient('127.0.0.1', 4560)
                message = [modeTime, b,  c]
                print(message)
                sender.send_message('/trigger/prophet', message)
            else: 
                sender.send_message('/trigger/prophet', message)
                message = [modeTime, b,  c]
                print(message)
                sender.send_message('/trigger/prophet', message)

        time.sleep(0.01)          
        
    except:
        print(sys.exc_info()[0])
        break