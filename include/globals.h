/**
 * @file globals.h
 * @brief This file contains global variables and constants used throughout the program.
 * @author Angel Rojas
 * @date 2024-11-10
 * @version 1.2
 * @details
 * This file serves as a repository for global variables and constants that are used
 * across multiple parts of the program. It includes definitions for barrel and
 * reflector configurations, file paths, and other program-wide settings.
 */

#ifndef ENIGMA_GLOBALS_H
#define ENIGMA_GLOBALS_H

#include "structures.h"
#include "defines.h"

#include <stdio.h>

extern const char *g_KEY_ACCESS;

/* ========== ARRAYS ========== */
/**
 * @var g_rotors
 * @brief Represents the configuration of rotors used for encoding and decoding operations.
 */
extern ccomb_t g_rotors[ROTORS_CANT][ALPHA_LEN];

/**
 * @var g_rotors_modifier
 * @brief Represents the modifiers of rotors used for encoding and decoding operations.
 */
extern int g_rotors_modifier[ROTORS_CANT-1];

/* ========== FILES NAMES ========== */
/**
 * @var g_input_file_name
 * @brief Name of the input file for encryption or decryption.
 */
extern char *g_input_file_name;
/**
 * @var g_output_file_name
 * @brief Name of the output file for encryption or decryption.
 */
extern char *g_output_file_name;

/* ========== FILES POINTERS ========== */
/**
 * @var g_input_file
 * @brief File pointer for the input file.
 */
extern FILE *g_input_file;
/**
 * @var g_output_file
 * @brief File pointer for the output file.
 */
extern FILE *g_output_file;

/* ========== PATHS ========== */
/**
 * @var g_path_rotors
 * @brief Path to the rotor's configuration file.
 */
extern char g_path_rotors[MAX_PATH_LEN];

/* ========== FLAGS ========== */
/**
 * @var g_mode
 * @brief Mode of operation for the Enigma machine.
 */
extern mod_t g_mode;

/**
 * @var g_actual_level
 * @brief Represents the current encryption or decryption level being used.
 */
extern level_t g_actual_level;

/**
 * @var g_make_output_file
 * @brief Represents a flag of make an output file
 */
extern int g_make_output_file;

/**
 * @var g_paragraph
 * @brief the flag of paragraph mode
 */
extern int g_paragraph;

/**
 * @var g_input_paragraph
 * @brief the paragraph buffer
 */
extern char g_input_paragraph[MAX_CHAR];
#endif //ENIGMA_GLOBALS_H
