int moterR1 = 5;
int moterL1 = 6;
int moterR2 = 10;
int moterL2 = 11;
int trigpin = A4;
int echopin = A3;
long duration, cm;
void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(moterR1, OUTPUT);
  pinMode(moterL1, OUTPUT);
  pinMode(moterR2, OUTPUT);
  pinMode(moterL2, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  distance();
  
    if (distance() > 30)
    { forward();
    }
    while (distance() < 30)
    {
      left();
    }
}
void left()
{
  analogWrite(moterR1, 0);
  analogWrite(moterL1, 70);
  analogWrite(moterR2, 90);
  analogWrite(moterL2, 0);
}
int distance()
{
  //Serial.println("Inside distance function");
  int y;
  digitalWrite(trigpin, LOW);
  /*
    we will get distance from ultrasonic
    sensor. */ delay(20);
  digitalWrite(trigpin, HIGH);
  delay(100);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  cm = (duration / 2) * 0.034;
  y = cm;
  Serial.println(y);

  return y;
}
void forward()
{ analogWrite(moterR1, 0); //Right Motor backward
  //motor will move forward
  analogWrite(moterL1, 140); //Right Motor forward
  analogWrite(moterR2, 0);  //Left Motor backward
  analogWrite(moterL2, 220);//Left Motor forward
}
