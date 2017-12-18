int analog_pin = 9;    // LED connected to analog pin 9
float fadeValue = 0.0;
int roundValue = (int) fadeValue;
int delayTime = 30;
float multiplier = 1.03;

int mode = 2; // 0 or 1

void setup() {
  // nothing happens in setup
}

void loop() {

  if (mode == 0) {
    int j;
    for (int i = 0; i < 255; i++) {
      analogWrite(analog_pin, i);
      if (i == 0){
        j = 700/4;
      }
      else {
        j = (700/(i+3)) + 1;      
      }
      delay(j);    
    }
    for (int i = 254; i >= 0; i--) {
      analogWrite(analog_pin, i);
      if (i == 0){
        j = 700/4;
      }
      else {
        j = (700/(i+3)) + 1;      
      }
      delay(j);    
    }
  }
  


  // fade in from min to max exponentially:
  if (mode == 1){
    for (fadeValue = 1.0 ; roundValue < 255; fadeValue *= multiplier) {
      roundValue = (int) fadeValue;
      if (roundValue > 255){
        roundValue = 255;
      }
      analogWrite(analog_pin, roundValue);
      delay(delayTime);
    }
  
  //  analogWrite(analog_pin, 255);
    delay(delayTime*2);
    
    // fade out from max to min exponentially:
    for (fadeValue = 255.0 ; roundValue >= 1; fadeValue /= multiplier) {
      roundValue = (int) fadeValue;
      analogWrite(analog_pin, roundValue);
      delay(delayTime);
    }
      
    analogWrite(analog_pin, 0);
    delay(delayTime*3);
  }

}


