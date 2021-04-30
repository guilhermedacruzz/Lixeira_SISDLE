#ifndef _MODEAPIKEY_
#define _MODEAPIKEY_

extern void readNetwork();
extern String httpPost(String endpoint, String info);
extern String createJsonData();

void loopGetApikey();
void configKey();

extern Network network;

const char* endpoint_create = "http://192.168.100.68:3000/lixeira?";

void reconnectWiFi() {
  if(WiFi.status() == WL_CONNECTED) 
    return;

  while (WiFi.status() != WL_CONNECTED) { 
    delay(500);
    checkButton();
    Serial.println("Connectando a Rede WiFi..");
    WiFi.reconnect();
  }

  Serial.println("Conectado!");
  Serial.println(WiFi.localIP());
}

void configKey() {
    readSettings();
    readNetwork();

    WiFi.mode(WIFI_STA);
    WiFi.setAutoReconnect(true);
    WiFi.begin(network.ssid.c_str(), network.password.c_str());

    reconnectWiFi();

    delay(2000);
}

void loopGetApikey() {
    reconnectWiFi();
    
    String jsonData = createJsonData();
    Serial.println(jsonData);
    String response = httpPost(endpoint_create, jsonData);

    if(!response.compareTo("") == 0) {
        deserializeIdentifier(response);
        Serial.println(identifier.cod);
        writeIdentifier();
        delay(2000);
        ESP.restart();
    }

    delay(2000);
}


#endif