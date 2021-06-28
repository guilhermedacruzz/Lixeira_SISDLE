#ifndef _MODEAPIKEY_
#define _MODEAPIKEY_

extern void connectWiFi();
extern void readNetwork();
extern String httpPost(String endpoint, String info);
extern String createJsonData();

void loopGetApikey();
void configKey();

extern Network network;
extern const char* endpoint_create;

void configKey() {

    Serial.println("Carregando informações da NVS.....");
    readSettings();
    readNetwork();

    connectWiFi();
}

void loopGetApikey() {
    
    if(WiFi.status() == WL_CONNECTED) {
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
}


#endif