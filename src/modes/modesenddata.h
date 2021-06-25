#ifndef _MODESENDDATA_
#define _MODESENDDATA_

#define TIMER 0.01// Em horas

extern void connectWiFi();
extern void readNetwork();
extern void checkButton();
extern void startSensor();
extern int readSensor();
extern String createJsonCapacityLog(int distance);

void configStation();
void loopSendInfo();

extern Network network;
const char* endpoint_log = "http://jsonplaceholder.typicode.com/posts";

void configStation() {
  
  Serial.println("Carregando informações da NVS.....");
  readNetwork();
  readIdentifier();

  Serial.println("Iniciando o sensor....");
  startSensor();

  connectWiFi();
}

void loopSendInfo() {

  if(WiFi.status() == WL_CONNECTED) {
    int distance = readSensor();
    Serial.print("Leitura do Sensor: ");
    Serial.print(distance);
    Serial.println(" mm");

    String jsonData = createJsonCapacityLog(distance);
    Serial.print("JSON: ");
    Serial.println(jsonData);
    String response = httpPost(endpoint_log, jsonData);
    Serial.print("RESPOSTA: ");
    Serial.println(response);


    Serial.println("Timer: ");
    int cont = 0;
    while(cont <= TIMER * 3600) {
      checkButton();
      cont++;
      delay(1000);
      Serial.println(cont);
    }
  }
}

#endif