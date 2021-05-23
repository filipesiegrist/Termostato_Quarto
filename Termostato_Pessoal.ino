#include <DHT.h>

#include "heater.h"
#include "ambient.h"

#define MAX_TEMPERATURE 28
#define MIN_TEMPERATURE 15

#define IN_PIN 6
#define OUT_PIN 3

DHT temperatureSensor(IN_PIN, DHT11);
Ambient room = Ambient(&temperatureSensor, MAX_TEMPERATURE, MIN_TEMPERATURE);
Heater myHeater = Heater(OUT_PIN);

void setup() {
	Serial.begin(9600);
	pinMode(OUT_PIN, OUTPUT);
	temperatureSensor.begin();
}

void loop() {
	Serial.println(room.getTemperature());
	if (room.hasOverTemperature())
		myHeater.turnOff();
	else if (room.hasUnderTemperature())
		myHeater.turnOn();
	delay(100);
}
