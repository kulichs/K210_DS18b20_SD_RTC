//funkce pro zapis na sd kartu
void zapis() {
  soubor = SD.open("DS.csv", FILE_WRITE);
  // zavoláme funkci getTemp() v souboru onewire.ino a vrátí hodnotu
  // v promene temperature tu pak vypišeme na serial port
  float temperature = getTemp();
  //Serial.println(temperature);
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
  &year);
  //zápis času a datumu
  soubor.print(hour, DEC);

  soubor.print(":");
  if (minute<10)
  {
    soubor.print("0");
  }
  soubor.print(minute, DEC);
  soubor.print(":");
  if (second<10)
  {
    soubor.print("0");
  }
  soubor.print(second, DEC);
  soubor.print("-");
  soubor.print(dayOfMonth, DEC);
  soubor.print("/");
  soubor.print(month, DEC);
  soubor.print("/");
  soubor.print(year, DEC);
  soubor.print(" ");
  //zápis teploty
  soubor.print(temperature);
  soubor.println();
  soubor.close();
}
