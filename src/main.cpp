#include "Arduino.h"

void setup() {
	Serial.begin(115200);
	Serial1.begin(115200, SERIAL_8N1, 14, 15);
	Serial2.begin(115200, SERIAL_8N1, 16, 17);

	vTaskDelay(1000);
	Serial.println("Starting");
}

// USB TX --> RX Serial0 --> TX Serial0 --> RX Serial2 --> TX Serial2 --> RX Serial1 --> TX Serial1 --> TX Serial0   
void loop() {
	int c;
	if ((c = Serial.read()) > 0) {
		Serial2.println(static_cast<char>(c));
	}
	if ((c = Serial2.read()) > 0) {
		Serial1.println(static_cast<char>(c));
	}
	if ((c = Serial1.read()) > 0) {
		Serial.println(static_cast<char>(c));
	}
}