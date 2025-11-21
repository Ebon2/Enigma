//
// Created by angelrojas on 21/10/25.
//

#include "../include/core.h"
#include "../include/globals.h"
#include "../include/structures.h"
#include "../include/utils.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

static char s__ncrypt(char letter, char (*change)(char, const comb_t[]), char (*connection)(char, int));


/*======== ENCRYPT ========*/
static void s_lower_encrypt();
static void s_higher_encrypt();
static void s_extreme_encrypt();

static void s_add_level();
static void s_add_keys();

static char s_change_char(char letter, const comb_t barrel[]);
static char s_connection(char letter, int move);

/*======== DECRYPT ========*/
static void s_lower_decrypt();
static void s_higher_decrypt();
static void s_extreme_decrypt();

static void s_get_level();
static void s_get_keys();

static char s_unchange_char(char letter, const comb_t barrel[]);
static char s_inverse_connection(char letter, int move);


/*======== EXTERN FUNCTIONS ========*/

void encrypt() {
    s_add_level();

    switch (g_actual_level) {
        case LOW:
            s_lower_encrypt();
            break;
        case HIGH:
            s_higher_encrypt();
            break;
        case EXTREME:
            s_extreme_encrypt();
            break;

        default: ;
    }
}

void decrypt() {
    s_get_level();

    switch (g_actual_level) {
        case LOW:
            s_lower_decrypt();
            break;
        case HIGH:
            s_higher_decrypt();
            break;
        case EXTREME:
            s_extreme_decrypt();
            break;
        default: ;
    }
}

int check_barrels(){
    for (int i=0; i<3; i++)
        if (g_barrels_modifier[i]>26  || g_barrels_modifier[i]<1)
            return 0;

    return 1;
}

/*======== STATIC FUNCTIONS ========*/

static char s_change_char(const char letter, const comb_t barrel[]){
    int i=0;

    while (barrel[i].input != letter && barrel[i].input != ' ')
        i++;

    return barrel[i].output;
}

static char s_connection(char letter, const int move){
    if (letter == '\n' || letter == 0 || letter == 32)
        return letter;

    letter = (char)(letter + move);

    if (letter > 'Z')
        letter -= ALPHA_LEN-1;

    return letter;
}

static void s_add_keys() {
    for (int i=0; i<3; i++)
        fputc((char)(g_barrels_modifier[i]+64), g_output_file);
}


static char s_unchange_char(const char letter, const comb_t barrel[]){
    int i=0;

    while (barrel[i].output != letter && barrel[i].output != ' ')
        i++;

    return barrel[i].input;
}

static char s_inverse_connection(char letter, const int move){
    if (letter == '\n' || letter == 0 || letter == 32)
        return letter;

    letter = (char)(letter - move);

    if (letter < 'A')
        letter += ALPHA_LEN-1;

    return letter;
}

static void s_lower_encrypt() {
    s_add_keys();

    int c;
    while ((c = fgetc(g_input_file)) != EOF)
        fputc(s__ncrypt((char)toupper(c), s_change_char, s_connection), g_output_file);

    u_change_barrels();
}

static void s_higher_encrypt() {
    int c;
    do{
        s_add_keys();
        while ((c = fgetc(g_input_file)) != EOF) {
            fputc(s__ncrypt((char)toupper(c), s_change_char, s_connection), g_output_file);
            if (c == '\n')
                break;
        }

        u_change_barrels();
    }while (c != EOF);
}

static void s_extreme_encrypt() {
    int c;
    do{
        s_add_keys();
        while ((c = fgetc(g_input_file)) != EOF) {
            fputc(s__ncrypt((char)toupper(c), s_change_char, s_connection), g_output_file);
            if (isspace(c))
                break;
        }

        u_change_barrels();
    }while (c != EOF);
}

static void s_lower_decrypt() {
    s_get_keys();
    int c;
    while ((c = fgetc(g_input_file)) != EOF)
        fputc(s__ncrypt((char)toupper(c), s_unchange_char, s_inverse_connection), g_output_file);
}

static void s_higher_decrypt() {
    int c;
    do{
        s_get_keys();

        while ((c = fgetc(g_input_file)) != EOF) {
            fputc(s__ncrypt((char)toupper(c), s_unchange_char, s_inverse_connection), g_output_file);

            if (c == '\n')
                break;
        }
    } while (c != EOF);
}

static void s_extreme_decrypt() {
    int c;
    do{
        s_get_keys();

        while ((c = fgetc(g_input_file)) != EOF) {
            fputc(s__ncrypt((char)toupper(c), s_unchange_char, s_inverse_connection), g_output_file);

            if (isspace(c))
                break;
        }
    } while (c != EOF);
}

static void s_add_level() {
    switch (g_actual_level) {
        case LOW:
            fputs("LW", g_output_file);
            break;
        case HIGH:
            fputs("HW", g_output_file);
            break;
        case EXTREME:
            fputs("EX", g_output_file);
            break;
        default: ;
    }
}

static void s_get_level() {
    char level[2];

    level[0] = (char)fgetc(g_input_file);
    level[1] = (char)fgetc(g_input_file);

    if (strcmp(level, "LW") == 0) g_actual_level = LOW;
    if (strcmp(level, "HW") == 0) g_actual_level = HIGH;
    if (strcmp(level, "EX") == 0) g_actual_level = EXTREME;

}

static void s_get_keys() {
    for (int i=0; i<3; i++)
        g_barrels_modifier[i] = fgetc(g_input_file) - 64;
}

char s__ncrypt(char letter, char (*change)(char, const comb_t[]), char (*connection)(char, int)) {
    if (!isalpha(letter))
        return letter;

    int i;
    for (i=0; i<3; i++) {
        letter = change(letter, g_barrels[i]);
        letter = connection(letter, g_barrels_modifier[i]);
    }

    letter = change(letter, g_barrels[3]);

    for (i=2; i>=0; i--) {
        letter = change(letter, g_barrels[i]);
        letter = connection(letter, g_barrels_modifier[i]);
    }

    return letter;
}