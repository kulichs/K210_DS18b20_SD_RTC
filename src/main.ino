#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <OneWire.h>
#include <Wire.h>

int DS18S20_Pin = 9; //čidlo je připojeno na pinu 9

OneWire ds(DS18S20_Pin);

File soubor;

#define DS3231_I2C_ADDRESS 0x68

void setup() {
  //Nastavení Serial komunikace
  Serial.begin(115200);
  // Inicializace wire I2C
  Wire.begin();
  //Spuštění SD knihovny
  if (!SD.begin(29)) {
    Serial.println("SD karta nenalezena");
    while (1);
  }
  Serial.println("Inicializace SD karty hotova.");
}

void loop() {
  // Zápis data času a teploty na sd kartu
  zapis();
  //pomalejší zobrazování teplot pro lepší čitelnost
  delay(6000);
}
