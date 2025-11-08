//
// Created by angelrojas on 21/10/25.
//

#ifndef defines_H
#define defines_H

#ifndef MAXCHAR
#define MAXCHAR 256
#endif

#ifndef ALPHA_LEN
#define ALPHA_LEN 27
#endif

#ifndef PATH_MAX_LEN
#define PATH_MAX_LEN 128
#endif

#ifndef OUTPUT_FILE_DEFAULT
#define OUTPUT_FILE_DEFAULT "output.txt"
#endif

// Application metadata
#ifndef APP_NAME
#define APP_NAME "enigma"
#endif

#ifndef APP_VERSION
#define APP_VERSION "1.0.0"
#endif

// System-wide data directory (when installed globally)
#ifndef SYSTEM_DATA_DIR
#define SYSTEM_DATA_DIR "/usr/local/share/enigma"
#endif

// Per-user data directory suffix (prefixed at runtime with $HOME)
#ifndef USER_DATA_DIR_SUFFIX
#define USER_DATA_DIR_SUFFIX "/.local/share/enigma"
#endif

// Relative data directory (when running from the project/build tree)
#ifndef REL_DATA_DIR
#define REL_DATA_DIR "../bin"
#endif

// Data file names
#ifndef BARRELS_FILE
#define BARRELS_FILE "barrels_BIN"
#endif

#ifndef MODIFIERS_FILE
#define MODIFIERS_FILE "modifiers_BIN"
#endif

// Barrel step configuration
#ifndef STEPS_BARREL_A
#define STEPS_BARREL_A 2
#endif

#ifndef STEPS_BARREL_B
#define STEPS_BARREL_B 5
#endif

#ifndef STEPS_BARREL_C
#define STEPS_BARREL_C 7
#endif

#endif
