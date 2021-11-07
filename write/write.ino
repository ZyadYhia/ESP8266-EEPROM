#include <EEPROM.h>
String serial = "pedo_0z5PQghhrsQtcCmIxmgxafCTT6y5loXEILqhyHgoeZ5zCWovZZdBRPdEZNaXRE9Q";
  int charLength=serial.length();
void setup() {
  Serial.begin(115200);
  EEPROM.begin(512);
  delay(3000);
  Serial.println();
  Serial.println();
  Serial.println("Startup");
 

//write to eeprom

  
  Serial.println("writing eeprom ssid:");
          for (int i = 0; i < serial.length(); ++i)
            {
              EEPROM.write(i, serial[i]);
              Serial.print("Wrote: ");
              Serial.println(serial[i]); 
            }
            EEPROM.commit();


//read to eeprom
  
  Serial.println("Reading EEPROM ssid");
  String esid;
  for (int i = 0; i < charLength; ++i)
    {
      esid += char(EEPROM.read(i));
    }
    //esid.trim();
    Serial.println(esid.length());
  Serial.print("SSID: ");
  Serial.println(esid);

}

void loop() {
}
