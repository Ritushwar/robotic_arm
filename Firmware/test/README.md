## Test Programs Overview

This folder contains various test programs for the robotic arm firmware. Below is a summary of each test program from 1 to 12:

### 1. 1_testing_motor
**File:** `1_testing_motor/1_testing_motor.ino`
- Tests basic stepper motor operation using the AccelStepper library.
- Sets up the stepper with max speed and acceleration, enables the driver, and runs the motor at a constant speed.

### 2. 2_position
**File:** `2_position/2_position.ino`
- Moves the stepper motor to a user-specified position (in steps) received via serial input.
- Converts the input to steps and moves the motor accordingly using AccelStepper.

### 3. 3_two_motors_simultaneously
**File:** `3_two_motors_simultaneously/3_two_motors_simultaneously.ino`
- Controls two stepper motors simultaneously using AccelStepper.
- Moves both motors to set positions, then returns them to the origin in a loop.

### 4. 4_two_motors
**File:** `4_two_motors/4_two_motors.ino`
- Moves two stepper motors to specified positions using a helper function.
- Demonstrates coordinated movement and returning both motors to the origin.

### 5. 5_potentiometer_read
**File:** `5_potentiometer_read/5_potentiometer_read.ino`
- Reads analog input from a potentiometer and maps the value to an angle (0–250 degrees).
- Prints the angle to the serial monitor every second.

### 6. 6_potentiometer_feedback
**File:** `6_potentiometer_feedback/6_potentiometer_feedback.ino`
- Uses potentiometer feedback to control a stepper motor's position.
- Continuously moves the motor to reach a target angle, stopping when within a small error margin.

### 7. 7_normal_if_else
**File:** `7_normal_if_else/7_normal_if_else.ino`
- Receives a target angle via serial input and moves the stepper motor to that angle using if-else logic.
- Uses a deadband to stop the motor when close to the target angle.

### 8. 8_if_else_2_motors
**File:** `8_if_else_2_motors/8_if_else_2_motors.ino`
- Controls two stepper motors using potentiometer feedback and if-else logic.
- Both motors are updated to reach a target angle received via serial input.

### 9. 9_i2c_address_scanner
**File:** `9_i2c_address_scanner/10_i2c_address_scanner.ino`
- Scans the I2C bus for connected devices and prints their addresses to the serial monitor.
- Useful for identifying I2C devices and troubleshooting connections.

### 10. 10_magnet_strength
**File:** `10_magnet_strength/11_magnet_strength.ino`
- Checks the status of the magnet detected by the AS5600L sensor.
- Reports if the magnet is detected, too weak, too strong, or not present, and prints status to the serial monitor.

### 11. 11_read_rawAngle
**File:** `11_read_rawAngle/12_read_rawAngle.ino`
- Reads the raw angle value from the AS5600L magnetic encoder at I2C address 0x36.
- Converts the raw value to degrees and prints both values to the serial monitor.
