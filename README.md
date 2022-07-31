# Candy Dispenser v2 (IN WORK)
This is an automated Candy dispenser. When a hand is detected, the system lights up, plays spooky music, and dispenses candy.
This is version 2 of my automated candy dispenser. My previous version would occasionally jam up due to the design of candy releasing mechanism. However, this version does not jam regardless of the differing sizes of candy. 


## How It's Made:

**Hardware and other materials**
- Arduino Due
- NEMA23 CNC Stepper Motor
- TB6600 Stepper Motor Driver
- 12V Power Supply 
- Lazy Susan Turn Table Bearings
- HC-SR204 Ultrasonic Module Distance Sensor
- 5mm Individual LEDs
- 300 Ohm Resistors (for LEDs)
- Speakerbox from Halloween Decoration

**Tech used:** C++, Arduino, Blender

The motor, LEDs, sensors, and audio is controlled by an Arduino. Once an object is close enough to the handDetect sensor, the arduino turns on the leds, plays the audio from the speaker, spins the motor. Once the candy exit has been detected by the detectCandy sensor, the motor stops spinning. The motor will briefly rotate backwards to ensure no more candy falls out and turn off the LEDs.

The audio comes from a speaker I ripped out of an old Halloween direction. This means I do not need to save an audio file to my Arduino - I simply send the correct signal to the speaker to trigger it to play. 

I am using Blender to design some parts to 3D print, such as a lazy susan, gears to connect to the motor, and a small ramp for the candy to exit from. The housing for the electronics will most likely be a bucket. To hide the bucket, I will make a paper-mache jack-o-lantern or buy a plastic pumpkin large enough to cover everything. More pictures and files will be added as I get closer to the final designs.

## Optimizations from v1

v1 was created using two weak DC Micro Servos that could support a torque of only 2.5kg/cm. They also only rotated up to 180 degrees. This created several limitations in my designs. 
I decided to build a ramp that held the candy. The motors were attached to the door and an IR Sensor was placed to detect when a hand was close by to catch the candy. This would trigger the motors to open the door and release the candy. Once the IR sensor along the ramp detected that the candy had fallen out, the motors would close the door. However, sometimes the door would close on a piece of candy, causing the door to not close completely. Additionally, the motors were so weak that I could only fill the dispenser with about 1 lb of candy at a time.

v2 upgraded to a Stepper Motor with a higher torque that can spin continuously. Inital v2 designs used a converyor belt similar to what is used at grocery stores. This means jams do not occur and candy can be of any size However, This design requires properly tensioning pulleys and more force. It also takes up more space. I instead am electing to use a Lazy Susan that holds all the candy. As the candy rotates along the lazy susan, there is a bar in the way that will cause the candy to get caught and fall off the lazy susan. Similiar to the v1 design, an IR sensor will be used to trigger the mechanism to drop a candy, and another IR sensor will be used to make sure a candy has successfully fallen. 



