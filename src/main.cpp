#include <Arduino.h>
#include <config.hpp>

void handleMessage(AdafruitIO_Data *data);

AdafruitIO_Feed *location1 = io.feed("Fill in");
AdafruitIO_Feed *location2 = io.feed("Fill in");

void setup() {
  Serial.begin(115200);

  // wait for serial monitor to open
  while (!Serial);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // set up a message handler for the 'button_f' feed.
  // the handleMessage function (defined below)
  // will be called whenever a message is
  // received from adafruit io.

  /**
   * @attention uncomment the line below when you want to use it for input data to be sent to dashboard (buttons, switches, etc.)
   *  led_f->onMessage(handleMessage); 
   */

  // wait for a connection
  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
}

void loop() {
    io.run();

}