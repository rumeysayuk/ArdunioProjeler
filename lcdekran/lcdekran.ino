#include <LiquidCrystal_I2C.h>

#include<Wire.h>

LiquidCrystal_I2C ekran(0x27,16,2);

void setup() {

  ekran.init();
  ekran.backlight();
  ekran.setCursor(2,0);
  ekran.print("RUMEYSA YUK");
  ekran.setCursor(3,1);
  ekran.print("BIL. MUH.");
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
