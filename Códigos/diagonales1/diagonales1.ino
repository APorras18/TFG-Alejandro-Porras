#define EN 8      
#define X_DIR 5   
#define X_STEP 2  
#define Y_DIR 6  
#define Y_STEP 3  
#define Z_DIR 7   
#define Z_STEP 4 
int cuenta = 0; 
int i=0;
int j=0;
int t=2; /*tiempo en milis para controlar los pasos*/
boolean direccionx = LOW; /* direccion del giro*/
boolean direcciony = LOW; /* direccion del giro*/
boolean direccionz = LOW; /* direccion del giro*/
//
int valor = 0 ;
int X = A4 ;
int Y = A5 ;
int boton = 9;

void setup()
    {
       // pinMode( boton, INPUT_PULLUP) ; //inicializo el boton con una resistencia interna de arduino
        Serial.begin(9600);
        pinMode(EN, OUTPUT); 
        pinMode(X_DIR, OUTPUT); 
        pinMode(X_STEP, OUTPUT); 
        pinMode(Y_DIR, OUTPUT); 
        pinMode(Y_STEP, OUTPUT); 
        pinMode(Z_DIR, OUTPUT); 
        pinMode(Z_STEP, OUTPUT); 
        digitalWrite(EN, LOW); //Low para activar
    }
 void loop()
{
   int Xv= 0;
   int Yv= 0;
   Xv = analogRead(X);
   delay(5);
   Yv = analogRead(Y);
   cuenta++; 
   Serial.print("X=");
   Serial.println(Xv);
   Serial.print("Y=");
   Serial.println(Yv);
   if ((Xv <300) && (Yv <300)) //Arriba izquierda
    {
     ejey(10,HIGH); 
    }
    else if ((Xv<300) && (Yv>700))  //Abajo izquierda
    {
     ejex(10,HIGH);  //Pongo 10 por ser un movimiento en diagonal
    } 
    else if ((Xv>700) && (Yv<300))   //Arriba derecha
    {
     ejex(10,LOW);  //Pongo 10 por ser un movimiento en diagonal 
    }
    else if ((Xv>700) && (Yv>700))   //Arriba derecha
    {
     ejey(10,LOW);  //Pongo 10 por ser un movimiento en diagonal 
    }
    else if ((301<Xv<699) && (Yv<300))  //Arriba centro
    {
     ejex(1,LOW);  //Pongo 5 por ser un movimiento recto
     ejey(1,HIGH);  //Pongo 0 porque no se mueve en el eje Y
    }
    else if ((301<Xv<699) && (Yv>700))  //Abajo centro
    {
     ejex(1,HIGH);  //Pongo 5 por ser un movimiento recto
     ejey(1,LOW);  //Pongo 0 porque no se mueve en el eje Y
    }
    else if ((Xv>700) && (301<Yv<699))   //Centro derecha
    {
     ejex(1,LOW);  //Pongo 0 porque no se mueve en el eje X
     ejey(1,LOW); //Cambio a HIGH por ser hacia el otro sentido del movimiento
    }  
    else if ((Xv<300) && (301<Yv<699))  //Centro izquierda
    {
     ejex(1,HIGH);  //Pongo 0 porque no se mueve en el eje X
     ejey(1,HIGH);  //Pongo 5 por ser un movimiento recto
    }
    else if ((301<Xv<699) && (301<Yv<699))  //Centro
    {
    delay(50);
    }
    
    /*else if ((Xv>700) && (Yv>700));  //Abajo derecha
    {
     ejey(10,LOW);  //Pongo 0 porque no se mueve en el eje Y
    }  */
    //cambiar while por for porque al meterle contador da mas pasos de los que quiero en la funcion. Poner limite de pasos en el contador del for
}
    
void ejex(int pasosx, boolean sentidox)
{
          digitalWrite (X_DIR, sentidox);
          for (i=0; i< pasosx; i++ )
            {
               digitalWrite(X_STEP, HIGH);
               delay(t);
               digitalWrite(X_STEP, LOW);
               delay(t);
            }
}
void ejey(int pasosy, boolean sentidoy)
{
          digitalWrite (Y_DIR, sentidoy);
          for (j=0; j<pasosy; j++)
            {
               digitalWrite(Y_STEP, HIGH);
               delay(t);
               digitalWrite(Y_STEP, LOW);
               delay(t);
            }
}
    
