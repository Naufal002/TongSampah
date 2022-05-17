#include <Arduino.h>
#include <Servo.h>

Servo servo1;

int TRIG = 2;
int ECHO = 3; 
//==========
int servo = 6;
int lamps = 1;
int buzzer = 5;

void setup( ) {
  // put your setup code here, to run once:
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  // pinMode(lamps, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  servo1.attach(servo);
}

void loop( ) {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // read in the duration of the echo pulse
  int durasi;
  durasi = pulseIn(ECHO, HIGH);

  int jarak;
  jarak = durasi / 2 * 0.0340;
  Serial.println(jarak);


  // Servo
  servo1.write(0);
  if (jarak > 0 && jarak < 30){
    servo1.write(180);
    // digitalWrite(lamps, HIGH);
    digitalWrite(buzzer, HIGH);
    Serial.println("buka pintu..!!");
    delay(1000);

  }else{
    servo1.write(0);
    digitalWrite(buzzer, LOW);
  }

// }else if(jarak > 60){
//   digitalWrite(lamps, LOW);
// };
// servo1.write(0);
// delay(1000);
// servo1.write(100);
// delay(1000);

}