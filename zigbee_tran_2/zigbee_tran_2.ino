#include<SoftwareSerial.h>
#include<ArduinoJson.h>

#include<DHT.h>

#define DHTPIN 8
#define DHTTYPE 11

DHT dht(DHTPIN, DHTTYPE);

StaticJsonDocument<100> doc;

int group = 2;

SoftwareSerial mySerial(10, 11); //Rx, Tx

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  mySerial.begin(38400);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // doc[""]
  mySerial.println("Group: " + String(group));
  mySerial.println("Nhiet do: " + String(temp));
  mySerial.println("Do am: " + String(hum));
  delay(5000);
}
