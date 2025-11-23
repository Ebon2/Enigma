/**
 * @file core.h
 * @brief This file contains the main entry point for the program.
 * @author Angel Rojas
 * @date 2024-11-10
 * @version 1.1
 * @details
 * This file contains the main entry point for the program, orchestrating
 * the execution flow and coordinating various components such as file processing,
 * argument handling, and encryption/decryption operations.
 */

#ifndef functions_H
#define functions_H

/**
 * @brief Executes the encryption process based on the current encryption level.
 *
 * This function determines the encryption level using the global variable `g_actual_level`
 * and applies the corresponding encryption operation:
 * - LOW: Calls the function for lower-level encryption.
 * - HIGH: Calls the function for higher-level encryption.
 * - EXTREME: Calls the function for extreme-level encryption.
 *
 * Additionally, it adjusts the encryption parameters by internally invoking `s_add_level`.
 * The encryption levels are defined in the `level_t` enumeration.
 *
 * @note This function depends on the global variables `g_actual_level` and `g_mode`.
 *       Ensure these variables are properly initialized before invoking this function.
 */
void encrypt();

/**
 * @brief Executes the decryption process based on the current decryption level.
 *
 * This function determines the decryption level using the global variable `g_actual_level`
 * and applies the corresponding decryption operation:
 * - LOW: Invokes the function for lower-level decryption.
 * - HIGH: Invokes the function for higher-level decryption.
 * - EXTREME: Invokes the function for extreme-level decryption.
 *
 * The function first retrieves the current decryption level by internally invoking `s_get_level`.
 * The decryption levels are defined in the `level_t` enumeration.
 *
 * @note This function depends on the global variable `g_actual_level`, which must be set
 *       correctly prior to its invocation.
 */
void decrypt();

#endif
//functions