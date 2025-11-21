//
// Created by angelrojas on 06/11/25.
//

#include "../include/globals.h"
#include "../include/defines.h"

#include <stdio.h>

comb_t g_rotors[MAX_ROTORS][ALPHA_LEN];

int g_rotors_modifier[MAX_ROTORS-1] = {0};
int g_steps_rotors[MAX_ROTORS-1] = STEPS_ROTORS;

char *g_input_file_name = NULL;
char *g_output_file_name = OUTPUT_FILE_DEFAULT;

FILE *g_input_file = NULL;
FILE *g_output_file = NULL;

char g_path_rotors[PATH_MAX_LEN];
char g_path_modifier[PATH_MAX_LEN];

mod_t g_mode = ENCRYPT;
level_t g_actual_level = LOW;

int g_make_output_file = 1;
int g_paragraph = 0;

char g_input_paragraph[MAX_CHAR];

