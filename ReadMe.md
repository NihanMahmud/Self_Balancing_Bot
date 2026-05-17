# Self Balancing Robot 

A DIY Arduino-based self-balancing robot using an MPU6050 gyroscope + accelerometer and L298N motor driver.  
This robot continuously measures its tilt angle and adjusts the motors in real time to balance itself upright.

---

# Demo Video 

[Watch the Robot in Action](https://www.youtube.com/shorts/nsKsRMNk8Pc)

---

# Components Used

- 1x Arduino Uno
- 1x MPU6050 Gyroscope + Accelerometer
- 1x L298N Motor Driver
- 2x Yellow DC Gear Motors
- 2x Wheels
- 1x PVC Sheet Chassis / Frame
- Jumper Wires
- 1x Battery Holder
- 2x 3.7V Lithium Batteries
- Nuts / Glue / Double-sided tape
- USB Cable for uploading code

---

# Working Principle 

The MPU6050 continuously measures the tilt angle of the robot using its gyroscope and accelerometer.

The Arduino processes this data and instantly controls the motors:

- If the robot falls forward ? motors move forward
- If the robot falls backward ? motors move backward
- Motors continuously correct the balance angle

This creates a closed-loop balancing system similar to a Segway.

---

# Circuit Connections 

## Motor Driver (L298N) to Arduino

# Motor Driver (L298N) to Arduino Connections

| L298N Pin | Arduino Uno Pin | Purpose |
|---|---|---|
| ENA | D10 | Speed control for Motor A |
| IN1 | D9 | Motor A direction control |
| IN2 | D8 | Motor A direction control |
| ENB | D11 | Speed control for Motor B |
| IN3 | D13 | Motor B direction control |
| IN4 | D12 | Motor B direction control |

---

---

## MPU6050 to Arduino Uno

| MPU6050 Pin | Arduino Uno |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SCL | A5 |
| SDA | A4 |

---

## Power Connections 
- Two 3.7V batteries were used to power the robot
- The L298N motor driver powered the Arduino through:
  - VIN
  - GND

---

# Wiring Overview

```text
MPU6050 ---- Arduino Uno
SCL     -> A5
SDA     -> A4
VCC     -> 3.3V
GND     -> GND

L298N ---- Arduino
ENA     -> 10
IN1     -> 9
IN2     -> 8
ENB     -> 11
IN3     -> 13
IN4     -> 12

Battery -> L298N -> Arduino VIN
```

---

# Step-by-Step Building Process 

## Step 1 — Build the Chassis

- Cut the PVC sheet according to your preferred robot size
- Attach the two yellow gear motors on opposite sides
- Fix the wheels tightly
- Make sure the structure is symmetrical for better balancing

---

## Step 2 — Mount the Electronics

Attach:
- Arduino Uno
- MPU6050
- L298N Motor Driver
- Battery holder

Try to place the MPU6050 close to the center of the robot for better readings.

---

## Step 3 — Complete the Wiring

Connect:
- Motors to the L298N motor driver
- L298N to Arduino
- MPU6050 to Arduino
- Batteries to motor driver

Double-check:
- Ground connections
- Motor polarity
- MPU6050 SDA/SCL connections

---

## Step 4 — Install Required Libraries

Open Arduino IDE and install:

- MPU6050 library
- I2Cdev library

You can install them from:

`Sketch -> Include Library -> Manage Libraries`

---

## Step 5 — Upload the Code

1. Connect Arduino Uno to your PC using USB
2. Open Arduino IDE
3. Select:
   - Board ? Arduino Uno
   - Correct COM Port
4. Upload the balancing robot code

---

## Step 6 — Testing and PID Tuning

After uploading the code:

- Hold the robot upright
- Slowly release it
- Tune PID values if the robot:
  - shakes too much
  - falls instantly
  - oscillates heavily

PID tuning is the most important part of balancing robots.

---

# Challenges Faced 
- PID tuning was difficult
- Motors produced vibration
- Weight distribution affected balancing
- Sensor readings sometimes became noisy
- Small PID changes created huge differences

---

# Lessons Learned 

This project helped me learn:

- Basics of PID control
- Real-time motor correction
- Gyroscope + accelerometer usage
- Embedded systems debugging
- Motor driver control
- Sensor calibration
- Robotics fundamentals

---

# Future Improvements 
- Better PID tuning
- Bluetooth control
- Rechargeable battery module
- Custom PCB
- Encoder motors
- OLED display for debugging
- 3D printed chassis

---

# Folder Structure 

```text
Self-Balancing-Robot/
?
??? code/
??? images/
??? circuit_diagram/
??? README.md
```

---

# Author 

Made with Arduino, debugging, frustration, and patience ??
