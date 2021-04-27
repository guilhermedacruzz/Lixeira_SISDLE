#ifndef _JSON_
#define _JSON_

extern Identifier identifier;
extern Settings settings;

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
    jsonData.concat(-420);
    jsonData.concat(", \"distanceCover\":");
    jsonData.concat(settings.distanceCover);
    jsonData.concat(", \"distanceBottom\":");
    jsonData.concat(settings.distanceBottom);
    jsonData.concat("}}");

    return jsonData;
}

String createJsonCapacityLog(int distance) {

    String jsonData = "{";

    jsonData.concat("\"id\":\"");
    jsonData.concat(identifier.cod);
    jsonData.concat("\",");

    jsonData.concat("\"distance\":");
    jsonData.concat(distance);

    jsonData.concat("}");

    return jsonData;
}

#endif