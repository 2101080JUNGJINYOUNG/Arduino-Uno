#### bbbb
#### 실습과제2
#### 시간관리&인터럽트 실습과제 2
#### 
*한 자리 스톱워치
  * 처음에는 FND에 '0' 표시, 스위치 입력 대기
  * SW0 on -> 시작, FND에 '0' 표시,
                  * 1초마다 FND 숫자 1씩 증가,
                  * 1->2->3->.......->9->1->.....
  * SW1 on -> 일시중지, on 상태인 동안 동작 일시중지
  * SW1 off -> 동작 계속

* 제약사항
  * chkSwOn() 함수 사용 금지 -> 인터럽트 이용
    * SW0 on -> 핀 2의 입력 전압 변압(Low -> High)
    * SW1 on -> 핀 3의 입력 전압 변압(Low -> High)
    * SW1 off -> 핀 3의 입력 전압 변압(high -> low)
  * 1초 단위 시간 경과는 millis() 함수 이용

*TIP
  * SW0 on -> 핀 2의 입력 전압 변화(Low -> High)  -> 인터럽트 모드 RISHING
  * SW1 on -> 핀 3의 입력 전압 변화(Low -> High)
  * SW1 off -> 핀 3의 입력 전압 변화(Low -> High) -> 인터럽트 모드: CHANGE
  
  * 핀 3의 ISR에서 입력 전압 확인
    * digitalRead() 이용
   
![image](https://github.com/user-attachments/assets/cfa0a7a6-7f75-4c32-819c-af8dd2d0dcba)
![image](https://github.com/user-attachments/assets/62f0f77b-389e-4c72-8bd5-30bec5d000eb)

#### 실습과제3
#### 시간관리&인터럽트 실습과제3
#### 수신 문자와 수신 간격(시간) 출력
  * 호스트 PC가 문자 전송 -> 수신된 문자 및 수신 간격 출력
  * 수신 간격 출력 포맷: 초[sec] 밀리초[msec]

![image](https://github.com/user-attachments/assets/5eb85ed9-dede-4674-88b1-307daf277f27)
