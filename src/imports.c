//
// Created by angelrojas on 06/11/25.
//

#include "../include/imports.h"
#include "../include/globals.h"

#include <stdio.h>

static int_comb_t s_rotors [MAX_ROTORS][ALPHA_LEN];

static void s_change_char();

void import_rotors() {
    FILE *file = fopen(g_path_rotors, "rb");
    if (!file) {
        perror("Error opening rotors file");
        return;
    }

    fread(s_rotors, sizeof(int_comb_t), ALPHA_LEN * MAX_ROTORS, file);

    fclose(file);

    s_change_char();
}

void import_modifiers() {
    FILE *file = fopen(g_path_modifier, "rb");
    if (!file) {
        perror("Error opening modifiers file");
        return;
    }

    fread(g_rotors_modifier, sizeof(int), MAX_ROTORS-1, file);

    fclose(file);
}

static void s_change_char() {
    for (int i = 0; i < MAX_ROTORS; i++)
        for (int j = 0; j < ALPHA_LEN; j++) {
            g_rotors[i][j].input = (char)s_rotors[i][j].input;
            g_rotors[i][j].output = (char)s_rotors[i][j].output;
        }
}