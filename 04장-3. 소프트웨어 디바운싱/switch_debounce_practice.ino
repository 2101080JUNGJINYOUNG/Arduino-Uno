/*
소프트웨어 디바운싱 실습과제 1(단순 카운터)
스위치 on에 따라 한 자리 수 x의 값을 변경 -> FND에 X의 값 표시
  X의 초기값은 0-> FND에 '0' 표시
  스위치 ON에 따라 X의 값 변경 & FND에 표시
    SW1이 ON될 때마다 X를 1씩 감소, X가 0이면 더 이상 감소하지 않음
    SW2이 ON될 때마다 X를 1씩 증가, X가 9이면 더 이상 증가하지 않음
    SW0이 ON될 때마다 X는 0이됨
    SW3이 ON될 때마다 X는 9이됨
*/

const int SWs[] = {2, 3, 4, 5};
const unsigned int find[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
const int seg_io[] = {6, 7, 8, 9, 10, 11, 12, 13};

void setup() {
    for (int i = 0; i <= 3; i++) {
        pinMode(SWs[i], INPUT);
    }
    for (int i = 0; i <= 7; i++) {
        pinMode(seg_io[i], OUTPUT);
    }
}

bool chkSwOn(int iSwNum)
{
  static bool bPrevSwOn[]= {false,false,false,false};

  bool bSwOn= false;
  
  bool bCrntSwOn = digitalRead(SWs[iSwNum]);

  if(!bPrevSwOn[iSwNum] && bCrntSwOn){
    delay(50);
    bCrntSwOn = digitalRead(SWs[iSwNum]);
    bSwOn = bCrntSwOn;
  }

  bPrevSwOn[iSwNum] = bCrntSwOn;
  return bSwOn;
}

void disp_find(unsigned int iDispNum) {
  for (int i = 7; i >= 0; i--) {
    if (bitRead(find[iDispNum], i))
      digitalWrite(seg_io[i], LOW);
    else
      digitalWrite(seg_io[i], HIGH);
  }
}


void loop() {
  static int sum;
  if(chkSwOn(0)) sum =0;
  else if(chkSwOn(1)){
    if(--sum<0) 
      sum=0;
  }
  else if (chkSwOn(2)){
    if(++sum>9) 
      sum =9;
  }
  else if(chkSwOn(3)) sum=9;

  disp_find(sum);

}





/*
소프트웨어 디바운싱 실습과제 2(단순 계산기)
한자리 수 두 개에 대한 덧셈
  FND 끔
  각 스위치 번호에 수를 부여 -> SW3 ->3, SW2 ->2, SW1 ->1, SW0 ->0
  스위치를 이용하여 첫번째 한 자리 수를 입력 받고, FND에 500[msec] 동안 표시 후 FND 끔
  스위치를 이용하여 두번째 자리 수를 입력 받고, FND에 500[msec]동안 표시 후 FND 끔
  입력된 두 개의 수에 대한 덧셈 결과를 FND에 1[sec] 동안 표시 후 FND 끔
  위의 동작 무한 반복
*/

const int SWs[] = {2, 3, 4, 5};
const unsigned int find[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,0};
const int seg_io[] = {6, 7, 8, 9, 10, 11, 12, 13};

void setup() {
    for (int i = 0; i <= 3; i++) {
        pinMode(SWs[i], INPUT);
    }
    for (int i = 0; i <= 7; i++) {
        pinMode(seg_io[i], OUTPUT);
    }
}

bool chkSwOn(int iSwNum)
{
  static bool bPrevSwOn[]= {false,false,false,false};

  bool bSwOn= false;
  
  bool bCrntSwOn = digitalRead(SWs[iSwNum]);

  if(!bPrevSwOn[iSwNum] && bCrntSwOn){
    delay(50);
    bCrntSwOn = digitalRead(SWs[iSwNum]);
    bSwOn = bCrntSwOn;
  }

  bPrevSwOn[iSwNum] = bCrntSwOn;
  return bSwOn;
}

void disp_find(unsigned int iDispNum) {
  for (int i = 7; i >= 0; i--) {
    if (bitRead(find[iDispNum], i))
      digitalWrite(seg_io[i], LOW);
    else
      digitalWrite(seg_io[i], HIGH);
  }
}


void loop() {
  static int sum,count;
  for(int i =0; i<=3; i++){

    if(chkSwOn(i)){
      sum+=i;
      count++;
      disp_find(i);
      delay(500);
      disp_find(10);
    } 
   
  }


  if(count==2){
    delay(500);
    disp_find(sum);
    delay(1000);
    sum=0;
    count=0;
    disp_find(10);
  }

}
