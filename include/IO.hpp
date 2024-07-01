#include <Arduino.h>
#include <config.hpp>

AdafruitIO_Feed *temperaturefeed = io.feed("tempreading");
AdafruitIO_Feed *humidityfeed = io.feed("humidreading");

void handleMessagetemp(AdafruitIO_Data *data);
void handleMessagehumid(AdafruitIO_Data *data);


void IOSetup() {
    Serial.begin(115200);
    while(! Serial);
    io.connect();
     // set up a message handler for the location feed.
    temperaturefeed->onMessage(handleMessagetemp);
    humidityfeed->onMessage(handleMessagehumid);

    while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
    }
    Serial.println(io.statusText());
    temperaturefeed->get();
    humidityfeed->get();
}

void IOLoop() {
    io.run();
    if (io.status() > AIO_CONNECTED) {
        temperaturefeed->save(tempreading);
        humidityfeed->save(humidreading);
    }
}

void handleMessagetemp(AdafruitIO_Data *data) {
    char* received_tempreading = data->value();
}

void handleMessagehumid(AdafruitIO_Data *data) {
    char* received_humidreading = data->value();
}
