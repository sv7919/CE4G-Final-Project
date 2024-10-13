#include <Wire.h>
#include "Adafruit_SGP40.h"

Adafruit_SGP40 sgp;


void AQISetup() { // Sets up the AQI attachment 
  Serial.begin(115200);
  while (!Serial) { delay(10); } // Wait for serial console to open!

  Serial.println("SGP40 test");

  if (! sgp.begin()){ // If it cannot find the AQI sensor or if it fails to setup then a error message is run
    Serial.println("Sensor not found :(");
    while (1);
  }
  Serial.print("Found SGP40 serial #"); 
  Serial.print(sgp.serialnumber[0], HEX);
  Serial.print(sgp.serialnumber[1], HEX);
  Serial.println(sgp.serialnumber[2], HEX);
}


void AQILoop() { // the loop that runs everytime it is called
  uint16_t index; // unsigned 16-bit integer
  
  index = sgp.measureVocIndex(); //in-built function that measures the VOC index thatis calculated by takes the temperature and humdity objects that are read from the other attachments

  Serial.print("Measurement: ");
  Serial.println(index); //prints the VOC(Volatile Organic Compounds) index
  delay(1000);
}