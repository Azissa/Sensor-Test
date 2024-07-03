#include <Arduino.h>

#define TRIG_PIN 4
#define ECHO_PIN 3
#define LED_PIN 21

void setup() {
  // Mengatur pin
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  // Memulai komunikasi serial untuk debugging
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;
  
  // Memastikan pin TRIG rendah
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  // Mengirim sinyal trigger 10 microsecond
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Membaca durasi sinyal ECHO
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Menghitung jarak dalam cm
  distance = duration * 0.034 / 2;
  
  // Menampilkan jarak pada serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Jika jarak kurang dari atau sama dengan 10 cm, nyalakan LED
  if (distance <= 10) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  
  // Tunggu sebentar sebelum mengukur lagi
  delay(100);
}
