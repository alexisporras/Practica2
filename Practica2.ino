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
  // put your main code here, to run repeatedly:

  tone(bocina, 13.75);
  delay(150);
  tone(bocina, 9.72);
  delay(150);
  tone(bocina, 8.18);
  delay(150);
  noTone(bocina);
  delay(1000);
}
