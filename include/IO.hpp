#include <Arduino.h>
#include <config.hpp>

AdafruitIO_Feed *coordstrfeed2 = io.feed("weather-2");

void handleMessagecoordstr(AdafruitIO_Data *data);


void IOSetup() {
    Serial.begin(115200);
    while(! Serial);
    io.connect();
    coordstrfeed2->onMessage(handleMessagecoordstr);

    while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
    }
    Serial.println(io.statusText());
    coordstrfeed2->get();
}

void IOLoop() {
    io.run();
    if (io.status() >= AIO_CONNECTED) {
        coordstrfeed2->save(stats, lat, lon, ele);
    }
}

void handleMessagecoordstr(AdafruitIO_Data *data) {
    String received_coordstrreading2 = data->value();
}