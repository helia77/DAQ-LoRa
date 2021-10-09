
#include <LoRa.h>
#define SS 15
#define RST 16
#define DIO0 2
void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Receiver Host");
  LoRa.setPins(SS, RST, DIO0);
  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa Error");
    while (1);
  }

 
  // put the radio into receive mode
  LoRa.receive();
  
}
void loop() {
  int packetSize = LoRa.parsePacket();            //Returns the packet size in bytes or 0 if no packet was received.
  if (packetSize) {
    Serial.print("Receiving Data: ");
    while (LoRa.available()) {                    //Returns number of bytes available for reading.
      //int data = LoRa.readString();
      //Serial.println(data);
      for (int i = 0; i < packetSize; i++) {
        Serial.print((char)LoRa.read());
      }
      }
    }
}
