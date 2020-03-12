//установка pin фоторезистора
int phPin =0; 
//установка pin светодиода

int ledPin1 =8;
int ledPin2 =9;
int ledPin3 =10;
int ledPin4 =11;
int ledPin5 =12;

void setup() {
 analogReference(DEFAULT);
 analogRead(0);
 pinMode(ledPin1,OUTPUT);
 pinMode(ledPin2,OUTPUT);
 pinMode(ledPin3,OUTPUT);
 pinMode(ledPin4,OUTPUT);
 pinMode(ledPin5,OUTPUT);
}

void loop() { 
  
  int ph = analogRead(phPin); //Установка переменной ph
  if (ph < 80){              // Условие начала цикла
 digitalWrite(ledPin1, HIGH);
 delay(2000);
 digitalWrite(ledPin2, HIGH);
 delay(300);
 digitalWrite(ledPin2, LOW);
 delay(2000);
 digitalWrite(ledPin3, HIGH);
 delay(2000);
 digitalWrite(ledPin3, LOW);
 delay(3000);
 digitalWrite(ledPin1, LOW);
 delay(3000);
 digitalWrite(ledPin4, HIGH);
 delay(2000);
 digitalWrite(ledPin5, HIGH);
 delay(2000);
 digitalWrite(ledPin5, LOW);
 delay(300);
 digitalWrite(ledPin1, HIGH);
 delay(300);
 digitalWrite(ledPin4, LOW);
 delay(2000);
 digitalWrite(ledPin3, LOW);
 delay(2000);
 digitalWrite(ledPin1, LOW); 
    
 do {
delay(50); 
ph = analogRead(phPin); 
} while (ph < 100);}
  
  }

