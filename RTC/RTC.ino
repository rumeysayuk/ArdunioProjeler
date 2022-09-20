#include <virtuabotixRTC.h>                            //Kütüphanemizi ekliyoruz.
int CLK_PIN = 6;                                       //6. pini clock pini olarak tanımladık
int DAT_PIN = 7;                                       //7. pini data pini olarak tanımladık
int RST_PIN = 8;                                       //8. pini reset pini olarak tanımladık.
virtuabotixRTC myRTC(CLK_PIN, DAT_PIN, RST_PIN);      // Kütüphanemizi pinlere atıyoruz.

#include <LiquidCrystal_I2C.h>

#include<Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
 Serial.begin(9600);                                   //Seri haberleşmeyi başlatıyoruz.
 myRTC.setDS1302Time(10, 10, 16, 4, 15, 9, 2022);     //Saati saniye, dakika, saat, haftanın günü, ayın günü, ay, yıl olarak ayarlıyoruz.

 lcd.init();
 lcd.backlight();
}

void loop() {
 myRTC.updateTime();                                   //RTC'den zamanı okuyoruz

 Serial.print("Tarih / Saat: ");                       //Aldığımız verileri Serial Porta bastırıyoruz.
 Serial.print(myRTC.dayofmonth);
 Serial.print("/");
 Serial.print(myRTC.month);
 Serial.print("/");
 Serial.print(myRTC.year);
 Serial.print(" ");
 Serial.print(myRTC.hours);
 Serial.print(":");
 Serial.print(myRTC.minutes);
 Serial.print(":");
 Serial.println(myRTC.seconds);

                                  //RTC'den zamanı okuyoruz  
  lcd.clear();                                          //Başlamadan önce ekranı temizliyoruz.
  lcd.setCursor(0,0);                                   //Ekranın ilk satır ilk sütunundan yazmaya başlıyoruz.
  lcd.print(myRTC.dayofmonth);                          //Günü ekrana bastırıyoruz.
  lcd.print("/");
  lcd.print(myRTC.month);                               //Ayı ekrana bastırıyoruz.
  lcd.print("/");
  lcd.print(myRTC.year);                                //Yılı ekrana bastırıyoruz
  lcd.setCursor(0, 1);                                  //LCD'nin 2. satır 1. sütunundan yazmaya başlıyoruz.
  lcd.print(myRTC.hours);                               //Saati ekrana bastırıyoruz.
  lcd.print(":");
  lcd.print(myRTC.minutes);                             //Dakikayi ekrana bastırıyoruz.   
  lcd.print(":");
  lcd.print(myRTC.seconds);                             //Saniyeyi ekrana bastırıyoruz.
  delay(1000);                                         //1sn bekleme.
}
