#ifndef _NVSIDENTIFIER_
#define _NVSIDENTIFIER_

void writeIdentifier();
void readIdentifier();

extern Preferences preferences;
extern Identifier identifier;

void writeIdentifier() {
  preferences.begin("sisdle", false);

  preferences.putString("apikey", identifier.cod);

  preferences.end();
}

void readIdentifier() {
  preferences.begin("sisdle", false);

  identifier.cod = preferences.getString("apikey");

  preferences.end();
}

#endif