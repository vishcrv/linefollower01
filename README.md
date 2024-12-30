## linefollower01
This project is a simple line-following robot built using Arduino. The bot was designed for a contest but faced challenges because the sensors used were only responsive to dark surfaces, limiting its performance on lighter or reflective tracks. Despite the hiccup, the code and design showcase the foundational logic and approach to creating a line-follower using basic components.

### How It Works
1. Moving Forward: When the center sensor detects the line (LOW), the robot moves straight.
2. Turning Left: If the left or left-center sensor detects the line, the robot turns left.
3. Turning Right: If the right or right-center sensor detects the line, the robot turns right.
4. Stopping: If no sensors detect the line, the robot stops.

### Code Breakdown
Motor Control: Functions like `moveForward()`, `turnLeft()`, `turnRight()`, and `stopMotors()` define how the motors behave based on sensor input.
Sensor Readings: The `loop()` function continuously reads sensor data and adjusts the robot’s movement accordingly.

### Customization
Adjust Speed: Modify the `analogWrite(enablePin1, 200)` and `analogWrite(enablePin2, 200)` lines in setup(). Use values between 0-255 to control speed.
Sensor Calibration: Adjust sensor positions and sensitivity for different surface contrasts.

### limitation
1. Track Calibration Not Implemented: The code doesn't include calibration logic to help the robot adapt to variations within the track. This can cause performance issues if the track is not uniform or if the line width changes.
2. Surface Limitations: The bot may struggle on light or reflective surfaces due to sensor limitations. It's optimized for dark lines on light surfaces.
