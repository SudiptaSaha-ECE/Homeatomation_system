🏠 Home Automation System using ESP8266 & Blynk IoT

A simple IoT-based Home Automation System that allows users to control home appliances remotely from anywhere in the world using a smartphone.
The system is built using ESP8266 (NodeMCU), a 2-Channel Relay Module, and the Blynk IoT Cloud Platform.

📌 Project Overview

This project demonstrates how IoT can be used to automate and control electrical appliances such as lights and fans using a mobile application.
The ESP8266 connects to Wi-Fi and communicates with the Blynk Cloud, allowing real-time control through the Blynk mobile app.

🚀 Features

Control two electrical appliances remotely

Works over Wi-Fi (Internet-based control)

Real-time response using Blynk IoT Cloud

Simple and low-cost hardware

Can be expanded to more appliances

🛠️ Components Used
Component	Quantity
ESP8266 (NodeMCU)	1
2-Channel Relay Module	1
AC Load (Bulb/Fan for testing)	2
Jumper Wires	As required
Power Supply (5V)	1
🔌 Circuit Connections
Relay Module to ESP8266
Relay Pin	ESP8266 Pin
IN1	D1
IN2	D2
VCC	VIN / 5V
GND	GND

⚠️ Warning:
Be extremely careful while working with AC mains voltage. Improper handling can cause serious injury.

📱 Blynk App Configuration

Create a project in Blynk IoT Console

Select ESP8266 as the device

Note down:

Auth Token

Template ID

Add two Button Widgets

Button 1 → Virtual Pin V1

Button 2 → Virtual Pin V2

Set button mode to Switch

💻 Software Requirements

Arduino IDE

ESP8266 Board Package

Blynk Library

USB Cable

🧠 Working Principle

ESP8266 connects to the Wi-Fi network.

Blynk App sends control commands via the Blynk Cloud.

ESP8266 receives commands and switches the relay ON/OFF.

Relay controls the connected electrical appliances.

📂 Project Structure
Home-Automation-ESP8266/
│
├── Code/
│   └── home_automation.ino
│
├── Circuit_Diagram/
│   └── circuit.png
│
├── README.md

🔧 How to Upload Code

Open Arduino IDE

Install ESP8266 Board Manager

Install Blynk Library

Update Wi-Fi credentials and Blynk credentials in code

Select correct COM port and board

Upload the code

📈 Future Improvements

Add voice control using Google Assistant

Add energy monitoring

Increase relay channels

Integrate sensors (temperature, motion, gas)

👨‍💻 Author

Sudipta Saha
Diploma in Electronics & Telecommunication Engineering

⭐ Support

If you like this project:

⭐ Star this repository

🍴 Fork it

🧠 Learn and improve it