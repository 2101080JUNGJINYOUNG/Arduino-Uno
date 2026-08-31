#### 1104
#### 실습과제1
#### 소프트웨어 디바운싱 실습과제 1(단순 카운터)
#### 스위치 on에 따라 한 자리 수 x의 값을 변경 -> FND에 X의 값 표시
  * X의 초기값은 0-> FND에 '0' 표시
  * 스위치 ON에 따라 X의 값 변경 & FND에 표시
    * SW1이 ON될 때마다 X를 1씩 감소, X가 0이면 더 이상 감소하지 않음
    * SW2이 ON될 때마다 X를 1씩 증가, X가 9이면 더 이상 증가하지 않음
    * SW0이 ON될 때마다 X는 0이됨
    * SW3이 ON될 때마다 X는 9이됨

![image](https://github.com/user-attachments/assets/80905b5b-835a-43ab-ae85-c75406b526ae)

#### 실습과제2
#### 소프트웨어 디바운싱 실습과제 2(단순 계산기)
#### 한자리 수 두 개에 대한 덧셈
  * FND 끔
  * 각 스위치 번호에 수를 부여 -> SW3 ->3, SW2 ->2, SW1 ->1, SW0 ->0
  * 스위치를 이용하여 첫번째 한 자리 수를 입력 받고, FND에 500[msec] 동안 표시 후 FND 끔
  * 스위치를 이용하여 두번째 자리 수를 입력 받고, FND에 500[msec]동안 표시 후 FND 끔
  * 입력된 두 개의 수에 대한 덧셈 결과를 FND에 1[sec] 동안 표시 후 FND 끔
  * 위의 동작 무한 반복
  * chkSwOn() 함수 이용
  
![image](https://github.com/user-attachments/assets/3aa6a1e8-2e76-49d9-bdec-8866465cf3a6)
