/*
 * 
 * José Carlo Santizo Olivet
 * Carné 20185
 * Laboratorio 3 - Electrónica digital 2
 * 
 */

//-------------------Definición de pines-------------------

// Botones de inicio/reinicio de carrera
#define START PF_0                                          // Pushbutton 1 (sw1) tiene la función de inicio de carrera
#define RESET PF_4                                          // Pushbutton 2 (sw2) tiene la función de reiniciar la carrera

// Botones para jugador 1 y 2
#define J1 PA_3                                             // Botón para jugador 1 en pin PB0    
#define J2 PA_2                                             // Botón para jugador 2 en pin PB1

// Pines para LED RGB integrada
#define LED_verde PF_3                                      // Definición de pin para prender color verde en LED RGB integrada
#define LED_azul PF_2                                       // Definición de pin para prender color azul en LED RGB integrada
#define LED_rojo PF_1                                       // Definición de pin para prender color rojo en LED RGB integrada

// Pines de puertos para pista de carrera
#define PORTA_0 PB_5
#define PORTA_1 PB_0
#define PORTA_2 PB_1
#define PORTA_3 PE_4
#define PORTA_4 PE_5
#define PORTA_5 PB_4
#define PORTA_6 PA_5
#define PORTA_7 PA_6

#define PORTB_0 PD_0
#define PORTB_1 PD_1
#define PORTB_2 PD_2
#define PORTB_3 PD_3
#define PORTB_4 PE_1
#define PORTB_5 PE_2
#define PORTB_6 PE_3
#define PORTB_7 PB_3

//---------------Declaración de variables-------------------
int Estado_START = 0;
int Estado_J1 = 0;
int Estado_J2 = 0;
int Estado_RESET = 0;
int Estado_PORTA = 0;
int Estado_PORTB = 0;

int Bandera_inicio = 0;
int PORTA = 0;
int PORTB = 0;
int presionado_J1;
int presionado_J2;

//------------------Configuración---------------------------  
void setup() {

  // Declaraciones de entradas y salidas
  pinMode(START, INPUT_PULLUP);                             // Botón para start como INPUT
  pinMode(RESET, INPUT_PULLUP);                             // Botón para stop como INPUT

  pinMode(LED_verde, OUTPUT);                               // pin de LED_verde como output
  pinMode(LED_azul, OUTPUT);                                // pin de LED_azul como output
  pinMode(LED_rojo, OUTPUT);                                // pin de LED_rojo como output

  pinMode(J1, INPUT_PULLUP);                                // Botón para J1 como INPUT
  pinMode(J2, INPUT_PULLUP);                                // Botón para J2 como INPUT

  // Declaraciones de puertos
  pinMode(PORTA_0, OUTPUT);
  pinMode(PORTA_1, OUTPUT);
  pinMode(PORTA_2, OUTPUT);
  pinMode(PORTA_3, OUTPUT);
  pinMode(PORTA_4, OUTPUT);
  pinMode(PORTA_5, OUTPUT);
  pinMode(PORTA_6, OUTPUT);
  pinMode(PORTA_7, OUTPUT);

  pinMode(PORTB_0, OUTPUT);
  pinMode(PORTB_1, OUTPUT);
  pinMode(PORTB_2, OUTPUT);
  pinMode(PORTB_3, OUTPUT);
  pinMode(PORTB_4, OUTPUT);
  pinMode(PORTB_5, OUTPUT);
  pinMode(PORTB_6, OUTPUT);
  pinMode(PORTB_7, OUTPUT);
  
}

//-----------------------Main Loop---------------------------
void loop() {
  // Código Principal

  // Lectura de pines
  Estado_START = digitalRead(START);                        // Leer pin para botón de START
  Estado_RESET = digitalRead(RESET);                        // Leer pin para botón de RESET

  Estado_J1 = digitalRead(J1);                              // Leer pin para botón de J1
  Estado_J2 = digitalRead(J2);                              // Leer pin para botón de J2

  Estado_PORTA = digitalRead(PORTA_7);
  Estado_PORTB = digitalRead(PORTB_7);

  // Semáforo si se presiona botón de START
  if(Estado_START == HIGH && Bandera_inicio == 0 && Estado_RESET == LOW){      // Si se presiona el botón de START
    digitalWrite(LED_rojo, HIGH);                           // Asignar LED_rojo como 1
    delay(1000);                                            // Esperar 1 segundo

    digitalWrite(LED_verde, HIGH);                          // Asignar LED_verde y LED_rojo como 1 (Amarillo)
    delay(1000);                                            // Esperar 1 segundo

    digitalWrite(LED_rojo, LOW);                            // Asignar LED_rojo como 0 (Amarillo)
    Bandera_inicio = 1;                                     // Utilizar Bandera_inicio para indicar que la carrera ya puede iniciar
    delay(500);
  }

  // Reinicio de todo si se preciona el botón de RESET
  if(Estado_START == LOW && Estado_RESET == HIGH){          // Si se presiona el botón de RESET, entonces:
    digitalWrite(LED_rojo, LOW);                            // Apagar LED_rojo
    digitalWrite(LED_verde, LOW);                           // Apagar LED_verde
    digitalWrite(LED_azul, LOW);                            // Apagar LED_azul
    
    digitalWrite(PORTA_0, LOW);                             // Apagar pin 0 de puerto A
    digitalWrite(PORTA_1, LOW);                             // Apagar pin 1 de puerto A
    digitalWrite(PORTA_2, LOW);                             // Apagar pin 2 de puerto A
    digitalWrite(PORTA_3, LOW);                             // Apagar pin 3 de puerto A
    digitalWrite(PORTA_4, LOW);                             // Apagar pin 4 de puerto A
    digitalWrite(PORTA_5, LOW);                             // Apagar pin 5 de puerto A
    digitalWrite(PORTA_6, LOW);                             // Apagar pin 6 de puerto A
    digitalWrite(PORTA_7, LOW);                             // Apagar pin 7 de puerto A

    digitalWrite(PORTB_0, LOW);                             // Apagar pin 0 de puerto B
    digitalWrite(PORTB_1, LOW);                             // Apagar pin 1 de puerto B
    digitalWrite(PORTB_2, LOW);                             // Apagar pin 2 de puerto B
    digitalWrite(PORTB_3, LOW);                             // Apagar pin 3 de puerto B
    digitalWrite(PORTB_4, LOW);                             // Apagar pin 4 de puerto B
    digitalWrite(PORTB_5, LOW);                             // Apagar pin 5 de puerto B
    digitalWrite(PORTB_6, LOW);                             // Apagar pin 6 de puerto B
    digitalWrite(PORTB_7, LOW);                             // Apagar pin 7 de puerto B
    
    Bandera_inicio = 0;                                     // Reiniciar bandera que indica el poder reiniciar la carrera
    PORTA = 0;
    PORTB = 0;
  }

  if(Bandera_inicio == 1){                                  // Si el semáforo finalizó la cuenta regresiva, entonces:

    // Control de botones para Carrera
    if(Estado_J1 == LOW)                                    // Observar si J1 está presionado
    {
      presionado_J1 = 1;                                    // Cambiar estado de variable J1
    }
    if (Estado_J1 == HIGH && presionado_J1 == 1)            // Detectar cuando el botón J1 se soltó
    {
      PORTA++;                                              // Incrementar primer puerto
      Tabla_puertoA(PORTA);                                 // Pasar por tabla para indicar el pin a prender en TIVA C
      presionado_J1 = 0;                                    // Cambiar variable presionado_J1 como antirebote
    }

    if(Estado_J2 == LOW)                                    // Observar si J2 está presionado
    {
      presionado_J2 = 1;                                    // Cambiar estado de variable J2
    }
    if (Estado_J2 == HIGH && presionado_J2 == 1)            // Detectar cuando el botón J2 se soltó
    {
      PORTB++;                                              // Incrementar segundo puerto                                        
      Tabla_puertoB(PORTB);                                 // Pasar por tabla para indicar el pin a prender en TIVA C
      presionado_J2 = 0;                                    // Cambiar variable presionado_J2 como antirebote
    }


    // Control de ganadores de carrera
    if(Estado_PORTA == HIGH && Estado_PORTB == LOW){        // Si el jugador 1 llega a la meta primero, LED RGB = blanco
      digitalWrite(LED_rojo, HIGH);                         // Prender LED_rojo
      digitalWrite(LED_verde, HIGH);                        // Prender LED_verde
      digitalWrite(LED_azul, HIGH);                         // Prender LED_azul
      Bandera_inicio = 0;
    }
    else if(Estado_PORTA == LOW && Estado_PORTB == HIGH){   // Si el jugador 2 llega a la meta primero, LED RGB = morado
      digitalWrite(LED_rojo, HIGH);                         // Apagar LED_rojo
      digitalWrite(LED_verde, LOW);                         // Prender LED_verde
      digitalWrite(LED_azul, HIGH);                         // Prender LED_azul
      Bandera_inicio = 0;
    }
      
  }
  
  
}


//------------------------Subrutinas------------------------------
void Tabla_puertoA(int a){                                  // Colocar variable que incrementa por boton de J1
  switch(a){
    case 1:                                                 // Si botón J1 = 1, PORTA_0 = 1
      digitalWrite(PORTA_0, HIGH);
      break;
    case 2:                                                 // Si botón J1 = 2, PORTA_1 = 1
      digitalWrite(PORTA_1, HIGH);
      digitalWrite(PORTA_0, LOW);
      break;
    case 3:                                                 // Si botón J1 = 3, PORTA_2 = 1
      digitalWrite(PORTA_2, HIGH);
      digitalWrite(PORTA_1, LOW);
      break;
    case 4:                                                 // Si botón J1 = 4, PORTA_3 = 1
      digitalWrite(PORTA_3, HIGH);
      digitalWrite(PORTA_2, LOW);
      break;
    case 5:                                                 // Si botón J1 = 5, PORTA_4 = 1
      digitalWrite(PORTA_4, HIGH);
      digitalWrite(PORTA_3, LOW);
      break;
    case 6:                                                 // Si botón J1 = 6, PORTA_5 = 1
      digitalWrite(PORTA_5, HIGH);
      digitalWrite(PORTA_4, LOW);
      break;
    case 7:                                                 // Si botón J1 = 7, PORTA_6 = 1
      digitalWrite(PORTA_6, HIGH);
      digitalWrite(PORTA_5, LOW);
      break;
    case 8:                                                 // Si botón J1 = 8, PORTA_7 = 1
      digitalWrite(PORTA_7, HIGH);
      digitalWrite(PORTA_6, LOW);
      break;
    default:                                                // Estado default PORTA_0 = 0;
      digitalWrite(PORTA_1, LOW);
      digitalWrite(PORTA_0, LOW);
      break;
  }
}

void Tabla_puertoB(int b){                                  // Colocar variable que incrementa por boton de J1
  switch(b){
    case 1:                                                 // Si botón J2 = 1, PORTB_0 = 1
      digitalWrite(PORTB_0, HIGH);
      break;
    case 2:                                                 // Si botón J2 = 2, PORTB_1 = 1
      digitalWrite(PORTB_1, HIGH);
      digitalWrite(PORTB_0, LOW);
      break;
    case 3:                                                 // Si botón J2 = 3, PORTB_2 = 1
      digitalWrite(PORTB_2, HIGH);
      digitalWrite(PORTB_1, LOW);
      break;
    case 4:                                                 // Si botón J2 = 4, PORTB_3 = 1
      digitalWrite(PORTB_3, HIGH);
      digitalWrite(PORTB_2, LOW);
      break;
    case 5:                                                 // Si botón J2 = 5, PORTB_4 = 1
      digitalWrite(PORTB_4, HIGH);
      digitalWrite(PORTB_3, LOW);
      break;
    case 6:                                                 // Si botón J2 = 6, PORTB_5 = 1
      digitalWrite(PORTB_5, HIGH);
      digitalWrite(PORTB_4, LOW);
      break;
    case 7:                                                 // Si botón J2 = 7, PORTB_6 = 1
      digitalWrite(PORTB_6, HIGH);
      digitalWrite(PORTB_5, LOW);
      break;
    case 8:                                                 // Si botón J2 = 8, PORTB_7 = 1
      digitalWrite(PORTB_7, HIGH);
      digitalWrite(PORTB_6, LOW);
      break;
    default:                                                // Estado default PORTB_0 = 0;
      digitalWrite(PORTB_1, LOW);
      digitalWrite(PORTB_0, LOW);
      break;
  }
}
