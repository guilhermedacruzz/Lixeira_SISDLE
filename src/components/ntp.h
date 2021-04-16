#ifndef _NTP_
#define _NTP_

void startTimer();
void getTimer();

extern WiFiUDP ntpUDP;
extern NTPClient timeClient;

void startTimer() {
    timeClient.begin();
}

void getTimer() {
    timeClient.update();
    Serial.println(timeClient.getFormattedTime());
}

#endif