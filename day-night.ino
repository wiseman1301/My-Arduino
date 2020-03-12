int phPin =0;
int day_ledPin =3;
int night_ledPin =4; 

void setup() {
 analogReference(DEFAULT);
 pinMode(day_ledPin,OUTPUT);
 pinMode(night_ledPin,OUTPUT);
 

}

void loop() {
  int ph = analogRead(phPin);
  if (ph < 200) digitalWrite(night_ledPin, HIGH);
  else digitalWrite(night_ledPin, LOW);
  if (ph >= 200) digitalWrite(day_ledPin, HIGH);
  else digitalWrite(day_ledPin, LOW);
 
}
