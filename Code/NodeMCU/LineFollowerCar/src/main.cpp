#include <Arduino.h>
#include <WiFi.h>
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"


const char* ssid     = "LineFollowingCar";
const char* password = "";
AsyncWebServer server(80);
const int pwmPin = 5; 
const int pwmChannel = 0; // PWM channel number

void setup() {
  pinMode(pwmPin, OUTPUT);
  ledcSetup(pwmChannel, 5000, 8); // Set PWM frequency to 5 kHz and resolution to 8 bits
  ledcAttachPin(pwmPin, pwmChannel); // Attach PWM channel to the pin
  
  Serial1.begin(9600);
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

  
  server.on("/setAnalogValue", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("value")) {
      int analogValue = request->getParam("value")->value().toInt();
       analogWrite(pwmPin, analogValue);
      // ledcWrite(pwmChannel, analogValue);
      // request->send(200, "text/html", "Analog value set");
      request->send(SPIFFS, "/index.html", String());
    } else {
      request->send(400, "text/html", "Invalid request");
    }
  });


  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here: