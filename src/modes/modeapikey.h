#ifndef _MODEAPIKEY_
#define _MODEAPIKEY_

extern void readNVS();
extern void reconnect();

extern Data data_config;

void loopGetApikey();
void configKey();

void configKey() {
    readNVS();

    WiFi.mode(WIFI_STA);
    WiFi.setAutoReconnect(true);
    WiFi.begin(data_config.ssid.c_str(), data_config.password.c_str());

    reconnectWiFi();
}

void loopGetApikey() {
    Serial.println("hkdhfhf");

    reconnectWiFi();
}


#endif