#ifndef CONFIG_HPP
#define CONFIG_HPP
//defines the config before the complier reads it

// visit io.adafruit.com if you need to create an account,
// or if you need your Adafruit IO key.
#define IO_USERNAME  "" 
#define IO_KEY       ""

/******************************* WIFI **************************************/
// Wifi is needed for the connection of all of the microcontrollers and between Adafruit and the master microcontroller

#define WIFI_SSID ""
#define WIFI_PASS ""

#include "AdafruitIO_WiFi.h"

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS); 

//Includes
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"
#include <Adafruit_GPS.h>
#include <AdafruitIO.h>
#include <Adafruit_GFX.h> 
#include <Adafruit_ST7789.h> 
#include <cstdint>
#include "Adafruit_SGP40.h"

/**
 * @brief float variables that can be used anywhere in the code
 * 
 */
float tempreading; 
float humidreading;
float pressreading;
float aqireading;


/**
 * @brief double variables for the GPS and that can be used anywhere in the code
 * 
 */
double lat;
double lon;
double ele;

//A string that contains all of the statistics that will be sent to Adafruit IO
String stats;

#endif // CONFIG_HPP
