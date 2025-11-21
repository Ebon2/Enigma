/**
 * @file imports.h
 * @brief This file contains functions for importing configuration data to binary files.
 * @author Angel Rojas
 * @date 2024-11-10
 * @version 1.1
 * @details
 * This file serves as a repository for functions related to importing configuration
 * data from binary files. It includes functions for reading barrel and reflector
 * configurations from a binary file.
 */

#ifndef ENIGMA_IMPORTS_H
#define ENIGMA_IMPORTS_H

/**
 * @brief Loads the configuration data for barrels and the reflector from a binary file.
 *
 * This function reads the pre-defined barrel and reflector configurations from a file
 * located at the path specified by the global variable `g_path_barrels`. The binary file
 * is expected to contain the configurations for three barrels (`s_barrel_a`, `s_barrel_b`,
 * `s_barrel_c`) and one reflector (`s_reflector`), each consisting of `ALPHA_LEN` elements
 * of type `int_comb_t`.
 *
 * After successfully reading the data, the function invokes an internal function `s_change_char()`
 * to adjust or finalize the configuration, if necessary.
 *
 * If the file cannot be opened, an error message is printed to `stderr` and no further
 * processing occurs.
 *
 * @note The barrels and reflector are used as part of a cryptographic mechanism.
 *
 * Preconditions:
 * - The global variable `g_path_barrels` must be properly initialized with the path to the
 *   binary file containing the barrel and reflector configurations.
 * - The binary file must contain enough data to populate all barrels and the reflector.
 *
 * Postconditions:
 * - The barrel and reflector configurations are loaded into their respective static arrays.
 * - The internal function `s_change_char()` is called to finalize the configurations.
 *
 * Error Handling:
 * - If the file cannot be opened, an error message is logged using `perror`, and the function
 *   returns without modifying any barrel or reflector data.
 */
void import_rotors();

/**
 * @brief Loads modifier configuration values for the barrels from a binary file.
 *
 * This function reads the configuration modifiers for three barrels from a file
 * specified by the global variable `g_path_modifier`. The binary file is expected
 * to contain three `int` values, which are assigned to:
 * - `g_barrel_a_modifier`
 * - `g_barrel_b_modifier`
 * - `g_barrel_c_modifier`
 *
 * The function ensures the file is opened and successfully reads the necessary
 * values. After reading, the file is properly closed.
 *
 * Preconditions:
 * - The global variable `g_path_modifier` must be initialized with the correct path
 *   to the binary file containing the modifier data.
 * - The binary file must contain at least three `int` values.
 *
 * Postconditions:
 * - The values for `g_barrel_a_modifier`, `g_barrel_b_modifier`, and `g_barrel_c_modifier`
 *   are updated with the data read from the file.
 *
 * Error Handling:
 * - If the file cannot be opened, an error message is logged using `perror`, and the function
 *   returns without modifying any of the modifier data.
 * - If an error occurs during the read process, behavior is undefined, as the function does
 *   not perform explicit checks for partial reads.
 */
void import_modifiers();

#endif //ENIGMA_IMPORTS_H