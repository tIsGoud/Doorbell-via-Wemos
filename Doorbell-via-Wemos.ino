/*
 * Doorbell project to determine if the doorbell was pressed.
 * The "signal" to the physical doorbell is intercepted and is
 * send to a Wemos on pin A0. 
 * The Wemos publishes a message to an MQTT instance.
 *  
 * Used the Homie version with fix for ArduinoJSon 5.11.0
 * Wi-Fi and MQTT configuration are set in the Homie config file (data/homie/config.json).
 * 
 * Parameters:
 * - readDelay, sets the time between reading a value (100 = 1/10 of a second)
 * - buttonPressDelay, is used to prevent multiple reads (5000 = 5 seconds, very pragmatic but works fine)
 * 
 * Author: Albert W. Alberts
 * Date:   5-07-2017  
 * 
 */
#include <Homie.h>

int readDelay = 100;
int buttonPressDelay = 5000;

HomieNode doorbellNode("button", "button");

void loopHandler() {
  // Read the input value on pin 0
  int sensorValue = analogRead(A0);

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 3.2V):
  float voltage = sensorValue * (3.2 / 1023.0);
  
  if (voltage > 0.5) {
    Serial.println("Doorbell pressed ...");
    doorbellNode.setProperty("pressed").send("true");
    delay(buttonPressDelay);
  }
  delay(readDelay);
}

void setup() {
  Serial.begin(115200);
  Serial.println();
    
  Homie_setBrand("wemos");
  Homie_setFirmware("Doorbell-MQTT", "1.0.0");
  
  Homie.setLoopFunction(loopHandler);
  
  Homie.setup();
}

void loop() {
  Homie.loop();
}

