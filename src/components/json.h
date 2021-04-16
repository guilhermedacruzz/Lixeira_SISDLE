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

  String local = obj["local"];
  String description = obj["description"];
  String distanceBottom = obj["distanceBottom"];
  String distanceCover = obj["distanceCover"];

  data_config.ssid = ssid;
  data_config.password = pass;
  data_config.latitude = latitude;
  data_config.longitude = longitude;

  data_config.local = local;
  data_config.description = description;
  data_config.distanceBottom = distanceBottom;
  data_config.distanceCover = distanceCover;
}

void dese(String dados_recebidos) {
  DynamicJsonDocument doc(1024);

  deserializeJson(doc, dados_recebidos);

  JsonObject obj = doc.as<JsonObject>();

  int apikey = obj["id"];
  Serial.println(apikey);

  data_config.apikey = "teste123";

  /*    Versão Final
  String apikey = obj["_id"];
  Serial.println(apikey);

  data_config.apikey = apikey;
  */
}

#endif