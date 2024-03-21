#include<SoftwareSerial.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial mySerial(10, 11);

int red = 5;
int green = 6;
int blue = 7;

int led;

void setup() {
  Serial.begin(38400);
  mySerial.begin(38400);
  pinMode(8, OUTPUT);
  lcd.init();
  lcd.backlight();
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  if (mySerial.available()) {
    String data = mySerial.readStringUntil('\n'); //
    data.remove(data.length() - 1);

    String checkstr = data.substring(0, 2);

    if(data == "Group: 1")
    {
      led = red;
    }
    else if(data == "Group: 2")
    {
      led = green;
    }
    else if(data == "Group: 3")
    {
      led = blue;
    }

    if(checkstr == "Nh")
    {
      lcd.setCursor(0,0);
      lcd.print(data + " "); // In dữ liệu lên Serial Monitor
    }
    else if(checkstr == "Do")
    {
      lcd.setCursor(0,1); 
      lcd.print(data + " ");
    }
    else
    {
      lcd.setCursor(0,0);
      lcd.print("Gia tri: ");
      lcd.print(data);
      lcd.setCursor(0,1);
      if(data.toInt() >= 500)
      {
        lcd.print("Nguy hiem");
        digitalWrite(8, HIGH);
      }
      else
      {
        lcd.print("An toan   ");
        digitalWrite(8, LOW);
      }
    }
    digitalWrite(led, HIGH);
  }
  else
  {
    delay(500);
    digitalWrite(led, LOW);
  }
}