#ifndef _MODESENDDATA_
#define _MODESENDDATA_

#define TIMER 0.01// Em horas

extern void readNetwork();
extern void checkButton();
extern void startSensor();
extern int readSensor();
extern String createJsonCapacityLog(int distance);
extern void reconnectWiFi();

void configStation();
void loopSendInfo();

extern Network network;
const char* endpoint_log = "http://jsonplaceholder.typicode.com/posts";

void configStation() {
  
  readNetwork();
  readIdentifier();

  WiFi.mode(WIFI_STA);
  WiFi.setAutoReconnect(true);

  WiFi.begin(network.ssid.c_str(), network.password.c_str());

  startSensor();
  reconnectWiFi();
}

void loopSendInfo() {
  reconnectWiFi();

  int distance = readSensor();

  String jsonData = createJsonCapacityLog(distance);
  Serial.println(jsonData);
  String response = httpPost(endpoint_log, jsonData);

  int cont = 0;
  while(cont <= TIMER * 3600) {
    checkButton();
    cont++;
    delay(1000);
    Serial.println(cont);
  }
}

#endif