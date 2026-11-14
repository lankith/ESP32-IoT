# Project 04: IoT Motion Detector with Email Alert using ESP32

## Objective
To detect motion using a PIR sensor and ESP32, and send an email alert through an IFTTT Webhook.

## Components Required
- ESP32 DevKit V1
- PIR Motion Sensor
- LED
- 220 ohm Resistor
- Jumper Wires

## Circuit Connections

| Component | ESP32 |
|---|---|
| PIR VCC | VIN (5V) |
| PIR GND | GND |
| PIR OUT | GPIO 4 |
| LED Anode (+) via 220 ohm | GPIO 5 |
| LED Cathode (-) | GND |

## Working Principle
1. The PIR sensor detects motion and sets its output pin HIGH.
2. ESP32 reads the PIR output on GPIO 4.
3. When motion is detected, the LED turns ON.
4. ESP32 sends a request to the IFTTT Webhook (event: motion_detected).
5. IFTTT sends an email alert to the user.
6. A 30-second cooldown prevents repeated emails.

## Software Used
- Wokwi Simulator
- Arduino C++
- ESP32
- IFTTT Webhooks

## Output
The system successfully detects motion, turns ON the LED, and sends an email alert. The Serial Monitor displays the IFTTT response.

## Simulation
https://wokwi.com/projects/480652044747465729

## Applications
- Home security systems
- Intruder detection
- Smart office monitoring
- Automatic lighting systems

## Author
Ankitha V.

Electronics and Communication Engineering
