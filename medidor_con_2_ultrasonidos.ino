#define trigP 6
#define trigP2 10

#define echoP 5
#define echoP2 9

void setup ( )
{
  Serial.begin (9600);

  pinMode(7, OUTPUT);
  pinMode(11, OUTPUT);
  
  pinMode(trigP, OUTPUT);
  pinMode(echoP, INPUT);
  
  pinMode(trigP2, OUTPUT);
  pinMode(echoP2, INPUT);
}

void loop( )
{
  long duracion1, duracion2, distancia1, distancia2, capacidad1, capacidad2;
  int valorLCD1=0 ,valorLCD2=0;
  digitalWrite(trigP, LOW);
  digitalWrite(trigP2, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigP, HIGH);
  digitalWrite(trigP2, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigP, LOW);
  digitalWrite(trigP2, LOW);
  
  duracion1=pulseIn(echoP, HIGH);
  duracion2=pulseIn(echoP2, HIGH);
  
  distancia1=(duracion1/2)/29;
  distancia2=(duracion2/2)/29;
  
  capacidad1=100-(distancia1*100)/100;
  capacidad2=100-(distancia2*100)/100;
  
  if(capacidad1>=90 && capacidad1>=0)
  {
    valorLCD1=1;
    pulse
  }
  else{
    if(capacidad1>=50 && capacidad1<90){
      valorLCD1=2;
      }
      else{
        if(capacidad1<50 && capacidad1>=0)
        valorLCD1=3;
        }
    }

   if(capacidad2>=90 && capacidad2>=0)
  {
    valorLCD2=1;
  }
  else{
    if(capacidad2>=50 && capacidad2<90){
      valorLCD2=2;
      }
      else{
        if(capacidad2<50 && capacidad2>=0)
        valorLCD2=3;
        }
    }
}
