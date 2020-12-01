int sensorpin = 0;
int val = 0;


int ledpin = 13;
int ledState = LOW;    

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
 val = analogRead(sensorpin);
 
 if(val >300) {
  ledState = HIGH;
  
 } else {
  ledState = LOW;
 }


  digitalWrite(ledPin, ledState);
}
