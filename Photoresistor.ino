int phPin =0;
int ledPin =8;

void setup() {
 analogReference(DEFAULT);
 pinMode(ledPin,OUTPUT);

 

}

void loop() {
  int ph = analogRead(phPin);
  if (ph < 200) digitalWrite(ledPin, LOW);
  else digitalWrite(ledPin, HIGH);
}
