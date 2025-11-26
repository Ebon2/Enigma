/**
 * @file defines.h
 * @brief This file contains various constants and macros used throughout the program.
 * @author Angel Rojas
 * @date $date
 * @version $proyectnumber
 * @details
 * This file serves as a repository for constants and macros that are used across
 * multiple parts of the program. It includes definitions for character limits,
 * alphabet length, file path lengths, default output filenames, application metadata,
 * and various data directory paths.
 */

#ifndef ENIGMA_DEFINES_H
#define ENIGMA_DEFINES_H

/**
 * @brief Maximum character limit for input/output operations.
 */
#define MAX_CHAR 256

/**
 * @brief Length of the alphabet used in the Enigma machine.
 */
#define ALPHA_LEN 27

/**
 * @brief Maximum length of file paths used in the program.
 */
#define MAX_PATH_LEN 128

/**
 * @brief The cant of rotors used in the Enigma machine.
 */
#define ROTORS_CANT 4

/**
 * @brief Default output filename.
 */
#define OUTPUT_FILE_DEFAULT "output.txt"


#define KEY_ACCESS "_Ebon-21000_"
/* ========= APLICATION METADATA ==========*/

/**
 * @brief Application name.
 */
#define APP_NAME "enigma"
/**
 * @brief Application version.
 */
#define APP_VERSION "1.1.0"

/**
 * @brief System-wide data directory.
 */
#define SYSTEM_DATA_DIR "/usr/local/share/enigma"

#ifndef USER_DATA_DIR_SUFFIX
/**
 * @brief Per-user data directory suffix.
 */
#define USER_DATA_DIR_SUFFIX "/.local/share/enigma"
#endif

/**
 * @brief Relative data directory.
 */
#define REL_DATA_DIR "../bin"

/**
 * @brief Data file name
 */
#define ROTORS_FILE "rotors_BIN"

#endif
