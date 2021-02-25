#ifndef _MODESENDDATA_
#define _MODESENDDATA_

extern void readNVS();

extern Data data_config;

void configStation();
void reconnectWiFi();
void funcLoopEnviarInfo();

void configStation() {
  readNVS();
  WiFi.mode(WIFI_STA);

  WiFi.begin(data_config.ssid.c_str(), data_config.password.c_str());

  reconnectWiFi();
}

void reconnectWiFi() {
  if(WiFi.status() == WL_CONNECTED) 
    return;

  while (WiFi.status() != WL_CONNECTED) { 
    delay(500);
    // Lembre de colcoar o botão de reset aqui
    Serial.println("Connectando a Rede WiFi..");

  }

  Serial.println("Conectado!");
  Serial.println(WiFi.localIP());
}

void loopSendInfo() {
  Serial.println("Enviando info.....");
  reconnectWiFi();
  delay(1000);
}

#endif