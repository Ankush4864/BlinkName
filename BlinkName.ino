// Define the pins for the LED and the switch
const int ledPin = 13;
const int switchPin = 4;

// Default name to be blinked in Morse code
String defaultName = "ankush";

void setup() {
  // Set the LED pin as an output and the switch pin with internal pull-up resistor as input
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
}

void loop() {
  // Check if the switch is pressed (LOW)
  if (digitalRead(switchPin) == LOW) {
    // Call the function to blink Morse code for the default name
    blinkMorseCode(defaultName);
  }
}

// Function to blink Morse code for a given text
void blinkMorseCode(String text) {
  for (int i = 0; i < text.length(); i++) {
    char c = toLowerCase(text.charAt(i)); // Convert character to lowercase
    switch (c) {
      case 'a':
        blink(".-");   // Blink for 'A'
        break;
      case 'b':
        blink("-..."); // Blink for 'B'
        break;
      // ... (cases for other letters)
      case ' ':
        delay(300);    // Gap between words
        break;
    }
    delay(100); // Gap between letters
  }
}

// Function to blink dots and dashes for a given Morse code sequence
void blink(String morseCode) {
  for (int i = 0; i < morseCode.length(); i++) {
    char dotDash = morseCode.charAt(i);
    digitalWrite(ledPin, HIGH);
    if (dotDash == '.') {
      delay(200);   // Blink dot
    } else if (dotDash == '-') {
      delay(600);   // Blink dash
    }
    digitalWrite(ledPin, LOW);
    delay(200);     // Gap between dots and dashes
  }
  delay(200);       // Gap between characters
}
