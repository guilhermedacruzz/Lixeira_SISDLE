#ifndef _NVS_
#define _NVS_

// Prótótipos
bool hasDataStored();

// Extensões
extern Preferences preferences;

// Verifica se existe alguma configuração salva na lixeira
bool hasDataStored() {
  preferences.begin("sisdle", false);

  String ssid = preferences.getString("id");

  preferences.end();

  return !ssid.compareTo("") == 0;
}

#endif