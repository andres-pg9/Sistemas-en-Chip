#include <dht.h>
#include <LiquidCrystal_I2C.h>

#include <Wire.h>

#include <Adafruit_VL53L0X.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

dht DHT;

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup(){
  Serial.begin(9600);

  // Espera a que el sensor VL53L0X esté listo
  while (!lox.begin()) {
    Serial.println("No se encontró el sensor VL53L0X. Verifica las conexiones.");
    delay(1000);
  }

  // Configuración adicional si es necesaria
}
 

void loop() {
  VL53L0X_RangingMeasurementData_t measure;

  lox.rangingTest(&measure, false); // pasamos 'true' para imprimir datos en formato crudo

  if (measure.RangeStatus != 4) {  // 4 significa que no se detectó ningún objeto
    Serial.print("Distancia (mm): ");
    Serial.println(measure.RangeMilliMeter);
  } else {
    Serial.println("Objeto fuera de rango");
  }

  delay(100);
}
