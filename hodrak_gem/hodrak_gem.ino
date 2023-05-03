#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel. Avoid connecting
// on a live circuit... if you must, connect GND first.

void setup() {
  strip.begin();
  strip.show(); // initialize all pixels to "off"
}

void loop() {
  brighten();
  darken();
}

// 0 to 255
void brighten() {
  uint16_t i, j;

  for (j = 25; j < 80; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, j, 0, j);
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

  for (j = 80; j > 25; j--) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, j, 0, j);
    }
    strip.show();
    delay(10);
    Serial.println(j);
  }
  delay(1500);
}
