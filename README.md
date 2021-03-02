# Creative Embedded Systems - Module 2: Interactive Art
This piece is again an artificial examination and imitation of nature, this time through exploring the creation bird sounds and housed in a birdhouse that aids the visial and auditory elements of the piece.

A video demo can be found [here](https://youtu.be/NZu8o4pp4hs)

## Wiring
The wiring of this project is fairly complex. 
The joystick was connected as such:
- Joystick GRD --> ESP32 GRN
- Joystick +5V --> ESP32 5V
- Joystick VRX --> ESP32 GPIO 13
- Joystick VRY --> ESP32 GPIO 12
- Joystick SW --> ESP32 GPIO 14

The buttons and switch were connected in the same way as eachother, with one side connecting ground and the other to their respective GPIO pins: 
- button: GPIO 25
- button2: GPIO 32
- switch: GPIO 33
  
The LED modules was set up in a very simlar way to [this project](https://github.com/Cina10/EmbeddedSys_Generative).
The only differences is that instead of a Raspberry Pi, the wires were plugged into the ESP32. In particular, the signal wire was plugged into GPIO18. If you plug it in elsewhere, ensure you modify the line "#define LED_PIN 18" to match the GPIO used. [This source](https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use) was used for set up and can be used if you wish to further modify the code.

## Arduino
First, flash the Arduino code input.ino onto your ESP32 from your computer. Much of the set up for the ESP32 is detailed [here](https://github.com/Freenove/Freenove_Ultimate_Starter_Kit_for_ESP32)
For those using the Big Sur Mac Operating System, you may have to adjust the board manager, using the JSON file [here](https://github.com/espressif/esptool/issues/540#issuecomment-747185562) or changing the upload speed to the lowest possible upload speed.

Once you have wired everthing up, and the code is flashed to your ESP32, check the Serial Monitor to ensure that the correct values are printing. If the numbers are not showing up, try reseting the ESP32 and checking the baud rate. I used 9600, but it may vary for you. If you use a different baud rate, make sure to adjust the Python script to match in line 15.

## Python
Install the dependancies with the following commands: 

```
pip3 install python-osc
pip3 install pyserial
```

After making sure the Arduino code is running, run the Python code with the command `python3 sonicPiSerial.py`
You may have to edit the line 15 to match your port and baud rate. 
 

## Sonic Pi

First install Sonic Pi with the command `sudo apt install ./sonic-pi_3.3.1_1_armhf.deb`
Then open the file "birdSounds.rb" using in the application. Make sure to edit the file paths to samples to match the absolute file path to you samples on your Rasberry Pi. Then press run!

Finally I plugged the Rasberry Pi into the wall, the ESP32 into the Raspberry Pi, and set up the speakers(this was a bit tricky, but I think it was unique to my speakers) Put everything into your encloser, tape everything in and cross your fingers that it doesn't break!
