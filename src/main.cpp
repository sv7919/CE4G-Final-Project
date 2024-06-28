#include <config.hpp>
#include <screen.cpp>
#include <io.cpp>
#include <gps.cpp>
#include <bme.cpp>

void setup() {
  Serial.begin(115200);
  while (!Serial);
  // display LED to show running
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  initScreen();
  conAdaIO();


}

void loop() {
    ioLoop();

}