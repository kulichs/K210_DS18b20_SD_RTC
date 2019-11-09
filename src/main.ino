#include <Arduino.h>
#include <OneWire.h>
int DS18S20_Pin = 9; //čidlo je připojeno na pinu 9

OneWire ds(DS18S20_Pin);

void setup() {
  Serial.begin(115200);
}

void loop() {
  // zavoláme funkci getTemp() v souboru onewire.ino a vrátí hodnotu
  // v promene temperature tu pak vypišeme na serial port
  float temperature = getTemp();
  Serial.println(temperature);
  //pomalejší zobrazování teplot pro lepší čitelnost
  delay(1000);
}
