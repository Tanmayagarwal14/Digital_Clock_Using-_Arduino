///This code is for controlling the two 7-seg display //


// Defining the Variables///
int a,b,c,d,e,f,g,W,X,Y,Z,i,j,thispin;
int A=0,B=0,C=0,D=0;
int ledpins[]={2,3,4,5,6,7,8,9,10};
int pinCount=9;
int r0,r1;
int low_pins[]={9,10};
int cnt[2];
unsigned int initialtime,elapsed;
void showit(int x);


// Setting up the Pins//
// the setup function runs once when you press reset or power the board
void setup()
{

  //initialize digital pin 2 to 10 as an output
  
  for(thispin=0;thispin<=pinCount;thispin++)
  {
    pinMode(ledpins[thispin],OUTPUT);
  
  }
}

//Main Function///
//LOOP FUNCTION RUNS OVER AND OVER AGAIN FOREVER// 
 void loop()
 {
 for(r1=0;r1<=5;r1++) // count 0 to 5 after every 10 seconds
 {
  for(r0=0;r0<=9;r0++)
  {
    // number of milliseconds Since program Strated.
    initialtime=millis();
    elapsed = initialtime;
    //ensuring delay of 1 Second
    while (elapsed - initialtime<=1000)
    {
      elapsed=millis();
      cnt[0]=r0;
      cnt[1]=r1;
      //Multiplexing the Displays
      for(j=0;j<2;j++)
      {
        digitalWrite(low_pins[j],LOW);
        digitalWrite(low_pins[i],HIGH);

        showit(cnt[i]);
        delay(2);
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

  //===========LOGIC FOR THE DISPLAY=========
  a=(A&&!B&&!C&&!D)||(!A&&C);
  b=(A&&!B&&C)||(!A&&B&&C);
  c=(!A&&B&&!C&&!D);
  d=(!A&&!B&&C)||(A&&!B&&!C)||(A&&B&&C);
  e=A||(!B&&C);
  f=(A&&!C&&!D)||(A&&B)||(B&&!C);
  g=(!B&&!C&&!D)||(A&&B&&C);


  ///////// Writting the Values on the Seven Segment Display///
  
  digitalWrite(2,a);
  digitalWrite(3,b);
  digitalWrite(4,c);
  digitalWrite(5,d);
  digitalWrite(6,e);
  digitalWrite(7,f);
  digitalWrite(8,g);
}













