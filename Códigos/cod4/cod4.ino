#define EN 8      /* Enable pin for all stepper outputs */

#define X_DIR 5   /* Direction pin for X axis */
#define X_STEP 2  /* Step pin for X axis */
int cuenta = 0; /* cuenta los pasos */
int cambio = 0;
boolean direccion = LOW; /* direccion del giro*/

void setup() {
  Serial.begin(9600);

  pinMode(EN, OUTPUT); 
  pinMode(X_DIR, OUTPUT); 
  pinMode(X_STEP, OUTPUT); 
  digitalWrite(EN, LOW); //Low para activar
}

void loop() {
  cuenta++;

  if (Serial.available() > 0)
    {
      cambio = Serial.read();
      if (cambio == '1')
        {
           direccion = !direccion;
           digitalWrite (X_DIR, direccion);
           cuenta = 0;
      }
    }
  digitalWrite(X_STEP, HIGH);
  delay(10);
  digitalWrite(X_STEP, LOW);
  delay(10);
}
