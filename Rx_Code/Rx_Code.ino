#include <SPI.h>
#include <LoRa.h>
void setup() 
{
  Serial.begin(9600);
  //Serial.println("1");
  if (!LoRa.begin(433E6)) 
  {
    //Serial.println("10");
    while (1);
  }
  LoRa.setSyncWord(0xF3);
  //Serial.println("5");
}
void loop()
{
  String LoRaData; 

  int packetSize = LoRa.parsePacket();
  if (packetSize)
  {
    //Serial.print("Received packet:   ");
    while (LoRa.available()) 
    {
      LoRaData = LoRa.readString();
      Serial.println(LoRaData);
      //Serial.print((char)LoRa.read());
      //str=str+((char)LoRa.read());    
    }
    //Serial.print(" (with RSSI) ");
    //Serial.println(LoRa.packetRssi());
  }

  //delay(3000);
}
