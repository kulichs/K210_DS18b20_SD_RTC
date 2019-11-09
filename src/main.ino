#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <OneWire.h>
int DS18S20_Pin = 9; //čidlo je připojeno na pinu 9

OneWire ds(DS18S20_Pin);

File soubor;

void setup() {
  //Nastavení Serial komunikace
  Serial.begin(115200);
  //Spuštění SD knihovny
  if (!SD.begin(29)) {
    Serial.println("SD karta nenalezena");
    while (1);
  }
  Serial.println("Inicializace SD karty hotova.");
}

void loop() {
  //soubor = SD.open("DS.csv", FILE_WRITE);
  // zavoláme funkci getTemp() v souboru onewire.ino a vrátí hodnotu
  // v promene temperature tu pak vypišeme na serial port
  //float temperature = getTemp();
  //Serial.println(temperature);
  //soubor.print(temperature);
  //soubor.println();
  //soubor.close();
  zapis();
  //pomalejší zobrazování teplot pro lepší čitelnost
  delay(1000);
}
