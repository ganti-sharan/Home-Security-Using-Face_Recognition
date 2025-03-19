#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <Servo.h>
#include <WiFiUdp.h>


const char ssid[] = "Siri";    //network SSID (name) 
const char pass[] = "!gmr2424";    //network password
int status = WL_IDLE_STATUS;
WiFiClient  client;
Servo myservo;
const int FieldNumber = 1;
unsigned long myChannelNumber= 840354; //From the cloud
const char * myReadAPIKey = "ZFFT2O3KYEF2LE1O"; //From the cloud
const char * myWriteAPIKey = "MLVXSKHVG7EB7QQU";//To the cloud


void setup() {
WiFi.disconnect();
myservo.attach(2); //D4
Serial.begin(115200);

WiFi.begin(ssid, pass);

ThingSpeak.begin(client);


while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  ThingSpeak.begin( client );
}

void loop() {
  int statusCode = 0;
  myservo.write(0);
  int data= ThingSpeak.readIntField(myChannelNumber, FieldNumber , myReadAPIKey); //Connecting to the cloud
  statusCode = ThingSpeak.getLastReadStatus();
 if(statusCode == 200){
    Serial.println("Successfully Read the value");
  }
  else{
    Serial.print("error code = ");
     Serial.println(statusCode);
  }
 
  Serial.print("readValue = "); // debugging instrument
  Serial.println(data);
  
  //Serial.println("Doors Closed");
  if (data == 1)
      {
        myservo.write(90);
        Serial.println("Doors Open");
        delay(1000);
        myservo.write(0);
        Serial.println("Doors Closed");
        ThingSpeak.writeField(myChannelNumber, FieldNumber, 0, myWriteAPIKey);
        delay(10000);
        ThingSpeak.writeField(myChannelNumber, FieldNumber, 0, myWriteAPIKey);
        delay(20000);
        data=0;
      }
  else {
    delay(15000);
    }
 
   
  }
 
  
     

      
