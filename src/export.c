//
// Created by angelrojas on 06/11/25.
//

#include "../include/export.h"
#include "../include/globals.h"

#include <stdio.h>

void export_rotors() {
    FILE *file = fopen(g_path_rotors, "wb");
    if (!file) {
        perror("Error opening rotors file for writing");
        return;
    }

    for (int i = 0; i < MAX_ROTORS; i++)
        fwrite(g_rotors[i], sizeof(comb_t), ALPHA_LEN, file);

    fclose(file);
}

void export_modifiers() {
    FILE *file = fopen(g_path_modifier, "wb");
    if (!file) {
        perror("Error opening modifiers file for writing");
        return;
    }
    fwrite(g_rotors_modifier, sizeof(int), MAX_ROTORS-1, file);

    fclose(file);
}