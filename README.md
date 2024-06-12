# MIDI-8-SEQUENCER-V1.01

## Overview
The **MIDI-8-SEQUENCER-V1.01** is a microcontroller-based sequencer that interfaces with Digital Audio Workstations (DAWs), MIDI clock sources, and Eurorack modular synthesizer systems. It is built using an Arduino Nano and is inspired by the functionality of the classic Baby 8 sequencer. This device interprets MIDI signals to manage and execute a sequence of steps with adjustable output voltages, designed primarily for use in modular synthesizer setups.

## Features
- **MIDI Compatibility:** The sequencer handles MIDI clock, start, and stop commands, ensuring it remains synchronized with any external MIDI-equipped devices or DAWs.
- **Control Interfaces:** Includes two 'Menu' potentiometers that allow users to set the sequence length and adjust the MIDI clock division according to their musical needs.
- **Dual Potentiometers:** Each of the eight steps has two associated potentiometers for adjusting pitch and velocity independently.
- **Diode Summing Networks:** Implements separate diode summing networks for each row of potentiometers, providing clean and isolated outputs for pitch and velocity, which emulate the operational characteristics of 'Baby 8' circuits.
- **LED Indicators:** An LED is connected to each pin to visually indicate which step is currently active, offering straightforward feedback during operation.

## Operation Modes
- **Playback Modes:** Supports various playback modes including forward, reverse, and ping-pong, allowing for diverse and dynamic sequencing.
- **Tuning Mode:** When the DAW is stopped, the sequencer enters 'TUNING MODE' upon pressing the menu button. In this mode, the current step's pin goes high, and subsequent button presses cycle through the steps. Each step can be manually tuned using its respective potentiometer. Exiting 'TUNING MODE' is done by starting or stopping the DAW.

## Technical Specifications
- **Input/Output:** Receives MIDI input through a 6N137 optocoupler and outputs control voltages through a diode-summed network to Eurorack-compatible voltages.
- **Power Requirements:** Powered via the Arduino Nano's standard USB connection or an external 7-12V DC input.
- **Connectivity:** Utilizes standard MIDI connectors for MIDI input and 3.5mm jacks for voltage outputs to Eurorack modules.

## Usage
Connect the device to a MIDI source and Eurorack system, set the desired sequence length and clock division using the potentiometers, and select the playback mode to begin sequencing. Use 'TUNING MODE' for fine adjustments to each step's pitch and velocity settings.

## Video Demo
https://youtu.be/7BbvsP_2uEQ
