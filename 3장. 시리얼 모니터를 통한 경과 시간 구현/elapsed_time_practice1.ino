 // **"시리얼 모니터를 통한 시계 구현"**이나 "분과 초 타이머 출력" 

void setup() {
  Serial.begin(9600);
  while(!Serial);
}

int minute=0;
int second=0;

void loop() {
 
 Serial.print((minute<10?"0":"")+String(minute));
 Serial.print(":");
 Serial.println((second<10?"0":"")+String(second));

  delay(1000);
  second++;

  if(second==60){
    minute++;
    second=0;
  }


}
