#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  Serial.begin(9600);

  dht.begin();

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Temperature");
}

void loop() {

  float temp = dht.readTemperature();

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C");

  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C ");

  delay(1000);
}