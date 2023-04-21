#include <SoftwareSerial.h>

const int LED1 = 8;
const int LED2 = 9;
int pisca = 10;


void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);

}


