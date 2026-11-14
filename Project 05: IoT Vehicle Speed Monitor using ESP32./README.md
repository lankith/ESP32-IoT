# Project 05: IoT Vehicle Speed Monitor using ESP32

## Objective
To measure the speed of a moving object using two sensors placed a known distance apart, and upload the speed to ThingSpeak.

## Components Required
- ESP32 DevKit V1
- 2 x Push Buttons (simulating IR sensors)
- Jumper Wires

## Circuit Connections

| Component | ESP32 |
|---|---|
| Button 1 (Sensor 1), one leg | GPIO 17 |
| Button 1 (Sensor 1), opposite leg | GND |
| Button 2 (Sensor 2), one leg | GPIO 27 |
| Button 2 (Sensor 2), opposite leg | GND |

## Working Principle
1. Two sensors are placed 20 cm apart on a track.
2. When the object passes Sensor 1, ESP32 records the start time.
3. When the object passes Sensor 2, ESP32 records the stop time.
4. Speed is calculated as distance divided by time and converted to km/h.
5. The speed is shown on the Serial Monitor and uploaded to ThingSpeak.
6. Uploads are limited to one per 15 seconds (ThingSpeak free tier).

## Software Used
- Wokwi Simulator
- Arduino C++
- ESP32
- ThingSpeak

## Output
The system successfully calculates the speed of the moving object and displays it on the Serial Monitor. The readings are uploaded to a ThingSpeak channel.

## Simulation
https://wokwi.com/projects/480654216392173569
## Applications
- Road speed monitoring
- Conveyor belt speed measurement
- Traffic monitoring systems
- Industrial automation

## Author
Ankitha V.

Electronics and Communication Engineering
