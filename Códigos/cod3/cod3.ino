
#define EN 8      /* Enable pin for all stepper outputs */

#define Y_DIR 6   /* Direction pin for X axis */
#define Y_STEP 3  /* Step pin for X axis */
int cuenta = 0; /* cuenta los pasos */
boolean direccion = LOW; /* direccion del giro*/

void setup() {
  Serial.begin(9600);

  pinMode(EN, OUTPUT); 
  pinMode( Y_DIR, OUTPUT); 
  pinMode(Y_STEP, OUTPUT); 
  digitalWrite(EN, LOW); //Low para activar
}

void loop() {
  cuenta++;

  if (cuenta >= 400)
    {
      direccion = !direccion;
      digitalWrite (Y_DIR, direccion);
      cuenta = 0;
    }
  digitalWrite(Y_STEP, HIGH);
  delay(10);
  digitalWrite(Y_STEP, LOW);
  delay(10);
}
