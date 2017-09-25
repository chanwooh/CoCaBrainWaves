#include <Adafruit_NeoPixel.h>
#include <elapsedMillis.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(108, PIN, NEO_GRB + NEO_KHZ800);

int const NUM_PIXELS = 108;

void setup() {
  strip.begin();
}

void loop() {

  const uint32_t blank = strip.Color(0, 0, 0);
  const uint32_t yellow = strip.Color(255, 255, 0);
  const uint32_t green = strip.Color(0, 255, 0);
  const uint32_t blue = strip.Color(0, 0, 255);
  const uint32_t white = strip.Color(255, 255, 255);
  const uint32_t red = strip.Color(255, 0, 0);

  // Day time
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(yellow, blank, 5000, 1000); // Yellow
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(green, yellow, 10000, 1000); // Green & Yellow
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(green, blank, 5000, 1000); // Green
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(blue, blank, 30000, 1000); // Blue
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(green, blank, 40000, 1000); // Green
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(white, blank, 40000, 1000); // White
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(green, blank, 80000, 1000); // Green
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(blue, blank, 120000, 1000); // Blue

  // Sleep time
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(green, yellow, 2000, 1000); // Green & Yellow
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(yellow, red, 8000, 1000); // Yellow & Red
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(red, blank, 10000, 1000); // Red
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(yellow, red, 4000, 1000); // Yellow & Red
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(green, blank, 3000, 1000); // Green
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(yellow, red, 8000, 1000); // Yellow & Red
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(red, blank, 10000, 1000); // Red
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(yellow, red, 6000, 1000); // Yellow & Red
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(green, blank, 5000, 1000); // Green
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(green, yellow, 1000, 1000); // Green & Yellow
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(yellow, red, 11000, 1000); // Yellow & Red
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(red, blank, 5000, 1000); // Red
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(yellow, red, 9000, 1000); // Yellow & Red
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(green, blank, 7000, 1000); // Green
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(yellow, red, 11000, 1000); // Yellow & Red
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(red, blank, 7000, 1000); // Red
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(green, blank, 10000, 1000); // Green
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(green, yellow, 1000, 1000); // Green & Yellow
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(yellow, red, 11000, 1000); // Yellow & Red
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(green, blank, 11000, 1000); // Green
  changeColor(blank, blank, 0, 0); // Wipe
  changeColor(yellow, red, 7000, 1000); // Yellow & Red
}

static void changeColor(uint32_t primColor, uint32_t secColor, float delayValue, float flickerValue) {
  unsigned long start = millis();
  unsigned long current = millis();
  unsigned long elapsed = current - start;

  do {
    
    for(uint16_t i=0; i<NUM_PIXELS; i++) {
        strip.setPixelColor(i, primColor); // Draw new pixel
    }
  
    strip.show();
    
    delay(flickerValue);

    for(uint16_t i=0; i<NUM_PIXELS; i++) {
        strip.setPixelColor(i, secColor); // Draw new pixel
    }

    if (flickerValue != 0) { strip.show(); }
    delay(flickerValue);

    current = millis();
    elapsed = current - start;

  } while (elapsed < delayValue);
}
