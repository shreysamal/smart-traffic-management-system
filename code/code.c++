int trig_pin = 5;
int echo_pin = 4;
long duration;
int distance;
int redled = 7;       // Red LED connected to pin 7     
int greenled = 8;     // Green LED connected to pin 8
int switchslide = 6;
bool switchstate;

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(switchslide, INPUT);
  Serial.begin(9600);
}

void loop() {
  switchstate = digitalRead(switchslide);
  if (switchstate == HIGH) {
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);

    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trig_pin, LOW);

    // Measure the pulse duration
    duration = pulseIn(echo_pin, HIGH);
    distance = duration * 0.034 / 2;

    if (duration == 0) {                  // No obstacle detected (infinity)
      digitalWrite(redled, LOW);
      digitalWrite(greenled, HIGH);
    } else if (distance <= 18) {  // Closer object (Red LED)
      digitalWrite(redled, HIGH);
      digitalWrite(greenled, LOW);
    } else {                            // Farther object (Green LED)
      digitalWrite(redled, LOW);
      digitalWrite(greenled, HIGH);
    }
  } else {
    digitalWrite(redled, LOW);
    digitalWrite(greenled, LOW);       // Ensure all LEDs are off when switch is off
  }
}
