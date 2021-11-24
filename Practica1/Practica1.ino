#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11

//const char auth[] = "Svhy9iwmDnZ9Hlg3DjBVKXTUIMSgejxS";
const char auth[] = "AXIUiLXE_O2FINdow1tfGfwrlmAAjj9q";
const char ssid[] = "DAF_Lago_Nogal";
const char pass[] = "3336574030";

const int led = 0;
const int reley = 5;
const int LDR = A0;

float t;
float h;
float f;
int valor;

DHT dht(DHTPIN, DHTTYPE);
WiFiClient client; 

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(reley,OUTPUT);
  pinMode(LDR,INPUT);
  Blynk.begin(auth, ssid, pass);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  Serial.print("Conectando...");
  while (WiFi.status()!= WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Conexión OK!");
  Serial.print("IP Local: ");
  Serial.println(WiFi.localIP());
}


BLYNK_WRITE(V0){
  int V0Data=param.asInt();
  digitalWrite(led,V0Data);
}

BLYNK_WRITE(V3){
  int V3Data=param.asInt();
  digitalWrite(reley,V3Data);
  Serial.print(V3Data);Serial.println(" reley");
}

void loop()
{
  Blynk.run();
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
    
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.println(f);

  
  int a = analogRead(LDR);
  //Serial.println(a);
  valor = map(a, 0, 15, 0, 100); 
  Serial.print(valor); Serial.println(" % de luz");
    
  
  Blynk.virtualWrite(V1,h);
  Blynk.virtualWrite(V2,t);
  Blynk.virtualWrite(V4,valor);
}
