#include <ESP8266WiFi.h>
#include "FirebaseESP8266.h"
#include <SoftwareSerial.h>
#define pin1 13
#define pin2 12
#define pin3 14
#define pin4 4
#define pin5 5
#define pin6 16

#define ssid "abradeal"
#define password "no me acuerdo"

#define API_key "AIzaSyDBmwBEgAqANg0TyISjGtwhqjRnv9vzCpg"

const char *FIREBASE_HOST= "https://reto-estacionamiento-default-rtdb.firebaseio.com/";
const char *FIREBASE_AUTH = "4cdpt5Qc5ut5GCawjaTvH7PpePK5yP5mG0qxTICH";

FirebaseData firebaseData;
void setup() {
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  pinMode(pin5, INPUT);
  pinMode(pin6, INPUT);
  Serial1.begin(9600);
  Serial.begin(9600);

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(250);
  }
  Serial.print("\nConectado al Wi-Fi");
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  
}

bool prev [6] {0,0,0,0,0,0};
bool next [6];
bool dif = 0;
void sendValues(){
  String message = "a," + String (next[0]) + "," + String (next[1]) + "," + String (next[2]) +
  "," + String (next[3]) + "," + String (next[4]) + "," + String (next[5]) + "\n";
  Serial1.print(message);
  Serial.print(message);
}

String nodo = "Seccion A";
String estado;
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
      if(next[i] == 0){
        estado = "Ocupado";
      }
      else{
        estado = "Desocupado";
      }
      Firebase.setString(firebaseData, nodo + "/A" + String(i+1), estado);
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
