#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "bottle-tracker.firebaseio.com"
#define FIREBASE_AUTH "hTj9UCz9Wil16CFnxhUGqa35Cw0tekNc3EgDd1pE"
#define WIFI_SSID "speechbee"
#define WIFI_PASSWORD "speechbee"

const int input_pin = 5;

void setup() {
  Serial.begin(9600);
  pinMode(D4, OUTPUT);
  pinMode(input_pin, INPUT);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.set("sensor", 0);
}

void loop() {
  int sensor = digitalRead(input_pin);
  Firebase.setFloat("sensor", sensor);
  //delay(100);

  if (sensor == 1) {
    digitalWrite(D4, LOW);
  }

  if (sensor == 0) {
    digitalWrite(D4, HIGH);
  }



}
