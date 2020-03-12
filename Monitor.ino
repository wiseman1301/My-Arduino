#include <stDHT.h>

DHT sens(DHT11); // Указать датчик DHT11, DHT21, DHT22

void setup() 
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  
}

void loop() 
{
  int t = sens.readTemperature(2); // чтение датчика на пине 2
  int h = sens.readHumidity(2);    // чтение датчика на пине 2
  delay(2000);
  Serial.print("Hum: ");
  Serial.print(h);
  Serial.print(" %");
  Serial.print("  ");
  Serial.print("Temp: ");
  Serial.print(t);
  Serial.println(" *C ");
  
}
