/*
시간관리&인터럽트 실습과제2
실습 과제 2
한 자리 스톱워치
  처음에는 FND에 '0' 표시, 스위치 입력 대기
  SW0 on -> 시작, FND에 '0' 표시,
                  1초마다 FND 숫자 1씩 증가,
                  1->2->3->.......->9->1->.....
  SW1 on -> 일시중지, on 상태인 동안 동작 일시중지
  SW1 off -> 동작 계속

제약사항
  chkSwOn() 함수 사용 금지 -> 인터럽트 이용
    SW0 on -> 핀 2의 입력 전압 변압(Low -> High)
    SW1 on -> 핀 3의 입력 전압 변압(Low -> High)
    SW1 off -> 핀 3의 입력 전압 변압(high -> low)
  1초 단위 시간 경과는 millis() 함수 이용

TIP
  SW0 on -> 핀 2의 입력 전압 변화(Low -> High)
    -> 인터럽트 모드 RISHING
  SW1 on -> 핀 3의 입력 전압 변화(Low -> High)
  SW1 off -> 핀 3의 입력 전압 변화(Low -> High)
    -> 인터럽트 모드: CHANGE
  
  핀 3의 ISR에서 입력 전압 확인
    digitalRead() 이용


*/
const int SWs[] = {2,3,4,5};
const unsigned int fnd[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
const int seg_io[]={6,7,8,9,10,11,12,13};

void setup() {
  for(int i =0;i<=3;i++){pinMode(SWs[i],INPUT);}
  for(int i =0;i<=7;i++){pinMode(seg_io[i],OUTPUT);}
  attachInterrupt(0,Sw0on,RISING);
  attachInterrupt(1,Sw1on,CHANGE);
}

volatile bool Sw0 = false, Sw1=true;
unsigned long IPrevTime = 0;

void Sw0on(){
  Sw0=true;
  IPrevTime=millis();
}
void Sw1on(){
  Sw1=!digitalRead(SWs[1]);
}

void disp_fnd(unsigned int iDispNum){
  for(int i = 7;i>=0;i--){
    if(bitRead(fnd[iDispNum],i))
      digitalWrite(seg_io[i],LOW);
    else
      digitalWrite(seg_io[i],HIGH);
  }
}

void loop() {
  static int sum=0;
  unsigned long ICrntTime = millis();

  if(Sw0&&Sw1){
    if((ICrntTime - IPrevTime) >= 1000){
      IPrevTime = ICrntTime;
      if(++sum>9) sum=1;
    }
  }
  
  disp_fnd(sum);
}

/*
시간관리&인터럽트 실습과제3
실습과제 3
수신 문자와 수신 간격(시간) 출력
  호스트 PC가 문자 전송 -> 수신된 문자 및 수신 간격 출력
  수신 간격 출력 포맷: 초[sec] 밀리초[msec]
*/

void setup() {

  Serial.begin(9600);
  while(!Serial);

  Serial.println("Hello! I am BetaGo.");

}

void loop() {
  static double b,c;
  static unsigned long lPrevTime = 0, co;
  unsigned long lCrntTime = millis();

  if(Serial.available() > 0){
    co = lCrntTime - lPrevTime;
    b = co/1000;
    c = co % 1000;
    char a = Serial.read();
    Serial.print("Rx. char.: ");
    Serial.println(a);
    Serial.print("Elapsed time: ");
    Serial.print(co/1000); 
    Serial.print("[sec] ");
    Serial.print(co % 1000);
    Serial.println("[msec]");
    lPrevTime = lCrntTime;
  }
}


