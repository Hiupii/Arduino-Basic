#include<SoftwareSerial.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial mySerial(10, 11);

int red = 5;
int green = 6;
int blue = 7;
int yeallow = 9;

int led = 0;

int status = 0;

unsigned long currentTime = 0;

void setup() {
  Serial.begin(38400);
  Serial.println("begin");
  mySerial.begin(38400);
  lcd.init();
  lcd.backlight();
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(yeallow, OUTPUT);
  pinMode(8, INPUT_PULLUP);

}

void loop() {

  //Zigbee
  if (mySerial.available()) {
    String data = mySerial.readStringUntil('\n'); //
    data.remove(data.length() - 1);

    //Serial.println(data);

    String checkstr = data.substring(0, 2);

    if(data == "Group: 1")
    {
      led = red;
      //Serial.println(data);
    }
    else if(data == "Group: 2")
    {
      led = green;
      //Serial.println(data);
    }
    else if(data == "Group: 3")
    {
      led = blue;
      //Serial.println(data);
    }
    else if(data == "Group: 4")
    {                                                                          
      led = yeallow;
      //Serial.println(data);
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
    else if(checkstr == "Gr")
    {
      lcd.setCursor(13,1);
      lcd.print("N" + data.substring(7,8));
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

  if(digitalRead(8) == LOW)
  {
    delay(50);
    if(digitalRead(8) == LOW)
    {
      if(status == 0)
      {
        status = 1;
        mySerial.println("on");
        Serial.println("on");
      }
      else
      {
        status = 0;
        mySerial.println("off");
        Serial.println("off");
      }
    }
  }
}
