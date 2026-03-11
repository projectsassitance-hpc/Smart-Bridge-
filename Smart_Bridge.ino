#include <Servo.h>

Servo tap_servo;

// ===== PIN DEFINITIONS =====
int sensor_pin = 4;      // Soil sensor DO
int tap_servo_pin = 5;  // Servo
int buzzer_pin = 6;     // Buzzer
int led_pin = 7;        // LED

int val;

void setup() {
  pinMode(sensor_pin, INPUT);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(led_pin, OUTPUT);

  tap_servo.attach(tap_servo_pin);

  // Default OFF
  tap_servo.write(0);
  digitalWrite(led_pin, LOW);
  noTone(buzzer_pin);
}

void loop() {
  val = digitalRead(sensor_pin);

  // ===== SOIL DETECTED (ACTIVE LOW) =====
  if (val == LOW) {
    tap_servo.write(90);   // Servo move

    // 🔊 BUZZER ON, 💡 LED OFF
    tone(buzzer_pin, 1500);
    digitalWrite(led_pin, LOW);
    delay(200);

    // 🔊 BUZZER OFF, 💡 LED ON
    noTone(buzzer_pin);
    digitalWrite(led_pin, HIGH);
    delay(200);
  }
  // ===== NO SOIL =====
  else {
    tap_servo.write(0);
    digitalWrite(led_pin, LOW);
    noTone(buzzer_pin);
  }
}
