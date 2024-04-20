#include <LiquidCrystal.h>//include the library code
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;//creat an lcd object
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int ledred = 8;//specifty the base
int ledgreen = 7;
void setup() {
  Serial.begin(9600);//speed
  lcd.begin(16, 2);//set up the lcd number of columns and rows
  pinMode(ledred, OUTPUT);//the out put turns led red
  pinMode(ledgreen, OUTPUT);//the out put turns led green
}
void loop() {
  float voltage = analogRead(A2);//convert the avaloge reading
  float Temp = voltage * 0.48828125;
  lcd.setCursor(0, 0);//prin the temperature on the lcd
  lcd.print("Temp: ");//print to the lcd
  lcd.print(Temp);//print to the lcd
  lcd.print(" *C");//print to the lcd
  
  if (Temp > 30)
  { digitalWrite(ledred, HIGH);
  lcd.setCursor(0, 1);
    lcd.print("warm");
  }
  else
  { digitalWrite(ledred, LOW);
    digitalWrite(ledgreen, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("cold");
  }
  delay(2000);
  lcd.clear();
}
