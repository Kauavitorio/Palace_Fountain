const int A = A3; // Primeiramente setamos os 7 pinos dos segmentos
const int B = A5;
const int C = A1;
const int D = 2;
const int E = 3;
const int F = A4;
const int G = A2;

const int PT = A0; // setemaos o ponto do display

boolean ligaPonto = false;

// Variaveis liga e desliga p/ display 7 segmentos
const int l = 1, d = 0; // Display 7 segmentos (catodo comum)
//const int l = 0, d = 1; // Display 7 segmentos (anodo comum)



void StartEnconderDisplay(){
pinMode(A, OUTPUT); // seta todos as portas que estão os leds do display como saída
pinMode(B, OUTPUT);
pinMode(C, OUTPUT);
pinMode(D, OUTPUT);
pinMode(E, OUTPUT);
pinMode(F, OUTPUT);
pinMode(G, OUTPUT);
pinMode(PT, OUTPUT);
startdisplay();
}

void DisplayStatus(int status){
  switch (status){
    case 0:
        digitalWrite(A, l); //acende os leds que representam o número 0
        digitalWrite(B, l);
        digitalWrite(C, l);
        digitalWrite(D, l);
        digitalWrite(E, l);
        digitalWrite(F, l);
        digitalWrite(G, d);
        blinkDP(); // Função para piscar o ponto 2 vezes
    break;
    case 1:
        digitalWrite(A, d); //acende os leds que representam o número 1
        digitalWrite(B, l);
        digitalWrite(C, l);
        digitalWrite(D, d);
        digitalWrite(E, d);
        digitalWrite(F, d);
        digitalWrite(G, d);
        blinkDP();
    break;
    case 2:
        digitalWrite(A, l); //acende os leds que representam o número 2
        digitalWrite(B, l);
        digitalWrite(C, d);
        digitalWrite(D, l);
        digitalWrite(E, l);
        digitalWrite(F, d);
        digitalWrite(G, l);
        blinkDP();
    break;
    case 3:
        digitalWrite(A, l); //acende os leds que representam o número 3
        digitalWrite(B, l);
        digitalWrite(C, l);
        digitalWrite(D, l);
        digitalWrite(E, d);
        digitalWrite(F, d);
        digitalWrite(G, l);
        blinkDP();
    break;
    case 4:
        digitalWrite(A, d); //acende os leds que representam o número 4
        digitalWrite(B, l);
        digitalWrite(C, l);
        digitalWrite(D, d);
        digitalWrite(E, d);
        digitalWrite(F, l);
        digitalWrite(G, l);
        blinkDP();
    break;
    case 5:
        digitalWrite(A, l); //acende os leds que representam o número 5
        digitalWrite(B, d);
        digitalWrite(C, l);
        digitalWrite(D, l);
        digitalWrite(E, d);
        digitalWrite(F, l);
        digitalWrite(G, l);
        blinkDP();
    break;
    case 6:
        digitalWrite(A, d); //acende os leds que representam o número 6
        digitalWrite(B, d);
        digitalWrite(C, l);
        digitalWrite(D, l);
        digitalWrite(E, l);
        digitalWrite(F, l);
        digitalWrite(G, l);
        blinkDP();
    break;
    case 7:
        digitalWrite(A, l); //acende os leds que representam o número 7
        digitalWrite(B, l);
        digitalWrite(C, l);
        digitalWrite(D, d);
        digitalWrite(E, d);
        digitalWrite(F, d);
        digitalWrite(G, d);
        blinkDP();
    break;
    case 8:
        digitalWrite(A, l); //acende os leds que representam o número 8
        digitalWrite(B, l);
        digitalWrite(C, l);
        digitalWrite(D, l);
        digitalWrite(E, l);
        digitalWrite(F, l);
        digitalWrite(G, l);
        blinkDP();
    break;
    case 9:
        digitalWrite(A, l); //acende os leds que representam o número 9
        digitalWrite(B, l);
        digitalWrite(C, l);
        digitalWrite(D, d);
        digitalWrite(E, d);
        digitalWrite(F, l);
        digitalWrite(G, l);
        blinkDP();
    break;
  }
}

void startdisplay(){
  digitalWrite(A, l); //acende os leds que representam o número 0
digitalWrite(B, l);
digitalWrite(C, l);
digitalWrite(D, l);
digitalWrite(E, l);
digitalWrite(F, l);
digitalWrite(G, d);
delay(100);

digitalWrite(A, d); //acende os leds que representam o número 1
digitalWrite(B, l);
digitalWrite(C, l);
digitalWrite(D, d);
digitalWrite(E, d);
digitalWrite(F, d);
digitalWrite(G, d);
delay(100);

digitalWrite(A, l); //acende os leds que representam o número 2
digitalWrite(B, l);
digitalWrite(C, d);
digitalWrite(D, l);
digitalWrite(E, l);
digitalWrite(F, d);
digitalWrite(G, l);
delay(100);

digitalWrite(A, l); //acende os leds que representam o número 3
digitalWrite(B, l);
digitalWrite(C, l);
digitalWrite(D, l);
digitalWrite(E, d);
digitalWrite(F, d);
digitalWrite(G, l);
delay(100);

digitalWrite(A, d); //acende os leds que representam o número 4
digitalWrite(B, l);
digitalWrite(C, l);
digitalWrite(D, d);
digitalWrite(E, d);
digitalWrite(F, l);
digitalWrite(G, l);
delay(100);

digitalWrite(A, l); //acende os leds que representam o número 5
digitalWrite(B, d);
digitalWrite(C, l);
digitalWrite(D, l);
digitalWrite(E, d);
digitalWrite(F, l);
digitalWrite(G, l);
delay(100);

digitalWrite(A, d); //acende os leds que representam o número 6
digitalWrite(B, d);
digitalWrite(C, l);
digitalWrite(D, l);
digitalWrite(E, l);
digitalWrite(F, l);
digitalWrite(G, l);
delay(100);

digitalWrite(A, l); //acende os leds que representam o número 7
digitalWrite(B, l);
digitalWrite(C, l);
digitalWrite(D, d);
digitalWrite(E, d);
digitalWrite(F, d);
digitalWrite(G, d);
delay(100);

digitalWrite(A, l); //acende os leds que representam o número 8
digitalWrite(B, l);
digitalWrite(C, l);
digitalWrite(D, l);
digitalWrite(E, l);
digitalWrite(F, l);
digitalWrite(G, l);
delay(100);

digitalWrite(A, l); //acende os leds que representam o número 9
digitalWrite(B, l);
digitalWrite(C, l);
digitalWrite(D, d);
digitalWrite(E, d);
digitalWrite(F, l);
digitalWrite(G, l);
delay(100);
digitalWrite(A, l); //acende os leds que representam o número 8
digitalWrite(B, l);
digitalWrite(C, l);
digitalWrite(D, l);
digitalWrite(E, l);
digitalWrite(F, l);
digitalWrite(G, l);
delay(100);

digitalWrite(A, l); //acende os leds que representam o número 7
digitalWrite(B, l);
digitalWrite(C, l);
digitalWrite(D, d);
digitalWrite(E, d);
digitalWrite(F, d);
digitalWrite(G, d);
delay(100);
digitalWrite(A, l); //acende os leds que representam o número 0
digitalWrite(B, l);
digitalWrite(C, l);
digitalWrite(D, l);
digitalWrite(E, l);
digitalWrite(F, l);
digitalWrite(G, d);
delay(200);
        digitalWrite(A, d); //acende os leds que representam o número 1
        digitalWrite(B, d);
        digitalWrite(C, d);
        digitalWrite(D, d);
        digitalWrite(E, d);
        digitalWrite(F, d);
        digitalWrite(G, d);
}

void blinkDP() { // Faz o DP piscar 2 vezes.

  for (int i=0; i<=3; i++) {
    if (ligaPonto)  {
      digitalWrite(PT, l);
    }   else  {
      digitalWrite(PT, d);
    }
    ligaPonto = !ligaPonto;
    delay(1000);
  }
  
} 
