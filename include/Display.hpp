#include <Arduino.h>
#include <config.hpp>

//Subclass of ST77XX class specific to the ST7789 driver
Adafruit_ST7789 screen = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void clear() { //clears the screen
  screen.fillScreen(ST77XX_BLACK); //Find out what tft_cs, tft_dc, tft_rst mean
  screen.setCursor(0, 10);
}

void initialise() { //code that initializes the screen on the microcontroller
  pinMode(TFT_BACKLITE, OUTPUT);
  digitalWrite(TFT_BACKLITE, HIGH); // Turns on the LCD screen backlight
  pinMode(TFT_I2C_POWER, OUTPUT); 
  digitalWrite(TFT_I2C_POWER, HIGH); //Turns on the I2C communication
  delay(10);

  screen.init(135, 240); //sets the length and width of the screen
  screen.setRotation(3); //sets the desired orientation
  clear(); //calls the clear screen function
  screen.setTextSize(3); //sets font size

  screen.setTextColor(ST77XX_WHITE); //sets font color
}

void DisplaySetup()  {
    Serial.begin(115200);
    initialise();
}


