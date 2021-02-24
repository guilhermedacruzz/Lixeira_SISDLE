#include <Arduino.h>
#include "components/button.h"

const int button_pin = 13;


void setup() {
  Serial.begin(115200);

  Serial.print("Iniciando o Botão no GPIO ");
  Serial.println(button_pin);
  startButton(button_pin);
}

void loop() {
  Serial.print("Pressionou?");
  Serial.println(checkButton(button_pin));
  delay(1000);
}