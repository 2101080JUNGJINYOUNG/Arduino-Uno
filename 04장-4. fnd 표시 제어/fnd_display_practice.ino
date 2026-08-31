// FND 표시 제어 실습 과제1
// 숫자 '0' - '3' 무한 반복 표시
// '0' -> '1' -> '2' -> '3' -> '0' -> '1' -> '2' -> ......
// 각 숫자 표시 시간: 500[mesc]

void setup() {
   for(int i=6; i<=13; i++)
     pinMode(i,OUTPUT);
 }

 void loop() {
   for(int i =0; i<=3; i++){
     if(i==0){
       for(int i=6; i<=13; i++){
         if(i==12 || i==13) digitalWrite(i,HIGH);
         else digitalWrite(i,LOW);
       }
     }
     if(i==1){
       for(int i=6; i<=13; i++){
         if(i==7 || i==8) digitalWrite(i,LOW);
         else digitalWrite(i,HIGH);
       }
     }

     if(i==2){
       for(int i=6; i<=13; i++){
         if(i==11 || i==8|| i==13) digitalWrite(i,HIGH);
         else digitalWrite(i,LOW);
       }
     }

     if(i==3){
       for(int i=6; i<=13; i++){
         if(i==11 || i==10||i==13) digitalWrite(i,HIGH);
         else digitalWrite(i,LOW);
       }
     }
     delay(500);
   }  
 }


/* FND 표시 제어 실습 과제2
  16진수 표현 위에 'A' ~ 'F' 표시 기능 추가
  
  숫자 '0' - 'F' 무한 반복 표시
  각 숫자 표시

*/
const unsigned int find[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77,0x7C,0x39, 0x5E, 0x79, 0x71};
const int seg_io[] = {6,7,8,9,10,11,12,13};
void setup() {
   for(int i=0; i<=7; i++)
     pinMode(seg_io[i],OUTPUT);
}

void disp_find(unsigned int iDispNum)
{
   for (int i =7;i>=0;i--){
     if(bitRead(find[iDispNum],i))
       digitalWrite(seg_io[i],LOW);
     else
       digitalWrite(seg_io[i],HIGH);
   }
}


void loop() {
   for(int iNum=0; iNum<=15; iNum++){
     disp_find(iNum);
     delay(500);
   }
}
