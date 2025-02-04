#include <NewPing.h>       // Нужные библиотеки
#include <AmperkaServo.h> 
#include <Servo.h>

// Переменные для ультразвуковых датчиков
#define PIN_TRIG1 2 
#define PIN_TRIG2 3
#define PIN_TRIG3 4
#define PIN_TRIG4 5
#define PIN_ECHO1 34
#define PIN_ECHO2 28
#define PIN_ECHO3 30
#define PIN_ECHO4 32

#define MAX_DISTANCE 200 // Константа для определения максимального расстояния, которое мы будем считать корректным.

// Создаем объект, методами которого будем затем пользоваться для получения расстояния.
// В качестве параметров передаем номера пинов, к которым подключены выходы ECHO и TRIG датчика

NewPing sonar1(PIN_TRIG1, PIN_ECHO1, MAX_DISTANCE);
NewPing sonar2(PIN_TRIG2, PIN_ECHO2, MAX_DISTANCE);
NewPing sonar3(PIN_TRIG3, PIN_ECHO3, MAX_DISTANCE);
NewPing sonar4(PIN_TRIG4, PIN_ECHO4, MAX_DISTANCE);

// Числовые переменные нужные в программе
int a1 = 0;
int a2 = 0;
int a3 = 0;
int a4 = 0;
int water;


// Библиотека с расширенными функциями для работы с Servo

Servo servoc;
Servo servov;
Servo servol;
Servo servop;
// Создаём объект для работы с сервомоторами
AmperkaServo servo;
 
// Задаём имя пина, к которому подключён сервопривод
constexpr uint8_t SERVO_PIN = 9;


void setup() {  
  pinMode(49, INPUT); //лимонады
  pinMode(43, INPUT);
  pinMode(45, INPUT);
  pinMode(47, INPUT);
  pinMode(51, INPUT);
  pinMode(53, INPUT);

  pinMode(A0, INPUT); // датчик воды

  pinMode(35, INPUT); // 1
  pinMode(37, INPUT); // 2
  pinMode(39, INPUT); // 3
  pinMode(41, INPUT); // 4

  pinMode(26, OUTPUT); // start


  // Пины для подключения кранов
  servoc.attach(11);
  servov.attach(8);
  servop.attach(10);
  servol.attach(12);

  // Выставляем каждому крану начальное закрытое положение
  servoc.write(90); 
  servov.write(90);
  servop.write(90); 
  servol.write(60); 


  Serial.begin(9600);       
  // Подключаем сервомотор
  // servo.attach(SERVO_PIN);
  // Подключаем сервомотор с расширенными параметрами
  // Советуем использовать именно этот вариант для точной настройки мотора  
  // servo.attach(pin, minPulseWidth, maxPulseWidth);
  // - pin: номер пина, к которому подключён сервопривод
  // - minPulseWidth: ширина импульса, 
  // соответствующая максимальной скорости по часовой стрелке CW.
  // Опциональный и по умолчанию стоит 544 мкс.
  // - maxPulseWidth: ширина импульса,
  // соответствующая максимальной скорости против часовой стрелки CW.
  // Опциональный и по умолчанию стоит 2400 мкс.
  // Данные возьмите из технических характеристик мотора
  servo.attach(SERVO_PIN, 544, 2400);
}

// "Газированная Вода" - 1 - 50
// "Мятный сироп" - 2 - 10
// "Апельсиновый сок" - 3 - 40
// "Лимонад 'Мятный'" - 4 - 100
// "Лимонад 'Заводной Апельсин'" - 5 - 80
// "Лимонад 'Тройной'" - 6 - 90

void loop() { // Формирование заказа 
  if (digitalRead(35) == HIGH) {
    delay(50); 
    while (true){
        if (digitalRead(49) == HIGH) { a1 = 50; break; }
        if (digitalRead(51) == HIGH) { a1 = 10; break;}
        if (digitalRead(53) == HIGH) { a1 = 40; break; }
        if (digitalRead(43) == HIGH) { a1 = 100; break; }
        if (digitalRead(45) == HIGH) { a1 = 80; break; }
        if (digitalRead(47) == HIGH) { a1 = 90; break; } }
        }
  if (digitalRead(37) == HIGH) {
    delay(50);
    while (true){
        if (digitalRead(49) == HIGH) { a2 = 50; break; }
        if (digitalRead(51) == HIGH) { a2 = 10; break; }
        if (digitalRead(53) == HIGH) { a2 = 40; break; }
        if (digitalRead(43) == HIGH) { a2 = 100; break; }
        if (digitalRead(45) == HIGH) { a2 = 80; break; }
        if (digitalRead(47) == HIGH) { a2 = 90; break; } }
         }
  if (digitalRead(39) == HIGH) {
    delay(50);
        while (true){
        if (digitalRead(49) == HIGH) { a3 = 50; break; }
        if (digitalRead(51) == HIGH) { a3 = 10; break; }
        if (digitalRead(53) == HIGH) { a3 = 40; break; }
        if (digitalRead(43) == HIGH) { a3 = 100; break; }
        if (digitalRead(45) == HIGH) { a3 = 80; break; }
        if (digitalRead(47) == HIGH) { a3 = 90; break; } }}
  if (digitalRead(41) == HIGH) { 
    delay(50);
    while (true){
        if (digitalRead(49) == HIGH) { a4 = 50; break; }
        if (digitalRead(51) == HIGH) { a4 = 10; break; }
        if (digitalRead(53) == HIGH) { a4 = 40; break; }
        if (digitalRead(43) == HIGH) { a4 = 100; break; }
        if (digitalRead(45) == HIGH) { a4 = 80; break; }
        if (digitalRead(47) == HIGH) { a4 = 90; break; } } }
  delay(50);
  if (digitalRead(26) == 1) {
    Zapusk();
    delay(52000);}
}



void Ukrali(){ //  Функция нужна для дого чтобы аппарат понимал что ему делать если нет стакана
  servov.write(90);
  delay(1000);
  while (true){ // Ждём пока стакан не поставят назад
    delay(100);

    // Получаем значение от датчика расстояния и сохраняем его в переменную
    unsigned int distance1 = sonar1.ping_cm();
    unsigned int distance2 = sonar2.ping_cm();
    unsigned int distance3 = sonar3.ping_cm();
    unsigned int distance4 = sonar4.ping_cm();
    if (distance1 <= 3 and distance2 <= 3 and distance3 <= 3 and distance4 <= 3) {break;};
  }
  delay(1000);
  servov.write(125);
}




void Zapusk() { // Что происходит когда начинается выполнение заказа

  
  int m1 = a1 * 500 / 5  + 200;
  int m2 = a2 * 500 / 5 + 200;
  int m3 = a3 * 500 / 5 + 200;
  int m4 = a4 * 500 / 5 + 200;


  servop.write(150);
  servov.write(125);
  uint32_t now1 = millis();
  while (millis() - now1 < m1){
    // Стартовая задержка, необходимая для корректной работы.
    delay(100);

    // Получаем значение от датчика расстояния и сохраняем его в переменную
    unsigned int distance1 = sonar1.ping_cm();
    unsigned int distance2 = sonar2.ping_cm();
    unsigned int distance3 = sonar3.ping_cm();
    unsigned int distance4 = sonar4.ping_cm();
    if (distance1 > 3) {servov.write(90); delay(100);
    Ukrali();};
    delay(50);
    if (distance2 > 3) {servov.write(90); delay(100);
    Ukrali();};
    delay(50);
    if (distance3 > 3) {servov.write(90); delay(100);
    Ukrali();};
    delay(50);
    if (distance4 > 3) {servov.write(90); delay(100);
    Ukrali();};

  }
  servop.write(90);


  delay(5000);
  servo.writeSpeed(-65); // 2й стакан для налива
  delay(1155);
  servo.writeSpeed(0);
  delay(3000);


  servop.write(150);
  servov.write(125);
  uint32_t now2 = millis();
  while (millis() - now2 < m2){
    // Стартовая задержка, необходимая для корректной работы.
    delay(100);

    // Получаем значение от датчика расстояния и сохраняем его в переменную
    unsigned int distance1 = sonar1.ping_cm();
    unsigned int distance2 = sonar2.ping_cm();
    unsigned int distance3 = sonar3.ping_cm();
    unsigned int distance4 = sonar4.ping_cm();
    if (distance1 > 3) {servov.write(90); delay(100);
    Ukrali();};
    delay(50);
    if (distance2 > 3) {servov.write(90); delay(100);
    Ukrali();};
    delay(50);
    if (distance3 > 3) {servov.write(90); delay(100);
    Ukrali();};
    delay(50);
    if (distance4 > 3) {servov.write(90); delay(100);
    Ukrali();};

  }
  servop.write(90);
  delay(5000);
  servo.writeSpeed(-65); // 3й стакан для налива
  delay(1425);
  servo.writeSpeed(0);
  delay(3000);


  servop.write(150);
  servov.write(125);
  uint32_t now3 = millis();
  while (millis() - now3 < m3){
    // Стартовая задержка, необходимая для корректной работы.
    delay(100);

    // Получаем значение от датчика расстояния и сохраняем его в переменную
    unsigned int distance1 = sonar1.ping_cm();
    unsigned int distance2 = sonar2.ping_cm();
    unsigned int distance3 = sonar3.ping_cm();
    unsigned int distance4 = sonar4.ping_cm();
    if (distance1 > 3) {servov.write(90); delay(100);
    Ukrali();};
    delay(50);
    if (distance2 > 3) {servov.write(90); delay(100);
    Ukrali();};
    delay(50);
    if (distance3 > 3) {servov.write(90); delay(100);
    Ukrali();};
    delay(50);
    if (distance4 > 3) {servov.write(90); delay(100);
    Ukrali();};

  }


  servop.write(90);
  delay(5000);

  servo.writeSpeed(-65); // 4й стакан стакан для налива
  delay(1140);
  servo.writeSpeed(0);
  delay(3000);

  servop.write(150);
  servov.write(125);
  uint32_t now4 = millis();
  while (millis() - now4 < m4){
    // Стартовая задержка, необходимая для корректной работы.
    delay(100);

    // Получаем значение от датчика расстояния и сохраняем его в переменную
    unsigned int distance1 = sonar1.ping_cm();
    unsigned int distance2 = sonar2.ping_cm();
    unsigned int distance4 = sonar4.ping_cm();
    if (distance1 > 3) {servov.write(90); delay(100);
    Ukrali();};
    delay(50);
    if (distance2 > 3) {servov.write(90); delay(100);
    Ukrali();};
    delay(50);
    if (distance4 > 3) {servov.write(90); delay(100);
    Ukrali();};

  }
  servop.write(90);

  delay(5000);
  

  while (true){
    // Стартовая задержка, необходимая для корректной работы.
    delay(100);

    // Получаем значение от датчика расстояния и сохраняем его в переменную
    unsigned int distance3 = sonar3.ping_cm();
    if (distance3 > 3) {break;};

  }
  delay(3000);
  servo.writeSpeed(-65); // 2й стакан для выдачи
  delay(1155);
  servo.writeSpeed(0);
  delay(3000);


  while (true){
    // Стартовая задержка, необходимая для корректной работы.
    delay(100);

    // Получаем значение от датчика расстояния и сохраняем его в переменную
    unsigned int distance4 = sonar4.ping_cm();
    if (distance4 > 3) {break;};

  }

  delay(3000);
  servo.writeSpeed(-65); // 3й стакан для выдачи
  delay(1425);
  servo.writeSpeed(0);
  delay(3000);

  while (true){
    // Стартовая задержка, необходимая для корректной работы.
    delay(100);

    // Получаем значение от датчика расстояния и сохраняем его в переменную
    unsigned int distance2 = sonar2.ping_cm();
    if (distance2 > 3) {break;};

  }

  servo.writeSpeed(-65); // 4й стакан стакан для выдачи
  delay(1140);
  servo.writeSpeed(0);
  delay(3000);

  while (true){
    // Стартовая задержка, необходимая для корректной работы.
    delay(100);

    // Получаем значение от датчика расстояния и сохраняем его в переменную
    unsigned int distance1 = sonar1.ping_cm();
    if (distance1 > 3) {break;};

  }

  servo.writeSpeed(65); // Возращаем поднос в изначальное положение
  delay(6500);
  servo.writeSpeed(0);
  delay(3000);
   
}


