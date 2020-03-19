#include <DS1302.h>
#include <OLED_I2C.h>

OLED  lcd(SDA, SCL, 2); //подключение к SDA SCL и 2й пин как кнопка RESET для монитора
DS1302 RTC(8,7,13); //подключение RST=D8, DAT=D7, CLK=D13
//объявляем шрифты
extern uint8_t RusFont[];
extern uint8_t BigNumbers[];

char dat;
Time t;

void setup() {
  lcd.begin();
  Serial.begin(9600);
  RTC.halt(false);
  RTC.writeProtect(false);   
}

//устанавливаем наименование каждому дню
String dowToDay(int day){
  String nameday;
  switch (day){
    case 1: {nameday = "Gjytltkmybr"; //понедельник
      break;}
    case 2:{nameday = "Dnjhybr"; //вторник
      break;}
    case 3:{nameday = "Chtlf"; //среда
      break;}
    case 4:{nameday = "Xtndthu"; //четверг
      break;}
    case 5:{nameday = "Gznybwf"; //пятница
      break;}
    case 6:{nameday = "Ce,,jnf"; //суббота
      break;}
    case 7:{nameday = "Djcrhtctymt"; //воскресенье
      break;}
             }
  return nameday;
}

void loop() {
  
      t = RTC.getTime();  //Запрос времени
      
      String h = String(t.hour, DEC); //Библиотека понимает только формат String приходится в него переводить
      String m = String(t.min, DEC);
      String s = String(t.sec, DEC);
      String day = dowToDay(t.dow);
      
 //Рисуем впереди ноль для заполнения пустоты    
      if (t.hour<10) h = "0" + h; 
      if (t.min<10) m = "0" + m;
      if (t.sec<10) s = "0" + s;
      
//чистим экран и устанавливаем цифровой шрифт       
      lcd.clrScr();   
      lcd.setFont(BigNumbers);
      
//Выводим на экран часы минуты секунды     
      lcd.print(h,10,10); 
      lcd.print(m,46,10);
      lcd.print(s,80,10);
      
//меняем шрифт на русский и печатаем день недели
      lcd.setFont(RusFont);
      lcd.print(day,0,50);
      
//рисуются точки (:) между час и минута        
      lcd.drawLine(42,15,42,17); 
      lcd.drawLine(43,15,43,17);
      lcd.drawLine(42,27,42,29);
      lcd.drawLine(43,27,43,29);
      
//рисуются точки (:) между минута и секунда
      lcd.drawLine(76,15,76,17);  
      lcd.drawLine(77,15,77,17);
      lcd.drawLine(76,27,76,29);
      lcd.drawLine(77,27,77,29);
      
//Для отладки выдаем в COM порт информацию      
       Serial.print(t.hour, DEC);
       Serial.print(" : ");
       Serial.print(t.min, DEC);
       Serial.print(" : ");
       Serial.print(t.sec, DEC);
       Serial.print(" День: ");
       Serial.println(day);
     
       lcd.update(); 
       delay(450);  //Оптимальная задержка для корректного отражения времени
}
