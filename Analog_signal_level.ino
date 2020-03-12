int sensePin =0;

void setup() {
 analogReference(DEFAULT);
Serial.begin(9600);
 

}

void loop() {
   Serial.println(analogRead(sensePin));
  delay(1000);
}
