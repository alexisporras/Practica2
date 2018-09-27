/*
  Programa: Alarma
  Objetivo: Implemenatr una alarma para el acceso de puerta. Cuando la puerta se abra,
           la alarma se debe activar
           Para evitar gastos el consumo de energia debe ser minimo cuando no se abra la puerta,
           mientras la alarma se active regrese al estado normal y una vez cerrada regrese al
           estado minimo de consumo de energia
  - Alexis Antonio Porras Lobato
*/
#include "LowPower.h" //Incluir libreria
const int pinSensor = 2; 
const int pinLed = 13;
const int pinBocina = 6;

void setup() {
  //configurar pin como entrada con resistencia pull-up interna
  pinMode(pinSensor, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);
  pinMode(pinBocina, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pinSensor), alarma, LOW); //funcion que sirve para el minimo consumo de energia, los parametros son el la variable que controla el sensor, el metodo que ejecutara y su estado
  digitalWrite(pinLed, LOW);
  digitalWrite(pinBocina, HIGH);
  digitalWrite(pinSensor, HIGH);
}

void loop() {
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF); //accion que inicializa la interrupcion, se le asigna el modo el cual estara en minimo consumo
}
void alarma() {

  digitalWrite(pinLed, HIGH); //se prende el led al detectar movimiento

  for(int contador = 0; contador <= 255; contador += 5){
    analogWrite(pinBocina, 2); //activar bocina con un valor bajo de intensidad (2)
    delay(100);
    }
     analogWrite(pinBocina, 0); //apaga bocina

  digitalWrite(pinLed, LOW);

}
