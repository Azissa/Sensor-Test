# IoT Project with ESP32-C3, HC-SR04 Ultrasonic Sensor, and Piezo Buzzer

## Project Description

This project uses an ESP32-C3, an HC-SR04 ultrasonic sensor, and a piezo buzzer to detect the distance of an object and produce a sound based on that distance. The buzzer sound will vary depending on the distance detected by the sensor.

I programmed this using VSCode with the PlatformIO extension, [here](https://docs.platformio.org/en/latest/integration/ide/vscode.html) if you want to see the documentation.

## Required Components

- ESP32-C3
- HC-SR04 Ultrasonic Sensor
- Piezo Buzzer 3-24V
- 220 Ohm Resistor (for LED if needed)
- Jumper Wires
- Breadboard
- Computer with PlatformIO installed on Visual Studio Code

## Connection Diagram

1. **HC-SR04 Sensor:**

   - VCC → 5V on ESP32-C3
   - GND → GND on ESP32-C3
   - Trig → GPIO 12 on ESP32-C3
   - Echo → GPIO 14 on ESP32-C3

2. **Piezo Buzzer:**
   - One pin of the piezo buzzer connected to ground.
   - The other pin connected to a GPIO on ESP32-C3 (e.g., GPIO 13).

I programmed this using VSCode with the PlatformIO extension, [here](https://docs.platformio.org/en/latest/integration/ide/vscode.html) if you want to see the documentation.

## Program Code

```cpp
#define TRIG_PIN 12
#define ECHO_PIN 14
#define BUZZER_PIN 13

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  long duration;
  int distance;

  // Send trigger signal
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Receive echo signal and calculate distance
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  // Display distance on serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control buzzer sound based on distance
  if (distance > 100) {
    tone(BUZZER_PIN, 400);
    delay(500);
    noTone(BUZZER_PIN);
    delay(500);
  } else if (distance > 80) {
    tone(BUZZER_PIN, 400);
    delay(300);
    noTone(BUZZER_PIN);
    delay(300);
  } else if (distance > 60) {
    tone(BUZZER_PIN, 400);
    delay(200);
    noTone(BUZZER_PIN);
    delay(200);
  } else if (distance > 40) {
    tone(BUZZER_PIN, 400);
    delay(100);
    noTone(BUZZER_PIN);
    delay(100);
  } else if (distance > 20) {
    tone(BUZZER_PIN, 400);
    delay(50);
    noTone(BUZZER_PIN);
    delay(50);
  } else {
    tone(BUZZER_PIN, 400);
  }
}
```
