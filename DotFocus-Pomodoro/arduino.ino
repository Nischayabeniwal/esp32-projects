#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <math.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int centerX = SCREEN_WIDTH / 2;
const int centerY = SCREEN_HEIGHT / 2;

const int NUM_PLANETS = 4;

// Orbit radii: Mercury, Venus, Earth, Mars
const int orbitRadii[NUM_PLANETS] = {10, 18, 26, 34};

// Planet pixel sizes (relative sizes)
const int planetSizes[NUM_PLANETS] = {1, 2, 2, 1};

// Angular position and speed
float angles[NUM_PLANETS] = {0};
float speeds[NUM_PLANETS] = {0.15, 0.1, 0.075, 0.05};

void setup() {
  Wire.begin(32, 33);  // ESP32 I2C pins
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  display.clearDisplay();

  // Draw double pixel-thick border (two rectangles)
  display.drawRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
  

  // Draw the Sun in the center
  display.fillCircle(centerX, centerY, 3, WHITE);

  // Draw the 4 planets rotating
  for (int i = 0; i < NUM_PLANETS; i++) {
    float x = centerX + cos(angles[i]) * orbitRadii[i];
    float y = centerY + sin(angles[i]) * orbitRadii[i];

    display.fillCircle((int)x, (int)y, planetSizes[i], WHITE);

    angles[i] += speeds[i];
    if (angles[i] > TWO_PI) angles[i] -= TWO_PI;
  }

  display.display();
  delay(40);
}
