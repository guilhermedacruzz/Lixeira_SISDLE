#ifndef _NVS_
#define _NVS_

// Prótótipos
bool hasDataStoredNVS();
void clearNVS();
void writeNVS();
void readNVS();

// Extensões
extern Preferences preferences;
extern Data data_config;

// Verifica se existe alguma configuração salva na lixeira
bool hasDataStoredNVS() {
  preferences.begin("sisdle", false);

  String ssid = preferences.getString("status");

  preferences.end();

  return !ssid.compareTo("") == 0;
}

// Limpa os dados da NVS
void clearNVS() {
  preferences.begin("sisdle", false);

  preferences.clear();

  preferences.end();
}

// Escreve novas informações na NVS
void writeNVS() {
  preferences.begin("sisdle", false);

  String ssid = data_config.ssid;
  String pass = data_config.password;


  Serial.println(ssid);
  Serial.println(pass);

  preferences.putString("status", "statdus");
  preferences.putString("id", ssid);
  preferences.putString("password", pass);

  preferences.end();
}

// Lê as informações da NVS
void readNVS() {
  preferences.begin("sisdle", false);

  data_config.ssid = preferences.getString("id");
  data_config.password = preferences.getString("password");

  preferences.end();
}

#endif