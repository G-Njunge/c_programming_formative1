// pin assignments
const int TRIG      = 6;
const int ECHO      = 4;
const int GREEN_LED = 2;
const int RED_LED   = 3;
const int BUZZER    = 11;

// A vehicle closer than this is treated as parked in the space.
const int THRESHOLD_CM = 30;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);
}

// Returns distance in cm, or -1 if no echo came back.
float readDistanceCm() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 30000);   // give up after 30 ms

  if (duration == 0) {
    return -1;                                   // nothing within range
  }

  return duration * 0.0343 / 2;                  // /2 for the return trip
}

void loop() {
  float distance = readDistanceCm();

  Serial.print("Distance: ");
  if (distance < 0) {
    Serial.print("out of range");
  } else {
    Serial.print(distance);
    Serial.print(" cm");
  }

  if (distance > 0 && distance < THRESHOLD_CM) {
    // OCCUPIED
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    tone(BUZZER, 1000);
    Serial.println("   Buzzziiing");
    Serial.println("   Status: OCCUPIED");
  } else {
    // AVAILABLE
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    noTone(BUZZER);
    Serial.println("   Status: AVAILABLE");
  }

  delay(500);
}