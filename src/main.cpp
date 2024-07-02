#include <Arduino.h>
#include <GPSFunc.hpp>
#include <BME688.hpp>
#include <IO.hpp>

/**
 * @brief Add your Adafruit username, password, and your wifi and password
 * 
 */

String c = ", ";

void setup () {
    GPSSetup();
    BMESetup();
    IOSetup();
}

void loop() {
    /**
     * @brief the while loop makes sure the GPS is fully initialized before running the rest of the code otherwise it never happens
     */
    while (! GPS.fix) {
        GPSLoop();
    }

    GPSLoop();
    Serial.println();
    delay(5000);

    BMELoop();
    Serial.println();
    delay(5000);

    IOLoop();
    /**
     * @brief Simply lets the user know the dashboard has been updated through the serial monitor
     */
    if (io.status() >= AIO_CONNECTED) {
        Serial.println("AdafruitIO dashboard updated");
    }
    delay(5000);

    // figure out how to send the string to Adafruit IO
    String coordinates = String(String(lat) + c + String(lon) + c + String(ele) + c + String(tempreading) + c + String(humidreading) + c + String(pressreading));
    Serial.println(coordinates);
    Serial.println();
    }
