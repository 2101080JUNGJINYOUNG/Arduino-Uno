// 실습과제1
// on/off 제어
// 모두 500msec 동안 on
//모두 500mesc 동안 off
// 코딩 제한조건 pinmode() 1회만 사용, digitalWrite() 2회만 사용
// TIP  배열 이용 const int LEDs[4] = {13,12,11,10};

// const int LEDs[4] = {13,12,11,10};
// void setup() {
//   for(int i =0; i<4; i++){
//     pinMode(LEDs[i],OUTPUT);
//   }
// }

// void loop() {
//   for(int i =0; i<4; i++){
//     digitalWrite(LEDs[i],HIGH);
//   }
//   delay(500);
  
//    for(int i =0; i<4; i++){
//     digitalWrite(LEDs[i],LOW);
//   }
//   delay(500);
  

// }

// 위의 코드들을 더 간략하게
// const int LEDs[4]= {13,12,11,10};
// void setup() {
//   for(int pin: LEDs){
//     pinMode(pin,OUTPUT);
//   }
// }

// void setLEDs(int a){
//   for(int b:LEDs){
//     digitalWrite(b,a);
//   }
// }

// void loop() {
//   setLEDs(HIGH);
//   delay(500);
//   setLEDs(LOW);
//   delay(500);
// }


//실습과제2
// LED3 - LED0 on/off 제어
// 모두 500 동안 on
// 모두 500 동안 off
// 위의 동작 3회 반복 후 종료 -> 모든 LED off 상태 유지


// const int LEDs[4] = {13,12,11,10};
// int count =0;
// void setup() {
//   for(int i =0; i<4; i++){
//     pinMode(LEDs[i],OUTPUT);
//   }
  
// }

// void loop() {
//   while(count < 3){
//   for(int i =0; i<4; i++){
//      digitalWrite(LEDs[i],HIGH);
//     }
//   delay(500);

//   for(int i =0; i<4; i++){
//     digitalWrite(LEDs[i],LOW);
//   }
  
//   delay(500);
//   count++;
//   }
// }




// 위의 코드를 간략하게
// const int a[] = {13,12,11,10};
// int count =0;
// void setup() {
//   for(int i =0; i<4; i++){
//     pinMode(a[i],OUTPUT);
//   }
// }

// void setLEDs(int state){
//   for(int b:a){
//     digitalWrite(b,state);
//   }
// }

// void loop() {
//   if(count <3){
//     setLEDs(HIGH);
//     delay(500);
//     setLEDs(LOW);
//     delay(500);
//     count++;
//   }
// }
