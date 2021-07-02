#ifndef _MODESENDDATA_
#define _MODESENDDATA_

//Nesse modo, a placa realiza a leitura dos sensores, o cálculo da capacidade e envia para a API

#define TIMER 0.01// Em horas

// Protótipos de Função 
void configStation();
void loopSendInfo();

extern void connectWiFi();
extern void readNetwork();
extern void checkButton();
extern void startSensor();
extern int readSensor();
extern String createJsonCapacityLog(int distance);
extern int convertMM(int mm);

extern Network network;
extern const char* endpoint_log;

void configStation() {
  
  Serial.println("Carregando informações da NVS.....");
  // Lê todas as configurações salvas
  readNetwork(); 
  readIdentifier();
  readSettings();

  Serial.println("Iniciando o sensor....");
  startSensor(); // Inicializa o sensor

  connectWiFi(); // Conecta ao WiFi
}

void loopSendInfo() {

  if(WiFi.status() == WL_CONNECTED) {
    int distance = readSensor(); // Realiza a leitura do sensor
    Serial.print("Leitura do Sensor: ");
    Serial.print(distance);
    Serial.println(" mm");

    int porcent = convertMM(distance); // Converte a leitura do sensor bruta em milímetros para a porcentagem da capacidade.
    Serial.print("Porcentagem: ");
    Serial.print(porcent);
    Serial.println(" %");

    String jsonData = createJsonCapacityLog(porcent); // Cria o json para o envio da capacidade
    Serial.print("JSON: ");
    Serial.println(jsonData);
    String response = httpPost(endpoint_log, jsonData); // Realiza o post da capacidade
    Serial.print("RESPOSTA: ");
    Serial.println(response);


  // Após todo esse processo a lixeira entra em loop até o timer acabar e realizar tudo de novo
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