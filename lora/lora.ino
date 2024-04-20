#include <SoftwareSerial.h>

SoftwareSerial mySerial(6, 7); //TX, RX

#define M0 8
#define M1 9                 

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  
  pinMode(M0, OUTPUT);        
  pinMode(M1, OUTPUT);
  digitalWrite(M0, LOW);       // Set 2 chân M0 và M1 xuống LOW
  digitalWrite(M1, LOW);       // để hoạt động ở chế độ Normal
  
  pinMode(5, OUTPUT);
}

void loop() {
  Serial.println("loop");
  if(mySerial.available())
  {
    Serial.print("re");
    String data = mySerial.readStringUntil('\n');
    data.remove(data.length() - 1);
    if(data == "on")
    {
      digitalWrite(5, HIGH);
      Serial.println(data);
    }
    else if(data == "off")
    {
      digitalWrite(5, LOW);
      Serial.println(data);
    }
  }

  delay(2000);
}
