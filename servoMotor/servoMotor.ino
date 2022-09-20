int servo1 = 9;

void setup() {
  pinMode(servo1,OUTPUT);

}

void loop() {
  for(int i=0; i<180;i=i+5){
    int deger = map (i,0,180,0,255);
    analogWrite(servo1,deger);
    delay(20);
    }
    for(int i=180;i>0;i=i-5){
       int deger = map (i,0,180,0,255);
       analogWrite(servo1,deger);
       delay(20);
      
      }

}
