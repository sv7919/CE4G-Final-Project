#include <Arduino.h>
#include <config.hpp>

AdafruitIO_Feed *coordstrfeed1 = io.feed("weather-1"); //sets up the coordinate string feed for the first weather station

/**
 * @brief the function or method defintion is down below where the function is defined
 * 
 * @param data the class of "AdafruitIO_Data" that is stored in "data" through a pointer
 */
void handleMessagecoordstr(AdafruitIO_Data *data); 


void IOSetup() {
    Serial.begin(115200);
    while(! Serial); //waits for the serial to connect
    io.connect(); //The "Input/Output" class runs the connect function with the class
    coordstrfeed1->onMessage(handleMessagecoordstr); //Allows for the coordinate string to access the handle message function which contains the data in the AdafruitIO_Data class

    Serial.println("Waiting for connection with Adafruit IO");
    while(io.status() < AIO_CONNECTED) { //if the status function with in the IO class is "less than" or not connected 
        Serial.print("."); //print out a dot-dot-dot effect until connected
        delay(500);
    }
    Serial.println(io.statusText()); //prints out the status of the AIO value
    coordstrfeed1->get(); //publishes the coordinate stat string feed, currently null, to Adafruit IO 
}

void IOLoop() {
    io.run(); //keeps the connection to IO feed stable and up by refreshing the Wifi connection constantly
    if (io.status() >= AIO_CONNECTED) {
        coordstrfeed1->save(stats, lat, lon, ele); //saves the the current stats, latitude, longitude, and elevation to the coordinate string every minute because of when it is called in the main.cpp and to make sure we don't exceed the data limit
    }
}

void handleMessagecoordstr(AdafruitIO_Data *data) {
    String received_coordstrreading = data->value(); //converts values input in the coordinate string feed to characters so Adafruit can read it
}