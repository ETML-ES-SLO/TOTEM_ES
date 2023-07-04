#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 2

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(256, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code


  strip.begin();
  strip.setBrightness(100);
  strip.show(); // Initialize all pixels to 'off'
}
int i = 64;
int t = 0;
int t1 = 0;
int t2 = 0;
void loop() {

  
  strip.setPixelColor(i+2,0,255,0);
  strip.setPixelColor(i+3,0,255,0);
  strip.setPixelColor(i+4,0,255,0);
  strip.setPixelColor(i+12,0,255,0);
  strip.setPixelColor(i+14,0,255,0);
  strip.setPixelColor(i+16,0,255,0);
  strip.setPixelColor(i+19,0,255,0);
  strip.setPixelColor(i+30,0,255,0);
  strip.setPixelColor(i+28,0,255,0);
  strip.setPixelColor(i+34,0,255,0);
  strip.setPixelColor(i+35,0,255,0);
  strip.setPixelColor(i+36,0,255,0);

  i = 0;
  for (int u = 0;u <= 47;u++)
  {
    strip.setPixelColor(i+u,255,0,0);
  }
  strip.setPixelColor(i+0,0,0,0);
  strip.setPixelColor(i+23,0,0,0);
  strip.setPixelColor(i+22,0,0,0);
  strip.setPixelColor(i+24,0,0,0);
  strip.setPixelColor(i+25,0,0,0);
  strip.setPixelColor(i+19,0,0,0);
  strip.setPixelColor(i+18,0,0,0);
  strip.setPixelColor(i+28,0,0,0);
  strip.setPixelColor(i+29,0,0,0);
  strip.setPixelColor(i+47,0,0,0);

  i = 112;
  for (int u = 0;u <= 47;u++)
  {
    strip.setPixelColor(i+u,255,255,255);
  }
  strip.setPixelColor(i+0,0,0,0);
  strip.setPixelColor(i+23,0,0,0);
  strip.setPixelColor(i+22,0,0,0);
  strip.setPixelColor(i+24,0,0,0);
  strip.setPixelColor(i+25,0,0,0);
  strip.setPixelColor(i+19,0,0,0);
  strip.setPixelColor(i+18,0,0,0);
  strip.setPixelColor(i+28,0,0,0);
  strip.setPixelColor(i+29,0,0,0);
  strip.setPixelColor(i+47,0,0,0);

i = 192;
  for (int u = 0;u <= 47;u++)
  {
    strip.setPixelColor(i+u,Wheel((255/47*u)+t));
  }
  strip.setPixelColor(i+0,0,0,0);
  strip.setPixelColor(i+23,0,0,0);
  strip.setPixelColor(i+22,0,0,0);
  strip.setPixelColor(i+24,0,0,0);
  strip.setPixelColor(i+25,0,0,0);
  strip.setPixelColor(i+19,0,0,0);
  strip.setPixelColor(i+18,0,0,0);
  strip.setPixelColor(i+28,0,0,0);
  strip.setPixelColor(i+29,0,0,0);
  strip.setPixelColor(i+47,0,0,0);

  t ++;
  if (t >= 256)
  {
    t = 0;
    t1 ++;
    if (t1 >=5)
    {
      t1 = 0;
      switch(t2)
      {
        case 0:
        {
          t2 = 1;
          strip.setBrightness(5);
          break;
        }
        case 1:
        {
          t2 = 2;
          strip.setBrightness(10);
          break;
        }
        case 2:
        {
          t2 = 0;
          strip.setBrightness(50);
          break;
        }
      }
    }
  }
  strip.show();

  delay(1);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
