#define LED  27
#define POTENCIOMETRO 33
#define LDR 35

int pwm_in = 0;
int ldr_in = 0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  pwm_in = analogRead(POTENCIOMETRO);
  ldr_in = analogRead(LDR);
  Serial.println(pwm_in);
  //Serial.println(ldr_in);
  
  analogWrite(LED, pwm_in/16);
  //analogWrite(LED, (255 - (ldr_in/16)));

  delay(100);
}
