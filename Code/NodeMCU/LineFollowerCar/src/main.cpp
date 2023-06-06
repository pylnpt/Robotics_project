#include <Arduino.h>
#include <WiFi.h>
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"


const char* ssid     = "LineFollowingCar";
const char* password = "";
AsyncWebServer server(80);

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  if (!SPIFFS.begin(true)) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/index.html", String());
  });

  server.on("/index.css", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/index.css", "text/css");
  });
    
  server.on("/robocar.jpg", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/robocar.jpg", "image/jpg");
  });

  server.on("/powerON", HTTP_GET, [](AsyncWebServerRequest * request) {
    if(request->hasParam("character")){
      String character = request->getParam("character")->value();
      Serial.print(character);
      request->send(200, "text/plain", "Character sent to Arduino.");
    } else {
      request->send(400, "text/plain", "Missing character parameter.");
    }
    
  });

  server.on("/powerOFF", HTTP_GET, [](AsyncWebServerRequest * request) {
     if(request->hasParam("character")){
      String character = request->getParam("character")->value();
      Serial.print(character);
      request->send(200, "text/plain", "Character sent to Arduino.");
    } else {
      request->send(400, "text/plain", "Missing character parameter.");
    }
  });


  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}