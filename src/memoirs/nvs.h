#include <iostream>
#include <string>

#ifndef _NVS_
#define _NVS_

// Prótótipos
bool hasDataStoredNVS();
bool hasAPIKEY();
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

bool hasAPIKEY() {
  preferences.begin("sisdle", false);

  String apikey = preferences.getString("apikey");

  preferences.end();

  return !apikey.compareTo("") == 0;
}

void writeAPIKEY() {
  preferences.begin("sisdle", false);

  preferences.putString("apikey", data_config.apikey);

  preferences.end();
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

  preferences.putString("latitude", data_config.latitude);
  preferences.putString("longitude", data_config.longitude);

  preferences.end();
}

// Lê as informações da NVS
void readNVS() {
  preferences.begin("sisdle", false);

  data_config.ssid = preferences.getString("id");
  data_config.password = preferences.getString("password");
  data_config.latitude = preferences.getString("latitude");
  data_config.longitude = preferences.getString("longitude");
  data_config.apikey = preferences.getString("apikey");

  preferences.end();
}

#endif