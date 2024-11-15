#include <Servo.h>

// Define the servo motors for each finger
Servo finger1;
Servo finger2;
Servo finger3;

// Define the EMG sensor pin
int emgSensorPin = A0; // The analog pin where the EMG sensor is connected
int emgSignal; // Variable to store the EMG signal
int threshold = 300; // Define a threshold for muscle activation


void setup() {
  // put your setup code here, to run once:
  // Attach each servo motor to the corresponding digital pins
  finger1.attach(9);  // Servo for finger 1
  finger2.attach(10); // Servo for finger 2
  finger3.attach(11); // Servo for finger 3

  // Start serial communication for debugging
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 // Read the signal from the EMG sensor
  emgSignal = analogRead(emgSensorPin);

  // Debugging: Print EMG signal to serial monitor
  Serial.println(emgSignal);

  // Check if the EMG signal is greater than the threshold
  if (emgSignal > threshold) {
    // Muscle is activated, so close the hand by moving the servos
    finger1.write(180);  // Move finger 1 to the closed position
    finger2.write(180);  // Move finger 2 to the closed position
    finger3.write(180);  // Move finger 3 to the closed position
  } else {
    // Muscle is relaxed, so open the hand by moving the servos back
    finger1.write(0);  // Move finger 1 to the open position
    finger2.write(0);  // Move finger 2 to the open position
    finger3.write(0);  // Move finger 3 to the open position
  }

  // Small delay to smooth out servo movement
  delay(50);

}
