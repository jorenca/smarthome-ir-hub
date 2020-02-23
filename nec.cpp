#include <Arduino.h>

class IRNec {
  private:
    int outputPin;

    void up() {
      digitalWrite(outputPin, 1);
    }

    void down() {
      digitalWrite(outputPin, 0);
    }
  public:
    IRNec(int outputPin) {
      this->outputPin = outputPin;
    }

    void send(char* data, int len) {
      up();
      delayMicroseconds(9000);
      down();
      delayMicroseconds(4500);

      for(int i=0; i<len; i++) {
        for(int j=0; j<8; j++) {
          up();
          delayMicroseconds(560);
          down();
          delayMicroseconds(data[i] & (1<<j) ? 1690 : 560);
        }
      }

      up(); // final
      delayMicroseconds(560);
      down();
    }
};
