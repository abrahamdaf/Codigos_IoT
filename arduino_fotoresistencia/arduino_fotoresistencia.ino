void setup() {
// Open serial communications and wait for port to open:
Serial.begin(9600);
Serial1.begin(9600);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);

}
String seccion;
String variables [6];
 
void loop() { // run over and over
  if (Serial1.available()) {
    seccion = Serial1.readStringUntil(',');
    Serial.read();
    variables [0] = Serial1.readStringUntil(',');
    Serial.read();
    variables [1] = Serial1.readStringUntil(',');
    Serial.read();
    variables [2] = Serial1.readStringUntil(',');
    Serial.read();
    variables [3] = Serial1.readStringUntil(',');
    Serial.read();
    variables [4] = Serial1.readStringUntil(',');
    Serial.read();
    variables [5] = Serial1.readStringUntil('\n');
    Serial.read();
    for (int i = 2; i<8; i++){
      bool temp;
      if(variables[i-2] == "1"){
        temp = true;
      }else{
        temp = false;
      }
      if(seccion == "b"){
        digitalWrite(i+6, temp);
      }else if(seccion == "a"){
         digitalWrite(i, temp);
      }
    }
  }
}
