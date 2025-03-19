#include <ESP8266WiFi.h>

#include <ArduinoJson.h>
#include <WiFiUdp.h>
#include <HttpClient.h>
#include <Bridge.h>

// WiFi Parameters
const char ssid[] = "Siri";    //network SSID (name) 
const char pass[] = "!gmr2424";    //network password
int status = WL_IDLE_STATUS;
HttpClient client;  //Object of class HTTPClient

IPAddress ip(192, 168, 0, 110); 
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

void setup() {
 WiFi.disconnect();
Serial.begin(115200);
WiFi.config(ip, gateway, subnet);
WiFi.begin(ssid, pass);
WiFi.mode(WIFI_STA);


while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop() {
  // Check WiFi Status
  if (WiFi.status() == WL_CONNECTED) {

    client.get("https://api.thingspeak.com/channels/840354/fields/1.json?api_key=ZFFT2O3KYEF2LE1O&results=1");
//    int httpCode = http.GET();
  //  Serial.println(httpCode);
    //Check the returning code                                                                  
    
      // Parsing
      const size_t bufferSize = JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(8) + 370;
      DynamicJsonDocument doc(bufferSize);
      JsonObject root = doc.to<JsonObject>();

      // Parameters
      int id = root["field1"]; 
      // Output to serial monitor
      Serial.print("field1:");
      Serial.println(id);
    
//    http.end();   //Close connection
  }

}
