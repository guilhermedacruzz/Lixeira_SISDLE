#ifndef _MODECONFIGDATA_
#define _MODECONFIGDATA_

// Ao iniciar a lixera cria um rede WiFi
// Em seguida, o Usuário abre o aplicativo de configuração, preenche o formulário e clica em enviar.
// A lixeira recebe esses dados e grava na memória.

#include "ESPAsyncWebServer.h"

// Protótipos de Função 
void configServerApSta();
void loopServerConfig();
bool checkInfo();

// Extensões de Função 
extern void deserializeDataJson(String data);
extern void writeSettings();
extern void writeNetwork();

// Extensões
extern const char* assid;
extern const char* asecret;

AsyncWebServer server(80);
bool status = false; 

void configServerApSta() {
  Serial.println("Iniciando modo de configuração!");
  WiFi.mode(WIFI_MODE_AP); // Modifica o modo do WiFi para Access Point

  Serial.println("Criando ponto de acesso....");
  WiFi.softAP(assid,asecret);

  // Inicializa o server que recebe das configurações
  server.on( 
    "/hello",
    HTTP_POST,
    [](AsyncWebServerRequest * request){},
    NULL,
    [](AsyncWebServerRequest * request, uint8_t *data, size_t len, size_t index, size_t total) {
      
      size_t i;
      char mensage[len];

      for (i = 0; i < len; i++) {
        mensage[i] = data[i];
      }
      mensage[i] = '\0';

      Serial.println(mensage); 
      deserializeDataJson(mensage);

      status = true;
      request->send(200, "text/plain", "Hello");
  });


  Serial.print("Iniciando server no ip: ");
  Serial.println(WiFi.softAPIP());

  server.begin();
}

void loopServerConfig() {
  
  if(status) {  // Verifica se recebeu alguma configuração
    delay(2000);

    Serial.println("Escrevendo as configurações na memória permanente.....");
    // Escreve os dados na memória permanente
    writeSettings();
    writeNetwork();

    server.end(); // Encerra o server
    WiFi.disconnect(); // Fecha o WiFi
    
    Serial.println("Configurações salvas com sucesso...");
    Serial.println("Reiniciando....");
    delay(500);
    ESP.restart(); // Reinicia
  }
}

#endif