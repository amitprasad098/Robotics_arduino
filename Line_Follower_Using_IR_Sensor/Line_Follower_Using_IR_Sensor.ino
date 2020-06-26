#define ir1 12
#define ir2 13
int moterR1 = 5;
int moterL1 = 6;
int moterR2 = 10;
int moterL2 = 11;
void setup() {
  Serial.begin(9600);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(moterR1, OUTPUT);
  pinMode(moterL1, OUTPUT);
  pinMode(moterR2, OUTPUT);
  pinMode(moterL2, OUTPUT);
}
void moveLeft()
{
  analogWrite(moterR1, 0); //Right Motor backward
  analogWrite(moterL1, 70); //Right Motor forward
  analogWrite(moterR2, 0);  //Left Motor backward
  analogWrite(moterL2, 42);//Left Motor forward
  delay(200);
}

void moveRight()
{
  analogWrite(moterR1, 0); //Right Motor backward
  analogWrite(moterL1, 25); //Right Motor forward
  analogWrite(moterR2, 0);  //Left Motor backward
  analogWrite(moterL2, 115);//Left Motor forward
  delay(200);
}
void moveForward()
{
  analogWrite(moterR1, 0); //Right Motor backward
  analogWrite(moterL1, 40); //Right Motor forward
  analogWrite(moterR2, 0);  //Left Motor backward
  analogWrite(moterL2, 70);//Left Motor forward
}
void stopping()
{
  analogWrite(moterR1, 0); //Right Motor backward
  analogWrite(moterL1, 0); //Right Motor forward
  analogWrite(moterR2, 0);  //Left Motor backward
  analogWrite(moterL2, 0);//Left Motor forward
  delay(1000);
}
void loop() {
  int i1, i2;
  i1 = digitalRead(ir1);
  i2 = digitalRead(ir2);
  //Serial.print(i1);
  //Serial.print(i2);
  //Serial.println();
  
  if (i1 == 1 && i2 == 0)
  {
    moveLeft();
  }
  if (i1 == 0 && i2 == 1)
  {
    moveRight();
  }
  if (i1 == 0 && i2 == 0)
  {
    moveForward();
  }
  if (i1 == 1 && i2 == 1)
  {
    stopping();
  }
}
