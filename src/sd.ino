//funkce pro zapis na sd kartu
void zapis() {
  soubor = SD.open("DS.csv", FILE_WRITE);
  // zavoláme funkci getTemp() v souboru onewire.ino a vrátí hodnotu
  // v promene temperature tu pak vypišeme na serial port
  float temperature = getTemp();
  //Serial.println(temperature);
  soubor.print(temperature);
  soubor.println();
  soubor.close();
}
