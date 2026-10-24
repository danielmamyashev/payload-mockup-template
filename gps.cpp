#include "gps.h"

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static TinyGPSPlus gps;
static SoftwareSerial gpsSerial(4, 3);

void initGps() {
  gpsSerial.begin(9600);
}

void readGps(float &lat, float &lng, float &alt, int &sat) {
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }

  lat = gps.location.lat();
  lng = gps.location.lng();
  alt = gps.altitude.meters();
  sat = gps.satellites.value();

}
