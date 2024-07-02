#include <Arduino.h>
#include <config.hpp>

Adafruit_ST7789 screen = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void clear() {
  screen.fillScreen(ST77XX_BLACK);
  screen.setCursor(0, 10);
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

void DisplaySetup()  {
    Serial.begin(115200);
    initialise();
}



