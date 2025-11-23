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
 * @brief Regenerates the rotors' configuration.
 * Adjusts the modifiers for the rotating rotors used in encryption or
 * computation processes. The function increments the values of the rotor
 * modifiers by predefined step sizes specific to each rotor. If a modifier
 * exceeds the maximum allowable value (ALPHA_LEN), it wraps around to ensure
 * the values stay within a valid range. Finally, the updated modifiers are
 * exported to an external system or module.
 */
void u_change_rotors();

void u_init_program(int argc, char *argv[]);

void u_create_file(char name[]);
#endif //ENIGMA_UTILS_H