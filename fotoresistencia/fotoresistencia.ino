void setup() {
  pinMode(4, INPUT);
  pinMode(12, INPUT);
  Serial.begin(115200);
  
}
bool a, b;
void loop() {
  a = digitalRead(4);
  b = digitalRead(12);
  Serial.print("a=");
  Serial.println(a);
  Serial.print("b=");
  Serial.println(b);
  delay(500);
}
