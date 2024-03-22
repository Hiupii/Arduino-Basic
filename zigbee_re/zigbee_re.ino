#include<SoftwareSerial.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial mySerial(10, 11);

int red = 5;
int green = 6;
int blue = 7;
int yeallow = 9;

int led = 0;

void setup() {
  Serial.begin(38400);
  mySerial.begin(38400);
  pinMode(8, OUTPUT);
  lcd.init();
  lcd.backlight();
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(yeallow, OUTPUT);
}

void loop() {
  if (mySerial.available()) {
    String data = mySerial.readStringUntil('\n'); //
    // data.remove(data.length() - 1);

    Serial.println(data);

    String checkstr = data.substring(0, 2);

    Serial.println(checkstr);

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
    else if(data == "Group: 4")
    {                                                                          
      led = yeallow;
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
      lcd.print("Gia tri:  ");
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
    delay(1000);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(yeallow, LOW);
  }
}
