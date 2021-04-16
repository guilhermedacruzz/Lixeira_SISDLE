#ifndef _MODESENDDATA_
#define _MODESENDDATA_

extern void readNetwork();
extern void checkButton();
extern void startSensor();
extern int readSensor();
extern void startTimer();
extern String createJsonCapacityLog(int distance);
extern void getTimer();

extern void reconnectWiFi();
extern Network network;

void configStation();
void loopSendInfo();

void configStation() {
  
  readNetwork();

  WiFi.mode(WIFI_STA);
  WiFi.setAutoReconnect(true);

  WiFi.begin(network.ssid.c_str(), network.password.c_str());

  startSensor();
  startTimer();
  reconnectWiFi();
}

void loopSendInfo() {
  reconnectWiFi();

  int distance = readSensor();

  String jsonData = createJsonCapacityLog(distance);
  Serial.println(jsonData);

  getTimer();
  
  delay(1000);
}

#endif