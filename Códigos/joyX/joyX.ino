
#define EN 8      /* Enable pin for all stepper outputs */
#define X_DIR 5   /* Direction pin for X axis */
#define X_STEP 2  /* Step pin for X axis */
int cuenta = 0; /* cuenta los pasos */

boolean direccionx = LOW; /* direccion del giro*/

int X = A4 ;
int Xv= 0;
void setup()
    {
        Serial.begin(9600);
        pinMode(EN, OUTPUT); 
        pinMode(X_DIR, OUTPUT); 
        pinMode(X_STEP, OUTPUT); 
        digitalWrite(EN, LOW); //Low para activar
    }

void loop()
    {
      cuenta++; 
      Xv = analogRead(X);
      delay(10);
     Serial.println(Xv);
      if (Xv < 400 )
           {
              digitalWrite (EN, LOW);   
              direccionx = LOW;
              digitalWrite (X_DIR, direccionx);
              delay(2);
              digitalWrite (EN, HIGH);
              cuenta = 0;
           }
        else if (Xv > 700)
           {
              digitalWrite (EN, LOW);                   
              direccionx = HIGH;
              digitalWrite (X_DIR, direccionx);
              delay(2);
              digitalWrite (EN, HIGH);
              cuenta = 0;
           }
        else (301 < Xv <699);
           { 
              digitalWrite(EN, HIGH);
           }
digitalWrite(X_STEP, HIGH);
delay(2);
digitalWrite(X_STEP, LOW);
delay(2);
 }
