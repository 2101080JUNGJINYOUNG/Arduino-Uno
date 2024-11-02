// "분에 따라 다른 속도로 증가하는 타이머" 
// minute 값이 짝수일 때는 1초마다(delay(1000)) 한 번씩, 홀수일 때는 0.5초마다(delay(500)) 한 번씩 초를 증가시킵니다. 

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

  delay((minute%2==0||minute==0)?1000:500);

  second++;

  if(second==60){
    minute++;
    second=0;
  }


}
