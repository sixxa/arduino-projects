#include<SoftwareSerial.h>

int sensorPin = A0; // input  LDR

int sensorValue = 0; // sensor value

int buzzer = 12; // Output Buzzer

SoftwareSerial bluetoothSerial(11, 10);

void setup() {


pinMode(buzzer,OUTPUT);

Serial.begin(9600);

bluetoothSerial.begin(9600);

}

void loop()

{

Serial.println("Welcome to TechPonder Flame Sensor Tutorial");

sensorValue = analogRead(sensorPin);

Serial.println(sensorValue);

if (sensorValue < 90) {

Serial.println("Fire Detected");

digitalWrite(buzzer,HIGH);

delay(1000);

} 
{
  bluetoothSerial.print(sensorValue);
}

digitalWrite(buzzer,LOW);


delay(sensorValue);


}
