## Underwater ROV Project ( Under Development Stage of Autonomous Underwater Vehicle (AUV) )

### Project Overview

This project involves the development of an underwater Remotely Operated Vehicle (ROV) as a preliminary stage in building a fully autonomous underwater vehicle (AUV). The ROV is controlled via serial communication using Arduino Nano as the transmitter and Arduino Uno as the receiver. The system is currently in the development stage, and the circuit diagram is attached to provide a detailed layout of the components and their connections.

### Circuit Components:

* **Arduino Uno (Receiver):** Receives control signals from the transmitter and controls the motors and ESCs accordingly.
* **Arduino Nano (Transmitter):** Sends control commands through serial communication to the receiver.
* **L298N Motor Driver Module:** Controls the three DC motors for propulsion and direction control.
* **ESC (Electronic Speed Controller) x 2:** Controls the two brushless motors for vertical and horizontal thrust.
* **AA Battery Pack:** Power source for the joystick module.
* **Joystick Module x 2:** Used to control motor speed and direction (one for propulsion, one for thrust).

### Circuit Connections:


![Circuit Diagram](https://github.com/user-attachments/assets/a8e7d133-3548-4d9e-86ee-911e87a30e27)



* **Motor Connections:**

  * The L298N motor driver is connected to three DC motors responsible for propulsion and maneuvering.
  * The power connections from the battery pack are routed through the L298N motor driver to provide power to the motors.

* **ESC Connections:**

  * Two ESCs are connected to the brushless motors. Each ESC receives PWM signals from the Arduino Uno to control motor speed and direction.

* **Transmitter (Arduino Nano) Connections:**

  * The joystick modules are connected to the analog pins of the Nano to read control inputs.
  * The Nano sends serial data to the Uno through a wired connection.

* **Receiver (Arduino Uno) Connections:**

  * The Arduino Uno receives serial data from the Nano and processes it to control the L298N motor driver and ESCs.

### Serial Communication:

* The Arduino Nano acts as the transmitter, reading joystick inputs and sending control commands as serial data to the Arduino Uno.
* The Arduino Uno interprets the commands and adjusts motor speed and direction accordingly.

### Results: 

![IMG-20241217-WA0022](https://github.com/user-attachments/assets/872e9704-af12-4676-b457-cbd0bd58283e)

![IMG-20241217-WA0019](https://github.com/user-attachments/assets/b807adbd-f0a9-46aa-9fe6-577281245039)

![IMG-20241217-WA0023](https://github.com/user-attachments/assets/43039118-1e6b-4d16-95b7-95cb025611f5)

![Remote](https://github.com/user-attachments/assets/d9ac87d5-aa34-462a-82e2-f8d6d9bc1cc0)



### Development Stage and Future Plans:

* The current ROV setup serves as a foundational stage in developing a fully autonomous underwater vehicle (AUV).
* Further development will include implementing autonomous navigation, sensor integration, and control algorithms to transition from remote control to autonomous operation.
