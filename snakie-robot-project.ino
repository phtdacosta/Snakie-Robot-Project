// Code by Pedro Costa
// 11/2018
//
// Snakie Robot Project
// MIT License
// Conceptual robot design prototype for detection of humans in disaster areas

#include <Servo.h>

#define LED 13
#define PIR 10

// Servo library allows a maximum of eight objects to be instantiated
Servo s1, s2, s3, s4, s5, s6, s7, s8;

// Variable to store the servo positions
int pos;

void setup()
{
    pinMode(LED, OUTPUT);
    Serial.begin(9600);

    // Attaches each servo object to a specific digital pin
    s1.attach(2);
    s2.attach(3);
    s3.attach(4);
    s4.attach(5);
    s5.attach(6);
    s6.attach(7);
    s7.attach(8);
    s8.attach(9);

    // Assures the sensor to start with a low signal
    pinMode(PIR, INPUT);
    digitalWrite(PIR, LOW);
    // Gives some time to stabilize the sensor
    Serial.println("Stabilizing PIR sensor");
    for (int i = 0; i < 10; i++) {
        Serial.print(".");
        delay(1000);
    }
    Serial.println("Setup finished.");
    delay(1);
}

void loop()
{
    move();
    delay(1);
}

void move() {
    // Goes from 0 to 180 degrees in steps of 1 degree a time
    for (pos = 0; pos < 180; pos += 1) {
        // Sets all servo positions with the new value
        s1.write(pos);
        s2.write(pos);
        s3.write(pos);
        s4.write(pos);
        s5.write(pos);
        s6.write(pos);
        s7.write(pos);
        s8.write(pos);
        // Waits 30ms for all the servo motors to reach their position
        delay(30);
        detect();
    }
}

void detect() {
    if (digitalRead(PIR) == HIGH) {
        Serial.println("!");
        // Turns the LED on
        digitalWrite(LED, HIGH);
        // Waits for 5 seconds
        delay(5000);
        // Turns the LED off
        digitalWrite(LED, LOW);
    }
}