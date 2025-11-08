//
// Created by angelrojas on 06/11/25.
//

#ifndef ENIGMA_GLOBALS_H
#define ENIGMA_GLOBALS_H

#include <stdio.h>

#include "structures.h"
#include "defines.h"

extern comb_t g_barrel_a[ALPHA_LEN];
extern comb_t g_barrel_b[ALPHA_LEN];
extern comb_t g_barrel_c[ALPHA_LEN];
extern comb_t g_reflector[ALPHA_LEN];

extern int g_barrel_a_modifier;
extern int g_barrel_b_modifier;
extern int g_barrel_c_modifier;

extern char *g_input_file_name;
extern char *g_output_file_name;

extern FILE *g_input_file;
extern FILE *g_output_file;

extern char g_path_barrels[PATH_MAX_LEN];
extern char g_path_modifier[PATH_MAX_LEN];

extern mod_t g_mode;
extern level_t g_actual_level;

#endif //ENIGMA_GLOBALS_H
