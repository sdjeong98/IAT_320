#include <Adafruit_CircuitPlayground.h>

int presets[3][3][3] = {
  {
    {0,255,0},
    {255,0,0},
    {0,0,255}
  },
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
bool lastRightPress = false;
bool lastLeftPress = false;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  bool leftPress = CircuitPlayground.leftButton();
  if (leftPress && (lastLeftPress == false)) {
    preset = ((preset-1)+3) % 3;
  }
  lastLeftPress = leftPress;
  
  bool rightPress = CircuitPlayground.rightButton();
  if (rightPress && (lastRightPress == false)) {
    preset = (preset + 1) % 3;
  }
  lastRightPress = rightPress;

  float acc = abs(CircuitPlayground.motionX()) + abs(CircuitPlayground.motionY()) + abs(CircuitPlayground.motionZ());
  if (acc > 25) {
    preset = rand() % 3;
  }

  for (int i=0; i<10; i++) {
    CircuitPlayground.setPixelColor(
      i,presets[preset][i%2][0],presets[preset][i%2][1],presets[preset][i%2][2]);
  }
  
  delay(10);
}
