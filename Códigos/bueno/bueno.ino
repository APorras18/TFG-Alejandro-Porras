#define EN 8      /* Enable pin for all stepper outputs */
#define X_DIR 5   /* Direction pin for X axis */
#define X_STEP 2  /* Step pin for X axis */
#define Y_DIR 6   /* Direction pin for X axis */
#define Y_STEP 3  /* Step pin for X axis */
#define Z_DIR 7   /* Direction pin for X axis */
#define Z_STEP 4  /* Step pin for X axis */
int cuenta = 0; /* cuenta los pasos */
//int i=0;
int t=500; /*tiempo en milis para controlar los pasos*/
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
   delay(10);
   Yv = analogRead(Y);
   cuenta++; 
   if ((Xv <300) && (Yv <300))
    {
     ejex(5,LOW);
     ejey(5,LOW); 
    }
//cambiar while por for porque al meterle contador da mas pasos de los que quiero en la funcion. Poner limite de pasos en el contador del for
}
void ejex(int pasosx, boolean sentidox)
{
          digitalWrite (X_DIR, sentidox);
          while (pasosx>0)
            {
               digitalWrite(X_STEP, HIGH);
               delay(t);
               digitalWrite(X_STEP, LOW);
               delay(t);
               pasosx--;
            }
}
void ejey(int pasosy, boolean sentidoy)
{
          digitalWrite (X_DIR, sentidoy);
          while (pasosy>0)
            {
               digitalWrite(X_STEP, HIGH);
               delay(t);
               digitalWrite(X_STEP, LOW);
               delay(t);
               pasosy--;
            }
}

          

    
