#### AASAAA
#### 실습과제1
#### 아날로그 입력 실습과제 1
#### 아날로그 전압에 따른 LED on/off 제어
  * A5 핀에 입력되는 전압 크기에 따라 LED on/off
  * 입력 전압 크기에 따라 특정 LED만 on
    * 0.0[V] <= v < 1.5[V] -> LED0만 on
    * 1.5[V] <= v < 3.0[V] -> LED1만 on
    * 3.0[V] <= v < 4.0[V] -> LED2만 on
    * 4.0[V] <= v < 5.0[V] -> LED3만 on
   
![image](https://github.com/user-attachments/assets/5ba7fb7e-953d-4f4f-8463-cf8066becb8d)

#### 실습과제2
#### 아날로그 입력 실습과제 2
#### 아날로그 전압에 따른 LED 깜박임 주기 제어
  * 모든 LED 동시에 무한히 깜박임
  * A5 핀에 입력되는 전압의 크기에 따라 깜박임 주기 변경
  * 입력 전압 크기에 따른 LED 깜박임 주기
    * 0.0[V] <= v < 1.0[V] -> 100[msec] on & 100[mesc] off
    * 1.0[V] <= v < 2.0[V] -> 300[msec] on & 300[mesc] off
    * 2.0[V] <= v < 3.0[V] -> 500[msec] on & 500[mesc] off
    * 3.0[V] <= v < 4.0[V] -> 700[msec] on & 700[mesc] off
    * 4.0[V] <= v < 5.0[V] -> 900[msec] on & 900[mesc] off

![image](https://github.com/user-attachments/assets/711082aa-42e4-41ff-b709-fa70157f335c)


#### 실습과제 3-2
#### 아날로그 입력 실습과제 3-2
#### 아날로그 전압 감시
  * A5 핀에 입력되는 전압의 크기에 따라 다음 동작
  * 전압이 2.5[V] 이상이면 모든 LED off
  * 전압이 2.5[V] 미만으로 3초 이상 유지되면 모든 LED on
  * 전압이 2.5[V] 미만으로 3초 이상 유지되면 모든 LED on -> 다시 전압이 2.5[V] 이상이 되면 모든 LED off
  * 위의 동작 무한 반복

  * 기능 추가 
    * 전압이 1.5[V] 미만으로 2초 이상 유지되면 모든 LED 200[mesc] on & 200[mesc] off로 깜박이기  

![image](https://github.com/user-attachments/assets/bab96fd9-f6c6-4251-8c05-ad7daf7bf2be)

#### 실습과제1
#### 아날로그 출력 실습 과제 1
#### 아날로그 전압에 따른 LED0 밝기 제어
  * A0 핀 입력 전압 -> LED0밝기
  * 0[V] \~ 3[V]    -> 0[%] \~ 100[%]
  * 3[V] \~         -> 100[%]
    
![image](https://github.com/user-attachments/assets/fd174b78-f212-47b3-86cf-b88f5e83508e)

#### 실습과제2
#### 아날로그 출력 실습 과제 2
#### 아날로그 전압에 따른 LED1, LED0 밝기제어
  * A0 핀 입력 전압 -> LED0밝기
  * 0[V] \~ 3[V]    -> 0[%] \~ 100[%]
  * 3[V] \~         -> 100[%]

  * A0 핀 입력 전압 -> LED1밝기
  * 0[V] \~ 2[V]    -> 0[%]
  * 2[V] \~ 5[V]    -> 0[%] \~ 100[%]
    
![image](https://github.com/user-attachments/assets/8317ada8-d18b-465f-bb25-e220df700e86)
