#include <SPI.h>
#include <EEPROM.h>
#include "ArduboyLowMem.h"
#include "CascadePathGame.h"

ArduboyLowMem display;
CascadePathGame Game(&display);

void setup() {
//Serial.begin(9600);
  display.begin();
  Game.Begin();
}
void loop() {

  Game.Cycle();

}