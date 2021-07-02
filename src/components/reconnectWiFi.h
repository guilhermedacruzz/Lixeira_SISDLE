#ifndef _RECONNECTWIFI_
#define _RECONNECTWIFI_

extern Network network;

void connectWiFi();
void WiFiStationConnected(WiFiEvent_t event, WiFiEventInfo_t info);
void WiFiGotIP(WiFiEvent_t event, WiFiEventInfo_t info);
void WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t info);

// Função disparada ao connectar ao WiFi
void WiFiStationConnected(WiFiEvent_t event, WiFiEventInfo_t info){
  Serial.println("Conectando ao WiFi!");
}

// Função disparada ao conseguir um Ip na Rede
void WiFiGotIP(WiFiEvent_t event, WiFiEventInfo_t info){
  Serial.println("Conectado ao WiFi");
  Serial.println("IP: ");
  Serial.println(WiFi.localIP());
}

// Função disparada ao desconnectar ao WiFi
void WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t info){
  Serial.println("Desconectado....");
  Serial.print("Conexão perdida Reason: ");
  Serial.println(info.disconnected.reason);
  Serial.println("Aguarde Reconexão");
  WiFi.begin(network.ssid.c_str(), network.password.c_str());
}

void connectWiFi() {
    
  WiFi.disconnect(true); // Tenta desconnectar do Wifi, apenas questão de segurança e limpeza

  delay(1000);

  // Configura os eventos do WiFi
  WiFi.onEvent(WiFiStationConnected, SYSTEM_EVENT_STA_CONNECTED);
  WiFi.onEvent(WiFiGotIP, SYSTEM_EVENT_STA_GOT_IP);
  WiFi.onEvent(WiFiStationDisconnected, SYSTEM_EVENT_STA_DISCONNECTED);

  WiFi.begin(network.ssid.c_str(), network.password.c_str()); // Inicia a conexão com o WiFi
  
  Serial.println("Aguarde pela conexão...");
}

#endif