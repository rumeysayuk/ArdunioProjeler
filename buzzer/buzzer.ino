#define fa 349
#define sol 392
#define la 440
#define si 493
#define DOO 532
#define do_ 261
#define buzzerPin 11
int nota[]={do_,fa,sol,la,si,DOO};
void setup() {
  pinMode(buzzerPin,OUTPUT);

}

void loop() {
  for(int i=0; i<6; i++){
    tone(buzzerPin,nota[i]);
    delay(500);
  }

}
