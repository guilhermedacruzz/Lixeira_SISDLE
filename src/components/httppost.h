#ifndef _HTTPPOST_
#define _HTTPPOST_

#include <HTTPClient.h>

String httpPost(String endpoint, String info);

// Função por fazer o post http
String httpPost(String endpoint, String info) {
    String response = "";
    if(WiFi.status()== WL_CONNECTED){
  
        HTTPClient http;   
        
        http.begin(endpoint); 
        http.addHeader("Content-Type", "application/json"); 
        
        int httpResponseCode = http.POST(info); 
        
        if(httpResponseCode>0) {
            response = http.getString();   
        }
        
        http.end();
    }
    return response;
}
#endif