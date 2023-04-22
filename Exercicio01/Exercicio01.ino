#include <SoftwareSerial.h>

const int LED1 = 8;
const int LED2 = 9;
int pisca = 10;


void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);

}
void loop() {
  // Pergunta no Serial Monitor o nome.
  Serial.println("Qual o seu nome? ");
  while(!Serial.available());
  String nome = Serial.readString();
  
  // Pergunta qual produto o usuario quer.
  Serial.println("Qual produto voce quer? ");
  while(!Serial.available());
  String produto = Serial.readString();
  
  // Pergunta o saldo do usario.
  Serial.println("Quanto dinheiro possui? ");
  while(!Serial.available());
  String dinheiro = Serial.readString();
  float valor = atof(dinheiro.c_str());

  bool temIdade = false;
  int idade = 19;

  // Verifica se o usuario é maior de idade    
  if(idade > 18) {
  	temIdade = true;
  }

    // Se for maior de idade e tiver dinheiro suficiente, consegue comprar o produto desejado e o LED acende.
  if(temIdade) {
    if(valor > 250) {
      Serial.println  (nome + ", Voce consegue comprar um " + produto);
      digitalWrite(LED1, HIGH);
    } else {
      // Se nao tiver dinheiro suficiente, nao consegue comprar o produto e o LED permanece desligado.      
      Serial.println(nome + ", Voce nao possui dinheiro suficiente para comprar um " + produto);
      digitalWrite(LED1, LOW);
    }
  }
}
  if(valor > 10000) {
    digitalWrite(LED1, LOW);
    delay(500);
    digitalWrite(LED2, HIGH);
    delay(500);
    digitalWrite(LED1, HIGH);
    delay(500);
    digitalWrite(LED2, LOW);
    delay(500);
}

//Autodestruicao.
  while(pisca > 0) {
    Serial.println(String(pisca) + " Segundos para a autodestruição");
    pisca--;    
  } 

  Serial.println(" ");
    
}




