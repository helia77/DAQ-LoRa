#include <SPI.h>
#include <LoRa.h>
void setup() 
{
  Serial.begin(9600);
  Serial.println("LoRa Receiver");
  if (!LoRa.begin(433E6)) 
  {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");
}
void loop() 
{
  // To store the received message in a string, uncomment line 16 and 24.
  // String str="";
  String LoRaData; 

  int packetSize = LoRa.parsePacket();
  if (packetSize)
  {
    Serial.print("Received packet:   ");
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
}
