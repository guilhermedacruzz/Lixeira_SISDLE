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

// O setup roda apenas uma vez quando o programa inicia, parecido com o construtor em java...
void setup() {
  Serial.begin(115200);

  startButton();

}

//Após sair do setup ele vai ficar executando o código dentro do loop até
//fechar o programa.
void loop() {

}