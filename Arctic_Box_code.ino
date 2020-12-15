#include <Adafruit_CircuitPlayground.h>

int vals[8] = {3,2,0,1,10,6,9,12};

int ledPin = 13;
int ledState = LOW;    

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  for (int i=0;i<8;i++){
   int x = CircuitPlayground.readCap(vals[i]);
   if (x > 600) {
         ledState = HIGH;
     } else {
  ledState = LOW;
 }
  }

  digitalWrite(ledPin, ledState);
}
