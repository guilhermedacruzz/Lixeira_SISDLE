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
  // WiFi.disconnect();
    WiFi.reconnect();
    Serial.println(WiFi.status());
  }
}

void configKey() {

    Serial.println("Carregando informações da NVS.....");
    readSettings();
    readNetwork();

    delay(2000);
    Serial.println("Iniciando o Wifi....");
    WiFi.disconnect();
    WiFi.mode(WIFI_STA);
    WiFi.setAutoReconnect(true);
    WiFi.begin(network.ssid.c_str(), network.password.c_str());

    reconnectWiFi();

    delay(2000);
}

void loopGetApikey() {
    reconnectWiFi();
    
    Serial.println("Enviando informações para a API..");
    Serial.print("URL: ");
    Serial.println(endpoint_create);

    String jsonData = createJsonData();
    Serial.print("JSON: ");
    Serial.println(jsonData);
    String response = httpPost(endpoint_create, jsonData);
    Serial.print("RESPOSTA: ");
    Serial.println(response);

    if(!response.compareTo("") == 0) {
        deserializeIdentifier(response);
        writeIdentifier();

        Serial.println("Identificador da lixeira gravado com sucesso!");
        Serial.println("Reiniciando....");
        delay(2000);
        ESP.restart();
    }

    delay(2000);
}


#endif