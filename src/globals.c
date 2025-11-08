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

int g_barrel_a_modifier = 0;
int g_barrel_b_modifier = 0;
int g_barrel_c_modifier = 0;

char *g_input_file_name = NULL;
char *g_output_file_name = OUTPUT_FILE_DEFAULT;

FILE *g_input_file = NULL;
FILE *g_output_file = NULL;

char g_path_barrels[PATH_MAX_LEN];
char g_path_modifier[PATH_MAX_LEN];

mod_t g_mode = ENCRYPT;
level_t g_actual_level = LOW;

