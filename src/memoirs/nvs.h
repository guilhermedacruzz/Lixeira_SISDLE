#ifndef _NVS_
#define _NVS_

// Prótótipos
bool hasDataStored();
void limparNVS();

// Extensões
extern Preferences preferences;

// Verifica se existe alguma configuração salva na lixeira
bool hasDataStored() {
  preferences.begin("sisdle", false);

  String ssid = preferences.getString("ssid");

  preferences.end();

  return !ssid.compareTo("") == 0;
}

void limparNVS() {
  preferences.begin("sisdle", false);
  preferences.clear();
  preferences.end();
}

void escreverNVS(Data* dados_config) {
  preferences.begin("sisdle", false);
  preferences.putString("ssid", dados_config->ssid);
  preferences.putString("password", dados_config->password);
  preferences.end();
}

#endif