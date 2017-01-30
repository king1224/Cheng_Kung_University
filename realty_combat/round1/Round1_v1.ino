#define NORMAL 0
#define DEADROAD 1
#define LOOP 2

float duration,Front,Right,Left,LFront,RFront;
float PreFront[5],PreRight[5],PreLeft[5];
int mode;
int Close,DeadRoad,regulate_cd;
int Turn_Record;

void DistanceCalc(){
  for(int i=4;i>0;--i){
    PreFront[i]=PreFront[i-1];
    PreRight[i]=PreRight[i-1];
    PreLeft[i]=PreLeft[i];  
  }
  PreFront[0] = Front;
  PreRight[0] = Right;
  PreLeft[0] = Left;
  
  //Front
  digitalWrite(40, HIGH);
  delayMicroseconds(1000);
  digitalWrite(40, LOW);
  duration = pulseIn (41, HIGH);
  Front = (duration/2)/29;
  Serial.print("Data:");
  Serial.print(", Front = ");
  Serial.print(Front);
  Serial.print(" cm  ");

  //Left
  digitalWrite(30, HIGH);
  delayMicroseconds(1000);
  digitalWrite(30, LOW);
  duration = pulseIn (31, HIGH);
  Left = (duration/2)/29;
  Serial.print(", Left = ");
  Serial.print(Left);
  Serial.print(" cm  ");
  
  digitalWrite(36, HIGH);
  delayMicroseconds(1000);
  digitalWrite(36, LOW);
  duration = pulseIn (37, HIGH);
  LFront = (duration/2)/29;
  Serial.print(", LFront = ");
  Serial.print(LFront);
  Serial.print(" cm  ");

  
  digitalWrite(44, HIGH);
  delayMicroseconds(1000);
  digitalWrite(44, LOW);
  duration = pulseIn (45, HIGH);
  RFront = (duration/2)/29;
  Serial.print(", RFront = ");
  Serial.print(RFront);
  Serial.print(" cm  ");


  //Right
  digitalWrite(50, HIGH);
  delayMicroseconds(1000);
  digitalWrite(50, LOW);
  duration = pulseIn (51, HIGH);
  Right = (duration/2)/29;
  Serial.print(", Right = ");
  Serial.print(Right);
  Serial.println(" cm");
}

void MoveFront(int speed){
  analogWrite(12, 0);
  analogWrite(11, speed);
  analogWrite(8, 0);
  analogWrite(9, speed);
}

void MoveBack(int speed){
  analogWrite(12, speed);
  analogWrite(11, 0);
  analogWrite(8, speed);
  analogWrite(9, 0);
}

void MoveRight(int speed){
  analogWrite(12, speed);
  analogWrite(11, 0);
  analogWrite(8, 0);
  analogWrite(9, speed);
  Turn_Record = 2;
}

void MoveLeft(int speed){
  analogWrite(12, 0);
  analogWrite(11, speed);
  analogWrite(8, speed);
  analogWrite(9, 0);
  Turn_Record = 1;
}

void Stop(){
  analogWrite(12, 0);
  analogWrite(11, 0);
  analogWrite(8, 0);
  analogWrite(9, 0);
}

void TurnLeft(){
  int turncount=80;
  MoveLeft(200);
  delay(200);
  MoveFront(200);
  delay(120);
  MoveLeft(200);
  delay(90);
  DistanceCalc();
  Stop();
  while(Left>15){
    DistanceCalc();
    MoveFront(220);
    if( (turncount--) <= 0) break;
    if(regulate_cd--<0){
      if((PreRight[0]-Right)>1 && (PreRight[1]-PreRight[0])>1){
        MoveRight(160);
        delay(80);
        MoveFront(200);
        delay(100);
        regulate_cd=10;
        break;
      }
      else if((PreLeft[0]-Left)>1 && (PreLeft[1]-PreLeft[0])>1){
        MoveLeft(200);
        delay(80);
        MoveFront(255);
        delay(100);
        regulate_cd=10;
        break;
      }
    }
  }
  Stop();
//  delay(2000);
  Close = 0;
  DeadRoad = 0;
}

void TurnRight(){
  int turncount=80;
  MoveRight(200);
  delay(200);
  MoveFront(200);
  delay(120);
  MoveRight(200);
  delay(110);
  Stop();
  DistanceCalc();
  while(Right>15){
    DistanceCalc();
    MoveFront(220);
    if( (turncount--) <= 0) break;
    if(regulate_cd--<0){
      if((PreRight[0]-Right)>1 && (PreRight[1]-PreRight[0])>1){
        MoveRight(160);
        delay(80);
        MoveFront(200);
        delay(100);
        regulate_cd=10;
        break;
      }
      else if((PreLeft[0]-Left)>1 && (PreLeft[1]-PreLeft[0])>1){
        MoveLeft(160);
        delay(80);
        MoveFront(200);
        delay(100);
        regulate_cd=10;
        break;
      }
    }
  }

  Stop();
  Close = 0;
  DeadRoad = 0;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (30, OUTPUT);
  pinMode (31, INPUT);
  pinMode (36, OUTPUT);
  pinMode (37, INPUT);
  pinMode (40, OUTPUT);
  pinMode (41, INPUT);
  pinMode (44, OUTPUT);
  pinMode (45, INPUT);
  pinMode (50, OUTPUT);
  pinMode (51, INPUT); //echo
  //motor
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);
  mode = NORMAL;
  Close = 0;
  DeadRoad = 0;
  Turn_Record = 0; // 1 for left  ,  2 for right
  MoveFront(255);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  DistanceCalc();
  if(Left>30 && Front<10){
    MoveBack(200);
    delay(250);
    TurnLeft();
    MoveFront(180);
    delay(300);
  }
  else if(Right>30 && Front<10){
    MoveBack(200);
    delay(250);
    TurnRight();
    MoveFront(180);
    delay(300);
  }
  if(Right>11 || Left<6){
    MoveBack(200);
    delay(100);
    MoveRight(160);
    delay(80);
    MoveFront(200);
    delay(500);
    regulate_cd=20; 
  }
  else if(Right<6/* || (Left>12 && Left<15)*/){
    MoveBack(200);
    delay(100);
    MoveLeft(160);
    delay(80);
    MoveFront(200);
    delay(500);
  }
  else{
    MoveFront(200);
    delay(500);
  }
}
