//
// Created by angelrojas on 06/11/25.
//

#include "../include/utils.h"
#include "../include/globals.h"
#include "../include/export.h"

#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void s_init_globals(int opt);
static bool s_is_valid_level(int level);
static level_t s_get_level(int level);

static struct option long_options[] = {
    {"help", no_argument, NULL, 'h'},
    {"version", no_argument, NULL, 'v'},
    {"file", required_argument, NULL, 'f'},
    {"output", required_argument, NULL, 'o'},
    {"level", required_argument, NULL, 'l'},
    {"decrypt", no_argument, &g_decrypt, 'd'},
};

void u_process_args(const int argc, char *argv[]) {

    int option_index = 0;
    int opt;

    while (opt = getopt_long(argc, argv, "hvf:o:l:d", long_options, &option_index), opt != -1)
        s_init_globals(opt);
}

void u_process_file() {
    g_file = fopen(g_file_name, "r");
    g_output_file = fopen(g_output_file_name, "w");

    if (g_file == NULL) {
        printf("Error opening file 1\n");
        exit(1);
    }
    if (g_output_file == NULL) {
        printf("Error opening file 2\n");
        exit(1);
    }
}

void u_change_barrels() {
    g_barrel_a_modifier += STEPS_BARREL_A;
    g_barrel_b_modifier += STEPS_BARREL_B;
    g_barrel_c_modifier += STEPS_BARREL_C;

    if (g_barrel_a_modifier >= ALPHA_LEN)
        g_barrel_a_modifier -= ALPHA_LEN-1;

    if (g_barrel_b_modifier >= ALPHA_LEN)
        g_barrel_b_modifier -= ALPHA_LEN-1;

    if (g_barrel_c_modifier >= ALPHA_LEN)
        g_barrel_c_modifier -= ALPHA_LEN-1;

    export_modifiers();
}

static void s_init_globals(const int opt) {
    switch (opt) {
        case 'h':
            printf("Help\n");
            break;

        case 'v':
            printf("Version\n");
            break;

        case 'f':
            printf("File\n");
            g_file_name = optarg;

            // if (g_output_file_name == NULL)
            //     sprintf(g_output_file_name, "%s%s", "OUT", g_file_name);
            break;

        case 'o':
            printf("Output\n");
            g_output_file_name = optarg;
            break;

        case 'l':
			if (s_is_valid_level(atoi(optarg)))
				g_actual_level = s_get_level(atoi(optarg));
            break;

        case 'd':
            printf("Decrypt\n");
            g_mode = DECRYPT;
            break;

        default:
            printf("Unknown option: %c\n", opt);
            break;
    }
}

static bool s_is_valid_level(const int level) {
    return level >= LOW && level <= EXTREME;
}

static level_t s_get_level(const int level) {
    return (level_t)level;
}

