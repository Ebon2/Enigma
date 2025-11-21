//
// Created by angelrojas on 06/11/25.
//

#include "../include/export.h"
#include "../include/globals.h"

#include <stdio.h>

void export_barrels() {
    FILE *file = fopen(g_path_barrels, "wb");
    if (!file) {
        perror("Error opening barrels file for writing");
        return;
    }

    for (int i = 0; i < 4; i++)
        fwrite(g_barrels[i], sizeof(comb_t), ALPHA_LEN, file);

    fclose(file);
}

void export_modifiers() {
    FILE *file = fopen(g_path_modifier, "wb");
    if (!file) {
        perror("Error opening modifiers file for writing");
        return;
    }
    fwrite(g_barrels_modifier, sizeof(int), 4, file);

    fclose(file);
}