#include <Arduino.h>

// Equipment it seems compatible with:
//  * Fujitsu ASYG30LFCA with remote AR-RAH2E
class IRFujitsuRah2e {
  private:
    int outputPin;

    void up() {
      digitalWrite(outputPin, 1);
    }

    void down() {
      digitalWrite(outputPin, 0);
    }
  public:
    IRFujitsuRah2e(int outputPin) {
      this->outputPin = outputPin;
    }

    void send(char* data, int len) {
      up();
      delayMicroseconds(3324);
      down();
      delayMicroseconds(1574);

      for(int i=0; i<len; i++) {
        for(int j=0; j<8; j++) {
          up();
          delayMicroseconds(432); // 448 default
          down();
          delayMicroseconds(data[i] & (1<<j) ? 1175 : 390); // 1182 default
        }
      }

      up(); // final
      delayMicroseconds(432);
      down();
    }
};

const uint16_t kFujitsuAcMinGap = 8100;
