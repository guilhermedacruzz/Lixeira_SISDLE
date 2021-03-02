#ifndef _SENSOR_
#define _SENSOR_

#define DEAD_AREA 50.0  // Área em que o sensor não funciona corretamente
#define MAX_DISTANCE 270.0 // Distancia máxima de leitura
#define MAX_FAILURE 10 // Número máximo de falhas permitas, antes de acusar um possível erro no sensor

void startSensor();
int readSensor();
float convertMMinPorcent(int distance);

extern Adafruit_VL53L0X lox; // Objeto Sensor

int failure_counter = 0; // Contador de falhas do sensor

// Responsável por Inicializar o Sensor
void startSensor() {
  if (!lox.begin()) { // tenta inicializar o sensor
    Serial.println(F("Falha ao Tentar Inicializar o Sensor"));
    while(1);
  }
}

// Responsável por Ler as Distãncias e retorna-las
int readSensor() {
  VL53L0X_RangingMeasurementData_t measure; // variável que armazena a leitura

  Serial.print("Reading... ");
  lox.rangingTest(&measure, false); // faz a leitura

  if(measure.RangeStatus == 4){ // Verifica se houve alguma falha
    failure_counter++;
    return -1;
  }

  failure_counter = 0;
  return measure.RangeMilliMeter;
}

void sensorFailures() {
  if (failure_counter >= MAX_FAILURE)
    Serial.println("Possível falha no sensor");
}

// Responsável por converter as distâncias para porcentagem
float convertMMinPorcent(int distance) {
  return (1 - (distance-DEAD_AREA) / (MAX_DISTANCE-DEAD_AREA)) * 100; // Função responsável pela converção
}

#endif