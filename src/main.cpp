// Importes
#include <Arduino.h>
#include "components/button.h"

// Protótipos de Função 
extern void startButton();
extern bool checkButton();

// Pinos
const int button_pin = 13;

void setup() {
  Serial.begin(115200);

  startButton();
}

void loop() {
  Serial.print("Pressionou?");
  Serial.println(checkButton());
  delay(1000);
}