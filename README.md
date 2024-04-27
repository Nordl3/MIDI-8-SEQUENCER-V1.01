MIDI 8 SEQUENCER
Overview
This repository hosts the firmware for "MIDI 8 SEQUENCER," a straightforward MIDI-controlled step sequencer. The device interfaces with standard MIDI equipment to control analog synthesizers with potentiometer-adjusted voltage outputs. It is designed to generate rhythmic patterns and sequences that synchronize with other MIDI-compatible devices.

Features
Eight-Step Sequencing: Features an 8-step sequence with manual voltage control via potentiometers for each step.
Play Modes: Includes four modes:
Forward: Sequentially from the first to the last step.
Reverse: Backward from the last to the first step.
Ping-Pong: Alternates between the first and last steps.
Random: Randomly selects steps.
MIDI Synchronization: Syncs with MIDI clock signals and responds to start/stop commands.
LED Indicators: Visual feedback through LED indicators for each step.
Hardware Components
Arduino Nano: Manages MIDI data and sequence control.
Digital LEDs: Indicates active steps.
Potentiometers: Adjust voltage outputs for step control.
Usage
Connect "MIDI 8 SEQUENCER" to a MIDI device, set the voltage for each step using the potentiometers, select a play mode, and activate the MIDI clock to operate the sequencer.
