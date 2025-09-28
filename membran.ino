const byte keyPins[4] = {4, 5, 6, 7};  
const char keyChars[4] = {'1','2','3','4'};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(keyPins[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    if (digitalRead(keyPins[i]) == LOW) {
      delay(20); // debounce
      if (digitalRead(keyPins[i]) == LOW) {
        Serial.print("Basılan tuş: ");
        Serial.println(keyChars[i]);

        while (digitalRead(keyPins[i]) == LOW) {
          delay(10);
        }
      }
    }
  }
}
