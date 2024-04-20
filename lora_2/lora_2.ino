#include <SoftwareSerial.h>
#include <DHT.h>

DHT dht(5, DHT22);

SoftwareSerial mySerial(6, 7); //TX, RX

int g = 2; //sửa tên group ở đây: 1, 2 hoặc 3 để đèn chuyển màu

#define M0 8
#define M1 9                 

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  
  pinMode(M0, OUTPUT);        
  pinMode(M1, OUTPUT);
  digitalWrite(M0, LOW);       // Set 2 chân M0 và M1 xuống LOW
  digitalWrite(M1, LOW);       // để hoạt động ở chế độ Normal
  
  pinMode(12, OUTPUT);
  dht.begin();
}

void loop() {
  float t;
  float h;
  // float t = dht.readTemperature();
  // float h = dht.readHumidity();

  mySerial.println("Group: " + String(g));
  mySerial.println("Nhiet do: " + String(t));
  mySerial.println("Do am: " + String(h));
  Serial.println("Group: " + String(g));
  Serial.println("Temp: " + String(t));
  Serial.println("Hum: " + String(h));
  
  delay(2000);
}
