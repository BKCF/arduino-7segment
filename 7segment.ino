const bool decoder[10][7] = {
  {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0}, //1
  {1,1,0,1,1,0,1}, //2
  {1,1,1,1,0,0,1}, //3
  {0,1,1,0,0,1,1}, //4
  {1,0,1,1,0,1,1}, //5
  {1,0,1,1,1,1,1}, //6
  {1,1,1,0,0,0,0}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,1,0,1,1} //9
};

void setup() {
  Serial.begin(9600);
  for(int i = 6 ; i <= 13 ; i++)
    pinMode(i, OUTPUT);
  pinMode(3, INPUT);
}

void loop() {
//  for(int i = 6 ; i <= 13 ; i++)
//    digitalWrite(i, HIGH);
//  delay(1000);
//  for(int i = 6 ; i <= 13 ; i++)
//    digitalWrite(i, LOW);
//  delay(1000);
/*
  int i = 8;
  for(int seg = 0; seg < 8 ; seg++){
      if(decoder[i][seg]){
        digitalWrite(getPinForSegment(seg), HIGH);
      }else{
        digitalWrite(getPinForSegment(seg), LOW);
      }
    }
    delay(1000);*/
  int i = 0;
  bool pressed = false;
  
  while(true){
    /*
    if(digitalRead(3) == HIGH && !pressed){
      i++;
      i %= 10;
      pressed = true;
      Serial.println("PRESSED");
    }
    else if(digitalRead(3) == LOW){
      pressed = false;
      Serial.println("UNPRESSED");
    }*/
    
    for(int i = 0 ; i <= 9 ; i++){
      for(int seg = 0; seg < 7 ; seg++){
        if(decoder[i][seg]){
          digitalWrite(getPinForSegment(seg), HIGH);
        }else{
          digitalWrite(getPinForSegment(seg), LOW);
        }
      }
      delay(1000);
    }
    
  }
    
  

}

int getPinForSegment(int segment){
  return 7+segment;
}
