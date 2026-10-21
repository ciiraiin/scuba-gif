#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "bitmapscuba.h"

#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDR   0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDR)) for(;;);
  display.clearDisplay();
  display.display();
}

void loop() {
  static uint8_t idx = 0;
  static unsigned long t = 0;
  const uint8_t* frames[] = {
    frame0, frame1, frame2, frame3, frame4, frame5, frame6, frame7, frame8, frame9, frame10, frame11, frame12, frame13, 
    frame14, frame15, frame16, frame17, frame18, frame19, frame20, frame21, frame22, frame23, frame24, frame25, frame26, frame27};
  
  if (millis() - t >= 100) {
    t = millis();
    display.clearDisplay();
    display.drawBitmap(0, 0, frames[idx], 128, 64, SSD1306_WHITE);
    display.display();
    idx = (idx + 1) % 28;
  }
}