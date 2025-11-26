/**
 * @file rotors.h
 * @brief This file contains functions for exporting configuration data to binary files.
 * @author Angel Rojas
 * @date 2024-11-10
 * @version 1.2
 * @details
 * This file serves as a repository for functions related to exporting configuration
 * data to binary files. It includes functions for writing rotor and reflector
 * configurations to a binary file.
 */

#ifndef ENIGMA_ROTORS_H
#define ENIGMA_ROTORS_H

/**
 * @brief Exports rotor configurations to a binary file.
 *
 * This function writes the rotor configurations stored in the global array `g_rotors`
 * to a binary file specified by the global file path variable `g_path_rotors`.
 *
 * Each rotor's input-output mappings (`ccomb_t` structures in `g_rotors`) are sequentially
 * written to the file for all rotors defined in `ROTORS_CANT`.
 *
 * Error handling includes:
 * - If the file cannot be opened for writing, an error message is output using `perror`.
 *
 * Resource management includes:
 * - Ensuring the file is properly closed after the write operation.
 *
 * Global Variables:
 * - `g_path_rotors`:
 *   A string representing the file path where the rotor configurations will be saved.
 * - `g_rotors[MAX_ROTORS][ALPHA_LEN]`:
 *   A two-dimensional array of `ccomb_t` structures, representing the input-output mapping
 *   of each rotor and the reflector.
 *
 * Constants:
 * - `ALPHA_LEN`:
 *   Fixed size of input-output character mappings handled by each rotor.
 * - `MAX_ROTORS`:
 *   Represents the number of rotors, including the reflector.
 *
 * Notes:
 * - The binary file is written in a format aligned with the `ccomb_t` structure.
 * - Each rotor's configuration is written sequentially, enabling consistent formatting.
 */
void rotors_export();

/**
 * @brief Imports rotor and reflector configurations from a binary file.
 *
 * This function reads the rotor configurations from a binary file specified
 * by the global file path variable `g_path_rotors` into the static `s_rotors` array.
 * It reads data for all rotors and the reflector (specified by the configuration in `s_rotors`)
 * and applies the data to the internal structures used by the program.
 *
 * If the file cannot be opened or an error occurs during the read operation,
 * an appropriate error message is displayed using `perror`.
 *
 * Post-read, the function calls `s_change_char()` to perform further
 * processing or validation on the imported configuration data.
 *
 * Global Variables:
 * - `g_path_rotors`:
 *   A character array representing the file path used for binary file import.
 *
 * Static Variables:
 * - `s_rotors[MAX_ROTORS][ALPHA_LEN]`:
 *   A two-dimensional array of type `icomb_t` (integer combinations), which stores imported data
 *   representing rotor and reflector configurations.
 *
 * Constants:
 * - `ALPHA_LEN`:
 *   The fixed size representing the number of input-output mappings for a rotor.
 * - `MAX_ROTORS`:
 *   Represents the number of rotors, including the reflector.
 *
 * Notes:
 * - The binary file should be formatted correctly to match the `icomb_t` structure.
 * - The `fread` function loads the complete rotor configuration in a single operation.
 * - Proper file closure (`fclose`) ensures resources are released after reading.
 */
void rotors_import();

/**
 * @brief Checks the status of rotors and returns the result.
 *
 * This function verifies the state of rotors and returns a boolean value indicating
 * whether the rotors are in a valid configuration for encryption/decryption.
 *
 * @return True if rotors are valid, false otherwise.
 */
int rotors_check();

void u_print_barrels();

#endif //ENIGMA_ROTORS_H