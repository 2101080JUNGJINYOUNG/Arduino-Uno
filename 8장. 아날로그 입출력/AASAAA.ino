/*
아날로그 입력 실습 과제1
실습 과제 1
아날로그 전압에 따른 LED on/off 제어
  A5 핀에 입력되는 전압 크기에 따라 LED on/off
  입력 전압 크기에 따라 특정 LED만 on
    0.0[V] <= v < 1.5[V] -> LED0만 on
    1.5[V] <= v < 3.0[V] -> LED1만 on
    3.0[V] <= v < 4.0[V] -> LED2만 on
    4.0[V] <= v < 5.0[V] -> LED3만 on

*/

const int pin[] = {10,11,12,13};
void setup() {
  for(int i =0; i<4; i++){
    pinMode(pin[i],OUTPUT);
  }
  Serial.begin(9600);
  while(!Serial);

  Serial.println("Analog Input");
}

void loop() {
  int iA5Read, iLed;
  float fA5Volt;

  iA5Read = analogRead(5);
  fA5Volt = iA5Read * 5.0 / 1023;

  Serial.print(iA5Read);
  Serial.print(" --> ");
  Serial.print(fA5Volt);
  Serial.println("[V]");
  delay(500);

  if((fA5Volt>=0)&&(fA5Volt<1.5)) iLed =0;

  else if((fA5Volt>=1.5)&&(fA5Volt<3.0)) iLed=1;

  else if((fA5Volt>=3.0)&&(fA5Volt<4.0)) iLed=2;

  else if((fA5Volt>=4.0)&&(fA5Volt<=5.0)) iLed=3;

  for(int i =0; i<4; i++){
    digitalWrite(pin[i],LOW);
  }
  
  digitalWrite(pin[iLed],HIGH);
}

/*
아날로그 입력 실습 과제2
실습 과제 2
아날로그 전압에 따른 LED 깜박임 주기 제어
  모든 LED 동시에 무한히 깜박임
  A5 핀에 입력되는 전압의 크기에 따라 깜박임 주기 변경
  입력 전압 크기에 따른 LED 깜박임 주기
    0.0[V] <= v < 1.0[V] -> 100[msec] on & 100[mesc] off
    1.0[V] <= v < 2.0[V] -> 300[msec] on & 300[mesc] off
    2.0[V] <= v < 3.0[V] -> 500[msec] on & 500[mesc] off
    3.0[V] <= v < 4.0[V] -> 700[msec] on & 700[mesc] off
    4.0[V] <= v < 5.0[V] -> 900[msec] on & 900[mesc] off

*/

const int pin[] = {10,11,12,13};
void setup() {
  for(int i =0; i<4; i++){
    pinMode(pin[i],OUTPUT);
  }
  Serial.begin(9600);
  while(!Serial);

  Serial.println("Analog Input");
}

void loop() {
  static int count,t=0;
  int con,iA5Read;
  float fA5Volt;

  iA5Read = analogRead(5);
  fA5Volt = iA5Read * 5.0 / 1023;

  if((fA5Volt>=0)&&(fA5Volt<1.0)) con = 1;
  else if((fA5Volt>=1.0)&&(fA5Volt<2.0)) con=3;
  else if((fA5Volt>=2.0)&&(fA5Volt<3.0)) con=5;
  else if((fA5Volt>=3.0)&&(fA5Volt<4.0)) con=7;
  else con=9;
  
  
  if(t!=con) count=con;
  
  
  if(count>0) {
    for(int i =0; i<4; i++){
      digitalWrite(pin[i],HIGH);
    }
    
    delay(100);
    count--;
    if(count==0) count=-con;
  }
  else if(count<0){
    for(int i =0; i<4; i++){
      digitalWrite(pin[i],LOW);
    }
    
    delay(100);
    count++;
    if(count==0) count=con;
  }
  

  t = con;
}


/*
아날로그 입력 실습 과제 3-2
실습 과제 3-2
아날로그 전압 감시
  A5 핀에 입력되는 전압의 크기에 따라 다음 동작
  전압이 2.5[V] 이상이면 모든 LED off
  전압이 2.5[V] 미만으로 3초 이상 유지되면 모든 LED on
  전압이 2.5[V] 미만으로 3초 이상 유지되면 모든 LED on -> 다시 전압이 2.5[V] 이상이 되면 모든 LED off
  위의 동작 무한 반복

  기능 추가 
    전압이 1.5[V] 미만으로 2초 이상 유지되면 모든 LED 200[mesc] on & 200[mesc] off로 깜박이기  
*/

const int LEDs[4] = {6, 9, 10, 11};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(LEDs[i], OUTPUT);
  }
  Serial.begin(9600);
  while (!Serial);
}

void loop() {
  static unsigned long IPrevTime = 0, BlinkTime = 0;
  static int iCommCnt = 0;
  static bool check3sec = false, blinkState = false;

  unsigned long ICrntTime = millis();
  float iA5Read = analogRead(A5) * 5.0 / 1023.0;

  if (iA5Read >= 2.5) {
    for (int i = 0; i < 4; i++) {
      analogWrite(LEDs[i], 0);
    }
    check3sec = false;
  } 
  else if (iA5Read >= 1.5) {
    if (!check3sec) {
      IPrevTime = ICrntTime;
      check3sec = true;
    } else if (ICrntTime - IPrevTime >= 3000) {
      for (int i = 0; i < 4; i++) {
        analogWrite(LEDs[i], 255);
      }
    }
  } 
  else {
    if (ICrntTime - BlinkTime >= 2000) {
      BlinkTime = ICrntTime;
      blinkState = !blinkState;
      for (int i = 0; i < 4; i++) {
        if (blinkState) {
          analogWrite(LEDs[i], 255);
        } else {
          analogWrite(LEDs[i], 0);
        }
      }
    }
  }

  if (++iCommCnt == 700) {
    iCommCnt = 0;
    Serial.println(iA5Read);
  }
}

/*
아날로그 출력 실습 과제 1
실습 과제 1
아날로그 전압에 따른 LED0 밝기 제어
  A0 핀 입력 전압 -> LED0밝기
  0[V] ~ 3[V]    -> 0[%] ~ 100[%]
  3[V] ~         -> 100[%] 
*/


const int LEDs[4] = {6,9,10,11};
void setup() {
  for(int i =0; i<4; i++)
    pinMode(LEDs[i],OUTPUT);

  Serial.begin(9600);
  while(!Serial);

  Serial.print("LED0 brightness cont : ");
  Serial.print(__DATE__);
  Serial.print(" ");
  Serial.println(__TIME__);

}

void loop() {
  static int iCommCnt =0;
  int iA0Read, iLed0;
  float fA0Volt;


  fA0Volt = analogRead(0)*5.0 / 1023;
  
  
  iLed0 = fA0Volt * (255-0) / (3-0);
  if(iLed0 > 255) iLed0 = 255;
  analogWrite(LEDs[0],iLed0);

  if(++iCommCnt == 5){
    iCommCnt = 0;
    Serial.print(fA0Volt);
    Serial.print("[V], LED0: ");
    Serial.print(iLed0 * 100.0/255);
    Serial.println("[%]");
  }

  delay(100);
}


/*
아날로그 출력 실습 과제 2
실습 과제 1
아날로그 전압에 따른 LED1, LED0 밝기제어
  A0 핀 입력 전압 -> LED0밝기
  0[V] ~ 3[V]    -> 0[%] ~ 100[%]
  3[V] ~         -> 100[%]

  A0 핀 입력 전압 -> LED1밝기
  0[V] ~ 2[V]    -> 0[%]
  2[V] ~ 5[V]    -> 0[%] ~ 100[%]  
*/

const int LEDs[4]={6,9,10,11};
void setup() {
  for(int i=0;i<4;i++)
    pinMode(LEDs[i], OUTPUT);

  Serial.begin(9600);
  while(!Serial);

}

void loop() {
  static int iCommCnt = 0;
  int iA0Read, iA1Read, iLed0, iLed1;

  iA0Read = analogRead(0)*5.0/1023;
  iLed0=iA0Read*(255-0)/(3-0);
  iLed1=iA0Read*(255-0)/(2-0);
  if(iLed0>255) iLed0=255;
  if(iLed1<255) iLed1=0;
  analogWrite(LEDs[0],iLed0);
  analogWrite(LEDs[1],iLed1);

  if(++iCommCnt ==5){
    iCommCnt = 0;
    Serial.print(analogRead(0)*5.0/1023);
    Serial.print("[V], ");
    Serial.print(iLed0*100.0/255*(8.0/5.0));
    Serial.print("[%], ");
    Serial.print(iLed1*50.0/255);
    Serial.println("[%]");
  }

  delay(100);

}
