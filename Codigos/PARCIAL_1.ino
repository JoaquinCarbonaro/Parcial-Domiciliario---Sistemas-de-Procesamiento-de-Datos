#define A 12
#define B 13
#define C 7
#define D 8
#define E 9
#define F 11
#define G 10
#define SUBE 4
#define BAJA 3
#define RESET 5
#define UNIDAD A4
#define DECENA A5
#define APAGADOS 0
#define TIMEDISPLAYON 10

int contador = 0;
int sube = 1;
int subePrevia = 1;
int baja = 1;
int bajaPrevia = 1;
int reset = 1;
int resetPrevia = 1;

void setup()
{
// Configuración de pines
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
// Configuración de pines de salida para el display de 7 segmentos
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
// Inicializa el display con el valor 0
  verEnDisplay(0);
}

void loop()
{
// Detecta si se presionó algún botón (SUBE, BAJA o RESET)
  int presiona = botonPresionado();
    
  if (presiona == SUBE)
  {
  // Incrementa el contador
    contador++;
    if (contador > 99)
    {
      contador = 0;
    }
  }
  
  else if (presiona == BAJA)
  {
  // Decrementa el contador
    contador--;
    if (contador < 0)
    {
      contador = 99;
    }
  }
  
  else if (presiona == RESET)
  {
  // Reinicia el contador a 0
    contador = 0;
  }
// Muestra el contador en el display
  ContadorEntero(contador);
}


// Función para detectar qué botón se ha presionado
int botonPresionado(void)
{
  sube = digitalRead(SUBE);
  baja = digitalRead(BAJA);
  reset = digitalRead(RESET);
  
  if (sube) //entra cuando NO presiona, osea HIGH
    subePrevia = 1; //define estado anterior en HIGH
  if (baja)
    bajaPrevia = 1;
  if (reset)
    resetPrevia = 1;
  
  if (sube == 0 && sube != subePrevia) //si se presiono (LOW) y este es distinto al estado anterior
  {
    subePrevia = sube; //mismo valores
    return SUBE; //devuelve define SUBE
  }
  if (baja == 0 && baja != bajaPrevia)
  {
    bajaPrevia = baja;
    return BAJA;
  }
  if (reset == 0 && reset != resetPrevia)
  {
    resetPrevia = reset;
    return RESET;
  }
  return 0;
}


// Función para mostrar el contador en el display de 7 segmentos
void ContadorEntero(int numero)
{
    digitoEncendido(APAGADOS);
    verEnDisplay(numero / 10);
    digitoEncendido(DECENA);

    digitoEncendido(APAGADOS);
    verEnDisplay(numero - (numero / 10) * 10);
    digitoEncendido(UNIDAD);
}

//Función para activar un dígito (unidad o decena) 
void digitoEncendido(int digito)
{
  if (digito == UNIDAD)
  {
    digitalWrite(UNIDAD, LOW);
    digitalWrite(DECENA, HIGH);
    delay(TIMEDISPLAYON);
  }
  else if (digito == DECENA)
  {
    digitalWrite(UNIDAD, HIGH);
    digitalWrite(DECENA, LOW);
    delay(TIMEDISPLAYON);
  }
  else //APAGADOS
  {
    digitalWrite(UNIDAD, HIGH);
    digitalWrite(DECENA, HIGH);
  }
}  


// Función para mostrar un dígito en el display de 7 segmentos
void verEnDisplay(int digit)
{
// Apaga todos los segmentos
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  
// Configura los pines para mostrar el dígito
  switch (digit)
  {
    case 0:
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      break;
    }
    case 1:
    {
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    }
    case 2:
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(G, HIGH);
      break;
    }
    case 3:
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(G, HIGH);
      break;
    }
    case 4:
    {
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    }
    case 5:
    {
      digitalWrite(A, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    }
    case 6:
    {
      digitalWrite(A, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    }
    case 7:
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    }
    case 8:
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    }
    case 9:
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    }
  }
}
