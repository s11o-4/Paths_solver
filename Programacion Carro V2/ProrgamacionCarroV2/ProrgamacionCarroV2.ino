//MOTORES

//MOTOR 1

int m1p1 = 10;
int m1p2 = 9;

//MOTOR 2

int m2p1 = 6;
int m2p2 = 5; 

//Velocidad
int vel = 255;

    //SENSORES//

//Sensor Frontal 1

#define Ptrig1 13
#define Pecho1 12

long duracion1, distancia1;

//Sensor de la derecha 2

#define Ptrig2 11
#define Pecho2 8

long duracion2, distancia2;

//Sensor de la izquierda 3

#define Ptrig3 7
#define Pecho3 4
long duracion3, distancia3;

void setup() {

//MOTORES
pinMode(m1p1, OUTPUT);
pinMode(m1p2, OUTPUT);

pinMode(m2p1, OUTPUT);
pinMode(m2p2, OUTPUT);

//SENSOR FRONTAL
pinMode(Ptrig1, OUTPUT);
pinMode(Pecho1, INPUT);

//Sensor de la derecha

pinMode(Ptrig2, OUTPUT);
pinMode(Pecho2, INPUT);

//Sensor de la izquierda

pinMode(Ptrig3, OUTPUT);
pinMode(Pecho3, INPUT);

}

void loop() {
  
//Sensor Frontal
digitalWrite(Ptrig1, LOW);
delayMicroseconds(2);
digitalWrite(Ptrig1, HIGH);
delayMicroseconds(10);
digitalWrite(Ptrig1, LOW);
duracion1 = pulseIn(Pecho1, HIGH);
distancia1 = (duracion1 / 2) / 29;


//Sensor de la derecha sensor 2
digitalWrite(Ptrig2, LOW);
delayMicroseconds(2);
digitalWrite(Ptrig2, HIGH);
delayMicroseconds(10);
digitalWrite(Ptrig2, LOW);
duracion2 = pulseIn(Pecho2, HIGH);
distancia2 = (duracion2 / 2) / 29; 

//Sensor de la izquierda sensor 3

digitalWrite(Ptrig3, LOW);
delayMicroseconds(2);
digitalWrite(Ptrig3, HIGH);
delayMicroseconds(10);
digitalWrite(Ptrig3, LOW);
duracion3 = pulseIn(Pecho3, HIGH);
distancia3 = (duracion3 / 2) / 29;


if(distancia1 <= 15){
  //Detener motores
  digitalWrite(m1p1, 0);
  digitalWrite(m1p2, 0);
  digitalWrite(m2p1, 0);
  digitalWrite(m2p2, 0);
 
 if(distancia2 > 15){
    digitalWrite(m1p1, 0);
    digitalWrite(m1p2, 0);
  
    digitalWrite(m2p1, 0);
    digitalWrite(m2p2, vel);
     delay(430);  
  } else {
    if(distancia3 > 15){
    digitalWrite(m2p1, 0);
    digitalWrite(m2p2, 0);
    digitalWrite(m1p1, 0);
    digitalWrite(m1p2, vel);
    delay(420);  
   } else {
        
    digitalWrite(m1p1, 0);
    digitalWrite(m1p2, vel);
    digitalWrite(m2p1, vel);
    digitalWrite(m2p2, 0);
    
   }
  }
  
} else {

//Motores hacia adelante

//Activo mis motores
digitalWrite(m1p2,vel);
digitalWrite(m2p2, vel);

digitalWrite(m2p1, 0);
digitalWrite(m1p1,0);



   }

}
