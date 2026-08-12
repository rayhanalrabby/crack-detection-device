/*
 * Ultrasonic Crack Detection
 * EE397 Technical Report, Group 5 — Maynooth University, Dec 2025
 *
 * HC-SR04 swept across a surface. A crack shows as a spike in the
 * distance reading, visible live in the Arduino IDE serial plotter.
 */

int trig = 3;
int echo = 2;
long duration;    // echo pulse width
float distance;   // measured distance, cm

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  distance = calcDistance();
  Serial.print("Distance = ");
  Serial.println(distance);
  delay(300);
}

float calcDistance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);   // 10 us trigger pulse
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration * 0.034) / 2;   // speed of sound, halved for round trip
  return distance;
}