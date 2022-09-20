const int analogGiris = A0;
const int ledPin = 9;

void setup() {
  pinMode(analogGiris,INPUT);
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  
}

void loop() {
  int deger = analogRead(analogGiris);
  Serial.println("deger:");
  Serial.println(deger);
  delay(1000);
  int ledDeger = map(deger,0,1023,0,255);
  analogWrite(ledPin,ledDeger);
}
