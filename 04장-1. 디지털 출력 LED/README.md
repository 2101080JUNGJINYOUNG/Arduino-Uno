#### 1015
#### 실습과제1
#### LED3 - LED0 동시에 on/off 제어
  * 모두 500[500msec] 동안 on
  * 모두 500[500msec] 동안 off
  * 무한 반복

![image](https://github.com/user-attachments/assets/5a68ec05-35f4-44d5-baea-1ac9d434f84f)

#### 실습과제2
#### LED3 - LED0 동시에 on/off 제어
  * 모두 500[500msec] 동안 on
  * 모두 500[500msec] 동안 off
  * 위의 동작 3회 반복 후 종료 -> 모든 LED off 상태 유지

![image](https://github.com/user-attachments/assets/60614449-4b7d-42d6-a2fa-a543107896f2)

#### 실습과제3
#### LED3 - LED0 순차 on/off 제어
  * 항상 한 개의 LED만 500[msec] 동안 on
  * on 상태인 LED는 그림처럼 변경됨 -- LED3 -> LED2 -> LED1 -> LED0 -> LED3-> .......
  * 위의 동작 무한 반복
#### TIP
  * 배열 이용
  * const int LEDs[4] = { 13,12,11,10};

![image](https://github.com/user-attachments/assets/24117ee7-606c-44c8-a5de-aff2fb911eab)

#### 실습과제4
#### 실습 회로 구성
  * LED0 -> 디지털 6번
  * LED1 -> 디지털 7번
  * LED2 -> 디지털 8번
  * LED3 -> 디지털 9번
#### LED3 - LED0 순차 on/off 제어
  * 항상 한 개의 LED만 500[msec] 동안 on
  * on 상태인 LED는 그림처럼 변경됨 -- LED0 -> LED1 -> LED2 -> LED3 -> LED2-> LED1-> LED0-> LED1->....
  * 위의 동작 무한 반복

![image](https://github.com/user-attachments/assets/b5f974f0-6c19-42ee-b52d-5e2489ea9298)
