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
}
