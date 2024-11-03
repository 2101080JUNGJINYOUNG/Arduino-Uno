/*실습과제1
스위치 입력 처리 실습과제1
동시에 on된 스위치(들) 번호의 합을 FND에 표시
  모든 스위치 off - > FND에 '0' 표시
  예)
    SW1 on-> FND에 '1'표시
    SW1, SW3 on-> FND에 '4'표시
    SW2, SW3 on-> FND에 '5'표시
    SW1, SW2, SW3 on-> FND에 '6'표시
*/
const int SWs[] = {2,3,4,5};
const unsigned int fnd[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77,0x7C,0x39, 0x5E, 0x79, 0x71};
const int seg_io[] = { 6, 7, 8, 9, 10, 11, 12, 13}; 

void setup() {
  for(int i =0; i<=7; i++) pinMode(seg_io[i],OUTPUT);
  for(int i =0; i<=3; i++) pinMode(SWs[i],INPUT);
}

void setFND(int state){
  for(int i =0; i<8; i++){
    if(bitRead(fnd[state],i)) digitalWrite(seg_io[i],LOW);
    else digitalWrite(seg_io[i],HIGH);
  }
}

void loop() {
  int o=0;
  for(int i =0; i<=3; i++){
    if(digitalRead(SWs[i])) o+=i;
  }
  
  setFND(o);
}





/*실습과제2
스위치 on에 다라 한 자리 수 x의 값을 변경
->FND에 x의 값을 표시
  x의 초기값은 0-> FND에 '0' 표시
  스위치 on에 따라 x의 값 변경 & FND에 표시
    SW1가 on될 때마다 x를 1씩 감소
      x가 0이면 더 이상 감소하지 않음 -> 0표시 지속
    SW2가 on될 때마다 x를 1씩 증가
      x가 9이면 더 이상 증가하지 않음 -> 9표시 지속
    SW0이 on될 때마다 x의 값은 0이됨
    SW3이 on될 때마다 x의 값은 9가됨 

  TIP
    loop() 함수의 실행 빈도를 낮추기 위해 delay(100~500) 호출 필요
*/
const int SWs[] = {2,3,4,5};
const unsigned int fnd[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77,0x7C,0x39, 0x5E, 0x79, 0x71};
const int seg_io[] = { 6, 7, 8, 9, 10, 11, 12, 13}; 

void setup() {
  for(int i =0; i<=3; i++) pinMode(SWs[i],INPUT);
  for(int i =0; i<=7; i++) pinMode(seg_io[i],OUTPUT);
}

void setFND(int state){
  for(int i =0; i<=7;i++){
    if(bitRead(fnd[state],i)) digitalWrite(seg_io[i],LOW);
    else digitalWrite(seg_io[i],HIGH);
  }
}

void loop() {
  static int count = 0;
  if(digitalRead(SWs[0])) count=0;
  else if(digitalRead(SWs[1])){
    if(--count < 0) count=0;
  }
  else if(digitalRead(SWs[2])){
    if(++count > 9) count=9;
  } 
  else if(digitalRead(SWs[3])) count=9;

  setFND(count);
  delay(100);

}
