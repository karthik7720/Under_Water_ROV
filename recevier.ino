#include <WiFi.h>
#include <FirebaseESP32.h>
#include <Ultrasonic.h>

// WiFi credentials
#define WIFI_SSID "OPPO A15s"
#define WIFI_PASSWORD "12345678"

// Firebase project credentials
#define FIREBASE_HOST "ultrasonic-9f469-default-rtdb.asia-southeast1.firebasedatabase.app/" // Replace with your Firebase project URL
#define FIREBASE_AUTH "fBh48K18Poc7K06wuC3tFdOvJ0hpVguzCbE4YYU1" // Replace with your Firebase Database secret

// Ultrasonic sensor pins
#define TRIGGER_PIN 4
#define ECHO_PIN 2

// Firebase path
#define FIREBASE_PATH "/sensorData/distance"

FirebaseData firebaseData;
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Initialize Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true); //reconnect to wifi automatically
}

void loop() {
  // Measure distance
  long distance = ultrasonic.read(); // Read distance in centimeters

  // Print distance to serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Send distance to Firebase
  if (Firebase.setInt(firebaseData, FIREBASE_PATH, distance)) {
    Serial.println("Data sent to Firebase successfully");
  } else {
    Serial.print("Error sending data to Firebase: ");
    Serial.println(firebaseData.errorReason());
  }

  delay(1000); // Delay before next measurement
}