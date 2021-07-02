#ifndef _NVSSETTINGS_
#define _NVSSETTINGS_

// Protótipos de Função 
void writeSettings();
void readSettings();

extern Preferences preferences;
extern Settings settings;

// Escreve as configurações da lixeira na NVS
void writeSettings() {
  preferences.begin("sisdle", false);

  preferences.putString("latitude", settings.latitude);
  preferences.putString("longitude", settings.longitude);

  preferences.putString("local", settings.local);
  preferences.putString("description", settings.description);

  preferences.putString("distanceBottom", settings.distanceBottom);
  preferences.putString("distanceCover", settings.distanceCover);

  preferences.end();
}

// Lê as configurações da lixeira na NVS
void readSettings() {
  preferences.begin("sisdle", false);

  settings.latitude = preferences.getString("latitude");
  settings.longitude = preferences.getString("longitude");

  settings.local = preferences.getString("local");
  settings.description = preferences.getString("description");
  
  settings.distanceBottom = preferences.getString("distanceBottom");
  settings.distanceCover = preferences.getString("distanceCover");

  preferences.end();
}

#endif