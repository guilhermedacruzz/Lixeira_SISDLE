// Importes
#include <Arduino.h>
#include <WiFi.h>
#include <Preferences.h>
#include <ArduinoJson.h>

#include "entities/identifier.h"
#include "entities/network.h"
#include "entities/settings.h"
#include "utils/sensor.h"
#include "utils/httppost.h"
#include "utils/button.h"
#include "memoirs/nvs/nvs.h"
#include "memoirs/nvs/nvsIdentifier.h"
#include "memoirs/nvs/nvsNetwork.h"
#include "memoirs/nvs/nvsSettings.h"
#include "utils/json/createJson.h"
#include "utils/json/deserializeJson.h"
#include "utils/reconnectWiFi.h"
#include "utils/calculatePorc.h"
#include "modes/modeconfigdata.h"
#include "modes/modeapikey.h"
#include "modes/modesenddata.h"

// Extensões de Função 
extern void startButton();
extern void checkButton();
extern bool hasConfigSave(const char* value);
extern void configServerApSta();
extern void loopServerConfig();
extern void configKey();
extern void loopGetApikey();
extern void configStation();
extern void loopSendInfo();

typedef void(*pont_func)(void); // Ponteiro para a função que vai ser executada no loop

// Pinos
const int button_pin = 13; // Pino do botão

// Dados Rede Modo AP
const char* assid = "Teste12345"; // Nome da rede Wifi que a lixeira irá criar
const char* asecret = "12345678"; // Senha da rede Wifi que a lixeira irá criar
const char* endpoint_create = "http://192.168.100.68:3000/lixeira?"; // url do patch de criação da lixeira
const char* endpoint_log = "http://192.168.100.68:3000/capacity?"; // url do post de logs da capacidade

// Dados de Configuração da Placa
Network network;
Settings settings;
Identifier identifier;
pont_func pt;

// Objetos
Preferences preferences;

// O setup roda apenas uma vez quando o programa inicia, parecido com o construtor em java...
void setup() {
  Serial.begin(115200);

  startButton(); // Inicializa o Botão
  
  bool nvs = hasConfigSave("id"); // Verifica se tem alguma configuração de wifi, distância etc salva
  
  if(!nvs) {
    configServerApSta(); // Configura o server e o Wifi no mode de Acess Point
    pt = &loopServerConfig; 

  } else {
    bool isApi = hasConfigSave("apikey"); // Verifica se a tem algum Identificador Salvo

    if(!isApi) {
      configKey(); // Configura o Wifi para pedir o identificador
      pt = &loopGetApikey;
    } else {
      configStation(); // Configura o Wifi No modo Station para enviar os dados do sensor.
      pt = &loopSendInfo;
    }
  }
}

//Após sair do setup ele vai ficar executando o código dentro do loop até
//fechar o programa.
void loop() {
  
  pt();

  checkButton(); // Verifica se o botão de reset foi pressionado e reseta a lixeira
  
}
