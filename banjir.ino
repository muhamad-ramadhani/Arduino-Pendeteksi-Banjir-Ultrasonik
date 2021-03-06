#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

const int lebar=128;
const int tinggi=64;
const int reset=4;
#define trigPin 9
#define echoPin 8



Adafruit_SSD1306 oled(lebar,tinggi,&Wire,reset);

void setup() {

  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, OUTPUT);
  
  oled.begin(SSD1306_SWITCHCAPVCC,0x3C);
  oled.clearDisplay();
}

void loop() {
  
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  Serial.println(distance);
  delay(100);


  if(distance>=16) {
    oled.clearDisplay();
    digitalWrite(6, HIGH);
      oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(1,5);
  oled.println("Kelompok 3");
    oled.setTextSize(2);
    oled.setTextColor(WHITE);
    oled.setCursor(40,15);
    oled.println("AMAN");
    oled.setCursor(25,33);
    oled.println("SANTUY");
    oled.display();

    
  } else {
    digitalWrite(6, LOW);}
  if(distance>=10 && distance <=15) {
    digitalWrite(2, HIGH);
       oled.clearDisplay();
         oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(1,5);
  oled.println("Kelompok 3");
           oled.setTextSize(2);
    oled.setTextColor(WHITE);
    oled.setCursor(20,15);
    oled.println("HAYOLUH");
    oled.setCursor(40,33);
    oled.println("PANIK");
    oled.display();
  } else {
    digitalWrite(2, LOW);
    }
   
  if(distance<=9) {
    oled.clearDisplay();
    digitalWrite(3, HIGH);
      oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(1,5);
  oled.println("Kelompok 3");
    oled.setTextSize(2);
    oled.setTextColor(WHITE);
    oled.setCursor(20,15);
    oled.println("BANJIR!!");
    oled.setCursor(12,33);
    oled.println("LARI CUKK");
    oled.display();
  } else {
    digitalWrite(3, LOW);
  }
 

}
