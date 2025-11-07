//
// Created by angelrojas on 06/11/25.
//

#include "../include/export.h"
#include "../include/globals.h"

#include <stdio.h>

void export_barrels() {
    FILE *f = fopen(BARRELS_BIN, "wb");

    // Guardamos directamente las combinaciones como letras (char)
    fwrite(g_barrel_a, sizeof(comb_t), ALPHA_LEN, f);
    fwrite(g_barrel_b, sizeof(comb_t), ALPHA_LEN, f);
    fwrite(g_barrel_c, sizeof(comb_t), ALPHA_LEN, f);
    fwrite(g_reflector, sizeof(comb_t), ALPHA_LEN, f);

    fclose(f);
}

void export_modifiers() {
    FILE *f = fopen(MODIFIERS_BIN, "wb");

    fwrite(&g_barrel_a_modifier, sizeof(int), 1, f);
    fwrite(&g_barrel_b_modifier, sizeof(int), 1, f);
    fwrite(&g_barrel_c_modifier, sizeof(int), 1, f);

    fclose(f);
}