#ifndef _HTTPPOST_
#define _HTTPPOST_

void sendInfo(String server, String info);

void sendInfo(String server, String info) {
    if(WiFi.status()== WL_CONNECTED){
  
        HTTPClient http;   
        
        http.begin(server); 
        http.addHeader("Content-Type", "text/plain"); 
        
        int httpResponseCode = http.POST(info); 
        
        if(httpResponseCode>0) {
            String response = http.getString();   
        
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
}

#endif