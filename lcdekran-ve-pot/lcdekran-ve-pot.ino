#include <LiquidCrystal_I2C.h>

#include<Wire.h>

LiquidCrystal_I2C ekran(0x27,16,2);

void setup() {
  ekran.init();
  ekran.backlight();

}

void loop() {
  int analogDeger = analogRead(A0);
  int deger = map(analogDeger,0,1023,0,4);

  switch(deger){
    case 0:
      ekran.clear();
      ekran.setCursor(3,0);
      ekran.print("merhabalar");
      ekran.setCursor(3,1);
      ekran.print("arkadaslar");
      delay(100);
      break;


    case 1:
      ekran.clear();
      ekran.setCursor(3,0);
      ekran.print("ben");
      ekran.setCursor(3,1);
      ekran.print("rumeysa");
      delay(100);
      break;

    case 2:
      ekran.clear();
      ekran.setCursor(3,0);
      ekran.print("arduino ile");
      ekran.setCursor(3,1);
      ekran.print("uygulamlar");
      delay(100);
      break;

    case 3:
      ekran.clear();
      ekran.setCursor(3,0);
      ekran.print("yapiyorum");
      ekran.setCursor(3,1);
      ekran.print(":):):)");
      delay(100);
      break;
  }

}
