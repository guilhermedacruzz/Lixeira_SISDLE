// Importes
#include <Arduino.h>
#include <Preferences.h>
#include <ArduinoJson.h>
#include "components/button.h"
#include "entities/data.h"
#include "entities/json.h"
#include "memoirs/nvs.h"

// Protótipos de Função 

// button.h
extern void startButton();
extern bool checkButton();
// nvs.h
extern bool hasDataStoredNVS();
extern void clarNVS();
extern void writeNVS();
extern void readNVS();
// json.h
extern void deserializeDataJson(String dados_recebidos);

// Pinos
const int button_pin = 13;

// Dados de Configuração da Placa
Data dados_config;

// Objetos
Preferences preferences;

// O setup roda apenas uma vez quando o programa inicia, parecido com o construtor em java...
void setup() {
  Serial.begin(115200);

  startButton();

}

//Após sair do setup ele vai ficar executando o código dentro do loop até
//fechar o programa.
void loop() {

}