# Arduino Keypad Access Control System

A simple embedded access control system developed in **C++ using Arduino and PlatformIO**. The project simulates a PIN-based door lock using a 4×4 matrix keypad, a start button, and LED indicators.

The main focus is on implementing structured program logic, handling hardware inputs, and managing user interaction without an operating system.

## Features

- **Finite State Machine (FSM):** Controls the program flow through states such as `WAIT_TO_START`, `IDLE`, `SCANNING`, `VALIDATING`, and `SUCCESSFUL_PIN_CODE`.
- **4×4 Matrix Keypad:** Uses row-by-row scanning and internal pull-up resistors to detect key presses.
- **Sliding Window PIN Validation:** Stores only the four most recent digits, allowing users to correct accidental inputs by continuing to type instead of manually resetting the PIN.
- **Edge Detection:** Prevents a continuously held key from being registered repeatedly.
- **LED Feedback:** Provides visual feedback for keypad interaction and successful PIN validation.

## How It Works

1. The system waits for the start button to be pressed.
2. The keypad becomes active and detects user input.
3. Each new key shifts the previous digits one position to the left in a four-element array.
4. The latest four digits are compared against the predefined PIN (`1337`).
5. When the PIN matches, the green LED activates for three seconds before the system returns to its idle state.

## Hardware

- Arduino Uno R3
- 4×4 Matrix Keypad
- Push Button
- Red/Green LED (RGB LED)
- Breadboard and jumper wires

## Technologies & Concepts

**C++ · Arduino · PlatformIO · Finite State Machines · GPIO · Matrix Scanning · Arrays · Sliding Window · Edge Detection**

## Development Environment

Developed in **Visual Studio Code** using the **PlatformIO** extension.

The project is structured into separate source and header files to improve readability and maintainability.
