#include <Arduino.h>

class IRrc5 {
  private:
    int outputPin;

    void transmit(bool bit) {
      // in RC-5
      // bit 0 is 889usec on followed by 889usec off
      // bit 1 is off then on
      // output pin is connected to 555 RESET pin (active when pin high)
      digitalWrite(outputPin, !bit);
      delayMicroseconds(889);
      digitalWrite(outputPin, bit);
      delayMicroseconds(889);
    }

    static int buildCode(int address, int command) {
      int code = 0b011; // header and toggle bit
      for(int i=0; i<5; i++) {
        bool bit  = address & (1<<4-i);
        code |= bit << (3+i);
      }
      for(int i=0; i<6; i++) {
        bool bit  = command & (1<<5-i);
        code |= bit << (8+i);
      }
      return code;
    }

  public:
    IRrc5(int outputPin) {
      this->outputPin = outputPin;
    }

    void write(int code) {
      for(int i=0; i<14; i++) transmit(code & (1<<i));
      digitalWrite(outputPin, 0); // 0 = transmit off
      delay(114); // ms
    }

    void write(int address, int command) {
      write(buildCode(address, command));
    }
};
