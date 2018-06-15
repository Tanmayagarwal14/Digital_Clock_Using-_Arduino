///Code written by Tanmay Agarwal

int a,b,c,d,e,f,g,W,X,Y,Z,i,j,thispin,min0,min1,ar,arc=0;
int A=0,B=0,C=0,D=0;
int ledpins[]={2,3,4,5,6,7,8,9,10,11,12,13,1};
int pinCount=13;
int r0,r1,r2,r3,r4,r5;
int low_pins[]={9,10,11,12,13,1};
int cnt[6];
unsigned int initialtime,elapsed;
void showit(int x);

void setup()
{
  for(thispin=0;thispin<=pinCount;thispin++)
  {
    pinMode(ledpins[thispin],OUTPUT);
    Serial.begin(9600);
  
  }
}
 void loop()
 {
  for(r5=0;r5<=2;r5++)
  {
  for(r4=0;r4<=9;r4++)
  {
  for(r3=0;r3<6;r3++)
  {
  for(r2=0;r2<=9;r2++)
  {
  for(r1=0;r1<6;r1++)
  {
  for(r0=0;r0<=9;r0++)
  {

    initialtime=millis();
    elapsed = initialtime;
    while(elapsed-initialtime<=1000)
    {
    int ar=analogRead(A3);
    ar=(ar*(59/1024.0));
    Serial.println(ar);
    min0=ar%10;
    min1=ar/10;

    if(ar!=arc)
    
    {
      arc=ar;
      r2=min0;
      r3=min1;
    }
    
      elapsed = millis();
      if(r5==2 && r4==4)
       {   
      cnt[0]=0;
      cnt[1]=0;
      cnt[2]=0;
      cnt[3]=0;
      cnt[4]=0;
      cnt[5]=0;
       }  
      else
      {
        cnt[0]=r0;
        cnt[1]=r1;
        cnt[2]=r2;
        cnt[3]=r3;
        cnt[4]=r4;
        cnt[5]=r5;
      }
      for (i=0;i<6;i++)
      {
        for(j=0;j<6;j++)
        {
          digitalWrite(low_pins[j],LOW);
         }
        digitalWrite(low_pins[i],HIGH);
        showit(cnt[i]);
        delay(1);
        

    }
 }
 }
 }
 }
 }
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













