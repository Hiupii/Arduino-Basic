#include<SoftwareSerial.h>
#include<ArduinoJson.h>

StaticJsonDocument<100> doc;
SoftwareSerial mySerial(10, 11); //Rx, Tx

int group = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  mySerial.begin(38400);
  pinMode(A1, INPUT);
}

void loop() {
  float gas = analogRead(A1);

  // doc[""]
  // mySerial.println("P2P 0000 ")
  mySerial.println("Group: " + String(group));
  mySerial.println(String(gas));
  Serial.println(gas);
  Serial.println(group);
  delay(2000);
}
