#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include <Adafruit_BMP085.h>
#define LED  27
#define LDR 35
File readings;
Adafruit_BMP085 bmp;  //Objeto bmp
char payload [80];

void setup() {
  pinMode(LED, OUTPUT);
  bmp.begin(0x77);
  Serial.begin(115200);
  if(!SD.begin()){
        Serial.println("Card Mount Failed");
        return;
    }
}

void loop() {

  float presion = bmp.readPressure();
  float temperatura = bmp.readTemperature();
  int sensor_ldr = analogRead(LDR);

  sprintf(payload, "%6.2f,%3.2f,%d", presion, temperatura, sensor_ldr);

  digitalWrite(LED, HIGH);
    readings = SD.open("/Lecturas_sensor.csv", FILE_APPEND);
    readings.println(payload);
    Serial.println(payload);
    readings.close();
  digitalWrite(LED, LOW);

  delay(500);
}
