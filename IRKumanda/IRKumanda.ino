#include <IRremote.h>
int sensorPin = 2;
int led=5;
IRrecv sensor(sensorPin);
decode_results deger;
void setup() {
 sensor.enableIRIn();
 pinMode(led,OUTPUT);
Serial.begin(9600);
}

void loop() {
  
 if(sensor.decode(&deger)){
  Serial.println("Tus kodu : ");
  Serial.println(deger.value, HEX);
  sensor.resume();

  if(deger.value == 0xFFA25D){
    digitalWrite(led,HIGH);
  }else if(deger.value == 0xFF629D){
    digitalWrite(led,LOW);
  }
  }
delay(300);
}
