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
