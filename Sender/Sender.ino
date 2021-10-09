
#include <LoRa.h>

#define SS 15
#define RST 16
#define DIO0 2
//String data = "Yoooooooo mfs";
int counter = 0;

void setup()
{
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Sender Host");
  LoRa.setPins(SS, RST, DIO0);
  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa Error");
    delay(100);
    while (1);
  }
}
void loop()
{
  Serial.print("Sending Data: ");
  Serial.println(counter);
  LoRa.beginPacket();
  LoRa.print(F("Pkt no:"));
  LoRa.println(counter);
  LoRa.endPacket();

  counter++;
  
  delay(3000);
}
