/**
 * @file export.h
 * @brief This file contains functions for exporting configuration data to binary files.
 * @author Angel Rojas
 * @date 2024-11-10
 * @version 1.1
 * @details
 * This file serves as a repository for functions related to exporting configuration
 * data to binary files. It includes functions for writing barrel and reflector
 * configurations to a binary file.
 */

#ifndef ENIGMA_EXPORT_CONFIG_H
#define ENIGMA_EXPORT_CONFIG_H

/**
 * @brief Exports the barrel and reflector configurations to a binary file.
 *
 * This function writes the contents of the global barrel arrays (`g_barrel_a`,
 * `g_barrel_b`, `g_barrel_c`) and the reflector array (`g_reflector`)
 * into a binary file specified by the global path variable `g_path_barrels`.
 * Each barrel and the reflector are written sequentially in binary format.
 *
 * If the file cannot be opened or there is an error during the process,
 * the function outputs an error message using `perror`.
 *
 * Global Variables:
 * - `g_barrel_a`, `g_barrel_b`, `g_barrel_c`:
 *   Arrays of type `comb_t` representing barrel configurations.
 * - `g_reflector`:
 *   Array of type `comb_t` representing the reflector configuration.
 * - `g_path_barrels`:
 *   A character array specifying the file path for writing the binary data.
 *
 * Constants:
 * - `ALPHA_LEN`:
 *   The fixed size of the barrel and reflector arrays.
 * - `PATH_MAX_LEN`:
 *   The maximum length of the file path string.
 *
 * Notes:
 * - The file is opened in binary write mode (`wb`).
 * - Each `comb_t` structure consists of two characters (`input` and `output`),
 *   which are written in their raw binary form.
 * - Proper error handling is implemented to address potential issues
 *   with file I/O operations.
 */
void export_barrels();

/**
 * @brief Exports the barrel modifier values to a binary file.
 *
 * This function writes the values of `g_barrel_a_modifier`, `g_barrel_b_modifier`,
 * and `g_barrel_c_modifier` to a binary file specified by the global variable `g_path_modifier`.
 * Each modifier value is written sequentially as binary data.
 *
 * Global Variables:
 * - `g_barrel_a_modifier`, `g_barrel_b_modifier`, `g_barrel_c_modifier`:
 *   Integer values representing the modifiers for the barrels.
 * - `g_path_modifier`:
 *   A character array specifying the path to the binary file.
 *
 * Constants:
 * - `PATH_MAX_LEN`:
 *   The maximum allowable length for the file path string.
 *
 * Notes:
 * - The file is opened in binary write mode (`wb`).
 * - Proper error handling is implemented to ensure file operations succeed.
 * - The function outputs an error message using `perror` if the file cannot be opened.
 */
void export_modifiers();

#endif //ENIGMA_EXPORT_CONFIG_H