// base
#include <Arduino.h>
#include <SPI.h>

// IO utilities
#ifndef CONFIG_HPP
#define CONFIG_HPP

#define IO_USERNAME "your username here"
#define IO_KEY "your key here"

#define WIFI_SSID "your SSID here"
#define WIFI_PASS "your password here"

#include <AdafruitIO_WiFi.h>

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

#endif  

// GPS utilities
#include <Adafruit_GPS.h>

// screen
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>