//*************************************************************************************************//
//****** การสั่งงานควบคุมการ เปิด-ปิด อุปกรณ์เครื่องใช้ ไฟฟ้า ผ่าน Voice Recognition กับ บอร์ด Esp32 ioT All ******//
//****** 1. บอร์ด Esp32_ioT_All by TENERGY INNOVATION                                         ******//
//****** 2. บอร์ด AC220 CONVERTER by TENERGY INNOVATION                                       ******//
//****** 3. Module Voice Recognition                                                         ******//
//*************************************************************************************************//

#include "SoftwareSerial.h"
#include "esp32_iot_all_lib.h"

byte com = 0;

void setup() {
  Serial.begin(9600, SERIAL_8N1, RXD3, TXD3);

  pinMode(OUTPUT_1,OUTPUT);
  pinMode(OUTPUT_2,OUTPUT);
  pinMode(OUTPUT_3,OUTPUT);
  pinMode(OUTPUT_4,OUTPUT);

  digitalWrite(OUTPUT_1,HIGH);
  digitalWrite(OUTPUT_2,HIGH);
  digitalWrite(OUTPUT_3,HIGH);
  digitalWrite(OUTPUT_4,HIGH);

  Serial.write(0xAA);
  Serial.write(0x37);
  delay(1000);
  Serial.write(0xAA);
  Serial.write(0x21);
}

void loop() {
  while(Serial.available())
  {
    com = Serial.read();
    Serial.println("Ready...");
    Serial.println();
    delay(100);

    switch(com)
    {
      case 0x11:
        Serial.printf("HI !!\r\n");
        buzzer_beep(2);
      break;

      case 0x12:
        Serial.printf("Open lamp\r\n");
        digitalWrite(OUTPUT_1,LOW);
        buzzer_beep(1);
      break;

      case 0x13:
        Serial.printf("Off lamp\r\n");
        digitalWrite(OUTPUT_1,HIGH);
        buzzer_beep(1);
      break;

      case 0x14:
        Serial.printf("On Fan\r\n");
        digitalWrite(OUTPUT_2,LOW);
        buzzer_beep(1);
      break;

      case 0x15:
        Serial.printf("Off Fan\r\n");
        digitalWrite(OUTPUT_2,HIGH);
        buzzer_beep(1);
      break;
    }
  }

}
