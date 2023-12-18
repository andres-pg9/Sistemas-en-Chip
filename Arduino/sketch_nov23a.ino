#include <dht.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

dht DHT;
String mensaje = "";
#define DHT11_PIN 7

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  if (DHT.temperature >= 0 && DHT.temperature <= 20) {
    mensaje = "Rango: muy bajo";

  } else if (DHT.temperature > 20 && DHT.temperature <= 30) {
    mensaje = "Rango: intermedio";

  } else if (DHT.temperature > 30 && DHT.temperature <= 40) {
    mensaje = "Rango: muy alto";

  } else if (DHT.temperature < 0 || DHT.temperature > 40) {
    mensaje = "Fuera de rango";

  }

  lcd.setCursor(0, 0);
  lcd.print(mensaje);
  lcd.setCursor(0,1); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);


   delay(500);
 
    
}


