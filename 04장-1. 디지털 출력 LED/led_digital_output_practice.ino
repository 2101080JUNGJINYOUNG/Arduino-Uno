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


/*LED on/off 제어 실습과제3
    LED2 -LED0 순차 on/off 제어
      항상 한개의 LED만 500[msec]동안 on
      on 상태인 LED는 그림처럼 변경됨
        LED3 -> LED2 -> LED1 -> LED0 -> LED3 -> ....
      위의 동작 무한 반복
*/

// const int LEDs[] = {10,11,12,13};

// void setup() {
//   for(int i =0; i<4; i++){
//     pinMode(LEDs[i],OUTPUT);
//   }
// }

// void loop() {
//   for(int i =3; i >=0; i--){
//     digitalWrite(LEDs[i],HIGH);
//     delay(500);
//     digitalWrite(LEDs[i],LOW);
//   }

// }


/*LED on/off 제어 실습과제4
  실습회로 구성
    LED0 -> 디지털 6번
    LED1 -> 디지털 7번
    LED2 -> 디지털 8번
    LED3 -> 디지털 9번

  LED3 - LED0 순차 on/off 제어
    항상 한 개의 LED만 500[mesc] 동안 on
  on 상태인 LED는 그림처럼 변경됨
    LED0 -> LED1 -> LED2 -> LED3
    -> LED2 -> LED1 -> LED0
    -> LED1 -> LED2 -> LED3 ->....
  위의 동작 무한 반복
*/

// const int LEDs[] = {6,7,8,9};
// void setup() {
//   for(int i =0; i<4; i++){
//     pinMode(LEDs[i],OUTPUT);
//   }
// }

// void loop() {
//   static int pin=0;
//   static bool poze=true;

//   digitalWrite(LEDs[pin],HIGH);
//   delay(500);
//   digitalWrite(LEDs[pin],LOW);

//   if(poze){
//     if(++pin==3){
//       poze = false;
//     }
//   }
//   else{
//     if(--pin==0){
//       poze = true;
//     }
//   }
// }
