// Define pins for motor driver
const int motor1Pin1 = 9;  // IN1 on L298N
const int motor1Pin2 = 8;  // IN2 on L298N
const int motor2Pin1 = 7;  // IN3 on L298N
const int motor2Pin2 = 6;  // IN4 on L298N
const int enablePin1 = 10;  // ENA on L298N (for motor 1 speed control)
const int enablePin2 = 5; // ENB on L298N (for motor 2 speed control)

// Define pins for IR sensors
const int irSensor1 = A0;  // Leftmost sensor
const int irSensor2 = A1;  // Left center sensor
const int irSensor3 = A2;  // Center sensor
const int irSensor4 = A3;  // Right center sensor
const int irSensor5 = A4;  // Rightmost sensor

void setup() {
  // Initialize motor pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  pinMode(enablePin2, OUTPUT);

  // Initialize sensor pins as inputs
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(irSensor3, INPUT);
  pinMode(irSensor4, INPUT);
  pinMode(irSensor5, INPUT);

  // Set motor speed (PWM value 0-255)
  analogWrite(enablePin1, 200);
  analogWrite(enablePin2, 200);
}

void loop() {
  // Read the sensor values
  int s1 = digitalRead(irSensor1);
  int s2 = digitalRead(irSensor2);
  int s3 = digitalRead(irSensor3);
  int s4 = digitalRead(irSensor4);
  int s5 = digitalRead(irSensor5);

  // Logic to follow line based on sensor inputs
  if (s3 == LOW) {
    // Go straight
    moveForward();
  } else if (s2 == LOW || (s1 == LOW && s2 == LOW)) {
    // Slight left or sharp left
    turnLeft();
  } else if (s4 == LOW || (s5 == LOW && s4 == LOW)) {
    // Slight right or sharp right
    turnRight();
  } else {
    // Stop if line is lost
    stopMotors();
  }
}

// Function to move forward
void moveForward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

// Function to turn left
void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

// Function to turn right
void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

// Function to stop motors
void stopMotors() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
