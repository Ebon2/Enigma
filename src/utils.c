//
// Created by angelrojas on 06/11/25.
//

#include "../include/utils.h"
#include "../include/globals.h"
#include "../include/export.h"
#include "../include/defines.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int s_is_valid_level(int level);
static void s_init_globals(int opt);
static void s_modifiers_path();
static void s_rotors_path();
static void s_help();
static void s_version();
static level_t s_get_level(int level);

static struct option long_options[] = {
    {"help", no_argument, NULL, 'h'},
    {"version", no_argument, NULL, 'v'},
    {"file", required_argument, NULL, 'f'},
    {"output", required_argument, NULL, 'o'},
    {"level", required_argument, NULL, 'l'},
    {"paragraph", required_argument, NULL, 'p'},
    {"decrypt", no_argument, NULL, 'd'},
    {"no-output-file", no_argument, &g_make_output_file, 0},
};

void u_process_args(const int argc, char *argv[]) {

    int option_index = 0;
    int opt;

    while (opt = getopt_long(argc, argv, "hvf:o:l:p:d", long_options, &option_index), opt != -1)
        s_init_globals(opt);
}

void u_process_file() {
    g_input_file = fopen(g_input_file_name, "r");
    g_output_file = fopen(g_output_file_name, "w+");

    if (g_input_file == NULL) {
        printf("Error opening file 1\n");
        exit(1);
    }
    if (g_output_file == NULL) {
        printf("Error opening file 2\n");
        exit(1);
    }
}

void u_select_paths() {
    s_modifiers_path();
    s_rotors_path();

}

void u_create_file(char name[]) {
    FILE *file = fopen(name, "w");
    if (file != NULL) {
        g_input_file_name = malloc(strlen(name) + 1);
        strcpy(g_input_file_name, name);

        fputs(g_input_paragraph, file);
        fclose(file);
    }

}

void u_change_rotors() {
    for (int i=0; i<MAX_ROTORS-1; i++)
        g_rotors_modifier[i] += g_steps_rotors[i];

    for (int i=0; i<MAX_ROTORS-1; i++)
        if (g_rotors_modifier[i] >= ALPHA_LEN)
            g_rotors_modifier[i] -= ALPHA_LEN-1;

    export_modifiers();
}

static int s_is_valid_level(const int level) {
    return level >= LOW && level <= EXTREME;
}

static void s_init_globals(const int opt) {
    switch (opt) {
        case 'h':
            s_help();
            break;

        case 'v':
            s_version();
            break;

        case 'f':
            g_input_file_name = optarg;
            break;

        case 'o':
            g_output_file_name = optarg;
            break;

        case 'l':
            if (s_is_valid_level(atoi(optarg)))
                g_actual_level = s_get_level(atoi(optarg));
            break;

        case 'd':
            g_mode = DECRYPT;
            break;

        case 'p':
            g_paragraph = 1;
            strcpy(g_input_paragraph, optarg);
            break;

        default: break;
    }
}

static void s_modifiers_path() {
    char candidate[PATH_MAX_LEN];

    // 1) Try a relative path (development tree)
    snprintf(candidate, sizeof(candidate), "%s/%s", REL_DATA_DIR, MODIFIERS_FILE);
    FILE *f = fopen(candidate, "rb");
    if (f != NULL) {
        fclose(f);
        snprintf(g_path_modifier, sizeof(g_path_modifier), "%s", candidate);
        return;
    }

    // 2) Try per-user data dir: $HOME + USER_DATA_DIR_SUFFIX
    const char *home = getenv("HOME");
    if (home && *home) {
        snprintf(candidate, sizeof(candidate), "%s%s/%s", home, USER_DATA_DIR_SUFFIX, MODIFIERS_FILE);
        f = fopen(candidate, "rb");
        if (f != NULL) {
            fclose(f);
            snprintf(g_path_modifier, sizeof(g_path_modifier), "%s", candidate);
            return;
        }
    }

    // 3) Fallback to system-wide data dir
    snprintf(candidate, sizeof(candidate), "%s/%s", SYSTEM_DATA_DIR, MODIFIERS_FILE);
    f = fopen(candidate, "rb");
    if (f != NULL) {
        fclose(f);
        snprintf(g_path_modifier, sizeof(g_path_modifier), "%s", candidate);
    }
}

static void s_rotors_path() {
    char candidate[PATH_MAX_LEN];

    // 1) Try a relative path (development tree)
    snprintf(candidate, sizeof(candidate), "%s/%s", REL_DATA_DIR, ROTORS_FILE);
    FILE *f = fopen(candidate, "rb");
    if (f != NULL) {
        fclose(f);
        snprintf(g_path_rotors, sizeof(g_path_rotors), "%s", candidate);
        return;
    }

    // 2) Try per-user data dir: $HOME + USER_DATA_DIR_SUFFIX
    const char *home = getenv("HOME");
    if (home && *home) {
        snprintf(candidate, sizeof(candidate), "%s%s/%s", home, USER_DATA_DIR_SUFFIX, ROTORS_FILE);
        f = fopen(candidate, "rb");
        if (f != NULL) {
            fclose(f);
            snprintf(g_path_rotors, sizeof(g_path_rotors), "%s", candidate);
            return;
        }
    }

    // 3) Fallback to system-wide data dir
    snprintf(candidate, sizeof(candidate), "%s/%s", SYSTEM_DATA_DIR, ROTORS_FILE);
    f = fopen(candidate, "rb");
    if (f != NULL) {
        fclose(f);
        snprintf(g_path_rotors, sizeof(g_path_rotors), "%s", candidate);
    }
}

static void s_help() {
    printf("%s - Enigma-like encryption tool\n", APP_NAME);
    printf("Usage:\n");
    printf("  %s [options]\n\n", APP_NAME);
    printf("Options:\n");
    printf("  -h, --help              Show this help and exit\n");
    printf("  -v, --version           Show version information and exit\n");
    printf("  -f, --file <path>       Input file to process (required)\n");
    printf("  -o, --output <path>     Output file path (default: output.txt)\n");
    printf("  -l, --level <n>         Security level: 1=LOW, 2=HIGH, 3=EXTREME\n");
    printf("  -d, --decrypt           Decrypt mode (default is encrypt)\n");
    printf("  -p, --paragraph <text>  Use the terminal input to encrypt or decrypt\n");
    printf("      --no-output-file    No save output file\n\n");

    printf("Data search order for barrels/modifiers files:\n");
    printf("  1) Relative: %s/{%s,%s}\n", REL_DATA_DIR, ROTORS_FILE, MODIFIERS_FILE);
    printf("  2) User: $HOME%s/{%s,%s}\n", USER_DATA_DIR_SUFFIX, ROTORS_FILE, MODIFIERS_FILE);
    printf("  3) System: %s/{%s,%s}\n\n", SYSTEM_DATA_DIR, ROTORS_FILE, MODIFIERS_FILE);

    printf("Examples:\n");
    printf("  %s -f input.txt -o out.txt -l 2\n", APP_NAME);
    printf("  %s --decrypt --file cipher.txt --output plain.txt\n\n", APP_NAME);

    exit(0);
}

static void s_version() {
    printf("%s %s\n", APP_NAME, APP_VERSION);
    printf("Built on %s %s\n", __DATE__, __TIME__);
    exit(0);
}

static level_t s_get_level(const int level) {
    return (level_t)level;
}
