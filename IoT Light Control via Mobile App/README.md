
# Project 02: IoT Light Control via Mobile App

## Project Overview
This project demonstrates an IoT-based light control system using an ESP32 microcontroller, Blynk IoT Cloud, and Wokwi Simulator.

The system allows users to remotely switch an LED ON and OFF using a mobile application through an internet connection.

This project demonstrates wireless communication, cloud connectivity, and remote device control.

## Objective
To develop an IoT-based system that enables remote
control of electrical loads using a mobile application
and a Wi-Fi-enabled microcontroller.

## Components Used

| Component | Quantity |
|---|---|
| ESP32 DevKit V1 | 1 |
| LED | 1 |
| 220 Ohm Resistor | 1 |
| Wokwi Simulator | 1 |
| Blynk IoT Cloud | 1 |
| Blynk Mobile App | 1 |

## Software and Platforms
- Wokwi Simulator
- Arduino IDE compatible code
- Blynk IoT Cloud
- Blynk Mobile Application

## Circuit Connections

| Component | ESP32 Connection |
|---|---|
| LED Anode (+) through 220Ω resistor | GPIO 5 |
| LED Cathode (-) | GND |

## Working Principle

1. ESP32 connects to the internet using Wi-Fi.
2. Blynk IoT Cloud establishes communication with ESP32.
3. The Blynk mobile application sends ON/OFF commands.
4. Virtual Pin V0 receives the commands.
5. ESP32 processes the commands and controls the LED.
6. The LED switches ON or OFF according to the mobile input.

## Blynk Configuration

- Template Name: ESP32 IoT Light Control
- Device Name: IoT Light Control
- Datastream: Light Control
- Virtual Pin: V0
- Data Type: Integer
- Minimum Value: 0
- Maximum Value: 1
- Button Mode: Switch

## Communication Details

- Microcontroller: ESP32
- Communication: Wi-Fi
- Cloud Platform: Blynk IoT
- Virtual Communication Pin: V0
- Output Pin: GPIO 5

## Simulation

Platform: Wokwi Simulator

Simulation Link:
https://wokwi.com/projects/480479084421388289

## Expected Output

- When the mobile switch is turned ON, the LED glows.
- When the mobile switch is turned OFF, the LED turns OFF.
- The ESP32 communicates with Blynk Cloud through Wi-Fi.

## Results

The IoT Light Control system was successfully
implemented and tested using Wokwi Simulator
and Blynk IoT Cloud.

Remote LED switching was achieved through
the Blynk mobile application.

## Applications

- Smart home automation
- Remote lighting control
- IoT-based appliance monitoring
- Wireless device control
- Smart building automation

## Future Enhancements

- Control multiple electrical appliances.
- Integrate relay modules for physical loads.
- Add real-time power monitoring.
- Implement voice-controlled automation.

## Author
Ankitha V.

Electronics and Communication Engineering
