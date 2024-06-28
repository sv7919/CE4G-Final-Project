//This branch is solely for dashboard related things connected to Adafruit.IO
#ifndef CONFIG_HPP
#define CONFIG_HPP

// Fetch your key from Adafruit
#define IO_USERNAME "Akasi132"
#define IO_KEY "aio_osAp68Jclb1TODubavvEWdwm2lp4"

/******************************* WIFI **************************************/

#define WIFI_SSID "bootlogger"
#define WIFI_PASS "arunachalam"

#include <AdafruitIO_WiFi.h>

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

#endif  
