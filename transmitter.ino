void setup() {
  // Start serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  int joystickDC = analogRead(A0);  // Joystick for DC motor control
  int joystickBLDC = analogRead(A1);  // Joystick for BLDC motor control

  // Send joystick values over serial
  Serial.print(joystickDC);
  Serial.print(",");
  Serial.println(joystickBLDC);

  delay(50);  // Send data every 50ms (adjust as needed)
}
