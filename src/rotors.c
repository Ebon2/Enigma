//
// Created by angelrojas on 06/11/25.
//

#include "../include/barrels.h"
#include "../include/globals.h"

#include <stdio.h>

static void s_change_char();

void rotors_export() {
    FILE *file = fopen(g_path_rotors, "wb");
    if (!file) {
        perror("Error opening rotors file for writing");
        return;
    }

    for (int i = 0; i < MAX_ROTORS; i++)
        fwrite(g_rotors[i], sizeof(comb_t), ALPHA_LEN, file);

    fclose(file);
}

static int_comb_t s_rotors [MAX_ROTORS][ALPHA_LEN];


void rotors_import() {
    FILE *file = fopen(g_path_rotors, "rb");
    if (!file) {
        perror("Error opening rotors file");
        return;
    }

    fread(s_rotors, sizeof(int_comb_t), ALPHA_LEN * MAX_ROTORS, file);

    fclose(file);

    s_change_char();
}

int rotors_check(){
    for (int i=0; i<MAX_ROTORS-1; i++)
        if (g_rotors_modifier[i]>ALPHA_LEN-1  || g_rotors_modifier[i]<1)
            return 0;

    return 1;
}

static void s_change_char() {
    for (int i = 0; i < MAX_ROTORS; i++)
        for (int j = 0; j < ALPHA_LEN; j++) {
            g_rotors[i][j].input = (char)s_rotors[i][j].input;
            g_rotors[i][j].output = (char)s_rotors[i][j].output;
        }
}