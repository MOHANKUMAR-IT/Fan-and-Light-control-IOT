#include <ESP8266WiFi.h>
#include <string.h>
WiFiServer server(23);
void setup()
{
  Serial.begin(15200);
  pinMode(2,OUTPUT);
  pinMode(0,OUTPUT);
  digitalWrite(2,HIGH);
  digitalWrite(0,HIGH);
  WiFi.begin("FTTH-2CC3", "StrongPixel1090");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  Serial.println("connected to wifi");
  Serial.println("Waiting for client....");
  server.begin();
}
void loop() {
  
  
  WiFiClient client = server.available();
  if (client)
    { while (client.connected()) {
      Serial.println("connected to client");
        char data = '5';
        while(client.available()) {
          data = client.read();          
          }
          Serial.println(data);
          if(data=='1'){
            digitalWrite(2,LOW);
          }
          else if(data=='0'){
            digitalWrite(2,HIGH);
          }
          else if(data=='2'){
            digitalWrite(0,LOW);
          }
          else if(data=='3'){
            digitalWrite(0,HIGH);
          }     
      }
    }
  }
