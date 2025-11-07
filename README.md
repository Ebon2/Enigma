# Enigma-like Encryption Program

A C program that implements an Enigma-style encryption system using multiple barrel rotors for text encryption and
decryption.

## Description

This program implements a text encryption system inspired by the Enigma machine, using three configurable barrels (rotors) and a reflector. It processes input text through multiple encryption stages to produce a secure encrypted
output.

## Installation

1. Clone the repository
2. Compile the program using a C compiler:
   ```bash
   gcc src/*.c -o enigma
   ```
3. Run the compiled program:
   ```bash
   ./enigma
   ```

## Usage

1. Launch the program
2. Enter the text you want to encrypt when prompted
3. The program will display both the encrypted text and verify the decryption process

The encrypted output will include three characters at the end representing the barrel positions used for encryption.

## Configuration

The barrel settings can be configured in the defines.h file:

- BARREL_A: First rotor position (1–26)
- BARREL_B: Second rotor position (1–26)
- BARREL_C: Third rotor position (1–26)

All barrel values must be between 1 and 26 to represent valid letter shifts.

## How It Works

1. Input text is converted to uppercase
2. Each character passes through:
    - Barrel A encryption and rotation
    - Barrel B encryption and rotation
    - Barrel C encryption and rotation
    - Reflector
    - Reverse path through all barrels
3. The final output includes the barrel positions as validation keys

# *gutenmouguen*