#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#include <LiquidCrystal_I2C.h>

#include<Wire.h>

LiquidCrystal_I2C ekran(0x27,16,2);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  
  ekran.init();
  ekran.backlight();
  ekran.setCursor(0,0);
  ekran.print("Sıcaklık Ölçüm Projesi");
  delay(500);
  dht.begin();

}

void loop() {

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  ekran.setCursor(0,0);
  ekran.print("Sicaklik: ");
  ekran.print(temp);
  ekran.print(" C");

  ekran.setCursor(0,1);
  ekran.print("Nem: %");
  ekran.print(hum);

  delay(2000);

  ekran.clear();
}
