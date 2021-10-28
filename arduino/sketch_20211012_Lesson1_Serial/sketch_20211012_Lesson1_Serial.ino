//Button to turn ON/OFF LED

#define MY_KEYWORD  "YourKey-L1"

//Constants won't change. They are used here to set pin numbers:
const int buttonPin = 6;  // pin number of pushbutton pin
const int ledPin    = 4;  // pin number of LED pin
const int dummyPin  = 5;  // pin number of dummy pin

// variables will change:
int buttonState     = 0;  // variable for reading the pushbutton status
int serialState     = 0;  // variable for reading serial line
int currentState    = 0;  // variable for current state
int prevState       = -1; // variable for previous state
int counter         = 0;  // valiable for event counter

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  // Prepare for dummy PIN to make it GND.
  pinMode(dummyPin, OUTPUT); digitalWrite(dummyPin, LOW);
  //
  Serial.begin(57600);
  delay(1000);
  Serial.println("# Hello, Monogramming!");
  delay(1000);
}

void loop() {
  char keyword[32] = { 0 };
  long timeinfo;
  char buff[80];

  if (Serial.available() > 0) {
    String str = Serial.readStringUntil('\n');
    str.toCharArray(buff, 80);
    Serial.print("# ["); Serial.print(buff); Serial.println("]"); // You can delete this line. Because this is prepared for debugging only

    sscanf(buff, "%s %ld %d", keyword, &timeinfo, &serialState);
    Serial.print("# ("); Serial.print(keyword); Serial.print(")");
    Serial.print("# ("); Serial.print(timeinfo); Serial.print(")");
    Serial.print("# ("); Serial.print(serialState); Serial.println(")");
  }
  
  buttonState = digitalRead(buttonPin);

  // update the value of the currentState
  // currentState = serialState;
  currentState = buttonState;
  // currentState = buttonState | serialState;

  if (currentState != prevState) {
    counter++;

    Serial.print(keyword); Serial.print("\t"); Serial.print(timeinfo);   Serial.print("\t");
    if (currentState == HIGH) {
      // turn LED on:
      Serial.print("HIGH");
      digitalWrite(ledPin, HIGH);
    } else {
      // turn LED off:
      Serial.print("LOW");
      digitalWrite(ledPin, LOW);
    }
    Serial.print("\t"); Serial.print(millis());
    Serial.print("\t"); Serial.print(counter);
    Serial.println();

    prevState = currentState;
  }
}
