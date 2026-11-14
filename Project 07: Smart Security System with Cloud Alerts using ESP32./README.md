# Project 07: Smart Security System with Cloud Alerts using ESP32

## Objective
To build a motion-triggered security system that sends an instant Telegram alert and logs every motion event to the cloud (ThingSpeak).

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
2. ESP32 reads the PIR output on GPIO 4 and turns ON the LED.
3. ESP32 sends an alert message to a Telegram bot using the Telegram Bot API.
4. The motion event count is logged to ThingSpeak (Field 1) as a cloud record.
5. A 20-second cooldown prevents repeated alerts.

## Changes from the Handbook
The original project uses a Raspberry Pi with a Pi Camera, OpenCV and Google Drive. These are not available in Wokwi, so the following replacements were used:

| Handbook | This Version |
|---|---|
| Pi Camera + OpenCV motion detection | PIR motion sensor |
| Photo sent to Telegram | Text alert sent to Telegram |
| Photo uploaded to Google Drive | Motion event logged to ThingSpeak |
| Raspberry Pi 4 (Python) | ESP32 (Arduino C++) |

## Software Used
- Wokwi Simulator
- Arduino C++
- ESP32
- Telegram Bot API
- ThingSpeak

## Output
When motion is detected, the LED turns ON, a Telegram message is received on the phone, and the event count is logged on ThingSpeak. The Serial Monitor displays the Telegram and cloud responses.

## Simulation
https://wokwi.com/projects/480671453669199873

## Applications
- Home and office security
- Intruder detection
- Remote monitoring systems
- Smart surveillance

## Author
Ankitha V.

Electronics and Communication Engineering
