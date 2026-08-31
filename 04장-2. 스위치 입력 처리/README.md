#### 
#### 실습과제1
#### 스위치 입력 처리 실습과제1
#### 동시에 on된 스위치(들) 번호의 합을 FND에 표시
  * 모든 스위치 off -> FND에 '0' 표시
  * 예)
    * SW1 on-> FND에 '1'표시
    * SW1, SW3 on-> FND에 '4'표시
    * SW2, SW3 on-> FND에 '5'표시
    * SW1, SW2, SW3 on-> FND에 '6'표시
   
  ![image](https://github.com/user-attachments/assets/2d0f7434-beda-48ab-938b-8dc0f526f62e)

#### 실습과제2
#### 스위치 입력 처리 실습과제2
#### 스위치 on에 다라 한 자리 수 x의 값을  -> FND에 x의 값을 표시
  * x의 초기값은 0-> FND에 '0' 표시
  * 스위치 on에 따라 x의 값 변경 & FND에 표시
    * SW1가 on될 때마다 x를 1씩 감소
      * x가 0이면 더 이상 감소하지 않음 -> 0표시 지속
    * SW2가 on될 때마다 x를 1씩 증가
      * x가 9이면 더 이상 증가하지 않음 -> 9표시 지속
    * SW0이 on될 때마다 x의 값은 0이됨
    * SW3이 on될 때마다 x의 값은 9가됨

#### TIP
  * loop() 함수의 실행 빈도를 낮추기 위해 delay(100\~500) 호출 필요

![image](https://github.com/user-attachments/assets/9c00de3c-b70e-43e5-b267-92dbefbd8489)

