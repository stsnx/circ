

const int segmentA=A0;
const int segmentB=A1;
const int segmentC=A2;
const int segmentD=A3;
const int segmentE=A4;
const int segmentF=A5;
const int segmentG=2;
//const int segmentDP=13;
const int swith1=10;
const int swith2=11;
const int swith3=12;
const int swith4=9;
const int trigPin1 = 3;
const int echoPin1 = 4;
const int trigPin2 = 5;
const int echoPin2 = 6;
const int oa1 = 8;
const int oa2 = 13;
int sec = 0;
int l=0,r=0;
long d1;
int distance1;
long d2;
int distance2;
int finnum=0;
int finr=0;
int finl=0;
int stay = 0;
int stayfor = 0;

void setup() 
{
  
  Serial.begin(9600);
   pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
   pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
   pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
   pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
   pinMode(segmentA, OUTPUT);
   pinMode(segmentB, OUTPUT);
   pinMode(segmentC, OUTPUT);
   pinMode(segmentD, OUTPUT);
   pinMode(segmentE, OUTPUT);
   pinMode(segmentF, OUTPUT);
   pinMode(segmentG, OUTPUT);
//   pinMode(segmentDP, OUTPUT);
   pinMode(swith1, OUTPUT);
   pinMode(swith2, OUTPUT);
   pinMode(swith3, OUTPUT);
   pinMode(swith4, OUTPUT);
   pinMode(oa1, OUTPUT);
   pinMode(oa2, OUTPUT);
   noInterrupts();
 TCCR1A = 0; 
 TCCR1B = 0;
 TCNT1 = 0; 
 OCR1A = 15624; 
 
TCCR1B |= (1 << WGM12); 
 TCCR1B |= (1 << CS12) | (1 << CS10); 
 TIMSK1 |= (1 << OCIE1A); 
 interrupts(); 
 digitalWrite(oa1, LOW);
 digitalWrite(oa2, LOW);
}
void displaySegment(int numberToDisplay)
{
  switch(numberToDisplay)
  {
    //Number 0
    case 0:
    digitalWrite(segmentA,LOW);
    digitalWrite(segmentB,LOW);
    digitalWrite(segmentC,LOW);
    digitalWrite(segmentD,LOW);
    digitalWrite(segmentE,LOW);
    digitalWrite(segmentF,LOW);
    digitalWrite(segmentG,HIGH);
    break;

    //Number 1
    case 1:
    digitalWrite(segmentA,HIGH);
    digitalWrite(segmentB,LOW);
    digitalWrite(segmentC,LOW);
    digitalWrite(segmentD,HIGH);
    digitalWrite(segmentE,HIGH);
    digitalWrite(segmentF,HIGH);
    digitalWrite(segmentG,HIGH);
    break;

    //Number 2
    case 2:
    digitalWrite(segmentA,LOW);
    digitalWrite(segmentB,LOW);
    digitalWrite(segmentC,HIGH);
    digitalWrite(segmentD,LOW);
    digitalWrite(segmentE,LOW);
    digitalWrite(segmentF,HIGH);
    digitalWrite(segmentG,LOW);
    break;

    //Number 3
    case 3:
    digitalWrite(segmentA,LOW);
    digitalWrite(segmentB,LOW);
    digitalWrite(segmentC,LOW);
    digitalWrite(segmentD,LOW);
    digitalWrite(segmentE,HIGH);
    digitalWrite(segmentF,HIGH);
    digitalWrite(segmentG,LOW);
    break;

    //Number 4
    case 4:
    digitalWrite(segmentA,HIGH);
    digitalWrite(segmentB,LOW);
    digitalWrite(segmentC,LOW);
    digitalWrite(segmentD,HIGH);
    digitalWrite(segmentE,HIGH);
    digitalWrite(segmentF,LOW);
    digitalWrite(segmentG,LOW);
    break;

    //Number 5
    case 5:
    digitalWrite(segmentA,LOW);
    digitalWrite(segmentB,HIGH);
    digitalWrite(segmentC,LOW);
    digitalWrite(segmentD,LOW);
    digitalWrite(segmentE,HIGH);
    digitalWrite(segmentF,LOW);
    digitalWrite(segmentG,LOW);
    break;

    //Number 6
    case 6:
    digitalWrite(segmentA,LOW);
    digitalWrite(segmentB,HIGH);
    digitalWrite(segmentC,LOW);
    digitalWrite(segmentD,LOW);
    digitalWrite(segmentE,LOW);
    digitalWrite(segmentF,LOW);
    digitalWrite(segmentG,LOW);
    break;

    //Number 7
    case 7:
    digitalWrite(segmentA,LOW);
    digitalWrite(segmentB,LOW);
    digitalWrite(segmentC,LOW);
    digitalWrite(segmentD,HIGH);
    digitalWrite(segmentE,HIGH);
    digitalWrite(segmentF,HIGH);
    digitalWrite(segmentG,HIGH);
    break;

    //Number 8
    case 8:
    digitalWrite(segmentA,LOW);
    digitalWrite(segmentB,LOW);
    digitalWrite(segmentC,LOW);
    digitalWrite(segmentD,LOW);
    digitalWrite(segmentE,LOW);
    digitalWrite(segmentF,LOW);
    digitalWrite(segmentG,LOW);
    break;

    //Number 9
    case 9:
    digitalWrite(segmentA,LOW);
    digitalWrite(segmentB,LOW);
    digitalWrite(segmentC,LOW);
    digitalWrite(segmentD,LOW);
    digitalWrite(segmentE,HIGH);
    digitalWrite(segmentF,LOW);
    digitalWrite(segmentG,LOW);
    break;
  }
}
void displaySegment2(int numberToDisplay)
{
  switch(numberToDisplay)
  {
    //Number 0
    case 0:
    digitalWrite(segmentA,HIGH);
    digitalWrite(segmentB,HIGH);
    digitalWrite(segmentC,HIGH);
    digitalWrite(segmentD,HIGH);
    digitalWrite(segmentE,HIGH);
    digitalWrite(segmentF,HIGH);
    digitalWrite(segmentG,LOW);
    break;

    //Number 1
    case 1:
    digitalWrite(segmentA,LOW);
    digitalWrite(segmentB,HIGH);
    digitalWrite(segmentC,HIGH);
    digitalWrite(segmentD,LOW);
    digitalWrite(segmentE,LOW);
    digitalWrite(segmentF,LOW);
    digitalWrite(segmentG,LOW);
    break;

    //Number 2
    case 2:
    digitalWrite(segmentA,HIGH);
    digitalWrite(segmentB,HIGH);
    digitalWrite(segmentC,LOW);
    digitalWrite(segmentD,HIGH);
    digitalWrite(segmentE,HIGH);
    digitalWrite(segmentF,LOW);
    digitalWrite(segmentG,HIGH);
    break;

    //Number 3
    case 3:
    digitalWrite(segmentA,HIGH);
    digitalWrite(segmentB,HIGH);
    digitalWrite(segmentC,HIGH);
    digitalWrite(segmentD,HIGH);
    digitalWrite(segmentE,LOW);
    digitalWrite(segmentF,LOW);
    digitalWrite(segmentG,HIGH);
    break;

    //Number 4
    case 4:
    digitalWrite(segmentA,LOW);
    digitalWrite(segmentB,HIGH);
    digitalWrite(segmentC,HIGH);
    digitalWrite(segmentD,LOW);
    digitalWrite(segmentE,LOW);
    digitalWrite(segmentF,HIGH);
    digitalWrite(segmentG,HIGH);
    break;

    //Number 5
    case 5:
    digitalWrite(segmentA,HIGH);
    digitalWrite(segmentB,LOW);
    digitalWrite(segmentC,HIGH);
    digitalWrite(segmentD,HIGH);
    digitalWrite(segmentE,LOW);
    digitalWrite(segmentF,HIGH);
    digitalWrite(segmentG,HIGH);
    break;

    //Number 6
    case 6:
    digitalWrite(segmentA,HIGH);
    digitalWrite(segmentB,LOW);
    digitalWrite(segmentC,HIGH);
    digitalWrite(segmentD,HIGH);
    digitalWrite(segmentE,HIGH);
    digitalWrite(segmentF,HIGH);
    digitalWrite(segmentG,HIGH);
    break;

    //Number 7
    case 7:
    digitalWrite(segmentA,HIGH);
    digitalWrite(segmentB,HIGH);
    digitalWrite(segmentC,HIGH);
    digitalWrite(segmentD,LOW);
    digitalWrite(segmentE,LOW);
    digitalWrite(segmentF,LOW);
    digitalWrite(segmentG,LOW);
    break;

    //Number 8
    case 8:
    digitalWrite(segmentA,HIGH);
    digitalWrite(segmentB,HIGH);
    digitalWrite(segmentC,HIGH);
    digitalWrite(segmentD,HIGH);
    digitalWrite(segmentE,HIGH);
    digitalWrite(segmentF,HIGH);
    digitalWrite(segmentG,HIGH);
    break;

    //Number 9
    case 9:
    digitalWrite(segmentA,HIGH);
    digitalWrite(segmentB,HIGH);
    digitalWrite(segmentC,HIGH);
    digitalWrite(segmentD,HIGH);
    digitalWrite(segmentE,LOW);
    digitalWrite(segmentF,HIGH);
    digitalWrite(segmentG,HIGH);
    break;
  }
}
void displayNumber(int x)
{
         
          if(x>=10){
          digitalWrite(swith1,HIGH);
          digitalWrite(swith2,LOW);
           digitalWrite(swith3,HIGH);
          digitalWrite(swith4,HIGH);
          displaySegment((x/10)%10);
          delay(5);
          }
          digitalWrite(swith1,LOW);
          digitalWrite(swith2,HIGH);
           digitalWrite(swith3,HIGH);
          digitalWrite(swith4,HIGH);
          displaySegment(x%10);
          
          delay(5);
          
}
ISR(TIMER1_COMPA_vect)
{
 sec++;
}
void displaynuml(int x){
  digitalWrite(swith1,LOW);
  digitalWrite(swith2,LOW);
  digitalWrite(swith3,LOW);
  digitalWrite(swith4,HIGH);
  displaySegment2(x);
  delay(5);
}
void displaynumr(int x){
  digitalWrite(swith1,LOW);
  digitalWrite(swith2,LOW);
  digitalWrite(swith4,LOW);
  digitalWrite(swith3,HIGH);
  displaySegment2(x);
  delay(5);
}
unsigned long temp = 0;
unsigned long temp2 = 0;
void loop() 
{
    
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(2);
    digitalWrite(trigPin1, LOW);
    d1 = pulseIn(echoPin1, HIGH);
    distance1= d1*0.034/2;
    delayMicroseconds(2);
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(2);
    digitalWrite(trigPin2, LOW);
    d2 = pulseIn(echoPin2, HIGH);
    distance2= d2*0.034/2;
   
    if((distance1<5||distance2<5)&&(finr == 0&&finl == 0)){
      stay = 1;
      if(distance1<5){
        finr = 1;
        finnum = sec;
        digitalWrite(oa1, HIGH);
        digitalWrite(oa2, LOW);
      }
      else if(distance2<5) {
        finl = 1;
        finnum = sec;
        digitalWrite(oa1, LOW);
        digitalWrite(oa2, HIGH);
      }
    }
    if(finr == 1||finl == 1){
      temp++;
    } 

    if(temp>50){
        
       
      if(stayfor==0){
        if(finr ==1||finl==1){
        if(finr == 1 ) {
        r++;
        stayfor = 1;
        finr =0; 

        }
        else if(finl == 1 ) {
        l++;
        stayfor = 1;
        finl = 0;
        }
        }
       
      }
      if((distance1>5&&distance2>5)&&stay==1){
      stay = 0;
      finr =0; 
      finl = 0;
      sec = 0;
      stayfor = 0;
      temp = 0;
      digitalWrite(oa1, LOW);
      digitalWrite(oa2, LOW);
      }
    }
    
    if(finr ==1||finl==1) {
      sec = finnum;
    }
    displayNumber(sec);
    displaynuml(l);
    displaynumr(r);
    Serial.print("temp= ");
    Serial.print(temp);
    Serial.print(" : ");
    Serial.print(distance1);
    Serial.print(" : ");
    Serial.println(distance2);
   
}
