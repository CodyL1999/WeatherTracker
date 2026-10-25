#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include "env.h"


void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClientSecure client;
  client.setInsecure();
  HTTPClient http;
  //pulls updated data from open meteo forecast
  http.begin(client, "https://api.open-meteo.com/v1/forecast"
    "?latitude=53.55&longitude=-113.49"
    "&current=pressure_msl,surface_pressure,temperature_2m");
  if (http.GET() == 200) Serial.println(http.getString());
  http.end();
  delay(900000); // 15 miunute delay to match API interval
}