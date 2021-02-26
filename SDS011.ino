// SDS011 dust sensor example
// -----------------------------
//
// By R. Zschiegner (rz@madavi.de).
// April 2016

#include <SDS011.h>
#include <TFT_eSPI.h>
#include <SPI.h>
TFT_eSPI tft = TFT_eSPI(135, 240);

#define WHITE 0x5AEB

#define TFT_GREY 0x5AEB
#define lightblue 0x01E9
#define darkred 0xA041
#define blue 0x5D9B
#include "Orbitron_Medium_20.h"

// buffer to store the SDS011 message
byte buffer[10] = {};

SDS011 my_sds;
#ifdef ESP32
HardwareSerial port(2);
#endif
// Struct to keep calculated PM2.5 and PM10 values
struct AirQualityData {
  float pm25;
  float pm10;
} airQuality;

// Marker byte for SDS011 message end
byte DATA_END_MARK = 0xAB;

void setup() {
  my_sds.begin(&port);
  Serial.begin(115200);
  delay(10);
  tft.init();
  // Serial2 bound on 25/26 (UART RX and TX)
  Serial2.begin(9600, SERIAL_8N1, 25, 26);
  memset(buffer, 0, sizeof(buffer));
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  //tft.setTextColor(TFT_ORANGE,TFT_BLACK);
  tft.setTextSize(1);
}

void loop() {
 if(Serial2.available()) {
   Serial2.readBytesUntil(DATA_END_MARK, buffer, 10);
   readAirQuality();      
   displayAirQuality();
 }
}

void readAirQuality() {
  airQuality.pm25 = ((buffer[3] * 256) + buffer[2]) / 10.0;
  airQuality.pm10 = ((buffer[5] * 256) + buffer[4]) / 10.0;
}

void displayAirQuality() {
  
  tft.setRotation(1);
  tft.setFreeFont(&Orbitron_Medium_20);
  //tft.fillScreen(TFT_BLACK);
  tft.fillRect(2,2,85,22,darkred);
  //tft.fillRect(60,60,100,100,TFT_BLACK);
  tft.setTextColor(TFT_WHITE,TFT_BLACK);
  tft.setCursor(5, 20);
  tft.printf("PM2.5");
  tft.setTextColor(TFT_ORANGE,TFT_BLACK);
  tft.setTextFont(2);
  tft.setFreeFont(&Orbitron_Medium_20);
  tft.setCursor(5, 45);
  tft.fillRect(5,25,200,45,TFT_BLACK);
  tft.printf("%.2f ug/m3",airQuality.pm25);
  tft.setTextColor(TFT_ORANGE,TFT_BLACK);
  tft.setTextFont(2);
  tft.setFreeFont(&Orbitron_Medium_20);
  tft.fillRect(2,61,85,22,darkred);
  tft.setTextColor(TFT_WHITE,TFT_BLACK);
  tft.setCursor(5, 80);
  tft.printf("PM10");
  tft.setTextColor(TFT_ORANGE,TFT_BLACK);
  tft.setTextFont(2);
  tft.setFreeFont(&Orbitron_Medium_20);
  tft.setCursor(5, 105);
  tft.fillRect(5,85,200,105,TFT_BLACK);
  tft.printf("%.2f ug/m3",airQuality.pm10);
  tft.setTextColor(TFT_ORANGE,TFT_BLACK);
  tft.setTextFont(2);
  delay(2000);
}
