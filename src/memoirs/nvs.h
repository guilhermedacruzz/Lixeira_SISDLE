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

  String ssid = preferences.getString("id");

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

  preferences.putString("id", data_config.ssid);
  preferences.putString("password", data_config.password);

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