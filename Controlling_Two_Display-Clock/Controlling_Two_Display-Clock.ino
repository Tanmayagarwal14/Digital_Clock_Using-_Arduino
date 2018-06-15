int a,b,c,d,e,f,g,W,X,Y,Z,i,j,thispin;
int A=0,B=0,C=0,D=0;
int ledpins[]={2,3,4,5,6,7,8,9,10};
int pinCount=9;
int r0;
unsigned int initialtime,elapsed;
void showit(int x);

void setup()
{
  for(thispin=0;thispin<=pinCount;thispin++)
  {
    pinMode(ledpins[thispin],OUTPUT);
  
  }
}
 void loop()
 {
  for(r0=0;r0<=9;r0++)
  {
    initialtime=millis();

    for(elapsed=0;elapsed<=1000;elapsed=millis()-initialtime)
    {
      digitalWrite(9,HIGH);
      showit(r0);
      
    }
  }
 }
 void showit(int x)
 {
  int D,C,B,A;
  A=x%2;
  x=x/2;
  B=x%2;
  x=x/2;
  C=x%2;
  x=x/2;
  D=x%2;
  x=x/2;

  
 a=(A&&!B&&!C&&!D)||(!A&&C);
  b=(A&&!B&&C)||(!A&&B&&C);
  c=(!A&&B&&!C&&!D);
  d=(!A&&!B&&C)||(A&&!B&&!C)||(A&&B&&C);
  e=A||(!B&&C);
  f=(A&&!C&&!D)||(A&&B)||(B&&!C);
  g=(!B&&!C&&!D)||(A&&B&&C);
  
   digitalWrite(2,a);
  digitalWrite(3,b);
  digitalWrite(4,c);
  digitalWrite(5,d);
  digitalWrite(6,e);
  digitalWrite(7,f);
  digitalWrite(8,g);
}













