/**
 * @file utils.h
 * @brief This file contains functions related to utility operations.
 * @author Angel Rojas
 * @date 2024-11-10
 * @version 1.2
 * @details
 * This file serves as a repository for functions related to utility operations
 * within the Enigma program. It includes functions for processing command-line
 * arguments, handling file operations, and managing program settings.
 */

#ifndef ENIGMA_UTILS_H
#define ENIGMA_UTILS_H
#include <stdint.h>
#include <stdlib.h>

/**
 * @brief Regenerates the rotors' configuration.
 * Adjusts the modifiers for the rotating rotors used in encryption or
 * computation processes. The function increments the values of the rotor
 * modifiers by predefined step sizes specific to each rotor. If a modifier
 * exceeds the maximum allowable value (ALPHA_LEN), it wraps around to ensure
 * the values stay within a valid range. Finally, the updated modifiers are
 * exported to an external system or module.
 */
void u_change_rotors();

/**
 * @brief Initializes the program and sets up the necessary configurations.
 * This function prepares the program for operation by processing arguments,
 * importing rotor configurations, setting up input/output files, and initializing
 * required data structures. It configures necessary paths and triggers other
 * initialization-related operations essential for the program's functionality.
 *
 * @param argc The number of command-line arguments provided.
 * @param argv Array of command-line argument strings.
 */
void u_init_program(int argc, char *argv[]);

/**
 * @brief Creates a file and writes content to it.
 *
 * This function attempts to create a file with the specified name and writes
 * the current content of the paragraph stored in the global variable `g_input_paragraph`
 * into the file. If the file creation is successful, it updates the global
 * variable `g_input_file_name` to represent the name of the newly created file.
 *
 * @param name The name of the file to be created. It is expected to be a
 * null-terminated string.
 */
void u_create_file(char name[]);

void u_xor_crypt(uint8_t *data, size_t len);

#endif //ENIGMA_UTILS_H