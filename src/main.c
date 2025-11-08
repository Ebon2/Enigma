//
// Created by angelrojas on 21/10/25.
//

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
