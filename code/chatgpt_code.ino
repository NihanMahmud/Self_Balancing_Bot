#include <Wire.h>
#include <MPU6050_tockn.h>

MPU6050 mpu(Wire);

// Motor pins
#define ENA 10
#define IN1 9
#define IN2 8

#define ENB 11
#define IN3 13
#define IN4 12

float Kp =  35;
float Kd =  1;
float Ki = .8;

// Target angle
float targetAngle=-3;

void setup() {

  Serial.begin(115200);

  // Motor pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // MPU6050
  Wire.begin();
  
  mpu.begin();

  Serial.println("Keep robot still...");
  delay(2000);

  mpu.calcGyroOffsets(true);

  Serial.println("Ready!");
}

float integral=0;

void loop() {

  // Update MPU6050
  mpu.update();

  // Serial.println(mpu.getAngleY());
  // delay(50);
  // continue;

  float angle = mpu.getAngleY();
  float error = targetAngle - angle;

  float gyro = mpu.getGyroY();

  integral += error;
  integral = constrain(integral, -100, 100); // prevent windup

  int motorSpeed = (Kp * error) + (Ki * integral) - (Kd * gyro);

  motorSpeed = constrain(motorSpeed, -180, 180);

  if(motorSpeed > 0 && motorSpeed < 80)
    motorSpeed = 80;

  if(motorSpeed < 0 && motorSpeed > -80)
    motorSpeed = -80;

  // Debug
  Serial.print("Angle: ");
  Serial.print(angle);

  Serial.print(" | Motor: ");
  Serial.print(motorSpeed);

  Serial.print("  |  Error : ");
  Serial.print(error);

  Serial.print("  | Gyro : ");
  Serial.println(gyro);

  // Motor control
  balanceMotor(motorSpeed);

}

// ======================

void balanceMotor(int speed) {

  // Forward
  if(speed > 0) {

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
  }

  // Backward
  else {

    speed = abs(speed);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
  }
}