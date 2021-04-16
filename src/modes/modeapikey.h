#ifndef _MODEAPIKEY_
#define _MODEAPIKEY_

extern void readNVS();
extern void reconnectWiFi();
extern String httpPost(String endpoint, String info);

void loopGetApikey();
void configKey();

extern Data data_config;

String endpoint = "http://jsonplaceholder.typicode.com/posts";
String info = "Funciona garai";

void configKey() {
    readNVS();

    WiFi.mode(WIFI_STA);
    WiFi.setAutoReconnect(true);
    WiFi.begin(data_config.ssid.c_str(), data_config.password.c_str());

    reconnectWiFi();
}

void loopGetApikey() {
    reconnectWiFi();
    
    String jsonData = createJsonData();
    Serial.println(jsonData);
    String response = httpPost(endpoint, info);
    Serial.println(response);

    if(!response.compareTo("") == 0) {
        dese(response);
        writeAPIKEY();
        delay(2000);
        ESP.restart();
        
    }

    delay(1000);
}


#endif