#ifndef __HEATER_CPP__
#define __HEATER_CPP__

#include <Arduino.h>
#include "heater.h"


Heater::Heater(unsigned int out_pin) {
	pin = out_pin;
	pinMode(out_pin, OUTPUT);
}

void Heater::turnOn(void) {
	digitalWrite(pin, HIGH);
}

void Heater::turnOff(void) {
	digitalWrite(pin, LOW);
}

#endif
