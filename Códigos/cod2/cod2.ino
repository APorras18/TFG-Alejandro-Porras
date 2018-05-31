#define EN 8      /* Enable pin for all stepper outputs */

#define X_DIR 5   /* Direction pin for X axis */
#define X_STEP 2  /* Step pin for X axis */

#define Y_DIR 6   /* Direction pin for Y axis */
#define Y_STEP 3  /* Step pin for Y axis */

#define Z_DIR 7   /* Direction pin for Z axis */
#define Z_STEP 4  /* Step pin for Z axis */

#define A_DIR 13  /* Direction pin for Aux driver. Requires D13 and A-DIR pins to be shorted */
#define A_STEP 12 /* Direction pin for Aux driver. Requires D12 and A-STEP pins to be shorted */

#define X_ENDSTOP 9   /* X axis endstop input pin */
#define Y_ENDSTOP 10  /* Y axis endstop input pin */
#define Z_ENDSTOP 11  /* Z axis endstop input pin */
#define ABORT A0  /* Abort input pin */
#define HOLD A1   /* Hold input pin */
#define RESUME A2 /* Resume input pin */

int Count = 0; /* Counter to count number of steps made */
boolean Direction = LOW; /* Rotational direction of stepper motors */

/* The setup routine runs once when you press reset: */
void setup() 
{                
  /* Initialize serial */
  Serial.begin(9600);
  
  /* Configure the steper drive pins as outputs */ 
  pinMode(EN, OUTPUT); 
  pinMode(X_DIR, OUTPUT); 
  pinMode(X_STEP, OUTPUT); 
  pinMode(Y_DIR, OUTPUT); 
  pinMode(Y_STEP, OUTPUT); 
  pinMode(Z_DIR, OUTPUT); 
  pinMode(Z_STEP, OUTPUT); 
  pinMode(A_DIR, OUTPUT); 
  pinMode(A_STEP, OUTPUT); 
  
  /* Configure the control pins as inputs with pullups */
  pinMode(X_ENDSTOP, INPUT_PULLUP);
  pinMode(Y_ENDSTOP, INPUT_PULLUP);
  pinMode(Z_ENDSTOP, INPUT_PULLUP);

  pinMode(ABORT, INPUT_PULLUP);
  pinMode(HOLD, INPUT_PULLUP);
  pinMode(RESUME, INPUT_PULLUP);

  /* Enable the X, Y, Z & Aux stepper outputs */
  digitalWrite(EN, LOW); //Low to enable
}

// the loop routine runs over and over again forever:
void loop() 
{
  /* Count one step */
  Count++;
    
  /* If we have reached 500 steps then change the stepper direction and reset the counter */
  if (Count >= 500)
  {
    Direction = Direction;
    digitalWrite(X_DIR, Direction); // Low = CW 
//    digitalWrite(Y_DIR, Direction); // Low = CW 
//    digitalWrite(Z_DIR, Direction); // Low = CW 
//    digitalWrite(A_DIR, Direction); // Low = CW 
    Count = 0;
  }
    
  /* Step the X, Y, Z, and Aux motors */  
  digitalWrite(X_STEP, HIGH); 
  delay(10); 
//  digitalWrite(Y_STEP, HIGH); 
//  delay(1); 
//  digitalWrite(Z_STEP, HIGH); 
//  delay(1);    
//  digitalWrite(A_STEP, HIGH); 
//  delay(1); 
//  
  digitalWrite(X_STEP, LOW);  
  delay(10); 
//  digitalWrite(Y_STEP, LOW); 
//  delay(1); 
//  digitalWrite(Z_STEP, LOW);  
//  delay(1); 
//  digitalWrite(A_STEP, LOW);  
//  delay(1);
//  
//  /* Check state of inputs */
//  if (!digitalRead(X_ENDSTOP)) Serial.println("X-axis end-stop triggered!"); 
//  if (!digitalRead(Y_ENDSTOP)) Serial.println("Y-axis end-stop triggered!"); 
//  if (!digitalRead(Z_ENDSTOP)) Serial.println("Z-axis end-stop triggered!"); 
//  if (!digitalRead(ABORT)) Serial.println("Abort input triggered!"); 
//  if (!digitalRead(HOLD)) Serial.println("Hold input triggered!"); 
//  if (!digitalRead(RESUME)) Serial.println("Resume input triggered!"); 
}
