//
// Created by angelrojas on 21/10/25.

#include "../include/core.h"
#include "../include/globals.h"
#include "../include/structures.h"
#include "../include/utils.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>


/*======== MASTER FUNCTION ========*/
static char s__crypt(char letter, char (*change)(char, const comb_t[]), char (*connection)(char, int));

/*======== ENCRYPT ========*/
static void s_lower_encrypt(); /**< Encrypt using lower level */
static void s_higher_encrypt(); /**< Encrypt using higher level */
static void s_extreme_encrypt(); /**< Encrypt using extreme level */

/*======== DECRYPT ========*/
static void s_lower_decrypt(); /**< Decrypt using lower level */
static void s_higher_decrypt(); /**< Decrypt using higher level */
static void s_extreme_decrypt(); /**< Decrypt using extreme level */

/*======== KEYS ========*/
static void s_add_keys(); /**< Add keys to the rotor */
static void s_get_keys(); /**< Get keys from the rotor */

/*======== LEVEL ========*/
static void s_add_level(); /**< Add level to the rotor */
static void s_get_level(); /**< Get level from the rotor */

/*======== CHANGE ========*/
static char s_change_char(char letter, const comb_t rotor[]); /**< Change character representation */
static char s_unchange_char(char letter, const comb_t rotor[]); /**< Change character representation */

/*======== CONNECTORS ========*/
static char s_connection(char letter, int move); /**< Connect character with rotor */
static char s_inverse_connection(char letter, int move); /**< Connect character with rotor */


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

/*======== STATIC FUNCTIONS ========*/

/*======== MASTER FUNCTION ========*/
char s__crypt(char letter, char (*change)(char, const comb_t[]), char (*connection)(char, int)) {
    if (!isalpha(letter))
        return letter;

    int i;
    for (i=0; i<MAX_ROTORS-1; i++) {
        letter = change(letter, g_rotors[i]);
        letter = connection(letter, g_rotors_modifier[i]);
    }

    letter = change(letter, g_rotors[MAX_ROTORS-1]);

    for (i=MAX_ROTORS-2; i>=0; i--) {
        letter = connection(letter, g_rotors_modifier[i]);
        letter = change(letter, g_rotors[i]);
    }

    return letter;
}

/*======== ENCRYPT ========*/
static void s_lower_encrypt() {
    s_add_keys();

    int c;
    while ((c = fgetc(g_input_file)) != EOF)
        fputc(s__crypt((char)toupper(c), s_change_char, s_connection), g_output_file);

    u_change_rotors();
}

static void s_higher_encrypt() {
    int c;
    do{
        s_add_keys();
        while ((c = fgetc(g_input_file)) != EOF) {
            fputc(s__crypt((char)toupper(c), s_change_char, s_connection), g_output_file);
            if (c == '\n')
                break;
        }

        u_change_rotors();
    }while (c != EOF);
}

static void s_extreme_encrypt() {
    int c;
    do{
        s_add_keys();
        while ((c = fgetc(g_input_file)) != EOF) {
            fputc(s__crypt((char)toupper(c), s_change_char, s_connection), g_output_file);
            if (isspace(c))
                break;
        }

        u_change_rotors();
    }while (c != EOF);
}

/*======== DECRYPT ========*/
static void s_lower_decrypt() {
    s_get_keys();
    int c;
    while ((c = fgetc(g_input_file)) != EOF)
        fputc(s__crypt((char)toupper(c), s_unchange_char, s_inverse_connection), g_output_file);
}

static void s_higher_decrypt() {
    int c;
    do{
        s_get_keys();

        while ((c = fgetc(g_input_file)) != EOF) {
            fputc(s__crypt((char)toupper(c), s_unchange_char, s_inverse_connection), g_output_file);

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
            fputc(s__crypt((char)toupper(c), s_unchange_char, s_inverse_connection), g_output_file);

            if (isspace(c))
                break;
        }
    } while (c != EOF);
}

/*======== KEYS ========*/
static void s_add_keys() {
    for (int i=0; i<MAX_ROTORS-1; i++)
        fputc((char)(g_rotors_modifier[i]+64), g_output_file);
}

static void s_get_keys() {
    for (int i=0; i<MAX_ROTORS-1; i++)
        g_rotors_modifier[i] = fgetc(g_input_file) - 64;
}

/*======== LEVEL ========*/
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
    else if (strcmp(level, "HW") == 0) g_actual_level = HIGH;
    else if (strcmp(level, "EX") == 0) g_actual_level = EXTREME;
}

/*======== CHANGE ========*/
static char s_change_char(const char letter, const comb_t rotor[]){
    int i=0;

    while (rotor[i].input != letter && rotor[i].input != ' ')
        i++;

    return rotor[i].output;
}

static char s_unchange_char(const char letter, const comb_t rotor[]){
    int i=0;

    while (rotor[i].output != letter && rotor[i].output != ' ')
        i++;

    return rotor[i].input;
}

/*======== CONNECTORS ========*/
static char s_connection(char letter, const int move){
    if (!isalpha(letter))
        return letter;

    letter = (char)(letter + move);

    if (letter > 'Z')
        letter -= ALPHA_LEN-1;

    return letter;
}

static char s_inverse_connection(char letter, const int move){
    if (!isalpha(letter))
        return letter;

    letter = (char)(letter - move);

    if (letter < 'A')
        letter += ALPHA_LEN-1;

    return letter;
}