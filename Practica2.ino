//Sensor de movimiento para alarma con sonido

#define bocina 6 //Declaro bocina
#define sensor 2 //Declaro sensor
#define led 13 // Declaro led

int mov = 0; //Declaro variable para almacenar movimiento detectado
void setup() {
  Serial.begin(9600);
  pinMode(bocina, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  mov = digitalRead(sensor);
  delay(100);

  if (mov == HIGH) {
    movimiento();
  } else {
    sinMovimiento();
  }
}

void alarma() {
  tone(bocina, 8.18);
  delay(100);
  tone(bocina, 9.72);
  delay(100);
  tone(bocina, 14.57);
  delay(100);
  noTone(bocina);
  delay(100);
}

void movimiento() {
  digitalWrite(led, HIGH);
  Serial.print("Movimiento");
  Serial.print("\n");
  alarma();
  digitalWrite(led, LOW);
  mov = LOW;
  delay(500);
}

void sinMovimiento() {
  Serial.print("...");
  Serial.print("\n");
  digitalWrite(led, LOW);
  mov = LOW;
}
