#include <ESP8266WiFi.h>

#include <WiFiClient.h>

#include <ESP8266WebServer.h>

#include "gamer.h"
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 4
const int potPin=A0;
float ph;
float Value=0;
float temp;
float hum;



const char* ssid = "hippo";

const char* password = "samurai123";

ESP8266WebServer server(80);








void setup()

{

  
    // Starts the serial communication
  Serial.begin(9600);
  pinMode(potPin,INPUT);
  

}
int flag=0;
void header(){

Serial.println("PH,TEMPERATURE,HUMIDITY");
flag=1;
}

void loop(void)

{
if(flag == 0){
  header();
}
  
   // Clears the trigPin
  Value= analogRead(potPin);
   // Serial.print(Value);
    
    float voltage=Value*(3.3/4095.0);
    ph=(3.3*voltage);
    Serial.print(ph);
    Serial.print(",");
    
     DHT.read(DHT11_PIN);
  //Serial.print(" temp:");
  temp = DHT.temperature;
  Serial.print(DHT.temperature);
  Serial.print(",");
  hum = DHT.humidity;
  Serial.println(DHT.humidity);
  delay(5000);
  
}








