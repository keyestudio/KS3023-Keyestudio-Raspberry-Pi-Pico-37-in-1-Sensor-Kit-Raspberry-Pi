/* 
 * Keyestudio 37 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 37
 * mfrc522
 * http://www.keyestudio.com
*/
#include <Wire.h>
#include "MFRC522_I2C.h"
//iic pins default to pico's 4 and 5 
// 0x28 is the i2c address on SDA.  If it doesn't match, check your address with i2cscanner 
MFRC522 mfrc522(0x28);   // Create MFRC522 
String rfid_str = "";
void setup() {
  Serial.begin(115200);           // Set the baud rate to 115200
  Wire.begin();                   // Initialize I2C 
  mfrc522.PCD_Init();             // Initialize MFRC522
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }
  rfid_str = "";//clear up strings
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {// save UID
    rfid_str = rfid_str + String(mfrc522.uid.uidByte[i], HEX);  //convert into charater strings
    //        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    //        Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println(rfid_str);

}
