const int ledThumb = 2;   // LED for Thumb
const int ledIndex = 3;   // LED for Index
const int ledMiddle = 4;  // LED for Middle
const int ledRing = 5;    // LED for Ring
const int ledPinky = 6;   // LED for Pinky

byte fingers[5];  // Buffer to hold 5 finger states
int count = 0;

void setup() {
  Serial.begin(9600);

  // Set all LEDs as output
  pinMode(ledThumb, OUTPUT);
  pinMode(ledIndex, OUTPUT);
  pinMode(ledMiddle, OUTPUT);
  pinMode(ledRing, OUTPUT);
  pinMode(ledPinky, OUTPUT);
}

void loop() {
  // Wait until we receive 5 bytes
  if (Serial.available() >= 5) {
    for (int i = 0; i < 5; i++) {
      fingers[i] = Serial.read();
    }

    // Control LEDs based on finger states
    digitalWrite(ledThumb, fingers[0] ? HIGH : LOW);
    digitalWrite(ledIndex, fingers[1] ? HIGH : LOW);
    digitalWrite(ledMiddle, fingers[2] ? HIGH : LOW);
    digitalWrite(ledRing, fingers[3] ? HIGH : LOW);
    digitalWrite(ledPinky, fingers[4] ? HIGH : LOW);
  }
}
