#include <EEPROM.h>
String serial;
int serial_length = 69;

void setup() {
  Serial.begin(115200);
  EEPROM.begin(512);
  delay(3000);
  Serial.println();
  Serial.println();
  Serial.println("Startup");

Serial.println("Reading EEPROM ssid");
byte test;
EEPROM.get(0, test);
if(test == NAN){
  Serial.println("empty");
} else {
  for (int i = 0; i < serial_length; ++i)
    {
      serial += char(EEPROM.read(i));
    }
    //serial.trim();
    Serial.println(serial.length());
  Serial.print("SSID: ");
  Serial.println(serial);
}
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
