# Myoelectric-Prosthetic-Arm
This repository contains the implementation of a Myoelectric Prosthetic Arm prototype that uses EMG (electromyography) signals to control a robotic hand for basic movement and grasping.

## Project Overview
A myoelectric prosthetic arm reads electrical muscle activity from the residual limb using EMG sensors, processes the signals via a microcontroller (Arduino), and drives servo motors to actuate the prosthetic hand to open and close based on the user’s muscle contractions.

## Features
- Reads EMG signals from surface electrodes
- Processes signals with an Arduino microcontroller
- Controls servo motors for hand movement
- Includes flowcharts and block diagrams for system design
- Contains code and documentation for development

## Hardware Components
- EMG sensors (surface electrodes)
- Arduino microcontroller
- Servo motors
-Power supply
- Wiring and mounting frame

## System Design
The system is structured around the following modules:
- Signal Acquisition – EMG sensors capture muscle electrical activity.
- Signal Processing – Arduino converts analog signals to digital and applies threshold logic.
- Actuation – Servo motors respond to processed commands to perform hand movements.
