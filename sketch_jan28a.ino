// Some code that works with the updated IR Remote library
 
#include <IRremote.hpp>
const int IR_RECEIVE_PIN = 3;
 
void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
}
 
void loop()
{
  if (IrReceiver.decode()) // If the IR receiver has received something
  {
    if (IrReceiver.decodedIRData.decodedRawData == 0xE916FF00) // If '1' was pressed on the remote
    {
      Serial.println("Thing 0");
    }
    if (IrReceiver.decodedIRData.decodedRawData == 0xF30CFF00) // If '1' was pressed on the remote
    {
      Serial.println("Thing 1");
    }
    else if (IrReceiver.decodedIRData.decodedRawData == 0xE718FF00) // If '2' pressed
    {
      Serial.println("Thing 2");
    }
    else if (IrReceiver.decodedIRData.decodedRawData == 0xA15EFF00) // If '3' pressed
    {
      Serial.println("Thing 3");
    }
    else // can use print to find the new remote codes (now LSB-first) without doing math
    {
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    }
    IrReceiver.resume(); // Resume receiving input
  }
}