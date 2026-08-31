/*
초음파 센서 모듈 실습과제1
    초음파 센서(Trig/Echo)로 거리를 측정하여 시리얼 모니터에 출력하고, 거리 구간에 따라 LED 제어
      Trig 핀: 디지털 3번, Echo 핀: 디지털 2번
  트리거 펄스를 보낼 때마다 LED0을 짧게(5[msec]) 점멸시켜 측정 시점 표시
  pulseIn()으로 에코 신호 폭을 측정하여 거리(mm) 계산
    거리[mm] = 에코 펄스 폭 x 0.34 / 2 (음속 340[m/s] 기준)
      거리 150[mm] 이상 -> LED2, LED3 모두 off
  거리 110[mm] 이상 150[mm] 미만 -> LED2 on
  거리 80[mm] 이하 -> LED3만 on, 나머지 off
  측정할 때마다 거리를 [mm]와 [cm] 단위로 시리얼 모니터에 출력
  위의 동작 500[msec] 간격으로 무한 반복
*/

const int TrigPin =3;
const int EchoPin = 2;
const int Leds[4] = {10,11,12,13};

void setup() {
    Serial.begin(9600);
  while(!Serial);
  Serial.println("Hello! I am BetaGo");

  for(int i =0; i<4; i++){
    pinMode(Leds[i],OUTPUT);
  }

  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {
    unsigned long uEchoPulseWidth, uDistance;

  digitalWrite(Leds[0],HIGH);
  delay(5);
  digitalWrite(Leds[0],LOW);

  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);

  uEchoPulseWidth = pulseIn(EchoPin,HIGH);
  uDistance = uEchoPulseWidth *(340. / 1000 / 2);



  if(uDistance >=150){
    for(int i =0; i<4;i++){
      if((i==2)||(i==3)) digitalWrite(Leds[i],LOW);
    }
  }
  else if(uDistance >=110){
    for(int i =0; i<4;i++){
      if(i==2) digitalWrite(Leds[i],HIGH);
    }
  }
  else if(uDistance<=80){
    for(int i =0; i<4;i++){
      if(i==3) digitalWrite(Leds[i],HIGH);
      else digitalWrite(Leds[i],LOW);
    }
  }

  Serial.print("Distance: "); Serial.print(uDistance);
  Serial.print("[mm]->");Serial.print(uDistance/10); Serial.println("[cm]"); delay(500);

}
