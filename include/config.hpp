//This branch is solely for GPS related things 
#include <Adafruit_GPS.h>

// Connect to the GPS on the hardware I2C port
Adafruit_GPS GPS(&Wire);
#define GPSECHO false