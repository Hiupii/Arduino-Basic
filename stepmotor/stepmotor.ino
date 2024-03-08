#include <Stepper.h>

// Khai báo số bước và chân kết nối đến driver động cơ bước
const int stepsPerRevolution = 250;
Stepper stepper(stepsPerRevolution, 6, 7, 8, 9);

void setup() {
  // Thiết lập tốc độ quay của động cơ (điều chỉnh theo yêu cầu)
  stepper.setSpeed(100);
}

void loop() {
  
  // Quay theo chiều kim đồng hồ 1 vòng
  stepper.step(stepsPerRevolution);

  delay(1000); // Dừng 1 giây

  // Quay ngược chiều kim đồng hồ 1 vòng
  stepper.step(-stepsPerRevolution);

  delay(1000); // Dừng 1 giây
}
