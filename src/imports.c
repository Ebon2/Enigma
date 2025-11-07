//
// Created by angelrojas on 06/11/25.
//

#include "../include/imports.h"
#include "../include/globals.h"

#include <stdio.h>

static int_comb_t s_barrel_a [ALPHA_LEN];
static int_comb_t s_barrel_b [ALPHA_LEN];
static int_comb_t s_barrel_c [ALPHA_LEN];
static int_comb_t s_reflector [ALPHA_LEN];

static void change_char();

void import_barrels() {
    FILE *file = fopen(BARRELS_BIN, "rb");

    fread(s_barrel_a, sizeof(int_comb_t), ALPHA_LEN, file);
    fread(s_barrel_b, sizeof(int_comb_t), ALPHA_LEN, file);
    fread(s_barrel_c, sizeof(int_comb_t), ALPHA_LEN, file);
    fread(s_reflector, sizeof(int_comb_t), ALPHA_LEN, file);

    fclose(file);

    change_char();
}

void import_modifiers() {
    FILE *file = fopen(MODIFIERS_BIN, "rb");

    fread(&g_barrel_a_modifier, sizeof(int), 1, file);
    fread(&g_barrel_b_modifier, sizeof(int), 1, file);
    fread(&g_barrel_c_modifier, sizeof(int), 1, file);

    fclose(file);
}

static void change_char() {
    for (int i = 0; i < ALPHA_LEN; i++) {
        g_barrel_a[i].input = (char)s_barrel_a[i].input;
        g_barrel_a[i].output = (char)s_barrel_a[i].output;

        g_barrel_b[i].input = (char)s_barrel_b[i].input;
        g_barrel_b[i].output = (char)s_barrel_b[i].output;

        g_barrel_c[i].input = (char)s_barrel_c[i].input;
        g_barrel_c[i].output = (char)s_barrel_c[i].output;

        g_reflector[i].input = (char)s_reflector[i].input;
        g_reflector[i].output = (char)s_reflector[i].output;
    }
}