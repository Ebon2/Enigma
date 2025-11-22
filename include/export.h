/**
 * @file export.h
 * @brief This file contains functions for exporting configuration data to binary files.
 * @author Angel Rojas
 * @date 2024-11-10
 * @version 1.1
 * @details
 * This file serves as a repository for functions related to exporting configuration
 * data to binary files. It includes functions for writing rotor and reflector
 * configurations to a binary file.
 */

#ifndef ENIGMA_EXPORT_CONFIG_H
#define ENIGMA_EXPORT_CONFIG_H

/**
 * @brief Exports the rotors and reflector configurations to a binary file.
 *
 * This function writes the contents of the global rotor arrays (`g_rotors[0-2]`) and the reflector array (`g_rotors[3]`)
 * into a binary file specified by the global path variable `g_path_rotors`.
 * Each rotor and the reflector are written sequentially in binary format.
 *
 * If the file cannot be opened or there is an error during the process,
 * the function outputs an error message using `perror`.
 *
 * Global Variables:
 * - `g_rotors[0-2]`:
 *   Arrays of type `comb_t` representing rotor configurations.
 * - `g_rotors[3]`:
 *   Array of type `comb_t` representing the reflector configuration.
 * - `g_path_rotors`:
 *   A character array specifying the file path for writing the binary data.
 *
 * Constants:
 * - `ALPHA_LEN`:
 *   The fixed size of the rotor and reflector arrays.
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
void export_rotors();

/**
 * @brief Exports the rotor modifier values to a binary file.
 *
 * This function writes the values of `g_rotors_modifier` to a binary file specified by the global variable `g_path_modifier`.
 * Each modifier value is written sequentially as binary data.
 *
 * Global Variables:
 * - `g_rotors_modifier`:
 *   Integer values representing the modifiers for the rotors.
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