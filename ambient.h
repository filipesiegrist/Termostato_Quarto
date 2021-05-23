#ifndef __AMBIENT_H__
#define __AMBIENT_H__

#include <DHT.h>

class Ambient {
public:
	DHT *sensor;
	float max_temperature;
	float min_temperature;
	bool debug;
	Ambient(DHT *dht_sensor, float max_value, float min_value, bool debug=false);
	float getTemperature(void);
	bool hasOverTemperature(void);
	bool hasUnderTemperature(void);
	void configDebugMode(void);
};

#endif