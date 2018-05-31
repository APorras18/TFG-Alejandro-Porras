
#define EN 8      /* Enable pin for all stepper outputs */
#define X_DIR 5   /* Direction pin for X axis */
#define X_STEP 2  /* Step pin for X axis */
#define Y_DIR 6   /* Direction pin for X axis */
#define Y_STEP 3  /* Step pin for X axis */
#define Z_DIR 7   /* Direction pin for X axis */
#define Z_STEP 4  /* Step pin for X axis */
int cuenta = 0; /* cuenta los pasos */
char senal = ' ';
boolean direccionx = LOW; /* direccion del giro*/
boolean direcciony = LOW; /* direccion del giro*/
boolean direccionz = LOW; /* direccion del giro*/


void setup() {
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

void loop() {
  cuenta++;

  
   if (Serial.available() > 0)
    {
      senal = Serial.read();
      if (senal == 'x')
        {
           direccionx = !direccionx;
           digitalWrite (X_DIR, direccionx);
           cuenta = 0;
        }
       else if (senal == 'y')
        {
           direcciony = !direcciony;
           digitalWrite (Y_DIR, direcciony);
           cuenta = 0;
        }
       else if (senal == 'z')
        {
           direccionz = !direccionz;
           digitalWrite (Z_DIR, direccionz);
           cuenta = 0;
        }
       else (senal == 'p');
        { 
          digitalWrite(EN, HIGH);
          delay(1000);
          digitalWrite(EN,LOW);
        }
    }
  digitalWrite(X_STEP, HIGH);
  delay(2);
  digitalWrite(X_STEP, LOW);
  delay(2);
  digitalWrite(Y_STEP, HIGH);
  delay(2);
  digitalWrite(Y_STEP, LOW);
  delay(2);
  digitalWrite(Z_STEP, HIGH); 
  delay(2);
  digitalWrite(Z_STEP, LOW);
  delay(2);

}
