// Importes
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <WebSocketServer.h>
#include <Preferences.h>
#include <ArduinoJson.h>
#include "entities/data.h"
#include "components/json.h"
#include "modes/configdata.h"
#include "components/button.h"
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
// configdata.h
extern void configServerApSta();
extern void loopServerConfig();
extern void checkData();
extern bool checkInfo();
void a();

typedef void(*pont_func)(void);

// Pinos
const int button_pin = 13;

// Dados Rede Modo AP
const char* assid = "Teste12345";
const char* asecret = "12345678";

// Dados de Configuração da Placa
Data data_config;
pont_func pt;

// Objetos
Preferences preferences;
WiFiServer server;
WebSocketServer webSocketServer;

// O setup roda apenas uma vez quando o programa inicia, parecido com o construtor em java...
void setup() {
  Serial.begin(115200);

  startButton();  

  bool nvs = hasDataStoredNVS();

  if(!nvs) {
    configServerApSta();
    pt = &loopServerConfig;
  }
  else {
    WiFi.mode(WIFI_STA);
    Serial.println("já tem dados salvos");
    pt = &a;
  }
}

//Após sair do setup ele vai ficar executando o código dentro do loop até
//fechar o programa.
void loop() {
  
  pt();

  if(checkButton()) {
    Serial.println("Resetando....");
    clearNVS();
    ESP.restart();
  }
}

void a() {
  Serial.println("Enviando....");
  delay(1000);
}