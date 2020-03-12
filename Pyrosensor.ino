int pyrPin =1;
int ledPin =8;

void setup() {
 analogReference(DEFAULT);
 pinMode(ledPin,OUTPUT);

 

}

void loop() {
  int val = analogRead(pyrPin);
  if (val > 119) digitalWrite(ledPin, HIGH);
  else digitalWrite(ledPin, LOW);
}
