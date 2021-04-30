#ifndef _MODECONFIGDATA_
#define _MODECONFIGDATA_

void configServerApSta();
void loopServerConfig();
bool checkInfo();

extern void deserializeDataJson(String data);
extern void writeSettings();
extern void writeNetwork();

extern const char* assid;
extern const char* asecret;

AsyncWebServer server(80);
bool status = false; 

void configServerApSta() {
  Serial.println("Iniciando modo de configuração!");
  WiFi.mode(WIFI_MODE_AP);

  Serial.println("Criando ponto de acesso....");
  WiFi.softAP(assid,asecret);

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
  
  if(status) {    // Ver como reiniciar melhor
    delay(2000);

    Serial.println("Escrevendo as configurações na memória permanente.....");
    writeSettings();
    writeNetwork();

    server.end();
    WiFi.disconnect();
    
    Serial.println("Configurações salvas com sucesso...");
    Serial.println("Reiniciando....");
    delay(500);
    ESP.restart();
  }
}

#endif