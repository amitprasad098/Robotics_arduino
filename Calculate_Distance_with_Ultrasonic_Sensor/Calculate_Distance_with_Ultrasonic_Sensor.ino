#define echo_pin 8;
#define trig_pin 9;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
pinMode(echo_pin , INPUT);
pinMode(trig_pin , INPUT);
}

void loop() {
  double value,duration;
  digitalWrite(trig_pin, LOW);
  delay(2);
  digitalWrite(trig_pin, HIGH);
  delay(10);
  digitalWrite(trig_pin, LOW);
  delay(2);
  value = pulseIn(echo_pin, HIGH);
  duration = ((value/29.8)/2);
  Serial.println(duration);
}
