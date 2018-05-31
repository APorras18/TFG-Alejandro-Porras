#define EN 8      /* Enable pin for all stepper outputs */
#define A_DIR 16   /* Direction pin for X axis */
#define A_STEP 15  /* Step pin for X axis */
int cuenta = 0; /* cuenta los pasos */
char senal = ' ';
boolean da = LOW; /* direccion del giro*/

void setup() {
  Serial.begin(9600);

  pinMode(EN, OUTPUT); 
  pinMode(A_DIR, OUTPUT); 
  pinMode(A_STEP, OUTPUT); 
  digitalWrite(EN, LOW); //Low para activar
}
void loop() {
  cuenta++;
 
  
   if (Serial.available() > 0)
    {
      senal = Serial.read();
      if (senal == 'z')
      {
           da = !da;
           digitalWrite (A_DIR, da);
           cuenta = 0;
      }
    }

  digitalWrite(A_STEP, HIGH); 
  delay(2);
  digitalWrite(A_STEP, LOW);
  delay(2);
}
