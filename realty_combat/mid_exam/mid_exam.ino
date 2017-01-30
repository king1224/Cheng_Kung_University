int timer=0, stopcount=0;
int mode=0,changecount=0,backcount=0,aroundcount=0;
int MoveLeftCount=0,MoveRightCount=0;
float Dis_Left[30],Dis_Right[30];
float PreFront, PreRight, PreLeft, PreBehind;
float duration, Front, Right, Left, Behind;

void Regulate();

//前後左右四個超音波
void DistanceCalc(){

  PreRight=Right;
  PreLeft=Left;
  PreFront=Front;
  PreBehind=Behind;
  //右超音波
  digitalWrite(8, HIGH);
  delayMicroseconds(1000);
  digitalWrite(8, LOW);
  duration = pulseIn (9, HIGH);
  Right = (duration/2)/29;
  Serial.print("Data:");
  Serial.print (timer/1000);
  Serial.print(", Right = ");
  Serial.print(Right);
  Serial.print(" cm ,");
  //左超音波
  digitalWrite(52, HIGH);
  delayMicroseconds(1000);
  digitalWrite(52, LOW);
  duration = pulseIn (53, HIGH);
  Left = (duration/2)/29;
  Serial.print("Left = ");
  Serial.print(Left);
  Serial.print(" cm ,");
  //前超音波
  digitalWrite(12, HIGH);
  delayMicroseconds(1000);
  digitalWrite(12, LOW);
  duration = pulseIn (13, HIGH);
  Front = (duration/2)/29;
  Serial.print("Front = ");
  Serial.print(Front);
  Serial.print(" cm ,");
  //後超音波
  digitalWrite(50, HIGH);
  delayMicroseconds(1000);
  digitalWrite(50, LOW);
  duration = pulseIn (51, HIGH);
  Behind = (duration/2)/29;
  Serial.print("Behind = ");
  Serial.print(Behind);
  Serial.println(" cm");
  timer = timer + 1000;
}

//單純右轉
void MoveRight(int Speed){
  analogWrite(4, 0);
  analogWrite(5, Speed);
  analogWrite(6, Speed);
  analogWrite(7, 0);
}

//單純左轉
void MoveLeft(int Speed){
  analogWrite(4, Speed);
  analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(7, Speed);
}

//單純前進
void MoveForward(int Speed){
  analogWrite(4, Speed);
  analogWrite(5, 0);
  analogWrite(6, Speed-5);
  analogWrite(7, 0);
}

//單純後退
void MoveBack(int Speed){
  analogWrite(4, 0);
  analogWrite(5, Speed);
  analogWrite(6, 0);
  analogWrite(7, Speed);
}

//完全停止
void Stop(){
  analogWrite(4, 0);
  analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(7, 0);
}

//左轉90度，包裝好的
void TurnLeft(){
  //先退到左轉前的位置
  //退10次，或退到sensor對齊牆壁
  int x=0;
  while(Left>10){
    MoveBack(200);
    delay(80);
    Stop();
    DistanceCalc();
    x++;
    if(x>10) break;
  }

  //前進再左轉再前進再左轉
  MoveForward(255);
  delay(450);
  MoveLeft(255);
  delay(400);
  MoveForward(255);
  delay(300);
  MoveLeft(255);
  delay(250);
  MoveForward(255);
  delay(150);
  MoveForward(255);
  delay(600);
  
  //如果還沒轉夠，再前進再左轉
  //若要確保轉彎一定能成功，i的上限可以設5
  for(int i=1;i<1;++i){
    DistanceCalc();
    //完全轉完了，左右sensor距離會變很小
    if(Left<=8 && Right <=8){
      break;
    }
    MoveBack(255);
    delay(80);
    MoveLeft(255);
    delay(80);
    MoveForward(255);
    delay(300);
    MoveLeft(255);
    delay(80);
    if(i==4){
      MoveRight(255);
      delay(200);
    }
  }
}

//右轉90度，包裝好的
//與左轉相同，MoveLeft全部改成MoveRight
void TurnRight(){
  int x=0;
  while(Right>10){
    MoveBack(200);
    delay(80);
    Stop();
    DistanceCalc();
    if(x>10) break;
  }
  MoveForward(255);
  delay(450);
  MoveRight(255);
  delay(400);
  MoveForward(255);
  delay(300);
  MoveRight(255);
  delay(350);
  MoveForward(255);
  delay(150);
  MoveForward(255);
  delay(600);
  for(int i=1;i<1;++i){
    DistanceCalc();
    if(Left<=8 && Right <=8){
      break;
    }
    MoveBack(255);
    delay(80);
    MoveRight(255);
    delay(80);
    MoveForward(255);
    delay(300);
    MoveRight(255);
    delay(80);
    if(i==4){
      MoveLeft(255);
      delay(200);
    }
  }
}

//迴轉，包裝好的
void TurnAround(){
  stopcount=0;  //計算卡住多久了
  aroundcount=0;  //暫存目前迴轉的狀態
  //剛開始要迴轉時
  while(aroundcount==0){
    DistanceCalc();
    
    //如果卡住了，前後扭動
    if(stopcount>=3){
      stopcount=0;
      MoveForward(255);
      delay(50);
      MoveBack(255);
      delay(150);
    }
    
    //持續往右轉
    MoveRight(255);
    delay(200);
    
    //如果上次前sensor距離與這次差不多，有可能是卡住
    if( (PreFront-Front>-1 && PreFront-Front<1) ){
      stopcount++;
    }

    //左邊sensor大於15，代表已經轉半圈了
    if(Left>15){
      aroundcount=1;
    }
  }

  //已經轉半圈之後的狀態
  while(aroundcount==1){
    DistanceCalc();

    //卡住處理
    if(stopcount>=3){
      stopcount=0;
      MoveForward(255);
      delay(50);
      MoveBack(255);
      delay(150);
    }

    //持續右轉
    MoveRight(255);
    delay(100);

    //可能卡住的計算
    if( (PreFront-Front>-1 && PreFront-Front<1) ){
      stopcount++;
    }

    //如果左邊sensor又小於10
    //迴轉結束
    if(Left<10){
      aroundcount=2;
    }
  }
}

//卡住時的校正
void Regulate(){
  DistanceCalc();

  //左邊較近，往右轉
  if(Left<Right){
    MoveRight(255);
    delay(150);
  }
  //右邊較近，往左轉
  else{
    MoveLeft(255);
    delay(100);
  }

  //原先是先左右扭動
  //找出sensor最小值的點轉回去
/*  int MinL=99,MinR=99,MinL_i=2.5,MinR_i=2.5;
  int i;

  MoveLeft(255);
  delay(200);
  
  MoveRight(200);
  
  for(i=0;i<6;++i){
    Stop();
    DistanceCalc();
    Dis_Left[i]=Left;
    Dis_Right[i]=Right;
    if(Left<MinL){
      MinL=Left;
      MinL_i=i;
    }
    if(Right<MinR){
      MinR=Right;
      MinR_i=i;
    }
    MoveRight(200);
    delay(80);
  }

  MoveLeft(200);
  if(MinR_i+MinL_i<=12 && MinR_i+MinL_i>=0){
    if(MinR>10 && MinL_i<6 && MinL_i>0){
      delay( (6 - MinL_i) *60 );
    }
    else if(MinL>10 && MinR_i<6 && MinR_i>0){
      delay( (6 - MinR_i) *60 );
    }
    else{
      delay( (6 - ( MinR_i+MinL_i)/2 ) *60 );
    }
  }
  else{
    Stop();
    Regulate();
  }*/
}

void setup() {
  Serial.begin(9600);
  //右輪
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  //左輪
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  //右超音波
  pinMode (8, OUTPUT);
  pinMode (9, INPUT);
  //左超音波
  pinMode (52, OUTPUT);
  pinMode (53, INPUT);
  //前超音波
  pinMode (12, OUTPUT);
  pinMode (13, INPUT);
  //後超音波
  pinMode (50, OUTPUT);
  pinMode (51, INPUT);
}


void loop() {
  
  DistanceCalc();
  //mode0為一般前進模式
  if(mode==0){
    //changecount若不為0，為剛轉彎完
    //每次進這個if都會changecount--
    if(changecount){
      //剛轉彎完只會判斷卡住
      if(stopcount>=3){
        Serial.println("Regulate");
        stopcount=0;
        MoveBack(200);
        delay(500);
        Regulate();
      }
      //沒卡住就前進
      //避免連續轉彎兩次造成迴轉
      else{
        Serial.println("Forward");
        MoveForward(255);
        delay(100);
      }
      Serial.println("Noturn!!!!!!");
      Serial.println(changecount);
      --changecount;
    }
    //沒有剛轉彎完
    //一般時候
    else{
      //卡住就校正
      if(stopcount>=3){
        Serial.println("Regulate");
        stopcount=0;
        MoveBack(200);
        delay(250);
        Regulate();
        MoveForward(255);
        delay(200);
      }
      //如果左邊sensor大，左邊有路可以走
      else if(Left>35){
        Serial.println("TurnLeft");
        TurnLeft();
        Stop();
        changecount=1;
        delay(100);
      }
      //左邊沒路就直走
      else if(Front>35){
        Serial.println("Forward");
        MoveForward(255);
        delay(100);
      }
      //左邊、前面都沒路就右轉
      else if(Front<10&&Right>35){
        Serial.println("TurnRight");
        TurnRight();
        Stop();
        changecount=1;
        delay(100);
      }
      //前三面都卡住了就要迴轉了
      else if(Front<10&&Right<10&&Left<10){
        //backcount紀錄好像三面環壁
        //連續紀錄三次後轉為mode 1
        //迴轉模式
        ++backcount;
        if(backcount==3){
          mode=1;
          backcount=0;
          Stop();
          delay(300);
        }
      }
      //沒轉彎，沒岔路，沒死路
      //就一直直走
      else{
        backcount=0;
        Serial.println("Forward");
        MoveForward(255);
        delay(100);
      }
    }
    //紀錄有可能卡住了
    if( (PreFront-Front>-1 && PreFront-Front<1) ){
      stopcount++;
    }
  }
  //若mode不為0，即迴轉模式
  else{
    TurnAround();
    mode=0;
  }
}
