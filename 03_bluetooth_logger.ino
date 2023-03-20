#include <BluetoothSerial.h>
#include <Adafruit_BMP085.h>
#define LED  27
#define LDR 35
Adafruit_BMP085 bmp;  //Objeto bmp
char payload [80];


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

void setup() {
  pinMode(LED, OUTPUT);
  bmp.begin(0x77);
  Serial.begin(115200);
  SerialBT.begin("Axolote_Brayan"); //Bluetooth device name
  Serial.println("Bluetooth configurado!");
}

void loop() {

  float presion = bmp.readPressure();
  float temperatura = bmp.readTemperature();
  int sensor_ldr = analogRead(LDR);

  sprintf(payload, "%6.2f,%3.2f,%d", presion, temperatura, sensor_ldr);

  digitalWrite(LED, HIGH);
    SerialBT.println(payload);
    Serial.println(payload);
  digitalWrite(LED, LOW);

  delay(500);
}
