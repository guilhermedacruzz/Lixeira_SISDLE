#ifndef _JSON_
#define _JSON_

extern Identifier identifier;
extern Settings settings;

String createJsonData() {

    String jsonData = "{";

    jsonData.concat("\"local\":\"");
    jsonData.concat(settings.local);
    jsonData.concat("\",");

    jsonData.concat("\"description\":\"");
    jsonData.concat(settings.description);
    jsonData.concat("\",");

    jsonData.concat("\"distanceBottom\":");
    jsonData.concat(settings.distanceBottom);
    jsonData.concat(",");

    jsonData.concat("\"distanceCover\":");
    jsonData.concat(settings.distanceCover);
    jsonData.concat(",");

    jsonData.concat("\"latitude\":");
    jsonData.concat(settings.latitude);
    jsonData.concat(",");

    jsonData.concat("\"longitude\":");
    jsonData.concat(settings.longitude);

    jsonData.concat("}");

    return jsonData;
}

String createJsonCapacityLog(int distance) {

    String jsonData = "{";

    jsonData.concat("\"_id\":\"");
    jsonData.concat(identifier.cod);
    jsonData.concat("\",");

    jsonData.concat("\"distance\":");
    jsonData.concat(distance);

    jsonData.concat("}");

    return jsonData;
}

#endif