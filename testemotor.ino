// Programa : Acionamento Motor Kalatec KTC - HT23-397
// Motor Kalatec KTC - HT23-397- ordem: amarelo(A), verde(B), preto(C), vermelho(D);
// (Branco_Vermelho + Branco_Preto)(Branco_Verde + Branco_Amarelo)
// Autor: Elvis
// Data 29/10/2019 15h00

//porta 1
int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;


void setup()
{
  Serial.begin(9600);
  // Define os pinos como saida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

int tempo = 1800;
int npasso = 1;
int numPassos = 10;
int i = 0;
int j = 0;

void loop()
{

  for (j = 0; j <= 4; j++) {
  
    for (i = 0; i < numPassos; i++) {
      npasso++;
      printf(npasso);
      if (npasso > 4) {
        npasso = 1;
      }
      passo(npasso);
      delayMicroseconds(tempo);
        
    }
    passoDisabled1();
  }
  //passo(0);

  delay(200);

  /*for (j = 0; j <= 4; j++) {
    for (i = 0; i < numPassos; i++) {
      npasso--;
      if (npasso < 1) {
        npasso = 4;
      }
      passo(npasso);
      delayMicroseconds(tempo);
    }
  }
  passo(0);
  delay(200);
  passoDisabled1();
  */
  

  
  
}

void passo(int num) {
  if (num == 0) {
    // Passo 0 - desabilita
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 0);
  } else if (num == 1) {
    // Passo 1
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 0);
    analogWrite(IN4, 1);
  } else if (num == 2) {
    // Passo 2
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
  } else if (num == 3) {
    // Passo 3
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
  } else if (num == 4) {
    // Passo 4
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
  }
}

void passoDisabled1() {
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 0);
}
//FIM PROGRAMA MOTOR KALATEC SELADORA MODO BIPOLAR SERIE

void passoEnable() {
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 1);
}
