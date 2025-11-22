/**
 * @file utils.h
 * @brief This file contains functions related to utility operations.
 * @author Angel Rojas
 * @date 2024-11-10
 * @version 1.1
 * @details
 * This file serves as a repository for functions related to utility operations
 * within the Enigma program. It includes functions for processing command-line
 * arguments, handling file operations, and managing program settings.
 */

#ifndef ENIGMA_UTILS_H
#define ENIGMA_UTILS_H

/**
 * @brief Processes command-line arguments to configure the program's behavior.
 *
 * Parses the command-line arguments using `getopt_long` to handle both short
 * and long option forms. Based on the parsed options, this function updates
 * global settings or configurations required by the application.
 *
 * @param argc The number of command-line arguments passed to the program.
 * @param argv An array of character pointers, each pointing to a command-line
 *             argument string.
 */
void u_process_args(int argc, char *argv[]);

/**
 * @brief Processes the input and output files specified by global variables.
 *
 * This function opens the input and output files based on the file paths
 * stored in the global variables `g_input_file_name` and `g_output_file_name`.
 * It assigns the opened file streams to the global variables `g_input_file`
 * and `g_output_file`. If any file cannot be opened, the program will terminate
 * with an error message.
 */
void u_process_file();

/**
 * @brief Initializes and selects required paths for modifiers and rotors.
 * This function calls internal utility functions to set up
 * the paths necessary for further processing.
 */
void u_select_paths();

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

void u_create_file(char name[]);
#endif //ENIGMA_UTILS_H