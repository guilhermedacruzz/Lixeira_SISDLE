#ifndef _MODECONFIGDATA_
#define _MODECONFIGDATA_

void configServerApSta();
void loopServerConfig();
bool checkInfo();

extern void deserializeDataJson(String dados_recebidos);
extern void writeNVS();

extern const char* assid;
extern const char* asecret;

extern Data data_config;

AsyncWebServer server(80);
bool configOk = false;

void configServerApSta() {
  Serial.println("Iniciando modo de configuração!");
  WiFi.mode(WIFI_MODE_AP);

  Serial.println("Criando ponto de acesso....");
  WiFi.softAP(assid,asecret);

  Serial.print("Endereço IP:\t");
  Serial.println(WiFi.softAPIP());

  server.on(
    "/hello",
    HTTP_POST,
    [](AsyncWebServerRequest * request){},
    NULL,
    [](AsyncWebServerRequest * request, uint8_t *data, size_t len, size_t index, size_t total) {
      
      size_t i;
      char a[len];
      for (i = 0; i < len; i++) {
        a[i] = data[i];
      }
      a[i] = '\0';

      Serial.println(a);
      deserializeDataJson(a);

      configOk = true;
      request->send(200, "text/plain", "Hello");
  });
 
  server.begin();
}

void loopServerConfig() {
  
  if(configOk) {
    delay(2000);
    server.end();
    Serial.println("Escrevendo na NVS...");
    WiFi.disconnect();
    writeNVS();
    ESP.restart();
  }
}

#endif