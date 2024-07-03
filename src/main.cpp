#include <Arduino.h>

#define TRIG_PIN 4
#define ECHO_PIN 3
#define BUZZER_PIN 21

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;
  
  // Mengirimkan sinyal trigger
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Menerima sinyal echo dan menghitung jarak
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;
  
  // Menampilkan jarak pada serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Mengontrol bunyi buzzer berdasarkan jarak
  if (distance > 100) {
    tone(BUZZER_PIN, 400);
    delay(500);
    noTone(BUZZER_PIN);
    delay(500);
  } else if (distance > 80 && distance < 100) {
    tone(BUZZER_PIN, 400);
    delay(300);
    noTone(BUZZER_PIN);
    delay(300);
  } else if (distance > 60 && distance < 80) {
    tone(BUZZER_PIN, 400);
    delay(200);
    noTone(BUZZER_PIN);
    delay(200);
  } else if (distance > 40 && distance < 60) {
    tone(BUZZER_PIN, 400);
    delay(100);
    noTone(BUZZER_PIN);
    delay(100);
  } else if (distance > 20 && distance < 40) {
    tone(BUZZER_PIN, 400);
    delay(50);
    noTone(BUZZER_PIN);
    delay(50);
  } else {
    tone(BUZZER_PIN, 400);
  }
}
