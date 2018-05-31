int pinJoyX = A4;
int pinJoyY = A5;
//const int pinJoyButton = 9;
 
void setup() {
 //  pinMode(pinJoyButton , INPUT_PULLUP);   //activar resistencia pull up 
   Serial.begin(9600);
}
 
void loop() {
   int Xvalue = 0;
   int Yvalue = 0;
   //bool buttonValue = false;
 
   //leer valores
   Xvalue = analogRead(pinJoyX);
   delay(1000);                 //es necesaria una pequeña pausa entre lecturas analógicas
   Yvalue = analogRead(pinJoyY);
   //buttonValue = digitalRead(pinJoyButton);
 
   //mostrar valores por serial
   Serial.print("X:" );
   Serial.println(Xvalue);
   Serial.print(" | Y: ");
   Serial.println(Yvalue);
   //Serial.print(" | Pulsador: ");
  // Serial.println(buttonValue);
   delay(1000);
}
