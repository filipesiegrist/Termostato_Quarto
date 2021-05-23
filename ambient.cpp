#ifndef __AMBIENT_CPP__
#define __AMBIENT_CPP__

#include <Arduino.h>

#include "ambient.h"

#define DEBUG_MAX_TEMP_INPUT 7
#define DEBUG_MIN_TEMP_INPUT 8


Ambient::Ambient(DHT *dht_sensor, float max_value, float min_value, bool debug=false) {
	sensor = dht_sensor;
	max_temperature = max_value;
	min_temperature = min_value;
	if (debug) {
		configDebugMode();
	}
}

float Ambient::getTemperature(void) {
	return sensor->readTemperature();
}

bool Ambient::hasOverTemperature(void) {
	if (debug)
		return (!digitalRead(DEBUG_MAX_TEMP_INPUT));
	else
		return (getTemperature() > max_temperature);
}

bool Ambient::hasUnderTemperature(void) {
	if (debug)
		return (!digitalRead(DEBUG_MIN_TEMP_INPUT));
	else
		return (getTemperature() < min_temperature);
}

void Ambient::configDebugMode(void) {
	pinMode(DEBUG_MAX_TEMP_INPUT, INPUT_PULLUP);
	pinMode(DEBUG_MIN_TEMP_INPUT, INPUT_PULLUP);
	debug = true;
}

#endif
