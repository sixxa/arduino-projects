#include<SoftwareSerial.h>

int sensorPin = A0; // select the input pin for the LDR

int sensorValue = 0; // variable to store the value coming from the sensor

int buzzer = 12; // Output pin for Buzzer

SoftwareSerial bluetoothSerial(11, 10);

void setup() {

// declare the ledPin and buzzer as an OUTPUT:


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
