#include <HCSR04.h>

HCSR04 hc(5, 6); 

#include <LiquidCrystal_I2C.h>

#include<Wire.h>

LiquidCrystal_I2C ekran(0x27,16,2);

void setup()
{
    Serial.begin(9600);
    ekran.init();
    ekran.backlight();
}

void loop()
{
    Serial.println(hc.dist()); 
    delay(1000);      

    ekran.setCursor(0,0);
    ekran.print("Mesafe");
    ekran.setCursor(0,1);
    ekran.print(hc.dist());
}
