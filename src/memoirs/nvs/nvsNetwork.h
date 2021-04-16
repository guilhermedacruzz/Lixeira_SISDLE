#ifndef _NVSNETWORK_
#define _NVSNETWORK_

void writeNetwork();
void readNetwork();

extern Preferences preferences;
extern Network network;

void writeNetwork() {
  preferences.begin("sisdle", false);

  preferences.putString("apikey", network.ssid);
  preferences.putString("apikey", network.password);

  preferences.end();
}

void readNetwork() {
  preferences.begin("sisdle", false);

  network.ssid = preferences.getString("id");
  network.password = preferences.getString("password");

  preferences.end();
}

#endif