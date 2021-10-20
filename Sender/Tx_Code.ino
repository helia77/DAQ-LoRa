#include <SPI.h>
#include <LoRa.h>

int counter = 0;
char labview = 0;
int data = 0;
void setup() 
{
  Serial.begin(9600);
  Serial.println("LoRa Sender");
  if (!LoRa.begin(433E6)) 
  {
    Serial.println("Starting LoRa failed!");
    while(1);
  }
}
void loop() 
{
  //int sVal=analogRead(A1);
  //float tempc = (sVal/1024.0)*500.0;
  //String msg = "Temperature is " + String(tempc) + "°C";
  counter++;
  if (Serial.available()>0) {
    labview = Serial.read();
    if(labview == '1') {
      data = 1;
    }
    if(labview == '2'){ 
      data = 2;
    }
  }
  //data = 1;
  String msg = "Number ";
  Serial.print(counter); 
  Serial.print(". Sending message ");
  Serial.println(msg + data);
  
  LoRa.beginPacket();
  LoRa.print(msg + data);
  LoRa.endPacket();
  
  delay(5000);
}
