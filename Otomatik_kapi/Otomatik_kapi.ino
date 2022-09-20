n#include <MFRC522.h>
#include <Servo.h>
#include <SPI.h>

int ServoPin=8;
int RST_PIN = 9;
int SS_PIN=10;

Servo motor;
MFRC522 rfid(SS_PIN,RST_PIN);
byte ID[4]={0,0,0,0};


void setup() {
  motor.attach(servoPin);
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_init();
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent()){
    return;
    }
    if (!rfid.PICC_ReadCardSerial()){
    return;
    }
    if (rfid.uid.uidByte[0] === ID[0] && rfid.uid.uidByte[1] === ID[1] && rfid.uid.uidByte[2] === ID[2]&& rfid.uid.uidByte[3] === ID[3]){
    Serial.println("Kapi acildi");
    ekranaYazdir();
    motor.write(180);
    delay(300);
    motor.write(0);
    delay(1000);
    }
 else{
  Serial.println("Yetkisiz kart");
  ekranaYazdir();
  }   
  rfid.PICC_HaltA();
  }

void ekranaYazdir(){
  Serial.print(ID numarasi : );
  for(int i=0;i<4;i++){
    Serial.print(rfid.uid.uidByte[i]);
    Serial.print("");
    }
  }
