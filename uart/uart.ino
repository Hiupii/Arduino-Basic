void setup() {
  Serial.begin(9600); // Khởi tạo Serial với tốc độ Baudrate 9600
  pinMode(13,OUTPUT); //Trên board Uno có một con Led và nó được gắn nối
}

void loop() {
  while (Serial.available() == 0) {}     //wait for data available
  String teststr = Serial.readString();  //read until timeout
  teststr.trim();                        // remove any \r \n whitespace at the end of the String
  if (teststr == "on") {
    digitalWrite(13, HIGH);
    Serial.println("LED on");
  } else {
    digitalWrite(13, LOW);
    Serial.println("LED off");
  }
}