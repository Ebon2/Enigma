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

    fwrite(g_barrel_a, sizeof(comb_t), ALPHA_LEN, file);
    fwrite(g_barrel_b, sizeof(comb_t), ALPHA_LEN, file);
    fwrite(g_barrel_c, sizeof(comb_t), ALPHA_LEN, file);
    fwrite(g_reflector, sizeof(comb_t), ALPHA_LEN, file);

    fclose(file);
}

void export_modifiers() {
    FILE *file = fopen(g_path_modifier, "wb");
    if (!file) {
        perror("Error opening modifiers file for writing");
        return;
    }

    fwrite(&g_barrel_a_modifier, sizeof(int), 1, file);
    fwrite(&g_barrel_b_modifier, sizeof(int), 1, file);
    fwrite(&g_barrel_c_modifier, sizeof(int), 1, file);

    fclose(file);
}