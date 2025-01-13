#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

char input[12];
int count = 0;

int a;
int p1 = 0, p2 = 0;

double total = 0;

void setup()
{
  pinMode(A4, INPUT_PULLUP);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  lcd.clear();
  lcd.begin(16, 2);
  Wire.begin();
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print(" AUTOMATIC BILL");
  lcd.setCursor(2, 1);
  lcd.print(" SHOPPING CART ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print(" CSBS ");
  lcd.setCursor(2, 1);
  lcd.print("SUPER MARKET");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Plz Add iTem :- ");
}

void loop()
{
  count = 0;
  while (count < 12)
  {
    input[count] = 0;
    count++;
  }
  delay(5);
  count = 0;
  while (Serial.available() && count < 12)
  {
    input[count] = Serial.read();
    count++;
    delay(5);
  }
  int a = digitalRead(A4);

  if ((strncmp(input, "4900C623339F", 12) == 0) && (a == 1))
  {

    lcd.setCursor(0, 0);
    lcd.print("Cheese Added       ");
    lcd.setCursor(0, 1);
    lcd.print("Price :- 100.00      ");
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    delay(1000);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Total Price :-");
    lcd.setCursor(0, 1);
    total = total + 100.00;
    lcd.print(total);
    p1++;
  }
  else if ((strncmp(input, "4900C623339F", 12) == 0) && (a == 0))
  {
    if (p1 > 0)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Cheese Removed!!!        ");
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      delay(1000);
      lcd.clear();
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Total Price :-");
      lcd.setCursor(0, 1);
      total = total - 100.00;
      lcd.print(total);
      p1--;
    }
    else
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Not in cart!!!        ");
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      delay(1000);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Total Price :-");
      lcd.setCursor(0, 1);
      lcd.print(total);
    }
  }

  if ((strncmp(input, "090064BBCE18", 12) == 0) && (a == 1))
  {
    lcd.setCursor(0, 0);
    lcd.print("Milk Added       ");
    lcd.setCursor(0, 1);
    lcd.print("Price :- 70.00      ");
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    delay(1000);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Total Price :-");
    lcd.setCursor(0, 1);
    total = total + 70.00;
    lcd.print(total);
    p2++;
  }

  else if ((strncmp(input, "090064BBCE18", 12) == 0) && (a == 0))
  {
    if (p2 > 0)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Milk Removed!!!        ");
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      delay(1000);
      lcd.clear();
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Total Price :-");
      lcd.setCursor(0, 1);
      total = total - 70.00;
      lcd.print(total);
      p2--;
    }
    else
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Not in cart!!!        ");
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      delay(1000);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Total Price :-");
      lcd.setCursor(0, 1);
      lcd.print(total);
    }
  }
}
