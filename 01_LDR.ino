//LDR
#define LED  27
#define LDR 35

void setup() {
  pinMode(LED, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  int light = analogRead(LDR); 
  Serial.println(light);

  if(light < 400){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
  delay(100);
}
