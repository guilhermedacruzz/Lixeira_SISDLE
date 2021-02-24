#ifndef _CONFIGDATA_
#define _CONFIGDATA_

void configServerApSta();
void serverEscutarCliente();
String verificarInfo();

extern void deserializeDataJson(String dados_recebidos);

extern const char* assid;
extern const char* asecret;

extern Data data_config;

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


void serverEscutarCliente() {
  WiFiClient client = server.available();
 
  if (client.connected() && webSocketServer.handshake(client)) {

    String data;
 
    while (client.connected()) {
 
      data = webSocketServer.getData();

      if(data.length() > 0) {
        Serial.println(data);
        deserializeDataJson(data);
        //String z = verificarInfo(obj);
        webSocketServer.sendData("OK");
      }
    
      delay(10);
   }

   Serial.println("The client disconnected");
   delay(100);
  }
}

String verificarInfo() {

  Serial.print("connecting to... ");
  Serial.println(data_config.ssid);

  WiFi.begin(data_config.ssid.c_str(), data_config.password.c_str());

  int cont = 0;
  int MAX = 20;

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");

    if(cont == MAX)
      return "Erro";

    cont++;
  }

  Serial.println("\nÉ possível concectar............");
  WiFi.disconnect();

  return "Ok";
}


#endif