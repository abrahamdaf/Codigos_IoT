#include <SoftwareSerial.h>
#define pin1 13
#define pin2 12
#define pin3 14
#define pin4 4
#define pin5 5
#define pin6 16
void setup() {
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  pinMode(pin5, INPUT);
  pinMode(pin6, INPUT);
  Serial1.begin(9600);
  Serial.begin(9600);
  
}

bool prev [6] {1,1,1,1,1,1};
bool next [6];
bool dif = 0;
void sendValues(){
  String message = "b," + String (next[0]) + "," + String (next[1]) + "," + String (next[2]) +
  "," + String (next[3]) + "," + String (next[4]) + "," + String (next[5]) + "\n";
  Serial1.print(message);
  Serial.print(message);
}

void loop() {
  
  dif = 0;
  next[0] = digitalRead(pin1);
  next[1] = digitalRead(pin2);
  next[2] = digitalRead(pin3);
  next[3] = digitalRead(pin4);
  next[4] = digitalRead(pin5);
  next[5] = digitalRead(pin6);
  for (int i = 0; i < 6; i++){
    if(next[i] != prev[i]){
      dif = 1;
    }
  }
  while(dif == 1){
    if(!Serial.available()){
      sendValues();
      dif = 0;
    }
    delay(100);
    Serial.read();
  }

  for (int i = 0; i < 6; i++){
    prev[i] = next[i];
  }
  delay(1000);
}
