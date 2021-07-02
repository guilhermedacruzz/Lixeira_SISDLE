#ifndef _MODEAPIKEY_
#define _MODEAPIKEY_

//Nesse modo, a placa solicita um identificador para a API e salva na memória

// Protótipos de Função 
void loopGetApikey();
void configKey();

extern void connectWiFi();
extern void readNetwork();
extern String httpPost(String endpoint, String info);
extern String createJsonData();

extern Network network;
extern const char* endpoint_create;

void configKey() {

    Serial.println("Carregando informações da NVS.....");
    readSettings(); // Lê as configurações salvas na memória
    readNetwork(); // Lê as configurações de wiFi salvas

    connectWiFi(); // Inicia a o WiFi
}

void loopGetApikey() {
    
    if(WiFi.status() == WL_CONNECTED) {
      Serial.println("Enviando informações para a API..");
      Serial.print("URL: ");
      Serial.println(endpoint_create);

      String jsonData = createJsonData(); // Cria o json do patch
      Serial.print("JSON: ");
      Serial.println(jsonData); 
      String response = httpPost(endpoint_create, jsonData); // Faz o patch para a api
      Serial.print("RESPOSTA: ");
      Serial.println(response);

      if(!response.compareTo("") == 0) { // verifica se obteve resposta
          deserializeIdentifier(response); // Deserializa a resposta
          writeIdentifier(); // Salva na memória permanente

          Serial.println("Identificador da lixeira gravado com sucesso!");
          Serial.println("Reiniciando....");
          delay(2000);
          ESP.restart(); // Reinicia
      }

      delay(2000);
    }
}


#endif