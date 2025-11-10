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
