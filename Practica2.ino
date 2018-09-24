//Sensor de movimiento para alarma con sonido

#define bocina 6 //Declaro bocina
#define sensor 2 //Declaro sensor
#define led 13 // Declaro led

int mov = 0; //Declaro variable para almacenar movimiento detectado
void setup() {
  Serial.begin(9600);
  pinMode(bocina, OUTPUT); //Asigno variables con modo de entrada o salida
  pinMode(sensor, INPUT);  //Asigno variables con modo de entrada o salida
  pinMode(led, OUTPUT);    //Asigno variables con modo de entrada o salida
}

void loop() {
  mov = digitalRead(sensor); //Igualacion de valor del pin con el de variable
  delay(100); //Tiempo de espera

  if (mov == HIGH) { //Condicional de movimiento
    movimiento();
  } else {
    sinMovimiento();
  }
}

void alarma() { //Secuencia de sonido
  tone(bocina, 8.18);
  delay(100);
  tone(bocina, 9.72);
  delay(100);
  tone(bocina, 14.57);
  delay(100);
  noTone(bocina);
  delay(100);
}

void movimiento() { //Secuencia de acciones si se detecta movimiento
  digitalWrite(led, HIGH); //Encender led
  Serial.print("Movimiento"); //Comprobar estado en consola
  Serial.print("\n");
  alarma(); //Iniciar secuencia de sonido
  digitalWrite(led, LOW); //Apagar led
  mov = LOW; //Rgresar estado de movimiento al original
  delay(500); //Tiempo de espera
}

void sinMovimiento() { //Secuencia de acciones si no detecta movimiento
  Serial.print("..."); //Comprobar estado en consola
  Serial.print("\n");
  digitalWrite(led, LOW); //Mantener led apagado
  mov = LOW;
}
