#include <Adafruit_NeoPixel.h>
#include <Servo.h>

#define LED_Pin 6
#define LED_COUNT 21
#define BLINK_DELAY 200
#define BRIGHTNESS 80

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_Pin, NEO_GRB + NEO_KHZ800);

Servo servo1;  // servo control object

int Button_Pin = 8;

void setup()
{
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show(); // Initialize all pixels to 'off'

  servo1.attach(9);
  servo1.write(90); // not sure if this is necessary, but it won't hurt

  pinMode(Button_Pin, INPUT_PULLUP);
}

void loop()
{
  int button_state = digitalRead(Button_Pin);

  if (button_state == HIGH) {
    cars_crossing_1();
  }
    if (button_state == HIGH) {
    cars_crossing_2();
  }

  if (button_state == LOW) {
    servo1.attach(9); // necessary because the cars_crossing detaches servo1
    lower_gate();
    int count;
    for (count = 0; count <= 2; count++)
    {
      train_crossing();
    }
    raise_gate();
  }
}

void train_crossing()
{
  colorWipe(strip.Color(255,   0,   0), BLINK_DELAY);
  colorWipe(strip.Color(0,   0,   0), BLINK_DELAY);
  strip.show();
  delay (500);
  colorWipe(strip.Color(255,   0,   0), BLINK_DELAY);
  colorWipe(strip.Color(0,   0,   0), BLINK_DELAY);
  strip.show();
  delay (500);
  colorWipe(strip.Color(0,   0,   0), BLINK_DELAY);
  colorWipe(strip.Color(0,   0,   0), BLINK_DELAY);
  strip.show();
}

void cars_crossing_1()
{
  delay(100); // initially added to help with servo jitter at 90°
  if (servo1.attached()) {
    servo1.detach(); // this is what cleared up the jitter completely
  }
  brighten();
}

void cars_crossing_2()
{
  delay(100); // initially added to help with servo jitter at 90°
  if (servo1.attached()) {
    servo1.detach(); // this is what cleared up the jitter completely
  }
  darken();
}

void lower_gate()
{
  int angle;
  for (angle = 90; angle <= 180; angle++)
  {
    servo1.write(angle);
    switch (angle) { // this is to get the lights flashing while the gate is moving
      case 90 : //At starting point, turn on LED 0
        colorWipe(strip.Color(255,   0,   0), BLINK_DELAY);
        colorWipe(strip.Color(0,   0,   0), BLINK_DELAY);
        strip.show();
        break;
      case 113 : //At ~22.5°, switch to LED 1
        colorWipe(strip.Color(255,   0,   0), BLINK_DELAY);
        colorWipe(strip.Color(0,   0,   0), BLINK_DELAY);
        strip.show();
        break;
      case 135 : //At 45°, switch to LED 0
        colorWipe(strip.Color(255,   0,   0), BLINK_DELAY);
        colorWipe(strip.Color(0,   0,   0), BLINK_DELAY);
        strip.show();
        break;
      case 157 : //At ~67.5°, switch to LED 1
        colorWipe(strip.Color(255,   0,   0), BLINK_DELAY);
        colorWipe(strip.Color(0,   0,   0), BLINK_DELAY);
        strip.show();
        break;
    }
    delay (22);  //delay of 22ms creates a total sweep time of 1980ms, which is approx divisible by 500 ms that each LED is on in the trains_crossing function
  }
}

void raise_gate()  //works the same as raise_gate, but backwards
{
  int angle;
  for (angle = 180; angle >= 90; angle--)
  {
    servo1.write(angle);
    switch (angle) {
      case 180 :
        colorWipe(strip.Color(255,   0,   0), BLINK_DELAY);
        colorWipe(strip.Color(0,   0,   0), BLINK_DELAY);
        strip.show();
        break;
      case 157 :
        colorWipe(strip.Color(255,   0,   0), BLINK_DELAY);
        colorWipe(strip.Color(0,   0,   0), BLINK_DELAY);
        strip.show();
        break;
      case 133 :
        colorWipe(strip.Color(255,   0,   0), BLINK_DELAY);
        colorWipe(strip.Color(0,   0,   0), BLINK_DELAY);
        strip.show();
        break;
      case 110 :
        colorWipe(strip.Color(255,   0,   0), BLINK_DELAY);
        colorWipe(strip.Color(0,   0,   0), BLINK_DELAY);
        strip.show();
        break;
    }
    delay (22);
  }
}

void colorWipe(uint32_t color, int wait) {
  for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
  }
  strip.show();                          //  Update strip to match
  delay(wait);                           //  Pause for a moment
}

// 0 to 255
void brighten() {
  uint16_t i, j;

  for (j = 5; j < BRIGHTNESS; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 0, 0, j);
    }
    strip.show();
    delay(10);
  }
  //delay(1500);
}

// 255 to 0
void darken() {
  Serial.begin(9600);
  uint16_t i, j;

  for (j = BRIGHTNESS; j > 5; j--) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 0, 0, j);
    }
    strip.show();
    delay(10);
    Serial.println(j);
  }
  delay(1500);
}
