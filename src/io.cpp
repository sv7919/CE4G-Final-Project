#include <config.hpp>

// init
void handleMessage(AdafruitIO_Data *data);

AdafruitIO_Feed *location1 = io.feed("Fill in");
AdafruitIO_Feed *location2 = io.feed("Fill in");

void conAdaIO() {
    Serial.print("Connecting to Adafruit IO");
    io.connect();

    while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
    }

    // we're connected sigmas
    Serial.println();
    Serial.println(io.statusText());
}

// io necessities of loop
void ioLoop() {
    io.run();
}

// uploads GPS location to IO
void upLocation() {
    
}

// uploads BME weather data to IO
void upBME() {

}

// calcs average values of BME data
void calc() {
    
}

