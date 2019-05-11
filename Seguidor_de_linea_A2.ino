// John Torres & Santiago Bermúdez

#include <Wire.h>

int LEDV1 = 11; //Leds Verdes
int LEDV2 = 12;
int LEDV3 = 13;
int LEDV4 = 3;
int LEDA1 = 0;  //Leds Amarillos
int LEDA2 = 1;
int ENA = 10; //Motor A PWM
int IN1 = 9; //Motor A
int IN2 = 8; //Motor A
int IN3 = 7; //Motor B
int IN4 = 6; //Motor B
int ENB = 5; //Motor B PWM
int OPD = 2; //Sensor óptico derecho
int OPI = 4; //Sensor óptico izquierdo

void setup() {
  
  Wire.begin(1);
  pinMode(OPD, INPUT);      // Sensor Derecho
  pinMode(OPI, INPUT);      // Sensor izquierdo
  pinMode(IN1, OUTPUT);     // Motor A Atras
  pinMode(IN2, OUTPUT);     // Motor A adelante
  pinMode(IN3, OUTPUT);     // Motor B adelante
  pinMode(IN4, OUTPUT);     // Motor B Atras
  pinMode(ENA, OUTPUT);     // Motor A velocidad
  pinMode(ENB, OUTPUT);     // Motor B velocidad
  pinMode(LEDV1, OUTPUT);   // Leds como salidas
  pinMode(LEDV2, OUTPUT);
  pinMode(LEDV3, OUTPUT);
  pinMode(LEDV4, OUTPUT);
  pinMode(LEDA1, OUTPUT);
  pinMode(LEDA2, OUTPUT);
  Wire.onReceive(seguidor);   //Cuando se recibe el byte del Maestro entra al método
 // Serial.begin(9600);
}

void loop()
{
}

void seguidor() .  //Método llamado por el Wire.onReceive()
{
 inicio:           // etiqueta de inicio del programa por uso de saltos 

digitalWrite(IN1, LOW);   // Velocidad 0
digitalWrite(IN2, LOW);   // Velocidad 0
digitalWrite(IN3, LOW);   // Velocidad 0
digitalWrite(IN4, LOW);   // Velocidad 0

delay(100);                    // retardo de 100ms se evitan rebotes

for(;;)
  {
  if (digitalRead(OPI) && digitalRead(OPD))             // Lectura de las señales digitales y ejecucion cuando los dos sensores estan en línea negra
  {  
     analogWrite(ENA, 150);     
     analogWrite(ENB, 150);
     digitalWrite(IN2, HIGH);                           // Movimiento adelante 
     digitalWrite(IN3, LOW);
     digitalWrite(IN1, LOW);                                                
     digitalWrite(IN4, HIGH);
     digitalWrite(LEDA1, LOW);
     digitalWrite(LEDA2, LOW);
     digitalWrite(LEDV1, HIGH);
     digitalWrite(LEDV2, HIGH);
     digitalWrite(LEDV3, HIGH);
     digitalWrite(LEDV4, HIGH);
  }
  else if (!digitalRead(OPD) && digitalRead(OPI))            // Lectura de las señales digitales y ejecución cuando el sensor izquierdo entra a la línea negra
  {  
     analogWrite(ENA, 140);
     analogWrite(ENB, 140);
     digitalWrite(IN2, HIGH);                                                
     digitalWrite(IN3, HIGH);
     digitalWrite(IN1, LOW);                                                 
     digitalWrite(IN4, LOW);
     digitalWrite(LEDV1, HIGH);
     digitalWrite(LEDV2, HIGH);
     digitalWrite(LEDA1, LOW);
     digitalWrite(LEDV3, HIGH);
     digitalWrite(LEDV4, HIGH);
     digitalWrite(LEDA2, HIGH);
  }                                              
  else if (digitalRead(OPD) && !digitalRead(OPI))           // Lectura de las señales digitales y ejecución cuando el sensor derecho entra a la línea negra
  {  
     analogWrite(ENA, 140);
     analogWrite(ENB, 140);
     digitalWrite(IN2, LOW);                                                
     digitalWrite(IN3, LOW);
     digitalWrite(IN1, HIGH);                                                 
     digitalWrite(IN4, HIGH);
     digitalWrite(LEDV1, HIGH);
     digitalWrite(LEDV2, HIGH);
     digitalWrite(LEDV3, HIGH);
     digitalWrite(LEDV4, HIGH);
     digitalWrite(LEDA2, LOW);
     digitalWrite(LEDA1, HIGH);
  }  
  else                                                         // Lectura de las señales digitales y ejecución cuando los dos sensores estan en espacio blanco
  {  
     analogWrite(ENA, 130);
     analogWrite(ENB, 130);
     digitalWrite(IN1, HIGH);                                                 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, HIGH);                                                 
     digitalWrite(IN4, LOW);
     digitalWrite(LEDV1, HIGH);
     digitalWrite(LEDV2, HIGH);
     digitalWrite(LEDV3, LOW);
     digitalWrite(LEDV4, LOW);
     digitalWrite(LEDA1, HIGH);
     digitalWrite(LEDA2, HIGH);
  }                                                                                                      
    delay(100);                                              // retardo de 100ms se evitan rebotes
    goto inicio;}                                              // Vuelve a inicio a esperar pulso para arranque
}
