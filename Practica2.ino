//Sensor de movimiento para alarma con sonido

#define bocina 9 //Declaro bocina
#define sensor 8 //Declaro sensor
#define led 7 // Declaro led

int mov = 0; //Declaro variable para almacenar movimiento detectado

void setup() {
  Serial.befin(9600);
  pinMode(bocina, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  mov = digitalRead(sensor);
  delay(50);
  if (mov == HIGH) {
    Serial.print("Movimiento detectado");
    digitalWrite(led, HIGH);
    alarma();
    digitalWrite(led, LOW);
    mov = 0;
    delay(200);
  } else{
    //Serial.print("Sin movimiento detectado");
    }
  
}

void alarma() {
  tone(bocina, 8.18);
  delay(150);
  tone(bocina, 9.72);
  delay(150);
  tone(bocina, 14.57);
  delay(150);
  noTone(bocina);
  delay(1000);

  tone(bocina, 13.75);
  delay(150);
  tone(bocina, 9.72);
  delay(150);
  tone(bocina, 8.18);
  delay(150);
  noTone(bocina);
  delay(1000);
}
