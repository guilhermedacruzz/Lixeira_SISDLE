#ifndef _SENSOR_
#define _SENSOR_

#include "Adafruit_VL53L0X.h"

void startSensor();
int readSensor();

Adafruit_VL53L0X lox = Adafruit_VL53L0X();// Objeto Sensor

bool sensor_status = true;

// Responsável por Inicializar o Sensor
void startSensor() {
  if (!lox.begin()) { // tenta inicializar o sensor
    Serial.println(F("Falha ao Tentar Inicializar o Sensor"));
    sensor_status = false;
  }
}

// Responsável por Ler as Distãncias e retorna-las
int readSensor() {

  int result = -1;

  if(sensor_status) {
    VL53L0X_RangingMeasurementData_t measure; // variável que armazena a leitura

    lox.rangingTest(&measure, false); // faz a leitura

    if(measure.RangeStatus == 4)
      return result;

    result = measure.RangeMilliMeter;
  }

  return result;
}

#endif