#include <Arduino.h>
#include <config.hpp>

AdafruitIO_Feed *temperaturefeed = io.feed("temperature");
AdafruitIO_Feed *humidityfeed = io.feed("humidity");
AdafruitIO_Feed *pressurefeed = io.feed("pressure");
AdafruitIO_Feed *coordstrfeed = io.feed("coordinate-string");

void handleMessagetemp(AdafruitIO_Data *data);
void handleMessagehumid(AdafruitIO_Data *data);
void handleMessagepressure(AdafruitIO_Data *data);
void handleMessagecoordstr(AdafruitIO_Data *data);


void IOSetup() {
    Serial.begin(115200);
    while(! Serial);
    io.connect();
     // set up a message handler for the location feed.
    temperaturefeed->onMessage(handleMessagetemp);
    humidityfeed->onMessage(handleMessagehumid);
    pressurefeed->onMessage(handleMessagepressure);
    coordstrfeed->onMessage(handleMessagecoordstr);

    while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
    }
    Serial.println(io.statusText());
    temperaturefeed->get();
    humidityfeed->get();
    pressurefeed->get();
    coordstrfeed->get();
}

void IOLoop() {
    io.run();
    if (io.status() >= AIO_CONNECTED) {
        temperaturefeed->save(tempreading);
        humidityfeed->save(humidreading);
        pressurefeed->save(pressreading);
        coordstrfeed->save(stats, lat, lon, ele);
    }
}

void handleMessagetemp(AdafruitIO_Data *data) {
    char* received_tempreading = data->value();
}

void handleMessagehumid(AdafruitIO_Data *data) {
    char* received_humidreading = data->value();
}

void handleMessagepressure(AdafruitIO_Data *data) {
    char* received_pressreading = data->value();
}

void handleMessagecoordstr(AdafruitIO_Data *data) {
    String received_coordstrreading = data->value();

}