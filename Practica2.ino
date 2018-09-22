//Sensor de movimiento para alarma con sonido

#define bocina 6 //Declaro bocina
#define sensor 9 //Declaro sensor
#define led 13 // Declaro led

int mov = LOW; //Declaro variable para almacenar movimiento detectado

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
    Serial.print("Movimiento detectado");
    Serial.print("\n");
    digitalWrite(led, HIGH);
    alarma();
    digitalWrite(led, LOW);
    mov = LOW;
    //delay(200);
  } else{
    //Serial.print("Sin movimiento detectado");
    }
  
}

void alarma() {
  /*tone(bocina, 8.18);
  delay(100);
  tone(bocina, 9.72);
  delay(100);
  tone(bocina, 14.57);
  delay(100);
  noTone(bocina);
  delay(100);*/

  tone(bocina, 13.75);
  delay(150);
  tone(bocina, 9.72);
  delay(150);
  tone(bocina, 8.18);
  delay(150);
  noTone(bocina);
  delay(150);
}
