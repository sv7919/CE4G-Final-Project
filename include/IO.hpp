#include <Arduino.h>
#include <config.hpp>

AdafruitIO_Feed *coordstrfeed1 = io.feed("weather-1");

void handleMessagecoordstr(AdafruitIO_Data *data);


void IOSetup() {
    Serial.begin(115200);
    while(! Serial);
    io.connect();
    coordstrfeed1->onMessage(handleMessagecoordstr);

    while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
    }
    Serial.println(io.statusText());
    coordstrfeed1->get();
}

void IOLoop() {
    io.run();
    if (io.status() >= AIO_CONNECTED) {
        coordstrfeed1->save(stats, lat, lon, ele);
    }
}

void handleMessagecoordstr(AdafruitIO_Data *data) {
    String received_coordstrreading = data->value();
}