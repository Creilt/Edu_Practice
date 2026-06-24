const int PIN_GREEN = 5;  // ✅
const int PIN_RED   = 9;  // ✅
const int PIN_LDR   = A0;
bool dooropen = false;
void setup() {
    Serial.begin(9600);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_RED, OUTPUT);

    digitalWrite(PIN_RED, HIGH);
    digitalWrite(PIN_GREEN, LOW);
    Serial.println("Дверь закрыта");
}

void loop() {
    int val = analogRead(PIN_LDR);
    if (val > 512) {
        digitalWrite(PIN_RED, LOW);
        digitalWrite(PIN_GREEN, HIGH);
        if (!dooropen) {
          Serial.println("Дверь открыта");
          dooropen = true;
        }
        delay(1500);

        if (analogRead(PIN_LDR) > 512) {
          return;
        } else {
            digitalWrite(PIN_GREEN, LOW);
            digitalWrite(PIN_RED, HIGH);
            Serial.println("Дверь закрыта");
            dooropen = false;
        }
    }

    delay(100);
}