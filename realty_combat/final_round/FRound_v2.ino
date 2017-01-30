/* Periodically send or broadcast the custom message
 * until the user stops it.
 */

#include <BRCClient.h>
#include <SPI.h>
#include <RFID.h>

/* If you are using UNO, uncomment the next line. */
// #define UNO
/* If you are using MEGA and want to use HardwareSerial,
 * umcomment the next 2 lines. */
// #define USE_HARDWARE_SERIAL
// #define HW_SERIAL Serial3

#ifdef UNO
 #define UART_RX 3
 #define UART_TX 2
 #define SPI_MOSI 11
 #define SPI_MISO 12
 #define SPI_SCLK 13
#else
 #define UART_RX 10
 #define UART_TX 2
 #define SPI_MOSI 51
 #define SPI_MISO 50
 #define SPI_SCLK 52
#endif

#if !defined(UNO) && defined(USE_HARDWARE_SERIAL)
 BRCClient brcClient(&HW_SERIAL);
#else
 BRCClient brcClient(UART_RX, UART_TX);
#endif

#define SPI_SS   53
#define MFRC522_RSTPD 9

// You have to modify the corresponding parameter
/*#define AP_SSID    "programtheworld"
#define AP_PASSWD  "screamlab"
#define TCP_IP     "192.168.150.11"*/
#define AP_SSID    "Z5P"
#define AP_PASSWD  "0123456789"
#define TCP_IP     "192.168.43.1"
#define TCP_PORT   5000
#define MY_COMM_ID (char)0xCC

#define PARTNER_COMM_ID 0x20

RFID rfid(SPI_SS, MFRC522_RSTPD);

float duration,Front,Right,Left,LFront,RFront;
float PreFront[5],PreRight[5],PreLeft[5],PreLFront[5],PreRFront[5];
int Turn_Record,mode,x,y;
bool treasure[3];
static uint8_t status;
static uint16_t card_type;
static uint8_t sn[MAXRLEN], snBytes;


float DisFront(){
  for(int i=4;i>0;--i){
    PreFront[i]=PreFront[i-1];
  }
  PreFront[0] = Front;
  
  digitalWrite(40, HIGH);
  delayMicroseconds(1000);
  digitalWrite(40, LOW);
  duration = pulseIn (41, HIGH);
  Front = (duration/2)/29;
  Serial.print("Front = ");
  Serial.println(Front);

  return Front;
}

float DisLeft(){
  for(int i=4;i>0;--i){
    PreLeft[i]=PreLeft[i];  
  }
  PreLeft[0] = Left;
  
  digitalWrite(30, HIGH);
  delayMicroseconds(1000);
  digitalWrite(30, LOW);
  duration = pulseIn (31, HIGH);
  Left = (duration/2)/29;
  Serial.print("Left = ");
  Serial.println(Left);

  return Left;
}

float DisRight(){
  for(int i=4;i>0;--i){
    PreRight[i]=PreRight[i-1];
  }
  PreRight[0] = Right;
  
  digitalWrite(48, HIGH);
  delayMicroseconds(1000);
  digitalWrite(48, LOW);
  duration = pulseIn (49, HIGH);
  Right = (duration/2)/29;
  Serial.print("Right = ");
  Serial.println(Right);

  return Right;
}

float DisLFront(){
  for(int i=4;i>0;--i){
    PreLFront[i]=PreLFront[i-1];
  }
  PreLFront[0] = LFront;
  
  digitalWrite(36, HIGH);
  delayMicroseconds(1000);
  digitalWrite(36, LOW);
  duration = pulseIn (37, HIGH);
  LFront = (duration/2)/29;
  Serial.print("LFront = ");
  Serial.println(LFront);

  return LFront;
}

float DisRFront(){
  for(int i=4;i>0;--i){
    PreRFront[i]=PreRFront[i-1];
  }
  PreRFront[0] = RFront;
  
  digitalWrite(44, HIGH);
  delayMicroseconds(1000);
  digitalWrite(44, LOW);
  duration = pulseIn (45, HIGH);
  RFront = (duration/2)/29;
  Serial.print("RFront = ");
  Serial.println(RFront);

  return RFront;
}

void MoveFront(int speed){
  analogWrite(12, 0);
  analogWrite(11, speed);
  analogWrite(6, 0);
  analogWrite(7, speed+40);
}

void MoveBack(int speed){
  analogWrite(12, speed);
  analogWrite(11, 0);
  analogWrite(6, speed+40);
  analogWrite(7, 0);
}

void MoveRight(int speed){
  analogWrite(12, speed);
  analogWrite(11, 0);
  analogWrite(6, 0);
  analogWrite(7, speed+40);
  Turn_Record = 2;
}

void MoveLeft(int speed){
  analogWrite(12, 0);
  analogWrite(11, speed);
  analogWrite(6, speed+40);
  analogWrite(7, 0);
  Turn_Record = 1;
}

void MoveRight_1M(int speed){
  analogWrite(12, 0);
  analogWrite(11, 0);
  analogWrite(6, 0);
  analogWrite(7, speed+40);
  Turn_Record = 2;
}

void MoveLeft_1M(int speed){
  analogWrite(12, 0);
  analogWrite(11, speed);
  analogWrite(6, 0);
  analogWrite(7, 0);
  Turn_Record = 1;
}

void Stop(){
  analogWrite(12, 0);
  analogWrite(11, 0);
  analogWrite(6, 0);
  analogWrite(7, 0);
}

void TurnRight(){
  MoveRight(180);
  delay(485);
  MoveFront(200);
  delay(300);
  Turn_Record = 0;
}

void TurnLeft(){
  MoveLeft(180);
  delay(470);
  MoveFront(200);
  delay(300);
  Turn_Record = 1;
}

void TurnAround(){
  MoveLeft(180);
  delay(400);
  MoveBack(200);
  delay(300);
  MoveLeft(180);
  delay(450);
  MoveFront(200);
  delay(200);
}

void Scan(){
  if ((status = rfid.findTag(&card_type)) == STATUS_OK &&
      card_type == 1024) {
    Serial.print("Tag SN: ");
    if ((status = rfid.readTagSN(sn, &snBytes)) == STATUS_OK) {
      CommMsg msg;
      msg.type = 0x10;
      for (int i = 0; i < snBytes; ++i){
        msg.buffer[i]=sn[i];
        Serial.print(sn[i], HEX);
      }
      brcClient.sendMessage(&msg);
      Serial.println();
      rfid.piccHalt();
      
      brcClient.receiveMessage(&msg);
      x=msg.buffer[4];
      y=msg.buffer[5];
      int CC = msg.buffer[6];
      if( CC == 35 ){
        brcClient.broadcast("DD_IS_HERE");
        CommMsg msg;
        msg.type = MSG_ROUND_COMPLETE;
        brcClient.sendMessage(&msg);
        for(int i=0;i<10;++i){
          MoveFront(180);
          delay(100);
          MoveBack(180);
          delay(100);
        }
        Stop();
        while(1);
      }
      
      Serial.println("Recv:");
      Serial.print(x);
      Serial.print(",");
      Serial.print(y);
      Serial.println("Recv_END");
    }
  }
  else
    Serial.println("No tag.");
}

void setup()
{
  Serial.begin(9600);
  pinMode (30, OUTPUT);
  pinMode (31, INPUT);
  pinMode (36, OUTPUT);
  pinMode (37, INPUT);
  pinMode (40, OUTPUT);
  pinMode (41, INPUT);
  pinMode (44, OUTPUT);
  pinMode (45, INPUT);
  pinMode (48, OUTPUT);
  pinMode (49, INPUT); //echo
  //motor
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);

  brcClient.begin(9600);
  brcClient.beginBRCClient(AP_SSID, AP_PASSWD, TCP_IP, TCP_PORT);

  SPI.begin();
  SPI.beginTransaction(SPISettings(10000000L, MSBFIRST, SPI_MODE3));
  rfid.begin();
  
  delay(2000);
  if (brcClient.registerID(MY_COMM_ID))
    Serial.println("ID register OK");
  else {
    Serial.println("ID register FAIL");
    brcClient.endBRCClient();
  }
  
  CommMsg msg;
  char buf[40];
//  while(!brcClient.receiveMessage(&msg) || msg.type != (char)0x20);
  while(1){
    if(brcClient.receiveMessage(&msg)){
      sprintf(buf,"%s",msg.buffer);
      Serial.println(buf);
      delay(300);
/*      if(msg.type==(char)0x20)
        brcClient.broadcast("HAHA");
        break;*/
      if( (buf[0]=='C' && buf[1]=='C' && buf[2]=='_' && buf[3]=='G' && buf[4]=='O') || (buf[0]=='A' && buf[1]=='L' && buf[2]=='L' && buf[3]=='_' && buf[4]=='G' && buf[5]=='O') )
        break;
    }
  }
  mode=1;
  x=7;
  y=7;
  treasure[0]=false;
  treasure[1]=false;
  treasure[2]=false;
  MoveFront(200);
  delay(100);
}

void loop()
{ 
  Scan();
  if(DisFront<4){
    MoveBack(180);
    delay(100);
  }
    
  if(mode==1){
    if(DisLeft()<6.5 || (DisRight()>11 && DisRight()<20)){
      MoveRight_1M(200);
      delay(75);
      MoveFront(180);
      delay(100);
    }
    else if(DisRight()<6.8 || (DisLeft()>11 && DisLeft()<20)){
      MoveLeft_1M(180);
      delay(80);
      MoveFront(180);
      delay(100);
    }

    if(DisLFront()>2 && DisLFront()<5){
      MoveBack(200);
      delay(100);
      MoveRight(200);
      delay(150);
      MoveFront(200);
      delay(200);
    }
    else if(DisRFront()>2 && DisRFront()<5){
      MoveBack(200);
      delay(100);
      MoveLeft(200);
      delay(120);
      MoveFront(200);
      delay(200);
    }
    
    if(DisFront()>20){
      MoveFront(210);
      delay(30);
    }
    else if(DisLeft()>25 || DisRight()>25){
      MoveFront(180);
      delay(250);

      if(DisFront()>20){
        MoveFront(210);
        delay(30);
      }
      else if(DisFront()<20 && DisRight()>25 && DisLeft()>25){
        float F = DisFront();
        float L = DisLeft();
        float R = DisRight();
        if(R>20 && R<150){
          TurnRight();
        }
        else if(F>20){
          MoveFront(210);
          delay(30);
        }
        else if(L>20 && L<100){
          TurnLeft();
        }
      }
      else if(DisFront()<20 && DisLeft()>25 && DisRight()<20){
        TurnLeft();
        MoveRight(180);
        delay(60);
      }
      else if(DisFront()<20 && DisRight()>25 && DisLeft()<20){
        TurnRight();
        MoveFront(180);
        delay(100);
        MoveLeft(180);
        delay(50);
      }
    }
    else if(DisFront()<12 && DisRight()<15 && DisLeft()<15){
      if(DisFront()<12){
        Stop();
        delay(300);
        
        char buf[20];
        CommMsg msg;
        if(brcClient.receiveMessage(&msg)){
          sprintf(buf,"%s",msg.buffer);
          Serial.println(buf);
          delay(100);
          if(buf[0]=='C' && buf[1]=='C' && buf[2]=='_' && buf[3]=='D' && buf[4]=='I' && buf[5]=='E'){
            brcClient.broadcast("DD_IS_HERE");
            CommMsg msg;
            msg.type = MSG_ROUND_COMPLETE;
            brcClient.sendMessage(&msg);
            for(int i=0;i<10;++i){
              MoveFront(180);
              delay(100);
              MoveBack(180);
              delay(100);
            }
            Stop();
            while(1);
          }
        }
        
        TurnAround();
      }
    }
    else{
      MoveFront(210);
      delay(30);
    }
  }
}
