// John Torres & Santiago Bermúdez

#include <Wire.h>       // Librería para manejo de I2C

int MIC = 2;
int LED = 3;
int LED2 = 4;
int LED3 = 5;
int LED4 = 6;
int VALOR;
int ESTADO;

void setup() {
  pinMode(MIC, INPUT);    // Entrada digital sensor de sonido
  pinMode(LED, OUTPUT);   // Salidas hacia los Leds rojos desde LED hasta LED4
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  Wire.begin();           // Inicialización comunicación I2C  
}

byte x = 0;

void loop() {
  VALOR = digitalRead(MIC); // Asigna a VALOR la salida del sensor
  digitalWrite(LED, HIGH);  // Pone todos los leds en alto
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  if (VALOR == HIGH)        //Si recibe la señal del sensor de sonido entra al método
  {
    ESTADO = digitalRead(LED);  // asigna el valor actual del Led a ESTADO
    digitalWrite(LED, !ESTADO); // cambia el estado de los Leds
    digitalWrite(LED2, !ESTADO);
    digitalWrite(LED3, !ESTADO);
    digitalWrite(LED4, !ESTADO);
    if(digitalRead(LED) == LOW){
    Wire.beginTransmission(1);  // Comunicación hacia el dispositivo #1
    Wire.write(x);              // Envía un byte
    Wire.endTransmission();     // Termina la transmisión
    delay(800);
    }
    else if(digitalRead(LED) == HIGH){
    delay(100);
    }
   }    
}
