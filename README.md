# Enigma-like Encryption Program

A C program that implements an Enigma-style encryption system using multiple barrel rotors for text encryption and
decryption.

## Description

This program implements a text encryption system inspired by the Enigma machine, using three configurable barrels
(rotors) and a reflector. It processes input text through multiple encryption stages to produce an encrypted output.

## Prerequisites (Linux)

- A C compiler (GCC or Clang)
- CMake 3.16+ (recommended)
- Make or Ninja
- OpenSSL (libcrypto) development files, because the program uses RAND_bytes()
  - Debian/Ubuntu: sudo apt install libssl-dev
  - Arch: sudo pacman -S openssl
  - Fedora: sudo dnf install openssl-devel

Runtime data: the project includes rotor data under bin/rotors_BIN.

## Installation on Linux

Using CMake (recommended):

1) Configure and build
   ```bash
   cmake -S . -B build
   cmake --build build
   ```

2) Install (system-wide, default prefix /usr/local)
   ```bash
   sudo cmake --install build
   ```
   This typically installs:
   - Executable: /usr/local/bin/enigma
   - Data: /usr/local/share/enigma/rotors_BIN (copied from ./bin/rotors_BIN)

Install without sudo (user local prefix):
   ```bash
   cmake -S . -B build -DCMAKE_INSTALL_PREFIX="$HOME/.local"
   cmake --build build
   cmake --install build
   # Ensure ~/.local/bin is in your PATH
   ```
   This installs:
   - ~/.local/bin/enigma
   - ~/.local/share/enigma/rotors_BIN

Notes:
- You can change the prefix to any writable directory by setting -DCMAKE_INSTALL_PREFIX when configuring.
- The build directory can be any name; build is used here for clarity.

## Updating on Linux

To update to the latest version from this source tree, simply rebuild and reinstall to the same prefix:
```bash
cmake -S . -B build
cmake --build build
# For system-wide
sudo cmake --install build
# Or for user prefix
cmake --install build
```
This will overwrite the previously installed executable and refresh the data directory (rotors_BIN) as needed.

## Uninstallation on Linux

CMake generates an install manifest listing all installed files. From the same build directory you used to install:

- System-wide uninstall:
  ```bash
  sudo xargs rm -f < build/install_manifest.txt
  ```

- User prefix uninstall:
  ```bash
  xargs rm -f < build/install_manifest.txt
  ```

If you no longer have the build directory, you can manually remove typical locations:
- Executable: /usr/local/bin/enigma or ~/.local/bin/enigma
- Data directory: /usr/local/share/enigma or ~/.local/share/enigma (remove rotors_BIN inside)

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

Data files search order for rotors:
1) Relative to executable run dir: ../bin/rotors_BIN
2) User: $HOME/.local/share/enigma/rotors_BIN
3) System: /usr/local/share/enigma/rotors_BIN

Output format and keys:
- On encryption, the output always starts with a two-letter level tag:
  - LOW -> "LW"
  - HIGH -> "HW"
  - EXTREME -> "EX"
- Immediately after the level tag, three A–Z letters (the rotor keys) are written before the actual encrypted text of the first block.
- For LOW: keys are written once at the beginning of the file.
- For HIGH: keys are written at the start of each line (before the line’s ciphertext).
- For EXTREME: keys are written at the start of each whitespace-delimited block (before that block’s ciphertext).

Processing rules (from the current code):
- Input is converted to uppercase; non-alphabetic characters (spaces, punctuation, digits, newlines) pass through unchanged in position and value.
- Alphabetic characters are transformed by traversing three rotors, then a reflector, and then the inverse path back through the rotors. Between stages, per-rotor random shifts (modifiers) are applied.

## Behavior details (as implemented)

- Security level is selected at runtime with -l 1|2|3, not at compile time.
- Rotor modifiers are random for each run/block using OpenSSL RAND_bytes(); they are not configured via constants.
- Paragraph mode (-p):
  - Creates a temporary input file with the provided text.
  - Prints the resulting ciphertext/plaintext to stdout after processing.
  - Removes the temporary input file afterwards.
- --no-output-file:
  - The program still writes to an output file during processing, but removes it at the end of the run. Combine with -p to only print to stdout without keeping a file.

## How It Works

1. Input text is converted to uppercase.
2. Each alphabetic character is processed by:
   - Forward pass through three rotors (substitution via rotors_BIN definitions),
   - Inter-rotor shifting using three random modifiers (1–26),
   - Reflection (fixed mapping),
   - Reverse pass back through the rotors and inverse shifts.
3. Non-alphabetic characters are copied unchanged.
4. The output begins with the level tag (LW/HW/EX) and, depending on level, prepends three key letters to the start of the file (LOW), each line (HIGH), or each whitespace-delimited block (EXTREME).
