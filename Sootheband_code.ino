// code worked off of https://pulsesensor.com/pages/code-and-guide

#include <Adafruit_CircuitPlayground.h>



int presets[2][3][3] = {
  {
    {120, 45, 155},
    {0, 0, 138},
    {0,128,9}
    },
   {
    {0, 255, 255},
    {233, 35, 138},
    {154,128,200}
   }
  
};

int preset = 0;
int ledState = LOW;

//  Variables
int PulseSensorPurplePin = 0;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int LED13 = 13;   //  The on-board Arduion LED


int Signal;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 700;            // Determine which Signal to "count as a beat", and which to ingore.


// The SetUp Function:
void setup() {
  pinMode(LED13,OUTPUT);         // pin that will blink to your heartbeat!
   Serial.begin(9600);         // Set's up Serial Communication at certain speed.
CircuitPlayground.begin();
}

// The Main Loop Function
void loop() {

  Signal = analogRead(PulseSensorPurplePin);  // Read the PulseSensor's value.
                                              // Assign this value to the "Signal" variable.

   Serial.println(Signal);                    // Send the Signal value to Serial Plotter.


   if(Signal > Threshold){                          // If the signal is above "550", then "turn-on" Arduino's on-Board LED.
    preset = (preset + 1) % 2;
   } else if (Signal < Threshold) {
   preset = 10;               //  Else, the sigal must be below "550", so "turn-off" this LED.
   }


 for (int i=0; i<10; i++) {
    CircuitPlayground.setPixelColor(
      i,presets[preset][i%2][0],presets[preset][i%2][1],presets[preset][i%2][2]);
  }
  

delay(1500);


}
