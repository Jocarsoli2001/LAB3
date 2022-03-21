//-------------------Definición de pines-------------------

// Botones de inicio/reinicio de carrera
#define START PF_4                                          // Pushbutton 1 (sw1) tiene la función de inicio de carrera
#define RESET PF_2                                          // Pushbutton 2 (sw2) tiene la función de reiniciar la carrera

// Botones para jugador 1 y 2
#define J1 PB_0                                             // Botón para jugador 1 en pin PB0    
#define J2 PB_1                                             // Botón para jugador 2 en pin PB1

// Pines para LED RGB integrada
#define LED_verde PF_3                                      // Definición de pin para prender color verde en LED RGB integrada
#define LED_azul PF_2                                       // Definición de pin para prender color azul en LED RGB integrada
#define LED_rojo PF_1                                       // Definición de pin para prender color rojo en LED RGB integrada

//---------------Declaración de variables-------------------
int Estado_START = 0;
int Estado_J1 = 0;
int Estado_J2 = 0;
int Estado_RESET = 0;

int Bandera_inicio = 0;
  
void setup() {
  
  // Declaraciones de entradas y salidas
  pinMode(START, INPUT_PULLUP);                             // Botón para start como INPUT
  pinMode(RESET, INPUT_PULLUP);                             // Botón para stop como INPUT

  pinMode(LED_verde, OUTPUT);                               // pin de LED_verde como output
  pinMode(LED_azul, OUTPUT);                                // pin de LED_azul como output
  pinMode(LED_rojo, OUTPUT);                                // pin de LED_rojo como output

  pinMode(J1, INPUT_PULLUP);                                // Botón para J1 como INPUT
  pinMode(J2, INPUT_PULLUP);                                // Botón para J2 como INPUT
  
}

void loop() {
  // Código Principal

  // Lectura de pines
  Estado_START = digitalRead(START);                        // Leer pin para botón de START
  Estado_RESET = digitalRead(RESET);                        // Leer pin para botón de RESET

  Estado_J1 = digitalRead(J1);                              // Leer pin para botón de J1
  Estado_J2 = digitalRead(J2);                              // Leer pin para botón de J2

  // Semáforo si se presiona botón de START
  if(Estado_START == HIGH && Bandera_inicio == 0 && Estado_RESET == LOW){      // Si se presiona el botón de START
    digitalWrite(LED_rojo, HIGH);                           // Asignar LED_rojo como 1
    delay(1000);                                            // Esperar 1 segundo

    digitalWrite(LED_verde, HIGH);                          // Asignar LED_verde y LED_rojo como 1 (Amarillo)
    delay(1000);                                            // Esperar 1 segundo

    digitalWrite(LED_rojo, LOW);                            // Asignar LED_rojo como 0 (Amarillo)
    Bandera_inicio = 1;                                     // Utilizar Bandera_inicio para indicar que la carrera ya puede iniciar
    delay(500);                                             // Esperar 500 ms
  }

  // Reinicio de todo si se preciona el botón de RESET
  else if(Estado_START == LOW && Estado_RESET == HIGH){     // Si se presiona el botón de RESET, entonces:
    digitalWrite(LED_rojo, LOW);                            // Apagar LED_rojo
    digitalWrite(LED_verde, LOW);                           // Apagar LED_verde
    digitalWrite(LED_azul, LOW);                            // Apagar LED_azul
    Bandera_inicio = 0;                                     // Reiniciar bandera que indica el poder reiniciar la carrera
  }
}
