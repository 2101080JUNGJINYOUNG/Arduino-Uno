/*
씨리얼 모니터 피아노 실습과제1
    시리얼로 입력받은 숫자에 따라 부저로 계이름 재생
      부저는 디지털 2번 핀에 연결
      시리얼 모니터에 1~8 사이의 정수를 입력하면 해당 계이름 재생
        1 -> 도(C4), 2 -> 레(D4), 3 -> 미(E4), 4 -> 파(F4)
        5 -> 솔(G4), 6 -> 라(A4), 7 -> 시(B4), 8 -> 도(C5)
      1~8 범위를 벗어난 값이 입력되면 소리 끈(noTone)
      한 번 재생된 음은 다음 입력이 들어올 때까지 계속 울림 (별도의 duration 제어 없음)
    */

#include "pitches.h"  // 종소리 내는 함수

#define MelodyLen 8
const int BuzPin = 2;  // 부저 핀

const int Melody[MelodyLen] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};
const int Duration[MelodyLen] = {500, 500, 500, 500, 500, 500, 1000};

// 음악 재생 함수
void play(int a) {
    tone(BuzPin, Melody[a]);
}

void setup() {
  Serial.begin(9600);
  while (!Serial); // 시리얼 모니터 대기
  pinMode(BuzPin, OUTPUT);
}

void loop() {
  static int INUM,MAX,MIN, cnt=0,sum=0;
  static double AVG;


  if(Serial.available() > 0){
    INUM = Serial.parseInt();
    if(INUM>=1 && INUM <= 8){
      play(INUM-1);
    }
    else{
      noTone(2);
    }
  }

}
