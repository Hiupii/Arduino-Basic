#include<SoftwareSerial.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial mySerial(10, 11);

void setup() {
  Serial.begin(38400);
  mySerial.begin(38400);
  pinMode(7, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  if (mySerial.available()) {
    String data = mySerial.readStringUntil('\n'); //
    data.remove(data.length() - 1);

    String checkstr = data.substring(0, 2);

    if(checkstr == "Nh")
    {
      lcd.setCursor(0,0);
      lcd.print(data + " "); // In dữ liệu lên Serial Monitor
    }
    else
    {
      lcd.setCursor(0,1); 
      lcd.print(data + " ");
    }
    digitalWrite(7, HIGH);
  }
  else
  {
    delay(500);
    digitalWrite(7, LOW);
  }
}
