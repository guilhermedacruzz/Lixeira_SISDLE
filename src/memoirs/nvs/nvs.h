#ifndef _NVS_
#define _NVS_

// Prótótipos
bool hasConfigSave(const char* value);
void clearNVS();

// Extensões
extern Preferences preferences;

bool hasConfigSave(const char* value) {
  preferences.begin("sisdle", false);

  String result = preferences.getString(value);

  preferences.end();

  return !result.compareTo("") == 0;
}

// Limpa os dados da NVS
void clearNVS() {
  preferences.begin("sisdle", false);

  preferences.clear();

  preferences.end();
}

#endif