const int TrigPin =3;
const int EchoPin = 2;
const int Leds[4] = {10,11,12,13};

void setup() {
    Serial.begin(9600);
  while(!Serial);
  Serial.println("Hello! I am BetaGo");

  for(int i =0; i<4; i++){
    pinMode(Leds[i],OUTPUT);
  }

  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {
    unsigned long uEchoPulseWidth, uDistance;

  digitalWrite(Leds[0],HIGH);
  delay(5);
  digitalWrite(Leds[0],LOW);

  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);

  uEchoPulseWidth = pulseIn(EchoPin,HIGH);
  uDistance = uEchoPulseWidth *(340. / 1000 / 2);



  if(uDistance >=150){
    for(int i =0; i<4;i++){
      if((i==2)||(i==3)) digitalWrite(Leds[i],LOW);
    }
  }
  else if(uDistance >=110){
    for(int i =0; i<4;i++){
      if(i==2) digitalWrite(Leds[i],HIGH);
    }
  }
  else if(uDistance<=80){
    for(int i =0; i<4;i++){
      if(i==3) digitalWrite(Leds[i],HIGH);
      else digitalWrite(Leds[i],LOW);
    }
  }

  Serial.print("Distance: "); Serial.print(uDistance);
  Serial.print("[mm]->");Serial.print(uDistance/10); Serial.println("[cm]"); delay(500);

}
