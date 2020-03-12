int photoPin =0;
int pirPin =1;
int ledPin =9;


void setup() {
 analogReference(DEFAULT);
 pinMode(ledPin,OUTPUT);
 

}

void loop() {
 int pr = analogRead(pirPin);
 int ph = analogRead(photoPin);
  if (ph < 200 && pr > 158) digitalWrite(ledPin, HIGH);
  else digitalWrite(ledPin, LOW);
   
  
  
}
