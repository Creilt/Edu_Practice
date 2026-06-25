#include <Servo.h>

Servo servo;
int currentPos = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Введите угол");
  servo.attach(3);
  servo.write(currentPos);
}

void loop() {
  if (Serial.available() > 0) {
    int targetPos = Serial.parseInt(); 
    if (targetPos >= 0 && targetPos <= 180) {
        
      // Цикл плавного движения к новой позиции
      while (currentPos != targetPos) {
        if (targetPos >= currentPos) {
          currentPos += 1;
          servo.write(currentPos);
          delay(15);
        } else {
          currentPos += -1;
          servo.write(currentPos);
          delay(15);
        }
      }
    }
  }
}
