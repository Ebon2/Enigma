//
// Created by angelrojas on 06/11/25.
//

#include "../include/imports.h"
#include "../include/globals.h"

#include <stdio.h>

static int_comb_t s_barrels [4][ALPHA_LEN];

static void s_change_char();

void import_barrels() {
    FILE *file = fopen(g_path_barrels, "rb");
    if (!file) {
        perror("Error opening barrels file");
        return;
    }

    fread(s_barrels, sizeof(int_comb_t), ALPHA_LEN * 4, file);

    fclose(file);

    s_change_char();
}

void import_modifiers() {
    FILE *file = fopen(g_path_modifier, "rb");
    if (!file) {
        perror("Error opening modifiers file");
        return;
    }

    fread(g_barrels_modifier, sizeof(int), 4, file);

    fclose(file);
}

static void s_change_char() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < ALPHA_LEN; j++) {
            g_barrels[i][j].input = (char)s_barrels[i][j].input;
            g_barrels[i][j].output = (char)s_barrels[i][j].output;
        }
}