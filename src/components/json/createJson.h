#ifndef _JSON_
#define _JSON_

// Protótipos de Função 
String createJsonData();
String createJsonCapacityLog(int distance);

extern Identifier identifier;
extern Settings settings;

// Cria o json do patch de requisição do identificador
String createJsonData() {

    String jsonData = "{\"type\": \"Feature\", \"geometry\": {\"type\":\"Point\", \"coordinates\" : [";
    jsonData.concat(settings.latitude);
    jsonData.concat(",");
    jsonData.concat(settings.longitude);
    jsonData.concat("] }, \"properties\": {");
    jsonData.concat("\"location\":\"");
    jsonData.concat(settings.local);
    jsonData.concat("\", \"description\":\"");
    jsonData.concat(settings.description);
    jsonData.concat("\", \"capacity\":");
    jsonData.concat(0);
    jsonData.concat(", \"distanceCover\":");
    jsonData.concat(settings.distanceCover);
    jsonData.concat(", \"distanceBottom\":");
    jsonData.concat(settings.distanceBottom);
    jsonData.concat("}}");

    return jsonData;
}

// Cria o json das logs de capacidade
String createJsonCapacityLog(int distance) {

    String jsonData = "{";

    jsonData.concat("\"lixeira\":\"");
    jsonData.concat(identifier.cod);
    jsonData.concat("\",");

    jsonData.concat("\"capacity\":");
    jsonData.concat(distance);

    jsonData.concat("}");

    return jsonData;
}

#endif