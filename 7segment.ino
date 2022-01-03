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
      for(int seg = 0; seg < 7 ; seg++){ //decode current digit, set LED states accordingly
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
  return STARTPIN+segment;
}
