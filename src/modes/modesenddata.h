#ifndef _MODESENDDATA_
#define _MODESENDDATA_

#define TIMER 0.01// Em horas

extern void connectWiFi();
extern void readNetwork();
extern void checkButton();
extern void startSensor();
extern int readSensor();
extern String createJsonCapacityLog(int distance);
extern int convertMM(int mm);

void configStation();
void loopSendInfo();

extern Network network;
extern const char* endpoint_log;

void configStation() {
  
  Serial.println("Carregando informações da NVS.....");
  readNetwork();
  readIdentifier();
  readSettings();

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

    int porcent = convertMM(distance);
    Serial.print("Porcentagem: ");
    Serial.print(porcent);
    Serial.println(" %");

    String jsonData = createJsonCapacityLog(porcent);
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