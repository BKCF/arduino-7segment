//Decodes decimal -> 7 segment
//true flag corresponds to LED HIGH
const bool decoder[10][7] = {
// A B C D E F G
  {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0}, //1
  {1,1,0,1,1,0,1}, //2
  {1,1,1,1,0,0,1}, //3
  {0,1,1,0,0,1,1}, //4
  {1,0,1,1,0,1,1}, //5
  {1,0,1,1,1,1,1}, //6
  {1,1,1,0,0,0,0}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,1,0,1,1}  //9
};

//connect LED segments A-G in sequence to arduino pins,
//starting with pin STARTPIN
#define STARTPIN 7

void setup() {
  Serial.begin(9600);
  
  //initialize LED pins
  for(int i = STARTPIN ; i <= STARTPIN+7 ; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  
  while(true){
    for(int i = 0 ; i <= 9 ; i++){ //loop over all digits
      displayDigit(i);
      delay(1000);
    }
  }
}

//decode current digit, set LED states accordingly
int displayDigit(int num){
  if(num < 0 || num >= 10)
    return -1;
  for(int seg = 0; seg < 7 ; seg++){
    if(decoder[num][seg])
      digitalWrite(getPinForSegment(seg), HIGH);
    else
      digitalWrite(getPinForSegment(seg), LOW);
  }
  return 0;
}

int getPinForSegment(int segment){
  return STARTPIN+segment;
}
