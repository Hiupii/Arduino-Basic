#include<SoftwareSerial.h>
#include<ArduinoJson.h>

StaticJsonDocument<100> doc;

SoftwareSerial mySerial(10, 11); //Rx, Tx

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  mySerial.begin(38400);
  pinMode(A1, INPUT);
}

void loop() {
  float gas = analogRead(A1);

  // doc[""]
  mySerial.println(String(gas));
  delay(2000);
}
