#include <TM1637Display.h>
#include <random>

#define CLK 17
#define DIO 33
#define swPin 32
#define on HIGH
#define off LOW

int swState = 0;

TM1637Display display(CLK, DIO);
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> uni(1, 9999);

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT_PULLUP);
  display.setBrightness(0x0f);
}

void loop() {
  int randomNumber = uni(rng);
  display.showNumberDec(randomNumber);
  delay(200);
  swState = digitalRead(swPin);
  if (swState == off) {
    display.showNumberDec(777,0x0f);
    delay(10000);
  }
}
