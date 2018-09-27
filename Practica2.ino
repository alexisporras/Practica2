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
<<<<<<< HEAD
#define potenciometro A1
int valorPotenciometro = 0;
=======
>>>>>>> c9ef55f311464881962f890cd11d7037fa338e17

void setup() {
  //configurar pin como entrada con resistencia pull-up interna
  pinMode(pinSensor, INPUT_PULLUP);
<<<<<<< HEAD
  pinMode(potenciometro, INPUT_PULLUP);
=======
>>>>>>> c9ef55f311464881962f890cd11d7037fa338e17
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
<<<<<<< HEAD
  for(int contador = 0; contador <= 255; contador += 5){
    analogWrite(pinBocina, analogRead(potenciometro)); //activar bocina con un valor bajo de intensidad (2)
    delay(100);
    }
     analogWrite(pinBocina, 0); //apaga bocina

=======

  for(int contador = 0; contador <= 255; contador += 5){
    analogWrite(pinBocina, 2); //activar bocina con un valor bajo de intensidad (2)
    delay(100);
    }
     analogWrite(pinBocina, 0); //apaga bocina

>>>>>>> c9ef55f311464881962f890cd11d7037fa338e17
  digitalWrite(pinLed, LOW);

}
