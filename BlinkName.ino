const int ledPin = 13;
const int switchPin = 4;

String defaultName = "ankush";  // Initial name

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(switchPin) == LOW) {
    blinkMorseCode(defaultName);
  }
}

void blinkMorseCode(String text) {
  for (int i = 0; i < text.length(); i++) {
    char c = toLowerCase(text.charAt(i));
    switch (c) {
      case 'a':
        blink(".-");
        break;
      case 'b':
        blink("-...");
        break;
      case 'c':
        blink("-.-.");
        break;
      case 'd':
        blink("-..");
        break;
      case 'e':
        blink(".");
        break;
      case 'f':
        blink("..-.");
        break;
      case 'g':
        blink("--.");
        break;
      case 'h':
        blink("....");
        break;
      case 'i':
        blink("..");
        break;
      case 'j':
        blink(".---");
        break;
      case 'k':
        blink("-.-");
        break;
      case 'l':
        blink(".-..");
        break;
      case 'm':
        blink("--");
        break;
      case 'n':
        blink("-.");
        break;
      case 'o':
        blink("---");
        break;
      case 'p':
        blink(".--.");
        break;
      case 'q':
        blink("--.-");
        break;
      case 'r':
        blink(".-.");
        break;
      case 's':
        blink("...");
        break;
      case 't':
        blink("-");
        break;
      case 'u':
        blink("..-");
        break;
      case 'v':
        blink("...-");
        break;
      case 'w':
        blink(".--");
        break;
      case 'x':
        blink("-..-");
        break;
      case 'y':
        blink("-.--");
        break;
      case 'z':
        blink("--..");
        break;
      case ' ':
        delay(300); // Gap between words
        break;
    }
    delay(100); // Gap between letters
  }
}

void blink(String morseCode) {
  for (int i = 0; i < morseCode.length(); i++) {
    char dotDash = morseCode.charAt(i);
    digitalWrite(ledPin, HIGH);
    if (dotDash == '.') {
      delay(200);
    } else if (dotDash == '-') {
      delay(600);
    }
    digitalWrite(ledPin, LOW);
    delay(200); // Gap between dots and dashes
  }
  delay(200); // Gap between characters
}