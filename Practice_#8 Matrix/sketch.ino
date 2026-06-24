#include <Adafruit_NeoPixel.h>
#define PIN_MATRIX   3
#define NUM_LEDS    64
Adafruit_NeoPixel matrix = Adafruit_NeoPixel(NUM_LEDS, PIN_MATRIX, NEO_GRB + NEO_KHZ800);
void setup() {
  matrix.begin();
  matrix.setBrightness(40);
}
int getLED(int x, int y) {
  if (y % 2 != 0) {
    return (y * 8) + (7 - x);
  }
  return (y * 8) + x;
}
void loop() {
  // Дин. график
  for (int t = 0; t < 10; t++) {
    matrix.clear();
    for (int x = 0; x < 8; x++) {
      int height = random(1, 8);
      for (int y = 0; y < height; y++) {
        matrix.setPixelColor(getLED(x, 7 - y), matrix.Color(0, 255, 0));
      }
    }
    matrix.show();
    delay(300);
  }

  // Смайлик
  matrix.clear();
  // Рисуем глаза
  matrix.setPixelColor(getLED(2, 2), matrix.Color(0, 0, 255));
  matrix.setPixelColor(getLED(5, 2), matrix.Color(0, 0, 255));
  // Рисуем улыбку
  matrix.setPixelColor(getLED(1, 5), matrix.Color(0, 0, 255));
  matrix.setPixelColor(getLED(2, 6), matrix.Color(0, 0, 255));
  matrix.setPixelColor(getLED(3, 6), matrix.Color(0, 0, 255));
  matrix.setPixelColor(getLED(4, 6), matrix.Color(0, 0, 255));
  matrix.setPixelColor(getLED(5, 6), matrix.Color(0, 0, 255));
  matrix.setPixelColor(getLED(6, 5), matrix.Color(0, 0, 255));

  matrix.show();
  delay(2000);
}