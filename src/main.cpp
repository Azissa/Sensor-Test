#include <Arduino.h>

#define TRIG_PIN 4
#define ECHO_PIN 3
#define BUZZER_PIN 21

bool buzzerState = LOW;    // Menyimpan status buzzer (LOW = mati, HIGH = hidup)
int lastDistance = 0;     // Menyimpan jarak terakhir yang terdeteksi
  long duration;
  int distance;


void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {

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

// yang dimana saat sensor ultrasonik mendeteksi adanya benda pada jarak 10cm sensor maka piezo buzzer akan berbunyi layak nya suatu trigger dan tidak berhenti berbunyi hingga sensor di trigger lagi pada jarak yang sama, seperti layaknya suatu toggle dimana saat benda melewati sensor maka itu trigger pertama yang menyebabkan buzzer berbunyi kalaupun benda itu sudah menghilang dari jarak yang di tentukan buzzer akan tetap berbunyi, dan setelah benda melewati sensor untuk kedua kalinya itu adalah trigger kedua yang berfungsi untuk mematikan buzzer agar tidak berbunyi.
