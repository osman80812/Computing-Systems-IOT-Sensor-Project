# personal_projects
# Computing-Systems-IOT-Sensor-Project
 - This is project is a real-time home security system that is capable of emailing alerts and data to homeowners at the time of intrusion and a log tracking the time spent in the vicinity of the device. 
 - The general function of the program is to read the state the sensor is in. After the program reads if the sensor detects any motion, it will send a message to the cloud and output a signal if the program reads a high state from the sensor.
 - The sensor itself had a couple parts including these for main ones:
    - PIR motion sensor: It is also known as a proximity infrared sensor. It detects motions via thermal signatures. As soon as a person walks by the PIR     sensor, it will output HIGH in the source code. Once the person is outside the range of view of the infrared sensor, it will then return back to LOW in our source code.
   - Piezo buzzer: an actuator that is key to this project because it will alarm us with a sound as soon as someone is within range of the PIR sensor. 
   - Red LED: A red-colored LED will prove to be of utmost importance because it will give that emergency alarm look, only strengthening the effects of the         microcontroller as a result. It flashes every time the photon reads a high from the PIR motion sensor.
 - A video demonstration and circuit schematic is contained in the directory


