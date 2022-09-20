int led1Pin = 8;
int led2Pin = 9;
int led3Pin = 10;

int siviseviyePin = A0;
int siviseviyesi;

void setup()
{
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(siviseviyePin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  siviseviyesi = analogRead(siviseviyePin);
  Serial.print("Sıvı Seviyesi: ");
  Serial.println(siviseviyesi);

  if(siviseviyesi == 0)
  {
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
  }
  if(siviseviyesi > 0 and siviseviyesi <= 250)
  {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
  }
  if(siviseviyesi > 250 and siviseviyesi <= 350)
  {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, LOW);
  }
  if(siviseviyesi > 350)
  {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);
  }

  delay(100);
}
