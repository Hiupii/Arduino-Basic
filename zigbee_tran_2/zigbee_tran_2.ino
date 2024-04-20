#include<SoftwareSerial.h>

#include<DHT.h>

#define DHTPIN 8
#define DHTTYPE 22

DHT dht(DHTPIN, DHTTYPE);

int group = 3;

SoftwareSerial mySerial(10, 11); //Rx, Tx

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  mySerial.begin(38400);
  dht.begin();
  Serial.println("begin");
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  Serial.println("loop");

  mySerial.println("Group: " + String(group));
  Serial.println(temp);
  mySerial.println("Nhiet do: " + String(temp));
  Serial.println(hum);
  mySerial.println("Do am: " + String(hum));
  delay(2000);
}
