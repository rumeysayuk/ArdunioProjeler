int led = 9;
int sensorPin=A0;

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int deger= analogRead(sensorPin);
  Serial.println(deger);

  if(deger > 700){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
    }
}
