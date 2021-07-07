#include <LiquidCrystal.h> //Dołączenie bilbioteki
LiquidCrystal lcd(10, 9, 8, 7, 6, 5); //Informacja o podłączeniu nowego wyświetlacza
#define trigPin 12
#define echoPin 11
#define trigPin2 13
#define echoPin2 4

void setup() {
  lcd.begin(16, 2); //Deklaracja typu
  lcd.setCursor(0, 0); //Ustawienie kursora
 
  

  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); //Pin, do którego podłączymy trig jako wyjście
  pinMode(echoPin, INPUT); //a echo, jako wejście
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin2,INPUT);
  
}
 
void loop() {
  long czas,czas2, dystans,dystans2;
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //drugi czujnik
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
 
  czas = pulseIn(echoPin, HIGH);
  czas2 = pulseIn(echoPin2, HIGH);
  dystans = czas / 58;
  dystans2 = czas2 /58;
  lcd.print("Dystans 1 :");
  lcd.print(dystans);
  lcd.setCursor(0,1);//Ustawienie kursora
  lcd.print("Dystans 2 :");
  lcd.print(dystans2);

  
  
  
  delay(500);
  lcd.clear();
}
