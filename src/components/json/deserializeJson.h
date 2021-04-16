#ifndef _DESERIALIZEJSON_
#define _DESERIALIZEJSON_

extern Identifier identifier;
extern Settings settings;
extern Network network;

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

  network.ssid = ssid;
  network.password = pass;

  settings.latitude = latitude;
  settings.longitude = longitude;
  settings.local = local;
  settings.description = description;
  settings.distanceBottom = distanceBottom;
  settings.distanceCover = distanceCover;
}

void deserializeIdentifier(String dados_recebidos) {
  DynamicJsonDocument doc(1024);

  deserializeJson(doc, dados_recebidos);

  JsonObject obj = doc.as<JsonObject>();

  int cod = obj["id"];

  identifier.cod = "teste123";

  /*    Versão Final
  String cod = obj["_id"];

  identifier.cod = cod;
  */
}

#endif