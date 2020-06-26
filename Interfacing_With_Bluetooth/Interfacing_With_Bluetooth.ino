#define dir1 10
#define dir2 9
#define pwm1 12
#define pwm2 11
#define max_speed 255
char input_BT;
void setup()
{
  Serial.begin(9600);
  pinMode(dir1 , OUTPUT);
  pinMode(dir2 , OUTPUT);
  pinMode(pwm1 , OUTPUT);
  pinMode(pwm2 , OUTPUT);
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);
  analogWrite(pwm1, max_speed);
  analogWrite(pwm2, max_speed);
  delay(100);
}
void moveForward()
{
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);
  analogWrite(pwm1, max_speed);
  analogWrite(pwm2, max_speed);

}
void moveLeft()
{
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, HIGH);
  analogWrite(pwm1, max_speed);
  analogWrite(pwm2, max_speed);
}
void moveRight()
{
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, LOW);
  analogWrite(pwm1, max_speed);
  analogWrite(pwm2, max_speed);
}
void robot_Stop()
{
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);
  analogWrite(pwm1, 0);
  analogWrite(pwm2, 0);
}
void moveBackward()
{
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, HIGH);
  analogWrite(pwm1, max_speed);
  analogWrite(pwm2, max_speed);
}
void loop()
{
  if (Serial.available() > 0)
  {
    input_BT = Serial.read();
  }

  switch (input_BT)
  {
    case 'u': // forward
      moveForward();
      break;
    case 'l':
      moveLeft();
      break ;
    case 'r':
      moveRight();
      break ;
    case 'd':
      moveBackward();
      break ;
    case 's':
      robot_Stop();
      break ;
  }
}
