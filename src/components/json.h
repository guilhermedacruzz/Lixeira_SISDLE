#ifndef _JSON_
#define _JSON_

// Extensões
extern Data data_config;

// Protótipos
void deserializeDataJson(String dados_recebidos);

// Função que desserializa uma String Json
void deserializeDataJson(String dados_recebidos) {
  DynamicJsonDocument doc(1024);

  deserializeJson(doc, dados_recebidos);

  JsonObject obj = doc.as<JsonObject>();

  String ssid = obj["ssid"];
  String pass = obj["password"];

  String latitude = obj["latitude"];
  String longitude = obj["longitude"];

  data_config.ssid = ssid;
  data_config.password = pass;
  data_config.latitude = latitude;
  data_config.longitude = longitude;
}

#endif