#include <SPI.h>
#include <MFRC522.h>
 
int x;
int uid[4];
int kart[3][4]{ // массив для трех меток
  {
    52, 205, 230,31    }  
  ,
  { 
    251,53,224,13   }
  , 
  {
    162, 91,142, 96    } 
};
 
MFRC522 mfrc522(10,9); //(SDA_PIN10, RST_PIN9, MISO_PIN12, MOSI_PIN11,SCK_PIN13,IRQ - not used)   
 
void setup() {
  Serial.begin(9600);        
  while (!Serial);          
  SPI.begin();              
  mfrc522.PCD_Init();      
  pinMode(3,OUTPUT);// PIN3 - подключение реле
                      
}
 
void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }
  Serial.print("UID: ");
  for (byte y = 0; y < (sizeof(kart)/sizeof(int)/4); y++) {
    for (byte i = 0; i < 4; i++) {
      uid[i] = mfrc522.uid.uidByte[i];
      if(uid[i]==kart[y][i]){
        x++;
      }
    } 
    if(x<4){
      x=0;
    }
  }
 
  for (byte i = 0; i < 4; i++) {
    Serial.print(uid[i]);
    Serial.print(" ");
  }
  Serial.println(x);
  Serial.println();
 
  if(x>=4){
    digitalWrite(3,HIGH); 
    tone(4,700,500); //  PIN4 - подключение пьезоизлучателя
    Serial.println(" ON ");
    Serial.println(" pause 5 sek ");
    delay(5000);
    tone(4,300,100);
    digitalWrite(3,LOW);
    Serial.println(" OFF ");
  }
  else{
    tone(4,300,300);
    Serial.println(" OFF ");
    delay(1000);
  }
  x=0;   
}
