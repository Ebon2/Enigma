/**
 * @file defines.h
 * @brief This file contains various constants and macros used throughout the program.
 * @author Angel Rojas
 * @date 2024-11-10
 * @version 1.1
 * @details
 * This file serves as a repository for constants and macros that are used across
 * multiple parts of the program. It includes definitions for character limits,
 * alphabet length, file path lengths, default output filenames, application metadata,
 * and various data directory paths.
 */

#ifndef defines_H
#define defines_H

#define MAX_CHAR 256
#define ALPHA_LEN 27
#define PATH_MAX_LEN 128

#define OUTPUT_FILE_DEFAULT "output.txt"

// Application metadata
#define APP_NAME "enigma"
#define APP_VERSION "1.1.0"

// System-wide data directory (when installed globally)
#define SYSTEM_DATA_DIR "/usr/local/share/enigma"

// Per-user data directory suffix (prefixed at runtime with $HOME)
#ifndef USER_DATA_DIR_SUFFIX
#define USER_DATA_DIR_SUFFIX "/.local/share/enigma"
#endif

// Relative data directory (when running from the project/build tree)
#define REL_DATA_DIR "../bin"

// Data file names
#define BARRELS_FILE "barrels_BIN"
#define MODIFIERS_FILE "modifiers_BIN"

// Barrel step configuration
#define STEPS_BARREL_A 2
#define STEPS_BARREL_B 5
#define STEPS_BARREL_C 7

#endif
