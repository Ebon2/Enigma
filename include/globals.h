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

/**
 * @var g_barrel_a
 * @brief Array of comb_t structures representing the configuration of the first barrel.
 */
extern comb_t g_barrels[4][ALPHA_LEN];

/**
 * @var g_barrel_a_modifier
 * @brief Modifier for the first barrel's configuration.
 */
extern int g_barrels_modifier[3];

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
 * @var g_path_barrels
 * @brief Path to the barrels configuration file.
 */
extern char g_path_barrels[PATH_MAX_LEN];
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
 * @brief Represents a flag of the make an output file
 */
extern int g_make_output_file;
extern int g_paragraph;

extern char g_input_paragraph[MAX_CHAR];
#endif //ENIGMA_GLOBALS_H
