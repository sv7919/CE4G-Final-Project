#include <Arduino.h>
#include <GPSFunc.hpp>
#include <BME688.hpp>
#include <AQI.hpp>
#include <IO.hpp>
#include <Display.hpp>

/**
 * @brief Add your Adafruit username, password, and your wifi and password
 * 
 */

String c = ",";

void setup () {
    //GPSSetup();
    //BMESetup();
    AQISetup();
    IOSetup();
    DisplaySetup();
}

void loop() {
    /**
     * @brief the while loop makes sure the GPS is fully initialized before running the rest of the code otherwise it never happens
     */
    //while (! GPS.fix) {
        //GPSLoop();
    //}

    //GPSLoop();
    //Serial.println();
    //delay(5000);

    //BMELoop();
    //Serial.println();
    //delay(5000);

    AQILoop();
    Serial.println();
    delay(5000);

    stats = String(String(lat) + c + String(lon) + c + String(ele) + c + String(tempreading) + c + String(humidreading) + c + String(pressreading) + c + String(aqireading));
    clear();
    screen.print(stats);
    delay(5000);

    IOLoop();
    if (io.status() >= AIO_CONNECTED) {
        Serial.println("AdafruitIO dashboard updated");
    }
    delay(5000);
}