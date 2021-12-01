#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define entrada 5
#define salida 6

int lcdColumns = 20;
int lcdRows = 4;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  
Servo myservo;

void setup(){
  lcd.init();
  lcd.backlight();
  myservo.attach(4);
  pinMode(entrada, INPUT);
  pinMode(salida, INPUT);
  Serial.begin(9600);
  printToLCD(12, 0);
}
int total = 0;

byte left[8] = {
        B10100,
        B10100,
        B10100,
        B10100,
        B10100,
        B10100,
        B10100,
        B10100
};

byte uppleft[8] = {
        B11111,
        B10000,
        B10111,
        B10100,
        B10100,
        B10100,
        B10100,
        B10100
};

byte uppright[8] = {
        B11111,
        B00001,
        B11101,
        B00101,
        B00101,
        B00101,
        B00101,
        B00101
};

byte right[8] = {
        B00101,
        B00101,
        B00101,
        B00101,
        B00101,
        B00101,
        B00101,
        B00101
};

byte botright[8] = {
        B00101,
        B00101,
        B00101,
        B00101,
        B00101,
        B11101,
        B00001,
        B11111
};

byte bot[8] = {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B11111,
        B00000,
        B11111
};

byte botleft[8] = {
        B10100,
        B10100,
        B10100,
        B10100,
        B10100,
        B10111,
        B10000,
        B11111
};

byte top[8] = {
        B11111,
        B00000,
        B11111,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000
};

void printToLCD(int a, int b){
  lcd.createChar(0, uppleft);
  lcd.createChar(1, uppright);
  lcd.createChar(2, top);
  lcd.createChar(3, bot);
  lcd.createChar(4, left);
  lcd.createChar(5, right);
  lcd.createChar(6, botright);
  lcd.createChar(7, botleft);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write(0);
  for (int i = 1; i<19; i++){
    lcd.write(2);
  }
  lcd.write(1);
  lcd.setCursor(0,1);
  lcd.write(4);
  lcd.print(" Libres  Ocupados ");
  lcd.write(5);
  lcd.setCursor(0,2);
  lcd.write(4);
  lcd.print("   " + String(a));
  lcd.setCursor(13,2);
  lcd.print(String(b));
  lcd.setCursor(19,2);
  lcd.write(5);
  lcd.setCursor(0,3);
  lcd.write(7);
  for (int i = 1; i<19; i++){
    lcd.write(3);
  }
  lcd.write(6);
}

void loop(){
  myservo.write(0);
  bool a = digitalRead(entrada);
  bool b = digitalRead(salida);

  if(a == 1){
    myservo.write(90);
    delay(2000);
    if(total < 12){
      total += 1;
      Serial.print("total = ");
      Serial.println(total);
      printToLCD(12-total, total);
    }
  }else if(b == 1){
    myservo.write(90);
    delay(2000);
    if(total > 0){
      total -= 1;
      printToLCD(12-total, total);
    }
    Serial.print("total = ");
    Serial.println(total);
  }
}
