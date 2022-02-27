// C++ code
//
#define andy 6
int aux=0;
int x2=9;
void setup()
{
  Serial.begin(9600);
  pinMode(andy, INPUT);
}

void loop()
{
  
  int x = digitalRead(andy);
  if (x!=x2){
  if(x==0)
  	Serial.println("Son iguales");
  else if (x==1)
    Serial.println("Son diferentes");
  x2=x;
  }
}