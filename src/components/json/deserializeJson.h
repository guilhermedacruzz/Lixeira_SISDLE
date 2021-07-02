#ifndef _DESERIALIZEJSON_
#define _DESERIALIZEJSON_

// Protótipos de Função 
void deserializeDataJson(String data);
void deserializeIdentifier(String data);

extern Identifier identifier;
extern Settings settings;
extern Network network;

// Deserializa a post http recebido pelo APP de configuração
void deserializeDataJson(String data) {
  DynamicJsonDocument doc(1024);

  deserializeJson(doc, data);

  JsonObject obj = doc.as<JsonObject>();

  String ssid = obj["ssid"];
  String pass = obj["password"];
  String latitude = obj["latitude"];
  String longitude = obj["longitude"];

  String local = obj["local"];
  String description = obj["description"];
  String distanceBottom = obj["distanceBottom"];
  String distanceCover = obj["distanceCover"];

  network.ssid = ssid;
  network.password = pass;

  settings.latitude = latitude;
  settings.longitude = longitude;
  settings.local = local;
  settings.description = description;
  settings.distanceBottom = distanceBottom;
  settings.distanceCover = distanceCover;
}

// Deserializa a resposta do patch http de requisição do identificador
void deserializeIdentifier(String data) {
  DynamicJsonDocument doc(1024);

  deserializeJson(doc, data);

  JsonObject obj = doc.as<JsonObject>();

  String cod = obj["id"];

  identifier.cod = cod;
}

#endif