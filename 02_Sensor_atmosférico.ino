//Presión,Temperatura

#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;  //Objeto bmp
char payload [80];

void setup() {
  bmp.begin(0x77); //Inicializa bmp
  Serial.begin(115200);
}

void loop() {
  float presion = bmp.readPressure()/1000;  //Dividimos sobre 1000 para poder leer en el serial plotter ambas lecturas.
  float temperatura = bmp.readTemperature();

  sprintf(payload, "%6.2f,%3.2f", 
          presion, 
          temperatura);

  Serial.println(payload);
  delay(200);
}
