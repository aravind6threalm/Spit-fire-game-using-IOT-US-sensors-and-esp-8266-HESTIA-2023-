#include <ESP8266WiFi.h>

#include <WiFiClient.h>

#include <ESP8266WebServer.h>

#include "gamer.h"


const int trigPin = 12;
const int echoPin = 14;

//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

const char* ssid = "Tesla";

const char* password = "hulk10000";

ESP8266WebServer server(80);


void handleRoot() 

{

 String s = webpage;

 server.send(200, "text/html", s);

}

int str =0;
void sensor_data() 

{

 
str = distanceCm;

 
 String sensor_value = String(str);
  
 server.send(200, "text/plane", sensor_value);

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

  server.begin();
    // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);

}


void loop(void)

{

  server.handleClient();
   // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;
  
  // Prints the distance on the Serial Monitor
 // Serial.print("Distance (cm): ");
 // Serial.println(distanceCm);
 // Serial.print("Distance (inch): ");
 // Serial.println(distanceInch);
  
  delay(10);
  
}


 


 
