#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long tiempoAnterior = 300; // Guarda la última vez que se actualizó el evento
const long intervalo = 600; // Intervalo deseado (500 milisegundos)

byte PacD[] = {
  B00000,
  B01110,
  B11011,
  B11110,
  B11000,
  B11111,
  B01110,
  B00000
};

byte PacI[] = {
  B00000,
  B01110,
  B11011,
  B01111,
  B00011,
  B11111,
  B01110,
  B00000
};

byte PacO[] = {
  B00000,
  B01110,
  B11011,
  B11111,
  B11111,
  B11111,
  B01110,
  B00000
};
const int pushD = 8;
int readingD;
unsigned long ultimoCambio = 0; // Almacena el tiempo del último cambio de botón
int i = 0, j = 0, d = 1, c = 0;

void setup() {
  pinMode(pushD, INPUT_PULLUP);

  lcd.init();
  lcd.createChar(0, PacD);
  lcd.createChar(1, PacI);
  lcd.createChar(2, PacO);

  lcd.backlight();
  lcd.setCursor(5, 0);
  lcd.print("Pacman");
  lcd.setCursor(0, 1);
  lcd.print("PracticaEmbebido");
  lcd.setCursor(i, j);
}

void loop() {
 // Obtener el tiempo actual
  unsigned long tiempoActual = millis();
  c = tiempoActual - tiempoAnterior >= intervalo/3 ? 2 : d == 1 ? 0 : 1;
  pacman(c);
  
  if (tiempoActual - tiempoAnterior >= intervalo) {
    // Guardar la última vez que se actualizó el evento
    tiempoAnterior = tiempoActual;
    lcd.setCursor(i, j);
    lcd.print(" ");
    
    i = i + d;

    if (i == -1) {
      j++;
      i = 15;
    } else if (i == 16) {
      j++;
      i = 0;
    }

    if (j == 2) {
      j = 0;
    } 
  }

  readingD = digitalRead(pushD);
    if (readingD == LOW && tiempoActual - ultimoCambio > 200) { // Debounce de 200 ms
      d = -d; // Cambiar la dirección
      ultimoCambio = tiempoActual; // Actualizar el tiempo del último cambio
    }
}

void pacman(int c){
  lcd.setCursor(i, j);
  lcd.write(byte(c));
}
