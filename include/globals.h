/**
 * @file globals.h
 * @brief This file contains global variables and constants used throughout the program.
 * @author Angel Rojas
 * @date 2024-11-10
 * @version 1.1
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

extern comb_t g_rotors[MAX_ROTORS][ALPHA_LEN];

extern int g_rotors_modifier[MAX_ROTORS-1];

extern int g_steps_rotors[MAX_ROTORS-1];

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

/**
 * @var g_path_rotors
 * @brief Path to the rotor's configuration file.
 */
extern char g_path_rotors[PATH_MAX_LEN];
/**
 * @var g_path_modifier
 * @brief Path to the modifier configuration file.
 */
extern char g_path_modifier[PATH_MAX_LEN];

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
extern int g_paragraph;

extern char g_input_paragraph[MAX_CHAR];
#endif //ENIGMA_GLOBALS_H
