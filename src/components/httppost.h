#ifndef _HTTPPOST_
#define _HTTPPOST_

String httpPost(String endpoint, String info);

String httpPost(String endpoint, String info) {
    String response = "";
    if(WiFi.status()== WL_CONNECTED){
  
        HTTPClient http;   
        
        http.begin(endpoint); 
        http.addHeader("Content-Type", "application/json"); 
        
        int httpResponseCode = http.POST(info); 
        
        if(httpResponseCode>0) {
            response = http.getString();   
        
            Serial.println(httpResponseCode); 
            Serial.println(response);

        } else{
        
            Serial.print("Erro: ");  
            
            Serial.println(httpResponseCode);
        
        }
        
        http.end();
    } else {
        Serial.println("Sem conexão WiFi");   
    }

    return response;
}
#endif