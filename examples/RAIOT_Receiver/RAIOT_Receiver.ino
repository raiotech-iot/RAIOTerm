/*
  RAIOT_Receiver.ino
  Demonstrates how to listen for and parse incoming RAIOT packets.
*/

#include <RAIOTerm.h>

String cmdId;
String value;

void setup() {
  // Initialize the library
  raiot.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // .listen() returns true only when a full, valid packet is received
  if (raiot.listen(cmdId, value)) {
    
    // Example: If we receive "led:1", turn LED on
    if (cmdId == "led") {
      if (value.toInt() == 1) {
        digitalWrite(LED_BUILTIN, HIGH);
      } else {
        digitalWrite(LED_BUILTIN, LOW);
      }
    }
    
    // Optional: Echo back what we received for debugging
    // Note: This might mix with protocol data if connected to another automated system
    // Serial.print("Received Command: ");
    // Serial.println(cmdId);
  }
}