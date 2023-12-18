#include <dht.h>
#include <LiquidCrystal_I2C.h>


#include <Wire.h>
#include <VL53L1X.h>

VL53L1X sensor;


LiquidCrystal_I2C lcd(0x27, 16, 2);

dht DHT;
String mensaje = "";
#define DHT11_PIN 7

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);

  Serial.begin(9600);
  Wire.begin();

  sensor.init(true);
  sensor.setTimeout(500);
  sensor.startContinuous(100);

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

  lcd.clear(); // Limpia la pantalla
  lcd.setCursor(0, 0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);

  lcd.setCursor(0, 1); // Establece el cursor en la primera línea
  lcd.print("Distancia: ");
  lcd.print(sensor.readRangeContinuousMillimeters());

   delay(500);

}


