#ifndef _NVSNETWORK_
#define _NVSNETWORK_

// Protótipos de Função 
void writeNetwork();
void readNetwork();

// Extensões
extern Preferences preferences;
extern Network network;

// Escreve as configurações de WiFi na NVS
void writeNetwork() {
  preferences.begin("sisdle", false);

  preferences.putString("id", network.ssid);
  preferences.putString("password", network.password);

  preferences.end();
}

// Lê as configurações de WiFi na NVS
void readNetwork() {
  preferences.begin("sisdle", false);

  network.ssid = preferences.getString("id");
  network.password = preferences.getString("password");

  preferences.end();
}

#endif