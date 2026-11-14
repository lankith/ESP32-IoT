# Project 06: Smart Home Energy Meter using ESP32

## Objective
To measure the current drawn by an appliance, calculate the power consumption, display it on an LCD, and upload the readings to ThingSpeak.

## Components Required
- ESP32 DevKit V1
- Potentiometer (simulating the ACS712 current sensor)
- 16x2 LCD with I2C module
- Jumper Wires

## Circuit Connections

| Component | ESP32 |
|---|---|
| Potentiometer VCC | 3V3 |
| Potentiometer GND | GND |
| Potentiometer SIG | GPIO 34 |
| LCD VCC | VIN (5V) |
| LCD GND | GND |
| LCD SDA | GPIO 21 |
| LCD SCL | GPIO 22 |

## Working Principle
1. The potentiometer simulates the output of an ACS712-20A current sensor (0 to 20 A).
2. ESP32 reads the analog value on GPIO 34 and averages 100 samples for a stable reading.
3. The reading is converted to current in amperes (0 to 20 A).
4. Power is calculated as Power = Current x Voltage, using 220 V mains voltage.
5. The current and power are shown on the 16x2 LCD and the Serial Monitor every second.
6. The readings are uploaded to ThingSpeak every 30 seconds.

## Software Used
- Wokwi Simulator
- Arduino C++
- ESP32
- ThingSpeak

## Output
The LCD displays live current and power values. The readings are uploaded to a ThingSpeak channel (Field 1: Current, Field 2: Power).

## Simulation
https://wokwi.com/projects/480655205059152897
## Applications
- Smart home energy monitoring
- Appliance power consumption tracking
- Electricity bill estimation
- Overload detection

## Author
Ankitha V.

Electronics and Communication Engineering
