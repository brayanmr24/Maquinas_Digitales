#define BOTON 34
int numBotPres = 0;
uint32_t lastMillis = 0;

void IRAM_ATTR isrButton(){

  if((millis() - lastMillis) > 100){
    numBotPres += 1;
    lastMillis = millis();
  }

}

void setup() {
  Serial.begin(115200);
  pinMode(BOTON, INPUT);

  attachInterrupt(BOTON, isrButton, RISING);

}

void loop() {
  Serial.printf("El boton se ha presionado %u veces\n", numBotPres);
  delay(100);
}
