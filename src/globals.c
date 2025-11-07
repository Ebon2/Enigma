//
// Created by angelrojas on 06/11/25.
//

#include "../include/globals.h"
#include "../include/defines.h"

#include <stdio.h>

comb_t g_barrel_a[ALPHA_LEN];
comb_t g_barrel_b[ALPHA_LEN];
comb_t g_barrel_c[ALPHA_LEN];
comb_t g_reflector[ALPHA_LEN];

level_t g_actual_level = LOW;
char *g_file_name = NULL;
char *g_output_file_name = "OUTPUT";

mod_t g_mode = ENCRYPT;
FILE *g_file = NULL;
FILE *g_output_file = NULL;
int g_barrel_a_modifier = 0;
int g_barrel_b_modifier = 0;
int g_barrel_c_modifier = 0;

int g_decrypt = 0;

