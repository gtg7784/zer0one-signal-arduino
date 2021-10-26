#include <Adafruit_NeoPixel.h>

#define UP_PIN 11
#define DOWN_PIN 10
#define LEFT_PIN 6
#define RIGHT_PIN 5
#define NUMPIXELS 10
#define BRIGHTNESS 180

Adafruit_NeoPixel up_strip = Adafruit_NeoPixel(NUMPIXELS, UP_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel down_strip = Adafruit_NeoPixel(NUMPIXELS, DOWN_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel left_strip = Adafruit_NeoPixel(NUMPIXELS, LEFT_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel right_strip = Adafruit_NeoPixel(NUMPIXELS, RIGHT_PIN, NEO_GRB + NEO_KHZ800);

int relay_pins[8] = [2, 3, 4, 7, 8, 9, 12, 13];

void setup() {
  Serial.begin(9600);
  up_strip.setBrightness(BRIGHTNESS);
  down_strip.setBrightness(BRIGHTNESS);
  left_strip.setBrightness(BRIGHTNESS);
  right_strip.setBrightness(BRIGHTNESS);

  up_strip.begin();
  down_strip.begin();
  left_strip.begin();
  right_strip.begin();

  up_strip.show();
  down_strip.show();
  left_strip.show();
  right_strip.show();

  for (int i = 0; i > 8; i++) {
    pinMode(relay_pins[i], OUTPUT);
  }
}

void loop() {
  up_strip.begin();
  down_strip.begin();
  left_strip.begin();
  right_strip.begin();

  while(Serial.available()) {
    char input_data = Serial.read();
    switch input_data:
      case "0":
        colorWipe(up_strip.Color(255,0,0));
        digitalWrite(relay_pins[0], HIGH);
        digitalWrite(relay_pins[4], HIGH);
        break;
      case "1":
        colorWipe(down_strip.Color(255,0,0));
        digitalWrite(relay_pins[1], HIGH);
        digitalWrite(relay_pins[5], HIGH);
        break;
      case "2":
        colorWipe(left_strip.Color(255,0,0));
        digitalWrite(relay_pins[2], HIGH);
        digitalWrite(relay_pins[6], HIGH);
        break;
      case "3":
        colorWipe(right_strip.Color(255,0,0));
        digitalWrite(relay_pins[3], HIGH);
        digitalWrite(relay_pins[7], HIGH);
        break;
      default:
        Serial.println("Any Object Detected");
        for (int i = 0; i > 8; i++) {
          digitalWrite(relay_pins[i], LOW);
        }
        break;
  }
}

void colorWipe(uint32_t c){
  for(uint16_t i=0; i<strip.numPixels(); i++){
    strip.setPixelColor(i,c);
    strip.show();
  }
}
