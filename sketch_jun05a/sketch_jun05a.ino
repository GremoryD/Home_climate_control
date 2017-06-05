#include <DHT.h>
#include <LiquidCrystal.h>  // Лобавляем необходимую библиотеку
#define DHTTYPE DHT11 
#define DHTPIN 8 // номер пина, к которому подсоединен датчик


LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // (RS, E, DB4, DB5, DB6, DB7)
DHT dht(DHTPIN, DHT11); 
int Relay = 9;


void setup(){ 
  lcd.begin(16, 2);                  // Задаем размерность экрана

  lcd.setCursor(0, 0);              // Устанавливаем курсор в начало 1 строки
  lcd.print("Hello, world!");       // Выводим текст
  lcd.setCursor(0, 1);              // Устанавливаем курсор в начало 2 строки
  lcd.print("zelectro.cc");         // Выводим текст
    
  Serial.begin(9600);
  
  pinMode(Relay, OUTPUT);  
  dht.begin();
}

void loop(){
  // Задержка 2 секунды между измерениями

delay(1000);

//Считываем влажность

float h = dht.readHumidity();

// Считываем температуру

float t = dht.readTemperature();

// Проверка удачно прошло ли считывание.

if (isnan(h) || isnan(t)) {

Serial.println("Не удается считать показания");

return;

}

  lcd.setCursor(0, 0);   
  lcd.print("Vlaga " + String(h, 1) + "%");         // Выводим текст
  lcd.setCursor(0, 1);              // Устанавливаем курсор в начало 2 строки
  lcd.print("temp " + String(t, 1) + "*C");         // Выводим текст
  Serial.println("Humidity : "+String(h, 1)+"%\t Temperature : "+String(t, 1)+" *C");
  if(t > 22){             
    digitalWrite(Relay, LOW);   // реле включено 
    delay(2000);       
  }else{
    digitalWrite(Relay, HIGH);  // реле выключено
    delay(2000); 
    
  }
 
}
