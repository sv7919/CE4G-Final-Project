//This branch is solely for dashboard related things connected to Adafruit.IO
#ifndef CONFIG_HPP
#define CONFIG_HPP

// Fetch your key from Adafruit
#define IO_USERNAME "your username here"
#define IO_KEY "your key here"

/******************************* WIFI **************************************/

#define WIFI_SSID "your SSID here"
#define WIFI_PASS "your password here"

#include <AdafruitIO_WiFi.h>

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

#endif  