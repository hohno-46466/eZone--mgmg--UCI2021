// Rotary controls LED

int rotaryPin = A0; // select the input pin for the rotary
int ledPin = 4; // select the pin for the LED
int rotaryValue = 0; // variable to store the value coming from the rota
int prevValue = -1;
int cnt = 0;

#define MY_KEYWORD  "YOURNAME-L3A"

void setup() {
 // declare the ledPin as an OUTPUT:
 pinMode(ledPin, OUTPUT);
 Serial.begin(57600);
}

void loop() {
    static boolean prevStat = false;

    // read the value from the sensor:
    rotaryValue = analogRead(rotaryPin);
    rotaryValue = map(rotaryValue, 0, 1023, 2000, 0);
    if (rotaryValue != prevValue) {
        uint32_t tNow = millis();
        Serial.print("N/A ");
        Serial.print("N/A ");
        Serial.print(tNow/1000); Serial.print("."); 
	int x = tNow % 1000;
	if (x < 10) { Serial.print("0"); }
	if (x < 100) { Serial.print("0"); }
	Serial.print(x); Serial.print(" "); //  <-- printf("%d.%03d ", tNow/1000, tNow%1000);
        Serial.print(MY_KEYWORD); Serial.print(" ");
        Serial.print(cnt); Serial.print(" ");
        Serial.println(rotaryValue);

        // turn the ledPin on
        digitalWrite(ledPin, HIGH);
        // stop the program for 100 milliseconds:
        delay(100);
        // turn the ledPin off:
        digitalWrite(ledPin, LOW);
        // stop the program for 100 milliseconds:
        delay(100);
        prevValue = rotaryValue;
        cnt++;
    }
}
