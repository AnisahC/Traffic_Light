# Traffic Light Simulator

## Description
This project implements a simple traffic light control system using a Raspberry Pi and the Pigpio library. The traffic light is dynamically controlled by an Echo Sensor (HC-SR04), with the LED colors changing based on the measured distance. The system responds to the presence of an object detected by the sensor, mimicking real-world traffic light operation. I have included a video demonstrating the program (Demo.mov).

## What It Does
Echo Sensor: The system constantly measures the distance to an object using the Echo Sensor. The sensor sends out ultrasonic pulses and calculates the distance based on how long it takes for the pulse to reflect back.

Traffic Light Control: The traffic lights (three LEDs: red, yellow, and green) change based on the distance measured by the Echo Sensor:

Green light: When the object is more than 15cm away.
Yellow light: When the object is between 8cm to 15cm away, signaling caution.
Red light: When the object is less than 8cm away, indicating a stop.
Adaptive Response: The lights respond in real-time to changes in the distance, mimicking an adaptive traffic control system.

Continuous Operation: The system runs in a loop, continuously updating the lights every 0.5 seconds as the object moves.

End of Program: The LEDs turn off when the program is terminated, ensuring no lights are left on.

## Relevant Technologies
- Raspberry Pi: Single-board computer featuring GPIO pins. 
- Pigpio Library: A library for controlling the GPIO pins on the Raspberry Pi.
- C Programming Language: Low-level language known for its hardware access.

## Equipment Used
- Raspberry Pi Board (Zero)
- Echo Sensor (HC-SR04)
- LEDs
- Resistors
- Jumper Wires
- Breadboard

## How To Run The Code
1. Clone the repository and navigate into the file
2. Run "make" to compile the code
3. Start the Pigpio daemon by running "sudo pigpiod"
4. Execute "./traffic_light"

## Note
While Ubuntu or any Linux distribution can be used for development and compilation, the actual execution of the code controlling GPIO pins requires a Raspberry Pi setup.
