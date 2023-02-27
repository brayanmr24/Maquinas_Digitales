#define LED  27
#define POTENCIOMETRO 33

void setup() {
  pinMode(LED, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  int resistencia = analogRead(POTENCIOMETRO); 
  Serial.println(resistencia);

  if(resistencia < 2000){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
  delay(100);
}
