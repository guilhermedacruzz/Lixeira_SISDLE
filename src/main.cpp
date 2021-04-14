// Importes
#include <Arduino.h>
#include <string.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "ESPAsyncWebServer.h"
#include <Preferences.h>
#include "Adafruit_VL53L0X.h"
#include <ArduinoJson.h>
#include "components/sensor.h"
#include "entities/data.h"
#include "memoirs/ntp.h"
#include "memoirs/nvs.h"
#include "components/json.h"
#include "modes/modeconfigdata.h"
#include "modes/modesenddata.h"
#include "components/button.h"

// Protótipos de Função 

// button.h
extern void startButton();
extern void checkButton();
// nvs.h
extern bool hasDataStoredNVS();
// modeconfigdata.h
extern void configServerApSta();
extern void loopServerConfig();
// modessenddata.h
extern void configStation();
extern void loopSendInfo();

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
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "a.st1.ntp.br", -3 * 3600, 60000);

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
    configStation();
    pt = &loopSendInfo;
  }
}

//Após sair do setup ele vai ficar executando o código dentro do loop até
//fechar o programa.
void loop() {
  
  pt();

  checkButton();

}
