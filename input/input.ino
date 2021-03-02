 /**********************************************************************
  Filename    : Joystick
  Description : Read data from joystick.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#include <Adafruit_NeoPixel.h>

#define LED_PIN 18
#define LED_COUNT 8

int xyzPins[] = {13, 12, 14};   //x,y,z pins

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
int pressed = 1;
int modeSoundLight = 0;
int DAY_HUE = 49;
int NIGHT_HUE = 209;
int saturation = 125;
int value = 125;
int hue = DAY_HUE;

void setup() {
  Serial.begin(9600);
  strip.begin();
   strip.setPixelColor(0, strip.ColorHSV(hue, saturation, value));
   strip.setPixelColor(2, strip.ColorHSV(hue, saturation, value));
   strip.setPixelColor(4, strip.ColorHSV(hue, saturation, value));
  strip.show();
  pinMode(xyzPins[1], INPUT_PULLUP);  //z axis is a button.
  pinMode(33, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);
  pinMode(32, INPUT_PULLUP);
}

void loop() {
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);
  int buttonVal = digitalRead(25);
  int button2Val = digitalRead(32);
  int switchVal =  digitalRead(33);

 
  //controls light/sound mode
  if (button2Val == 0) {
    if( pressed == 1) {
      pressed = 0;
      modeSoundLight = abs(modeSoundLight - 1);
    }
  } else{
    pressed = 1; 
  }
  
  if(modeSoundLight == 1 && buttonVal == 0)
  {
    if(xVal >= 3500 && value < 255)
    {
      value+=2;
    } else if (xVal < 500 && value > 0) {
      value-=2;
    }

    if( yVal> 3500 && saturation < 255)
    {
      saturation+=2;
    } else if (xVal < 500 && saturation > 0) {
      saturation-=2;
    }

    if(switchVal  == 0) {
      hue = DAY_HUE;
    } else {
      hue = NIGHT_HUE;
      }

//    Serial.printf("value: %d, hue: %d, sat: %d", value, hue, saturation);
    uint32_t color = strip.ColorHSV(hue, saturation, value);

   strip.setPixelColor(0, color);
   strip.setPixelColor(2, color);
   strip.setPixelColor(4, color);
   strip.show();
  }
  
//  Serial.printf("X,Y,Z: %d,\t%d,\t%d\n", xVal, yVal, zVal);
//  Serial.printf("%d %d %d %d %d", xVal, yVal, buttonVal, button2Val, switchVal);
  Serial.printf("%d %d %d %d %d", xVal, yVal, buttonVal, modeSoundLight, switchVal);
  Serial.print('\n');

  delay(50);
}
