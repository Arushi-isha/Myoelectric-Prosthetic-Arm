#include <Servo.h> 
int SENSORPIN=A3; 
int volts; 
int MuscleVoltage = 700; 
Servo servo1; 
Servo servo2; 
Servo servo3; 
Servo servo4; 
Servo servo5; 
void setup() { 
// put your setup code here, to run once: 
servo1.attach(3);              
servo2.attach(5);   
servo3.attach(6);   
servo4.attach(9);   
servo5.attach(10);   
Serial.begin(9600); 
} 
void loop() { 
// attach the servo motors on PWM pins of Arduino 
volts = analogRead(SENSORPIN); 
Serial.println(volts); 
if (volts >= MuscleVoltage) { 
servo1.write(180); 
servo2.write(180); 
servo3.write(180); 
servo4.write(180); 
servo5.write(180); 
Serial.println("Start Motor"); 
delay(500); 
} if (volts < MuscleVoltage) { 
servo1.write(0); 
servo2.write(0); 
servo3.write(0); 
servo4.write(0); 
servo5.write(0); 
Serial.println("Stop Motor"); 
delay(500); 
} 
delay(50); 
}