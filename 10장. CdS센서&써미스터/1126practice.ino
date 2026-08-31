/*
CdS센서&써미스터 실습과제1
실습과제1
밝기(CdS 전압)와 온도 동시 측정
  CdS 전압과 온도를 1[sec]마다 측정
  최근 4[sec] 동안 평균값과 함께 시리얼 모니터에 출력
*/
const int CdsPin=2;
const int ThermistorPin = 3;
const float R=10000;
const float C1=1.154924e-03, C2=2.30614e-04, C3=9.6e-08;

void setup() {
  Serial.begin(9600);
  while(!Serial);

  Serial.println("hello!I am BetaGo");
}

void loop() {
  int iCdsRead = analogRead(CdsPin);
  static int iIndex=0;
  static float fCdsVolt[4]={0,0,0,0};
  float fAvgCdsVolt=0;

  float fRth, fLnRth, fT;
  static float fTc[4]={0,0,0,0};
  float fAvgTemp=0;


  if(++iIndex==4) {iIndex=0;}
  fCdsVolt[iIndex] = iCdsRead*5.0/1023;
  for(int i=0;i<4;i++) {fAvgCdsVolt+=fCdsVolt[i];}
  
  fRth=R*(1023.0/analogRead(ThermistorPin)-1.0);
  fLnRth=log(fRth);
  fT=(1.0/(C1+C2*fLnRth+C3*fLnRth*fLnRth*fLnRth));
  fTc[iIndex]=fT-273.15;
  for(int i=0;i<4;i++) {fAvgTemp+=fTc[i];}

  Serial.print("Cds: ");
  Serial.print(fCdsVolt[iIndex]);
  
  Serial.print("[V], avg. Cds: ");
  Serial.print(fAvgCdsVolt/4.0);

  Serial.print(", temp.: ");
  Serial.print(fTc[iIndex]);

  Serial.print("[C], avg. temp.: ");
  Serial.println(fAvgTemp/4);

  delay(1000);
}



/*
CdS센서&써미스터 실습과제3
실습과제3
밝기(CdS 전압)와 온도에 따라 LED 깜박임 주기 제어
  CdS 전압과 온도를 1[sec]마다 측정하여 씨리얼 모니터에 출력
  어둡고(CdS 전압 2[V] 미만) 온도 높을 때(26[C] 초과)는 모든 LED를 1[sec] 주기로 on&off
    on: 500[mesc], off: 500[mesc]
  그렇지않으면 모든 LED off
*/
const int CdsPin=2;
const int ThermistorPin = 3;
const float R=10000;
const float C1=1.154924e-03, C2=2.30614e-04, C3=9.6e-08;
const int LEDs[4]={10,11,12,13};

void setup() {
  Serial.begin(9600);
  while(!Serial);

  for(int i=0;i<4;i++){
    pinMode(LEDs[i], OUTPUT);
  }

  Serial.println("hello!I am BetaGo");
}

void loop() {
  int iCdsRead = analogRead(CdsPin);
  static float fCdsVolt=2;

  float fRth, fLnRth, fT, fTc=25;

  static bool LEDOn=false, check=false;
  if(check){
    fCdsVolt = iCdsRead*5.0/1023;
  
    fRth=R*(1023.0/analogRead(ThermistorPin)-1.0);
    fLnRth=log(fRth);
    fT=(1.0/(C1+C2*fLnRth+C3*fLnRth*fLnRth*fLnRth));
    fTc=fT-273.15;
  }
  if(fCdsVolt<2.0||fTc>26.0){
    if(!LEDOn){
      for(int i=0;i<4;i++){
        analogWrite(LEDs[i],255);
      }
    }
    else{
      for(int i=0;i<4;i++){
        analogWrite(LEDs[i],0);
      }
    }
    LEDOn=!LEDOn;
  }
  else{
    for(int i=0;i<4;i++){
        analogWrite(LEDs[i],0);
      }
  }

  if(check){
    Serial.print("Cds: ");
    Serial.print(fCdsVolt);
  
    Serial.print("[V], temp.: ");
    Serial.println(fTc);
  }
  check=!check;

  delay(500);
}

