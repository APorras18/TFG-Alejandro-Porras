
#define Y_DIR_PIN 5// poner número del pin de dirección
#define Y_STEP_PIN 2 // poner número de pin de conexión al motor
#define Y_ENABLE_PIN 8 // poner número de pin de poner en marcha 

int stepDelay = 200; // tiempo de parada para controlar la velocidad
int avancepasos = 0;

boolean primer_arranque = true;
int final_carrera_1 = 1;

void setup() 
{
  // Marcar los pines como salida
  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);
  pinMode(Y_ENABLE_PIN, OUTPUT);
  digitalWrite(Y_ENABLE_PIN, LOW);

  
  
  Serial.begin(9600);
}

void loop() 
{

if (primer_arranque == true) // cuando encendemos el programa nos vamos a la posicion del final de carrera nº1
  {
    posicion_1();
    primer_arranque = false;
  }
}

void posicion_1()
{
  while (final_carrera_1 == 1) // vamos a ir hasta la posicion del led 1
  {
    digitalWrite(Y_DIR_PIN, HIGH);
    for (int i = 0; i<3200; i++)
    {
    digitalWrite(Y_STEP_PIN, LOW);
    delayMicroseconds(stepDelay);
    digitalWrite(Y_STEP_PIN, HIGH);
    delayMicroseconds(stepDelay);
    }

      delay(3000); 
  }
}

