// C++ code
//

const int LED_BUILTIN2 =3;
int val=0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN2, INPUT);
  digitalWrite (LED_BUILTIN2, LOW);
  
}

void loop()
{
  delay(1000); // Wait for 1000 millisecond(s)
  val = digitalRead(LED_BUILTIN2);  
  Serial.println(val);
  
}