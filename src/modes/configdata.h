#ifndef _CONFIGDATA_
#define _CONFIGDATA_

extern const char* assid = "Teste12345";
extern const char* asecret = "12345678";

extern Data dados_config;

extern WiFiServer server;
extern WebSocketServer webSocketServer;

void configServerApSta() {
  WiFi.mode(WIFI_AP_STA);

  Serial.println("Criando ponto de acesso....");
  WiFi.softAP(assid,asecret,7,0,5);

  Serial.print("Endereço IP:\t");
  Serial.println(WiFi.softAPIP());

  server.begin();
}

#endif