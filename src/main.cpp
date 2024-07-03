#include <Arduino.h>

#define TRIG_PIN 4
#define ECHO_PIN 3
#define BUZZER_PIN 21

int buzzerState = LOW;    // Menyimpan status buzzer (LOW = mati, HIGH = hidup)
int lastDistance = 0;     // Menyimpan jarak terakhir yang terdeteksi

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

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

  // Logika untuk kontrol buzzer
  if (distance <= 10 && lastDistance > 10) {
    // Jika terdeteksi benda pada jarak <= 10 cm dan sebelumnya lebih dari 10 cm
    buzzerState = !buzzerState;  // Toggle status buzzer
    digitalWrite(BUZZER_PIN, buzzerState);
    Serial.println("Buzzer triggered!");
  }

  lastDistance = distance;  // Update nilai jarak terakhir

  delay(100);  // Tunggu sebentar sebelum mengukur lagi
}
