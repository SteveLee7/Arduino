#define wheelTime 1     //milliscondes
const int motor_A1 = 5; 
const int motor_A2 = 6;
const int motor_B1 = 9;
const int motor_B2 = 10;
const int IR_R = A0;
const int IR_M = A2;
const int IR_L = A4;

const int IR_L_R = 3;
const int IR_R_R = 12;

int IR_L_data;
int IR_M_data;
int IR_R_data;

int IR_R_R_data;
int IR_L_R_data;
int preIR_L_R_data = 0;

void setup() {
  pinMode(motor_A1, OUTPUT);
  pinMode(motor_A2, OUTPUT);
  pinMode(motor_B1, OUTPUT);
  pinMode(motor_B2, OUTPUT);
  pinMode(IR_L, INPUT);
  pinMode(IR_M, INPUT);
  pinMode(IR_R, INPUT);
  pinMode(IR_L_R, INPUT);
  pinMode(IR_R_R, INPUT);
  Serial.begin(9600);
  Serial.print("Start");
}


void loop() { 
  stop();
  delay(1000);
  rightInit();
  IR_L_R_data = digitalRead(IR_L_R);
  while(!IR_L_R_data)  {                   // if ir sensor detact as black, IR_L_R_data is "0" and led on
       IR_L_R_data = digitalRead(IR_L_R);
       Serial.println("leftinit");
       }
    stop();
    delay(1000);
      leftInit();
    IR_R_R_data = digitalRead(IR_R_R);
     while(!IR_R_R_data)  {
    IR_R_R_data = digitalRead(IR_R_R);
    Serial.println("rightInit");
    }
    stop();
    delay(1000);
   
    for(int i=0;i <= 23;) {          //1pole(360degree) -> 4pole(90degree) ->8pole(45degree) * 3rotation = 24
         IR_L_R_data = digitalRead(IR_L_R);
         if(IR_L_R_data==0){
           if(preIR_L_R_data==1) {
            i++;
            preIR_L_R_data = 0;
           }
         }
         else preIR_L_R_data = 1;
         delay(wheelTime);
         forward();
         Serial.println(i);
    }
     preIR_L_R_data = 0;
    stop();
    delay(1000);
    right();                        //270degree roation
    for(int i=0;i <= 7;) {          // 11 -> 315 degree rotation 7
         IR_L_R_data = digitalRead(IR_L_R);
         if(IR_L_R_data==0){
           if(preIR_L_R_data==1) {
            i++;
            preIR_L_R_data = 0;
           }
         }
         else preIR_L_R_data = 1;
         delay(wheelTime);

         Serial.println(i);
    }
  //  left();
  //  delay(400);
    preIR_L_R_data = 0;  
    stop();
    delay(1000);
    forward();
    for(int i=0;i <= 23;) {
         IR_L_R_data = digitalRead(IR_L_R);
         if(IR_L_R_data==0){
           if(preIR_L_R_data==1) {
            i++;
            preIR_L_R_data = 0;
           }
         }
         else preIR_L_R_data = 1;
         delay(wheelTime);

         Serial.println(i);
    }
    stop();
     preIR_L_R_data = 0;
    
    delay(1000);
    right();                        //270degree roation ->  return
    for(int i=0;i <= 7;) {
         IR_L_R_data = digitalRead(IR_L_R);
         if(IR_L_R_data==0){
           if(preIR_L_R_data==1) {
            i++;
            preIR_L_R_data = 0;
           }
         }
         else preIR_L_R_data = 1;
         delay(wheelTime);

         Serial.println(i);
    }
    preIR_L_R_data = 0;  
    stop();
    delay(1000);
    forward();
    for(int i=0;i <= 23;) {
         IR_L_R_data = digitalRead(IR_L_R);
         if(IR_L_R_data==0){
           if(preIR_L_R_data==1) {
            i++;
            preIR_L_R_data = 0;
           }
         }
         else preIR_L_R_data = 1;
         delay(wheelTime);

         Serial.println(i);
    }
    stop();
     preIR_L_R_data = 0;
    
  while(1){}
}
  /*
  //IR 센서 값을 읽어 출력해주는 코드
  IR_L_data = digitalRead(IR_L);
  IR_M_data = digitalRead(IR_M);
  IR_R_data = digitalRead(IR_R);
  IR_L_R_data = digitalRead(IR_L_R);
  IR_R_R_data = digitalRead(IR_R_R);
 

  Serial.print(IR_L_data);
  Serial.print("-");
  Serial.print(IR_M_data);
  Serial.print("-");
  Serial.print(IR_R_data);
  Serial.print("-");
  Serial.print(IR_L_R_data);
  Serial.print("-");
  Serial.println(IR_R_R_data);
 
 
  // [실습] 빈칸 채우기
  // 아래 라인 트레이서 코드가 있어요. (0이 흰색, 1이 검은색)
  // 자동차가 가야할 방향을 "  " 안에 적어주세요 (직진/정지/좌회전/우회전)
  // 예)  Serial.println("직진");
  if (IR_L_data == 0 and IR_M_data == 1 and IR_R_data == 0) {
    Serial.println("forward");
    forward();
  }
   else if (IR_L_data == 1 and IR_M_data == 0 and IR_R_data == 0) {
    Serial.println("Left");
    left();
  }
  else if  (IR_L_data == 0 and IR_M_data == 0 and IR_R_data == 1) {
    Serial.println("Right");
    right();
  }
/*   else if (IR_L_data == 1  and IR_R_data == 1) {
    Serial.println("정지");
    stop();
  } */
/*
  
  else if ((IR_L_data == 0 and IR_M_data == 1 and IR_R_data == 1) || (IR_L_data == 1 and IR_M_data == 0 and IR_R_data == 1)||
           (IR_L_data == 1 and IR_M_data == 1 and IR_R_data == 0) || (IR_L_data == 0 and IR_M_data == 0 and IR_R_data == 0)||
           (IR_L_data == 1 and IR_M_data == 1 and IR_R_data == 1)) { 
     Serial.println("stop");
     stop();
    } 
  } 
} 
*/
void rightInit () {
  //우
  analogWrite(motor_A1, 180);
  digitalWrite(motor_A2, LOW);
  digitalWrite(motor_B1, LOW);
  digitalWrite(motor_B2, LOW);
}
void right () {
  //우
  digitalWrite(motor_A1, HIGH);
  digitalWrite(motor_A2, LOW);
  digitalWrite(motor_B1, LOW);
  digitalWrite(motor_B2, LOW);
}
void leftInit() {
  //좌
  digitalWrite(motor_A1, LOW);
  digitalWrite(motor_A2, LOW);
  analogWrite(motor_B1, 170);
  digitalWrite(motor_B2, LOW);
}
void left() {
  //좌
  digitalWrite(motor_A1, LOW);
  digitalWrite(motor_A2, LOW);
  digitalWrite(motor_B1, HIGH);
  digitalWrite(motor_B2, LOW);
}

void forward() {
  //전진
  digitalWrite(motor_A1, HIGH);
  digitalWrite(motor_A2, LOW);
  digitalWrite(motor_B1, HIGH);
  digitalWrite(motor_B2, LOW);
}

void backward() {
  //후진
  digitalWrite(motor_A1, LOW);
  digitalWrite(motor_A2, HIGH);
  digitalWrite(motor_B1, LOW);
  digitalWrite(motor_B2, HIGH);
}

void stop() {
  digitalWrite(motor_A1, LOW);
  digitalWrite(motor_A2, LOW);
  digitalWrite(motor_B1, LOW);
  digitalWrite(motor_B2, LOW);
}
