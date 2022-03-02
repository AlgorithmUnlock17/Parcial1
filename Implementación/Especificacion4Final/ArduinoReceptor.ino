#include <LiquidCrystal.h>

// C++ code
// Arduino Receptor
#define clave 10
char arr[8]={0};
int aux=0, key=0, c=0;
LiquidCrystal lcd(A0,A1,A2,13,12,11);
int pos=0;
char* results=new char[3];
void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  for (int i=2;i<10;i++) //Se especifican los pines de 2 a 9 como input
    pinMode(i,INPUT);
  pinMode(clave,INPUT);
}

void loop()
{
  delay (100);
  key=digitalRead(clave);
  if (key==0)
    c++;
  if (c==2){
  for (int i=0;i<3;i++){
    delay(100);
    for (int j=2;j<10;j++){ //creacion de arreglo 0 y 1
      arr[j-2]=digitalRead(j);}
  int number=0;
  for(int j=0;j<8;j++) //Pasar de arreglo a int
  	number=number*2+arr[j];
  *(results+i)=char(number);   
  Serial.print(number);
  Serial.print(' '); 
  c=0;
  }
  lcd.clear();
  lcd.setCursor(0,0);
  for (int i=0;i<3;i++){
  	lcd.print(int(*(results+i)));  
    lcd.print(' ');
  }
  lcd.setCursor(0,1);
  for (int i=0;i<3;i++){
  	lcd.print(*(results+i));
  	lcd.print(' ');
  }
  }
}