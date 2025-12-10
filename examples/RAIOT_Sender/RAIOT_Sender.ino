/*
  RAIOT_Sender.ino
  Demonstrates how to send data using the RAIOTerm library.
*/

#include <RAIOTerm.h>

void setup() {
  // Initialize the library. 
  // By default, this uses the main USB Serial at 115200 baud.
  raiot.begin(115200);
}

void loop() {
  // Send a simulated temperature value
  // Protocol output: [FEND]temp:24.50[FEND]
  float temperature = 24.5;
  raiot.send("temp", temperature);

  // Send a simulated status message
  // Protocol output: [FEND]status:OK[FEND]
  raiot.send("status", "OK");

  delay(1000);
}