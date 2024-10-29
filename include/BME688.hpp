#include <Arduino.h>
#include <config.hpp>

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10
Adafruit_BME680 bme; // I2C

void BMESetup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println(F("BME680 test"));

  if (!bme.begin()) { // If the sensor could not begin the process or it failed to find the correct attachments then it will stay in this loop
    Serial.println("Could not find a valid BME680 sensor, check wiring!");
    while (1);
  } else {
    Serial.println("BME680 found.");
  }

  // Set up oversampling and filter initialization
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // 320*C for 150 ms
}

void BMELoop() { //Initial loop
  if (! bme.performReading()) { //If the BME sensor cannot start its reading, then it will not continue the code
    Serial.println("Failed to perform reading :(");
    return;
  }

  /**
   * @brief The "bme." represents the in built Adafruit_BME680 class and connected to it are various objects that can be retrived from said class
   * It also has some global float variables created in the "config.hpp" file that every file has and will store them to be used in other .hpps
   * 
   */
  Serial.print("Temperature = ");
  tempreading = (bme.temperature * 1.8)+32; // Since it is given in Celsius and I couldn't find a command that would just give it to me in Fahrenheit I just made the conversion myself
  Serial.print(tempreading);
  Serial.println(" *F");

  Serial.print("Pressure = ");
  pressreading = bme.pressure/100; // The pressure sensor is a little strange due to the elevation above sea level, so we had to divide the pressure by 100 to get the correct pressure readings
  Serial.print(pressreading); 
  Serial.println(" hPa");

  Serial.print("Humidity = ");
  Serial.print(bme.humidity); //Again using the bme class, humidity is found because of the bme library that is on the computer and it is able to retrieve humidity easily without having to code soft and hardware
  humidreading = bme.humidity;
  Serial.println(" %");

  Serial.print("Gas = ");
  Serial.print(bme.gas_resistance / 1000.0); //Gas resistance must be divided by 1000 to show the accurate reading of it
  Serial.println(" KOhms");
}