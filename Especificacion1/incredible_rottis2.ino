// C++ code
//
#define ORCLK 5
#define SRCLK 6
#define num 7

void setup()
{
  pinMode(num, OUTPUT);
  pinMode(ORCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);
}

void loop()
{
  int number=12; //Menor de 16
  digitalWrite(ORCLK,LOW);
  shiftOut(num, SRCLK, MSBFIRST, number);
  digitalWrite(ORCLK,HIGH);
}