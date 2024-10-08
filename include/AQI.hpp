#include <Wire.h>
#include "Adafruit_SGP40.h"

Adafruit_SGP40 sgp;


void AQISetup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); } // Wait for serial console to open!

  Serial.println("SGP40 test");

  if (! sgp.begin()){
    Serial.println("Sensor not found :(");
    while (1);
  }
  Serial.print("Found SGP40 serial #");
  Serial.print(sgp.serialnumber[0], HEX);
  Serial.print(sgp.serialnumber[1], HEX);
  Serial.println(sgp.serialnumber[2], HEX);
}

int counter = 0;
void AQILoop() {
  uint16_t index;
  
  index = sgp.measureVocIndex();

  Serial.print("Measurement: ");
  Serial.println(index);
  delay(1000);
}