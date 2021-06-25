#ifndef _RECONNECTWIFI_
#define _RECONNECTWIFI_

extern Network network;

void connectWiFi();
void WiFiStationConnected(WiFiEvent_t event, WiFiEventInfo_t info);
void WiFiGotIP(WiFiEvent_t event, WiFiEventInfo_t info);
void WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t info);

void WiFiStationConnected(WiFiEvent_t event, WiFiEventInfo_t info){
  Serial.println("Connected to AP successfully!");
}

void WiFiGotIP(WiFiEvent_t event, WiFiEventInfo_t info){
  Serial.println("Conectado ao WiFi");
  Serial.println("IP: ");
  Serial.println(WiFi.localIP());
}

void WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t info){
  Serial.println("Desconectado....");
  Serial.print("Conexão perdida Reason: ");
  Serial.println(info.disconnected.reason);
  Serial.println("Aguarde Reconexão");
  WiFi.begin(network.ssid.c_str(), network.password.c_str());
}

void connectWiFi() {
    
  WiFi.disconnect(true);

  delay(1000);

  WiFi.onEvent(WiFiStationConnected, SYSTEM_EVENT_STA_CONNECTED);
  WiFi.onEvent(WiFiGotIP, SYSTEM_EVENT_STA_GOT_IP);
  WiFi.onEvent(WiFiStationDisconnected, SYSTEM_EVENT_STA_DISCONNECTED);

  WiFi.begin(network.ssid.c_str(), network.password.c_str());
    
  Serial.println();
  Serial.println();
  Serial.println("Aguarde pela conexão...");
}

#endif