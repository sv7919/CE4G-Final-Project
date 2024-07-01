#include <Arduino.h>
#include <GPSFunc.hpp>
#include <BME688.hpp>
#include <IO.hpp>

/**
 * @brief Add your Adafruit username, password, and your wifi and password
 * 
 */

void setup () {
    //GPSSetup();
    BMESetup();
    IOSetup();
}

void loop() {
    //GPSLoop();

    delay(5000);
    BMELoop();
    delay(5000);
    IOLoop();
}