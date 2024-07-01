#include <Arduino.h>
#include <GPSFunc.hpp>
#include <BME688.hpp>
#include <IO.hpp>

/**
 * @brief Add your Adafruit username, password, and your wifi and password
 * 
 */

String c = ",";

void setup () {
    GPSSetup();
    BMESetup();
    IOSetup();
}

void loop() {
    GPSLoop();
    Serial.println();
    delay(5000);
    BMELoop();
    Serial.println();
    delay(5000);
    IOLoop();
    if (io.status() >= AIO_CONNECTED) {
      Serial.println("AdafruitIO dashboard updated");
    }
    delay(5000);
    String coordinates = String(String(lat) + c + String(lon) + c + String(ele) + c + String(tempreading) + c + String(humidreading) + c + String(pressreading));
    Serial.println(coordinates);
}