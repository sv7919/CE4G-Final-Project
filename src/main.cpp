#include <Arduino.h> // Includes the Arduino Library so the microcontroller can talk to the other sensors
#include <GPSFunc.hpp> // Includes the code used to run the GPS attachment
#include <BME688.hpp>  //Includes the code used to run the BME688 sensor
#include <AQI.hpp>  // Includes the code used to run the AQI sensor
#include <IO.hpp>  // Includes to the code used to run the Adafruit IO readings and dashboard
#include <Display.hpp>

/**
 * @brief Add your Adafruit username, password, and your wifi and password
 * 
 */


void setup () {
    GPSSetup(); // Initializes the GPS attachment on the microcontroller
    BMESetup(); // Initializes the temperature sensor on the microcontroller
    AQISetup(); // Initializes the AQI sensor on the microcontroller
    IOSetup(); // Initializes the connection between the Adafruit IO website and the microcontroller
    DisplaySetup();
}

void loop() {
    /**
     * @brief the while loop makes sure the GPS is fully initialized before running the rest of the code otherwise the GPS will never initialize
     */
    while (! GPS.fix) {
        GPSLoop();
    }

    GPSLoop(); //Runs the GPS Loop found in GPSFunc.hpp
    Serial.println(); //Spacing
    delay(12000); //Waits 12 seconds before the next function is run because of our data limit for Adafruit IO

    BMELoop(); //Runs the BME Loop found in BME688.hpp
    Serial.println();
    delay(12000);

    AQILoop(); //Runs the AQI Loop found in AQI.hpp
    Serial.println();
    delay(12000);

    /* 
    Intitializing our stats and prints out our statistics that we have collected so far
    */
    stats = String(String(lat) + "," + String(lon) + "," + String(ele) + "," + String(tempreading) + "," + String(humidreading) + "," + String(pressreading) + "," + String(aqireading));
    clear();
    screen.print(stats);
    delay(12000);

    IOLoop(); //Runs the IO function in IO.hpp that connects us to our dashboard in Adafruit IO
    if (io.status() >= AIO_CONNECTED) { //If it is connected
        Serial.println("AdafruitIO dashboard updated"); //Then we get a message on the console saying that the dashboard got updated
    }
    delay(12000);
    
    /*
    Continuously runs the function over and over for a live feed of temperature, location, elevation, AQI, and air pressure
    */
}