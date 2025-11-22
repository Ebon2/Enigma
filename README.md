# Enigma-like Encryption Program

A C program that implements an Enigma-style encryption system using multiple barrel rotors for text encryption and
decryption.

## Description

This program implements a text encryption system inspired by the Enigma machine, using three configurable barrels 
(rotors) and a reflector. It processes input text through multiple encryption stages to produce a secure encrypted
output.

## Installation

Using CMake (recommended):

1. Configure and build
   ```bash
   cmake -S . -B build
   cmake --build build
   ```
2. Install
   ```bash
   sudo cmake --install build
   ```
   - The executable will be installed to: /usr/local/bin/enigma (default prefix)
   - The data files from ./bin (barrels_BIN, modifiers_BIN) will be installed to: ~/.local/share/enigma

Notes:
- If you prefer a different system prefix, set it when configuring, for example:
  ```bash
  cmake -S . -B build -DCMAKE_INSTALL_PREFIX=/usr/local
  ```
- You can also install without sudo by choosing a writable prefix (e.g., your home):
  ```bash
  cmake -S . -B build -DCMAKE_INSTALL_PREFIX="$HOME/.local"
  cmake --build build
  cmake --install build
  # Ensure ~/.local/bin is in your PATH
  ```

## Usage

Command-line options:

```
 enigma [options]

 Options:
   -h, --help              Show this help and exit
   -v, --version           Show version information and exit
   -f, --file <path>       Input file to process (required)
   -o, --output <path>     Output file path (default: output.txt)
   -l, --level <n>         Security level: 1=LOW, 2=HIGH, 3=EXTREME
   -d, --decrypt           Decrypt mode (default is encrypt)
   -p, --paragraph <text>  Use the terminal input to encrypt or decrypt
       --no-output-file    No save output file
```

Examples:
- Encrypt with level 2:
  ```bash
  enigma -f input.txt -o out.txt -l 2
  ```
- Decrypt:
  ```bash
  enigma --decrypt --file cipher.txt --output plain.txt
  ```

Data files search order for barrels/modifiers:
1) Relative: ../bin/{barrels_BIN, modifiers_BIN}
2) User: $HOME/.local/share/enigma/{barrels_BIN, modifiers_BIN}
3) System: /usr/local/share/enigma/{barrels_BIN, modifiers_BIN}

Notes below describe the algorithmic behavior. The encrypted output will include three characters at the end
representing the barrel positions used for encryption.

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
