int ledPin = 9;
int LDRpin = A0;

void setup() {
  pinMode(ledPin,OUTPUT);

}

void loop() {
  int deger = analogRead(LDRpin);
  if(deger<5){
    digitalWrite(ledPin,HIGH);
  }else{
    digitalWrite(ledPin,LOW);
  }

}
