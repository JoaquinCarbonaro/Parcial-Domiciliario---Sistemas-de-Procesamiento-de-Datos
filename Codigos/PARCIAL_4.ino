#define A 12
#define B 13
#define C 7
#define D 8
#define E 9
#define F 11
#define G 10

#define INTERRUPTOR 2
#define UNIDAD A4
#define DECENA A5

#define APAGADOS 0
#define TIMEDISPLAYON 10

#define SENSOR_TEMPERATURA A1
#define PIN_MOTOR A3
#define FOTORRESISTENCIA A0
#define LED_ROJO 5

// VARIABLES
int numeroPrimo = 2;   // Guarda el valor del número primo
//int numero = 0;        // Guarda el valor del contador
// Agrega dos variables para controlar el tiempo de los dos contadores
unsigned long tiempoContadorNormal = 0;
unsigned long tiempoContadorPrimo = 0;

int mediaTemperatura = 0;
int intensidadLuz = 0;

// Variables para la temperatura
int temperatura;
int umbralTemperatura = 40;  // Define el umbral de temperatura deseado en grados Celsius

// FUNCION: SETUP
void setup() 
{
  pinMode(2, INPUT_PULLUP);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

  pinMode(UNIDAD, OUTPUT);
  pinMode(DECENA, OUTPUT);

  digitalWrite(UNIDAD, 0);
  digitalWrite(DECENA, 0);
  verEnDisplay(0);

  pinMode(SENSOR_TEMPERATURA, INPUT);
  pinMode(PIN_MOTOR, OUTPUT);
  pinMode(FOTORRESISTENCIA, INPUT);
  pinMode(LED_ROJO, OUTPUT);
}

void loop() 
{
    int posicionSwitch = digitalRead(INTERRUPTOR);

    // Leer la temperatura desde el sensor TMP36
    int lecturaSensor = analogRead(SENSOR_TEMPERATURA);
    float voltaje = (lecturaSensor / 1023.0) * 5.0; // Convertir lectura a voltaje
    temperatura = (voltaje - 0.5) * 100; // Calcular la temperatura en grados Celsius

    // Leer la intensidad de luz desde la fotoresistencia
    int lecturaLuz = analogRead(FOTORRESISTENCIA);
    intensidadLuz = map(lecturaLuz, 0, 1023, 0, 255); // Mapear la lectura de la fotorresistencia a un valor de brillo para el LED rojo

    if (temperatura >= umbralTemperatura) 
    {
        digitalWrite(PIN_MOTOR, HIGH); // Encender el motor
    } else {
        digitalWrite(PIN_MOTOR, LOW); // Apagar el motor
    }

    if (temperatura >= umbralTemperatura) 
    {
        analogWrite(LED_ROJO, intensidadLuz); // Ajustar la intensidad del LED rojo en función de la fotorresistencia
    } else {
        digitalWrite(LED_ROJO, LOW); // Apagar el LED rojo
    }

    // Lógica del interruptor deslizante
    if (posicionSwitch == LOW) 
    {
        // Aquí se implementa la lógica para mostrar solo los números primos.
        numeroPrimo++;
        if (numeroPrimo > 97) 
        {
            numeroPrimo = 0;
        }
        if (esPrimo(numeroPrimo)) 
        {
            iniciarContadorPrimo(numeroPrimo);
            delay(800);
        }
    } else 
    {
        // Apagar el sistema si el interruptor está en la posición de apagado
        apagarSistema();
    }
}

// FUNCION: APAGAR SISTEMA
// apaga todo el sistema
void apagarSistema() 
{
    digitalWrite(PIN_MOTOR, LOW); // Apagar el motor
    digitalWrite(LED_ROJO, LOW); // Apagar el LED rojo
    apagarDisplays(); // Apagar los displays
}

// FUNCION: INICIAR CONTADOR PRIMO
// Inicializa los displays para mostrar un número primo 
// en el formato UNIDAD-DECENA.
void iniciarContadorPrimo(int numeroPrimo) 
{

  digitoEncendido(APAGADOS);
  verEnDisplay(numeroPrimo % 10);  //UNIDADES
  digitoEncendido(UNIDAD);

  
  digitoEncendido(APAGADOS);
  verEnDisplay(numeroPrimo / 10);  //DECENAS
  digitoEncendido(DECENA);

}

// FUNCION: DIGITO ENCENDIDO
// La funcion tiene como objetivo controlar la visualizacion de 
// los displays a traves de la UNIDAD y DECENA, apagando y 
// prendiendo los mismos dependiendo el numero a mostrar
void digitoEncendido(int numero) 
{
    if (numero == UNIDAD) 
    {
        digitalWrite(UNIDAD, LOW);
        digitalWrite(DECENA, HIGH);
 		delay(TIMEDISPLAYON);
    }
    else if (numero == DECENA) 
    {
        digitalWrite(UNIDAD, HIGH);
        digitalWrite(DECENA, LOW);
		delay(TIMEDISPLAYON);
    } 
    else 
    {
        digitalWrite(UNIDAD, HIGH);
        digitalWrite(DECENA, HIGH);
		delay(TIMEDISPLAYON);
    }
}

// FUNCION: APAGAR DISPLAYS 
//Apaga todos los segmentos de los displays.  
void apagarDisplays() {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
}

         
//FUNCION: ES PRIMO
//Comprueba si un número es primo.
bool esPrimo(int num) 
{
  int contadorPrimo = 0;  // Inicializamos el contador de números primos a 0

  for (int i = 1; i <= num; i++) 
  {
    if (num % i == 0) 
    {
      contadorPrimo += 1;
    }
  }

  if (contadorPrimo == 2) 
  {
    return true;  // Si tiene exactamente 2 divisores, es primo
  } else 
  {
    return false;  // De lo contrario, no es primo
  }
}

// FUNCION: VER EN DISPLAY
// La funcion tiene como objetivo el manejo de los segmentos del
// display dependiendo del numero del contador (UNIDAD Y DECENA)                
void verEnDisplay(int numero)
{
    apagarDisplays();
    switch (numero)
    {
      case 0:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      break;
      case 1:
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        break;
      case 2:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(G, HIGH);
        break;
      case 3:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(G, HIGH);
        break;
      case 4:
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
      case 5:
        digitalWrite(A, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
      case 6:
        digitalWrite(A, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
      case 7:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        break;
      case 8:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
      case 9:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
    }
}

/*
// FUNCION: INICIAR CONTADOR
// La funcion tiene como objetivo pasarle a los display  
// el numero que debe mostrar a traves de los segmentos 
void iniciarContadorEntero(int numero)
{	
    digitoEncendido(APAGADOS);
    verEnDisplay(numero - (numero / 10) * 10);
    digitoEncendido(UNIDAD);

  
    digitoEncendido(APAGADOS);
    verEnDisplay(numero / 10);
    digitoEncendido(DECENA);
}
*/