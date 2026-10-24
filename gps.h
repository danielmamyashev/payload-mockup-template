#ifndef GPS_H
#define GPS_H

#include <Arduino.h>

void initGps();
void readGps(float &lat, float &lng, float &alt, int &sat);

#endif
