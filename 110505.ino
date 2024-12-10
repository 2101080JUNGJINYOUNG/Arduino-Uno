/*
직렬 통신 실습과제 1
호스트 PC 명령에 따라 LED 상태 제어
  "L b 2 3" : LED2를 3회 깜박임
  "L b 1 2" : LED1을 2회 깜박임
  "L t 0 on" : LED0을 on
  "L t 2 off" : LED2를 off
  TIP 아래 코드 참고
  if(Serial.available() >= 7) {
    chRx = Serial.read();
    Serial.read();
    chOpType = Serial.read();
    iLed = Serial.parseInt();
  }
*/


const int LEDs[4] = {10,11,12,13};

void setup() {
  for(int i =0; i<4; i++){
    pinMode(LEDs[i],OUTPUT);
  }

  Serial.begin(9600);
  while(!Serial);

  Serial.println("Hello! I am BetaGo.");
  Serial.println("I will control LEDs");
}

void loop() {
  char chRx, chOpType;
  int iLed,iTimes;
  String strOnOff;

  if(Serial.available() >= 7){
    chRx = Serial.read();

    if(chRx == 'L'){ 
      Serial.read();
      chOpType = Serial.read();
      
      if(chOpType == 'b'){
        iLed = Serial.parseInt();
        if(iLed<=3){
          iTimes = Serial.parseInt();
          for(int i =0; i<iTimes;i++){
            digitalWrite(LEDs[iLed],HIGH);
            delay(200);
            digitalWrite(LEDs[iLed],LOW);
            delay(200);          
          }
        }
      }

      else if(chOpType == 't'){
        iLed = Serial.parseInt();
        if(iLed<=3){
          strOnOff = Serial.readString();
          strOnOff.trim();
          if(strOnOff == "on")
            digitalWrite(LEDs[iLed],HIGH);
          else if(strOnOff == "off")
            digitalWrite(LEDs[iLed],LOW);
        }
      }
    }
  }

}


/*
직렬 통신 실습과제 2
최대값과 최소값 찾기
  호스트 PC
    4개의 정수를 표현하는 문자열 송신
  아두이노 보드
    수신된 문자열에서 4개의 정수들 추출
    수신된 정수들 송신
    수신된 정수들 중 최대값과 최소값 송신
*/

void setup() {

  Serial.begin(9600);
  while(!Serial);

  Serial.println("Hello! I am BetaGo.");
}

void loop() {
  int INUM,MAX,MIN;

  if(Serial.available() > 0){
    for(int i =0; i<=3; i++){
      INUM=Serial.parseInt();
      if(i==0){
        MAX = INUM;
        MIN = INUM;
        Serial.print("Received numbers: ");
        Serial.print(String(INUM)+" ");
      }
      else{
        if(MAX<INUM) MAX = INUM;
        if(MIN>INUM) MIN = INUM;
        Serial.print(String(INUM)+" ");
      }
    }
    Serial.println("");
    Serial.println("Max: "+ String(MAX));
    Serial.println("Min: "+ String(MIN));

  }

}


/*
직렬 통신 실습과제 3
최대 10개 정수 수신 처리
  호스트 PC는 정수에 해당하는 문자열을 한 번에 한 개씩 전송
  우노 보드는 호스트 PC로부터 정수를 수신할 '때 마다' 수신된 모든 정수, 최대값, 최소값, 평균을 송신
  10개의 정수 이후에는 우노 보드가 "Not accepted"만 송신
*/
void setup() {

  Serial.begin(9600);
  while(!Serial);

  Serial.println("Hello! I am BetaGo.");
  Serial.println("Give me an integer");

}

void loop() {
  static int INUM[10],MAX,MIN, cnt=0,sum=0;
  static double AVG;


  if(Serial.available() > 0){
    

    if(cnt<10){
      INUM[cnt] = Serial.parseInt();
      sum += INUM[cnt];
      if(cnt==0){
        MAX=INUM[0];
        MIN=INUM[0];
        AVG = sum/1.0;
      }
      else{
        if(MAX < INUM[cnt]) MAX = INUM[cnt];
        if(MIN > INUM[cnt]) MIN = INUM[cnt];
        AVG = sum/(cnt+1.0);
      }

      
      Serial.print("Received number(s): ");
      for(int i =0; i<=cnt; i++){
        if(i==cnt) Serial.println(String(INUM[i])+" ");
        else {Serial.print(String(INUM[i])+" ");}
      }
      
      Serial.println("Max.: "+String(MAX) + ",Min.: " + String(MIN) +", Avg.:" + String(AVG));
      Serial.println("Give me an integer.");
      cnt++;
    }
    else{
      Serial.parseInt();
      Serial.println("Not accepted.");
    }
    
  }
}
