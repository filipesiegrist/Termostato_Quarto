#ifndef __HEATER_H__
#define __HEATER_H__


class Heater {
public:
	unsigned int pin;
	Heater(unsigned int out_pin);
	void turnOn(void);
	void turnOff(void);
};

#endif