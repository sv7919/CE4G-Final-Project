#ifndef CONFIG_HPP
#define CONFIG_HPP

// visit io.adafruit.com if you need to create an account,
// or if you need your Adafruit IO key.
#define IO_USERNAME  ""
#define IO_KEY       ""

/******************************* WIFI **************************************/

#define WIFI_SSID ""
#define WIFI_PASS ""

#include "AdafruitIO_WiFi.h"

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"
#include <Adafruit_GPS.h>
#include <AdafruitIO.h>
#include <Adafruit_GFX.h> 
#include <Adafruit_ST7789.h> 
#include <SPI.h>
#include <cstdint>
#include <Wire.h>
#include "Adafruit_SGP40.h"

float tempreading;
float humidreading;
float pressreading;
float aqireading;

double lat;
double lon;
double ele;

String stats;

#endif // CONFIG_HPP
