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


void handleRoot() 

{

 String s =  webpage;

 server.send(200, "text/html", s);

}


void sensor_data() 

{


  
String sensor_value = String(ph);
 

  
 server.send(200, "text/plane", sensor_value);

}

void dht_data() 

{


  
String sensor_valueT = String(temp);
 

  
 server.send(200, "text/plane", sensor_valueT );

}

void dht_data_hum() 

{


  
String sensor_valueH = String(hum);
 

  
 server.send(200, "text/plane", sensor_valueH );

}



void setup(void)

{

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  Serial.println("");



  

  while (WiFi.status() != WL_CONNECTED)

  {

    Serial.print("Connecting...");

  }

  Serial.println("");

  Serial.print("Connected to ");

  Serial.println(ssid);

  Serial.print("IP address: ");

  Serial.println(WiFi.localIP());

 

  server.on("/", handleRoot);

  

  server.on("/adcread", sensor_data);
  server.on("/adcread1",dht_data);
  server.on("/adcread2",dht_data_hum);
  server.begin();
    // Starts the serial communication

  pinMode(potPin,INPUT);
  delay(1000);

}


void loop(void)

{

  server.handleClient();
   // Clears the trigPin
  Value= analogRead(potPin);
    Serial.print(Value);
    Serial.print(" | ");
    float voltage=Value*(3.3/4095.0);
    ph=(3.3*voltage);
    
    Serial.println(ph);
    
     DHT.read(DHT11_PIN);
  Serial.print("temp:");
  temp = DHT.temperature;
  Serial.print(DHT.temperature);
  Serial.print("  humi:");
  hum = DHT.humidity;
  Serial.println(DHT.humidity);
  delay(500);
  
}








