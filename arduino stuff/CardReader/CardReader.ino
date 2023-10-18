#include <SPI.h>
#include <RFID.h>
#include <Servo.h>
#include <SoftwareSerial.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN, RST_PIN);
SoftwareSerial ChemiSeriali(2, 3); // RX, TX (chemi seriali 'blutuzisaTvis')

int BaratNum = 0;
String str;

Servo servo8; // Declare the servo object

void setup()
{
  Serial.begin(9600);
  ChemiSeriali.begin(9600);
  SPI.begin();
  rfid.init();
  servo8.attach(8); // Attach the servo to pin 8
  Serial.println("machvene barati");
}

void loop()
{
  if (rfid.isCard())
  {

    if (rfid.readCardSerial())
    {
      str = String(rfid.serNum[0]) + String(rfid.serNum[1]) + String(rfid.serNum[2]) + String(rfid.serNum[3]) + String(rfid.serNum[4]);

      BaratNum = 0;
      if (str == "20814713616219")
      {
        servo8.write(90);
        delay(5000);
        servo8.write(0);
      }
      else
      {
        servo8.write(0);
      }

      Serial.print(str);
      Serial.print("    ");
      Serial.println(BaratNum);
      ChemiSeriali.println(BaratNum);
      delay(100);
    }
  }
  rfid.halt();
}

