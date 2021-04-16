#ifndef _NVS_
#define _NVS_

// Prótótipos
bool hasConfigSave(const char* value);
void clearNVS();
void writeNVS();
void readNVS();

// Extensões
extern Preferences preferences;
extern Data data_config;


bool hasConfigSave(const char* value) {
  preferences.begin("sisdle", false);

  String result = preferences.getString(value);

  preferences.end();

  return !result.compareTo("") == 0;
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

  preferences.putString("local", data_config.local);
  preferences.putString("description", data_config.description);

  preferences.putString("distanceBottom", data_config.distanceBottom);
  preferences.putString("distanceCover", data_config.distanceCover);

  preferences.end();
}

// Lê as informações da NVS
void readNVS() {
  preferences.begin("sisdle", false);

  data_config.ssid = preferences.getString("id");
  data_config.password = preferences.getString("password");
  data_config.latitude = preferences.getString("latitude");
  data_config.longitude = preferences.getString("longitude");

  data_config.local = preferences.getString("local");
  data_config.description = preferences.getString("description");
  data_config.distanceBottom = preferences.getString("distanceBottom");
  data_config.distanceCover = preferences.getString("distanceCover");

  data_config.apikey = preferences.getString("apikey");

  preferences.end();
}

#endif