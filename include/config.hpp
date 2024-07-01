#ifndef CONFIG_HPP
#define CONFIG_HPP

// visit io.adafruit.com if you need to create an account,
// or if you need your Adafruit IO key.
#define IO_USERNAME  "YOUR_USERNAME"
#define IO_KEY       "YOUR_KEY"

/******************************* WIFI **************************************/

#define WIFI_SSID "YOUR_WIFI"
#define WIFI_PASS "YOUR_PASSWORD"

#include "AdafruitIO_WiFi.h"

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

//Merged branches: BME688 and GPS
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"
#include <Adafruit_GPS.h>
#include <AdafruitIO.h>

int tempreading;
int humidreading;


#endif // CONFIG_HPP

