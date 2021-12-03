
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPL1JxEP0bW"
#define BLYNK_DEVICE_NAME "test"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

//#define ssid "DAF_Lago_Nogal"
//#define password "3336574030"

#define API_key "AIzaSyDBmwBEgAqANg0TyISjGtwhqjRnv9vzCpg"

const char *FIREBASE_HOST= "https://reto-estacionamiento-default-rtdb.firebaseio.com/";
const char *FIREBASE_AUTH = "4cdpt5Qc5ut5GCawjaTvH7PpePK5yP5mG0qxTICH";

#include "BlynkEdgent.h"
#include "FirebaseESP8266.h"

FirebaseData firebaseData;

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void loop() {
  BlynkEdgent.run();
  Firebase.getInt(firebaseData,"Seccion A/A1");
  Blynk.virtualWrite(V0, firebaseData.to<int>());
  Firebase.getInt(firebaseData,"Seccion A/A2");
  Blynk.virtualWrite(V1, firebaseData.to<int>());
  Firebase.getInt(firebaseData,"Seccion A/A3");
  Blynk.virtualWrite(V2, firebaseData.to<int>());
  Firebase.getInt(firebaseData,"Seccion A/A4");
  Blynk.virtualWrite(V3, firebaseData.to<int>());
  Firebase.getInt(firebaseData,"Seccion A/A5");
  Blynk.virtualWrite(V4, firebaseData.to<int>());
  Firebase.getInt(firebaseData,"Seccion A/A6");
  Blynk.virtualWrite(V5, firebaseData.to<int>());
  
  Firebase.getInt(firebaseData,"Seccion B/B1");
  Blynk.virtualWrite(V6, firebaseData.to<int>());
  Firebase.getInt(firebaseData,"Seccion B/B2");
  Blynk.virtualWrite(V7, firebaseData.to<int>());
  Firebase.getInt(firebaseData,"Seccion B/B3");
  Blynk.virtualWrite(V8, firebaseData.to<int>());
  Firebase.getInt(firebaseData,"Seccion B/B4");
  Blynk.virtualWrite(V9, firebaseData.to<int>());
  Firebase.getInt(firebaseData,"Seccion B/B5");
  Blynk.virtualWrite(V10, firebaseData.to<int>());
  Firebase.getInt(firebaseData,"Seccion B/B6");
  Blynk.virtualWrite(V11, firebaseData.to<int>());
  delay(2500);
}
