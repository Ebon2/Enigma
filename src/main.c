/**
 * @file main.c
 * @brief This file contains the main entry point for the program.
 * @author Angel Rojas
 * @date 2024-11-10
 * @version 1.1
 * @details
 * This file serves as the primary entry point for the program, orchestrating
 * the execution flow and coordinating various components such as file processing,
 * argument handling, and encryption/decryption operations.
 */

#include "../include/core.h"
#include "../include/globals.h"
#include "../include/imports.h"
#include "../include/structures.h"
#include "../include/utils.h"


/**
 * The entry point of the program. This function initializes necessary resources,
 * processes command-line arguments, imports required components, and executes
 * the desired encryption or decryption operation.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array containing command-line arguments.
 * @return Returns 0 if the program executes successfully.
 */
int main(const int argc, char *argv[]) {
    u_select_paths();
    u_process_args(argc, argv);


    import_barrels();
    import_modifiers();

    u_process_file();

    check_barrels();
    if (g_mode == ENCRYPT)
        encrypt();
    else if (g_mode == DECRYPT)
        decrypt();

    return 0;
}
