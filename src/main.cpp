#include <Arduino.h>
#include <M5Unified.h>
#include <SCServo.h>
#include <Avatar.h>

using namespace m5avatar;
Avatar avatar;

SCSCL sc;


void testServo() {
  for (int i=0; i< 2; i++) {
    sc.WritePos(1, 511, 1000, 500);
    sc.WritePos(2, 511, 1000, 500);
    delay(1000);
    sc.WritePos(1, 0, 1000, 500);
    sc.WritePos(2, 650, 1000, 500);
    delay(1000);
    sc.WritePos(1, 511, 1000, 500);
    sc.WritePos(2, 511, 1000, 500);
    delay(1000);
    sc.WritePos(1, 1023, 1000, 500);
    sc.WritePos(2, 650, 1000, 500);
    delay(1000);
    sc.WritePos(1, 511, 1000, 500);
    sc.WritePos(2, 511, 1000, 500);
    delay(1000);
  }
}

void testRotation() {
  sc.PWMMode(1, true); // 回転モード
  sc.WritePWM(1, 500);
  sc.WritePos(2, 600, 1500);
  delay(1500);
  sc.WritePos(2, 511, 1500);
  delay(1500);
  sc.WritePWM(1, 1500);
  sc.WritePos(2, 600, 1500);
  delay(1500);
  sc.WritePos(2, 511, 1500);
  delay(1500);
  sc.PWMMode(1, false);  // 位置決めモードに戻す
  sc.WritePos(1, 0, 1000);
  sc.WritePos(2, 600, 1000);
  delay(1000);
  sc.WritePos(1, 511, 1000);
  sc.WritePos(2, 511, 1000);
  delay(1000);
  sc.WritePos(1, 1024, 1000);
  sc.WritePos(2, 600, 1000);
  delay(1000);
  sc.WritePos(1, 511, 1000);
  sc.WritePos(2, 511, 1000);
  delay(1000);
  sc.WritePos(2, 600, 1000, 500);
  delay(1000);
  sc.WritePos(2, 511, 1000, 500);
  delay(1000);
}

void setup() {
  M5.begin();
  M5.Display.println("Feetech SCS0009 Test");
  avatar.init();
  Serial2.begin(1000000, SERIAL_8N1, 33, 32);
  sc.pSerial = &Serial2;
  sc.WritePos(1, 511, 0, 1500);
  sc.WritePos(2, 511, 0, 1500);

}

void loop() {
  M5.update();
  if (M5.BtnA.wasClicked()) {
    testRotation();
  }
  if (M5.BtnB.wasClicked()) {
    sc.WritePos(1, 511, 500, 1500);
    sc.WritePos(2, 600, 500, 1500);
  }
  if (M5.BtnC.wasClicked()) {
    testServo();
  }
}
