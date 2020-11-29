#include "Arduino.h"
#include "snake_start.h"

void setup() {
  Serial.begin(115200);
}

void loop(){
	snake_start(0);
}