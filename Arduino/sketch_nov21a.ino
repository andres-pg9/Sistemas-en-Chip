#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte CharA[8] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B01010,
  B01010,
  B01110,
  B00000

};

byte CharB[8] = {
  B00000,
  B00100,
  B01010,
  B01010,
  B01110,
  B01010,
  B01010,
  B00000
};


byte CharC[8] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};

byte CharD[8] = {
    B00000,
  B01010,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};

byte CharE[8] = {
  B00010,
  B00101,
  B10010,
  B00000,
  B01001,
  B10100,
  B01000,
  B00000
};

byte CharF[8] = {
  B00000,
  B00110,
  B11001,
  B00000,
  B01100,
  B10011,
  B00000,
  B00000
};

byte CharG[8] = {
  B00000,
  B01110,
  B10011,
  B00011,
  B10011,
  B01110,
  B00000,
  B00000
};

byte CharH[8] = {
 B00000,
  B01010,
  B10101,
  B01110,
  B10101,
  B01010,
  B00000,
  B00000
};

byte CharI[8] = {
B00000,
  B00110,
  B01010,
  B01001,
  B10001,
  B11111,
  B00000,
  B00000
};

byte CharJ[8] = {
  B00000,
  B10101,
  B01110,
  B11011,
  B01110,
  B10101,
  B00000,
  B00000
};

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, CharI);
  lcd.createChar(1, CharJ);
  lcd.createChar(2, CharC);
  lcd.createChar(3, CharD);
  lcd.createChar(4, CharE);
  lcd.createChar(5, CharF);
  lcd.createChar(6, CharG);
  lcd.createChar(7, CharH);
  lcd.createChar(8, CharI);
  lcd.createChar(9, CharJ);

  lcd.setCursor(0,0);
  lcd.print("Clase 6CV2");

  lcd.setCursor(0,1);
  lcd.write(byte (0));
 lcd.print(" ");
  lcd.write(byte (1));
 lcd.print(" ");
  lcd.write(byte (2));
lcd.print(" ");
  lcd.write(byte (3));
lcd.print(" ");
  lcd.write(byte (4));
lcd.print(" ");
  lcd.write(byte (5));
  lcd.print(" ");
  lcd.write(byte (6));
  lcd.print(" ");
  lcd.write(byte (7));

}


void loop() {
  // put your main code here, to run repeatedly:

}
