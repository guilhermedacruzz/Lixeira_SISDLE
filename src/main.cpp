// Importes
#include <Arduino.h>
#include <Preferences.h>
#include "components/button.h"
#include "entities/data.h"
#include "memoirs/nvs.h"

// Protótipos de Função 

// button.h
extern void startButton();
extern bool checkButton();
// nvs.h
extern bool hasDataStored();
extern void limparNVS();
extern void escreverNVS();
extern void carregarInfoNVS();

// Pinos
const int button_pin = 13;

Data dados_config;

// Objetos
Preferences preferences;

void setup() {
  Serial.begin(115200);

  startButton();

  limparNVS();
  Serial.println(hasDataStored());
  dados_config.ssid = "ssid";
  dados_config.password = "password";
  escreverNVS();
  Serial.println(hasDataStored());
  carregarInfoNVS();
  Serial.println(dados_config.ssid);
  Serial.println(dados_config.password);

}

void loop() {

}