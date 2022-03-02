//Arduino Emisor
// C++ code
//
#define ORCLK 8
#define SRCLK 7
#define num 9

int aux1=0;

void setup()
{
  Serial.begin(9600); 
  pinMode(num, OUTPUT);
  pinMode(ORCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  randomSeed(analogRead(A2));
  
}

void loop()
{
  if(aux1==0){
  delay(100);
  //Manera manual, se puede utilizar para pruebas NO PUEDE TERMINAR EN 42
  unsigned char array[]={12,245,43,43,42,2,52,38,42,110,115,65,4,9,9,42,12,1,42,65,65,65,41,42,42,111,112,103}; 
  int size=sizeof(array)/sizeof(*(array));
  //Manera random
  //El array de arriba se puede utilizar para pruebas
  //int size=random(200);
  //unsigned char array[size]={0};
  //for(int i=0;i<size;i++) //Creacion del arreglo 
  //   array[i]=random(256);
  for (int i=0;i<size;i++){ //Envio arreglo a 74hc595
    ledLineWrite(array[i]);
    
  }
    aux1=1;}
}

void ledLineWrite(unsigned char Sf1)
  //Solo se permite la entrada de numeros menores de 255
{
   
   shiftOut(num, SRCLK, MSBFIRST, Sf1);
   digitalWrite(ORCLK, HIGH);
   digitalWrite(ORCLK, LOW);
   delay(100);
}
