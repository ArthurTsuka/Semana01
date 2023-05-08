"C:\Users\Inteli\Documents\GitHub\Semana01\Exercicio01\Exercicio01.ino"#include <bits/stdc++.h>
using namespace std;

const int LED_PINS[] = {25, 2, 27, 18};  // yellow, blue, green, red
const int BUTTON_PINS[] = {34, 35, 32, 13};  // yellow, blue, green, red
const int restart=4;
const int NUM_LEDS = 4;
const int NUM_BUTTONS = 4;
vector<int> player_sequence;
vector<int> sequence;
void setup() {

  pinMode(LED_BUILTIN, OUTPUT);  // onboard LED
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(BUTTON_PINS[i], INPUT_PULLUP);
  }
  pinMode(restart,INPUT_PULLUP);
  Serial.begin(9600);
  
}
void resetESP32() {
  // Disable interrupts
  noInterrupts();

  // Restart the ESP32
  ESP.restart();

  // Wait for the restart to take effect
  while (true) {}
}


void machine_turn(vector<int>& psequence){
  int random_number = random(0, 4);
  psequence.push_back(random_number);
  for(int i=0;i<psequence.size();i++){
    digitalWrite(LED_PINS[psequence[i]],HIGH);
    delay(500);
    digitalWrite(LED_PINS[psequence[i]],LOW);
    delay(500);
  }
}


void player_turn(vector<int> psequence, vector<int> pplayer_sequence){
  player_sequence.clear();
  while(pplayer_sequence.size()<psequence.size()){
    if(digitalRead(BUTTON_PINS[0])==HIGH){
      pplayer_sequence.push_back(0);
      digitalWrite(LED_PINS[0],HIGH);
      delay(500);
       digitalWrite(LED_PINS[0],LOW);
      
    }  
    else if(digitalRead(BUTTON_PINS[1])==HIGH){
      pplayer_sequence.push_back(1);
      digitalWrite(LED_PINS[1],HIGH);
      delay(500);
       digitalWrite(LED_PINS[1],LOW);
    }
    
    else if(digitalRead(BUTTON_PINS[2])==HIGH){
      pplayer_sequence.push_back(2);
      digitalWrite(LED_PINS[2],HIGH);
      delay(500);
       digitalWrite(LED_PINS[2],LOW);
    }
    
    else if(digitalRead(BUTTON_PINS[3])==HIGH){
      pplayer_sequence.push_back(3);
      digitalWrite(LED_PINS[3],HIGH);
      delay(500);
       digitalWrite(LED_PINS[3],LOW);
    }
    else if(digitalRead(restart)==HIGH){
    resetESP32();
  }
    for(int i=0;i<pplayer_sequence.size();i++){
      if(pplayer_sequence[i]!=psequence[i]){
        gameover();
      }
    }
   
  }
  delay(500);
}
void gameover(){
  digitalWrite(LED_PINS[0],HIGH);
  digitalWrite(LED_PINS[1],HIGH);
  digitalWrite(LED_PINS[2],HIGH);
  digitalWrite(LED_PINS[3],HIGH);
  delay(1000);
  digitalWrite(LED_PINS[0],LOW);
  digitalWrite(LED_PINS[1],LOW);
  digitalWrite(LED_PINS[2],LOW);
  digitalWrite(LED_PINS[3],LOW);
  resetESP32();

}

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




void loop(){
  if(digitalRead(restart)==HIGH){
    resetESP32();
  }
  machine_turn(sequence);
  player_turn(sequence, player_sequence);
}