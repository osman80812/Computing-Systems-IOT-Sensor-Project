// Photon1-PIR_Motion sensor
#include <particle.h>
using namespace std;

//sensor parameters
int inPin = D0;              
int ledPin = D7;                
int pIRstate = LOW;             
int val = 0; 
int sensIR = 0;

//photon LED configuration
int calibrateTime = 5000;    

//string publisher
void motionDetected(const char *event, const char *data){
  Serial.print("INTRUDER ALERT!");
}

void intruderLOG(const char *event, const char *data){
  Serial.print(sensIR);
}

//setup for circuit
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);
  //sets a log for the times someone has walked near the sensor
  Particle.subscribe("intruder_log", motionDetected, "430028000447363339343638");
  //sends message of the time room was breached
  Particle.subscribe("intruder_alert", intruderLOG, "430028000447363339343638");
}

void loop(){
//Sensor breach parameters
  if (calibrated()){
    readSensor();
    reportData();
  }
}

void readSensor() {
  val = digitalRead(inPin);
}

bool calibrated() {
  return millis() - calibrateTime > 0;
}

void reportData() {
  if (val == HIGH) {
    sensIR += 10;
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);

    //sends message to cloud
    Particle.publish("intruder_alert", "INTRUDER ALERT!");
    Particle.publish("intruder_log", String(sensIR));

   }
   else if (val == LOW) { 
     if(sensIR > 0){
       sensIR -= 10;
     } else{
        sensIR = 0;
     }
     Particle.publish("intruder_log", String(sensIR));
    }
}
