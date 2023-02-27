//Boton
#define LED  27
#define BOTON 34

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BOTON, INPUT);
}

void loop() {
  if(digitalRead(BOTON)){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
  delay(100);
}
