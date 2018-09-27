/*
 Programa: Alarma
 Objetivo: Implemenatr una alarma para el acceso de puerta. Cuando la puerta se abra,
           la alarma se debe activar
           Para evitar gastos el consumo de energia debe ser minimo cuando no se abra la puerta,
           mientras la alarma se active regrese al estado normal y una vez cerrada regrese al 
           estado minimo de consumo de energia
- Alexis Antonio Porras Lobato
*/

const int pinSensor = 2;
const int pinLed = 13;
const int pinBocina = 7;

void setup() {
  //configurar pin como entrada con resistencia pull-up interna
  pinMode(pinSensor, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);
  pinMode(pinBocina, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(pinSensor);

  if (value == LOW) {
    digitalWrite(pinLed, HIGH);

    for (int contador = 0; contador <= 100; contador ++) {
      tone(pinBocina, 8.18);
      delay(pinBocina);
    }
    noTone(pinBocina);


  } else {
    digitalWrite(pinLed, LOW);
  }

  delay(500);
}
