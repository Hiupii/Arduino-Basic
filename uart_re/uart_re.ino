#include <ArduinoJson.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

StaticJsonDocument<100> doc;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  while(Serial.available() > 0){
// Đọc Dữ liệu kênh truyền vừa gửi tới
    String data = Serial.readStringUntil('\n');

    DeserializationError error = deserializeJson(doc, data);
    // Lấy giá trị nhiệt độ và độ ẩm từ đối tượng JsonDocument
    float temperature = doc["temperature"];
    float humidity = doc["humidity"];
    // In các giá trị ra màn hình nối tiếp
    lcd.setCursor(0,0);
    lcd.print("Temperature: ");
    lcd.print(temperature);
    Serial.println(" C");
    lcd.setCursor(0,1);
    lcd.print("Humidity: ");
    lcd.print(humidity);
    Serial.println(" %");
    delay(1000);
  }
}
