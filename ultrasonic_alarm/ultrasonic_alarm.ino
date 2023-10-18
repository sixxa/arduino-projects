#define trigP 2
#define echoP 3
#define LEDlampRed 4
#define LEDlampYellow 5
#define LEDlampGreen 6
#define soundbuzzer 7
int sound = 500;

void setup() {
Serial.begin(9600);
pinMode(trigP, OUTPUT);
pinMode(echoP, INPUT);
pinMode(LEDlampRed, OUTPUT);
pinMode(LEDlampYellow, OUTPUT);
pinMode(LEDlampGreen, OUTPUT);
pinMode(soundbuzzer, OUTPUT);
}

void loop() {
long durationindigit, distancecm;
digitalWrite(trigP, LOW);
delayMicroseconds(2);
digitalWrite(trigP, HIGH);
delayMicroseconds(10);
digitalWrite(trigP, LOW);
durationindigit = pulseIn(echoP, HIGH);
distancecm = (durationindigit / 5) / 29.1;

if (distancecm < 50) {
digitalWrite(LEDlampGreen, HIGH);
} else {
digitalWrite(LEDlampGreen, LOW);
}

if (distancecm < 20) { 
digitalWrite(LEDlampYellow, HIGH);
} else {
digitalWrite(LEDlampYellow, LOW);
}

if (distancecm < 5) { 
digitalWrite(LEDlampRed, HIGH);
sound = 1000;
} else {
digitalWrite(LEDlampRed, LOW);
}

if (distancecm > 5 || distancecm <= 0) { 
Serial.println("legit zone");
noTone(soundbuzzer);
} else {
Serial.print(distancecm);
Serial.println(" cm");
}

delay(300);
}
