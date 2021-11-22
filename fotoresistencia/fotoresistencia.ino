#include <SoftwareSerial.h>
#define pin1 13
#define pin2 12
#define pin3 14
#define pin4 4
#define pin5 5
#define pin6 16
void setup() {
  pinMode(pin1, INPUT);
  Serial1.begin(9600);
  Serial.begin(9600);
  
}

bool a, b;
bool prev [6];
bool next [6];
void loop() {
  a = digitalRead(pin1);
  String str = String(a)+ "," + String(0);
  Serial1.println(str);
  Serial.println(str);

}
