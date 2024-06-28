//This branch is solely for the display components
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
#include <cstdint>

Adafruit_ST7789 screen = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

/**
 * @brief sets up the screen of the microcontroller
 * 
 */
void initialise();
void clear();

void setup() {
  Serial.begin(115200);
}

void initialise() {
  pinMode(TFT_BACKLITE, OUTPUT);
  digitalWrite(TFT_BACKLITE, HIGH);
  pinMode(TFT_I2C_POWER, OUTPUT);
  digitalWrite(TFT_I2C_POWER, HIGH);
  delay(10);

  screen.init(135, 240);
  screen.setRotation(3);
  clear();
  screen.setTextSize(3);

  screen.setTextColor(ST77XX_WHITE);
}

void clear() {
  screen.fillScreen(ST77XX_BLACK);
  screen.setCursor(0, 35);
}