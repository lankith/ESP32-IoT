
# Project 03: Soil Moisture Sensor using ESP32

## Objective
To monitor soil moisture levels using an ESP32 microcontroller and a soil moisture sensor.

## Components Required
- ESP32 DevKit V1
- Soil Moisture Sensor
- Jumper Wires

## Circuit Connections

| Soil Sensor | ESP32 |
|---|---|
| VCC | 3V3 |
| GND | GND |
| AO | GPIO 34 |

## Working Principle
1. The soil moisture sensor detects the moisture level in the soil.
2. The sensor sends an analog signal to ESP32 GPIO 34.
3. ESP32 reads the analog value.
4. The program converts the reading into an approximate moisture percentage.
5. The Serial Monitor displays the moisture level as DRY, MODERATE or WET.

## Software Used
- Wokwi Simulator
- Arduino C++
- ESP32

## Output
The system successfully monitors soil moisture levels and displays the corresponding readings on the Serial Monitor.

## Simulation
https://wokwi.com/projects/480651319307723777

## Applications
- Smart irrigation systems
- Agricultural monitoring
- Plant watering automation
- Smart gardens

## Author
Ankitha V.

Electronics and Communication Engineering
