
#define EN 8     
#define X_DIR 5   
#define X_STEP 2 
int cuenta = 0;
boolean dx = LOW;
int X = A4;
int Xv = 0;

void setup() {
  Serial.begin(9600);
  pinMode(EN,OUTPUT);
  pinMode(X_DIR, OUTPUT);
  pinMode(X_STEP, OUTPUT);
  digitalWrite(EN, LOW);
}

void loop() {

Xv = analogRead (X);
delay(10);
cuenta++;
if (Xv < 300)
  {
    dx = HIGH;
    digitalWrite(X_DIR, dx);
    delay(5);
    dx = LOW;
    cuenta = 0;
  }
else;
  {
    dx = LOW;
    digitalWrite (X_DIR, dx);
    delay(5);
    cuenta = 0;
  }
           digitalWrite(X_STEP, HIGH);
           delay(2);
           digitalWrite(X_STEP, LOW);
           delay(2);
  }

