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

static void s_lower_encrypt();
static void s_higher_encrypt();
static void s_extreme_encrypt();

static void s_lower_decrypt();
static void s_higher_decrypt();
static void s_extreme_decrypt();

static void s_add_level();
static void s_add_keys();

static void s_get_level();
static void s_get_keys();

static char s_encrypter(char letter);
static char s_decripter(char letter);
static char s_change_char(char, const comb_t[]);
static char s_unchange_char(char, const comb_t[]);
static char s_conection(char, int);
static char s_inverse_conection(char, int);


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

char s_encrypter(char letter){
    if (!isalpha(letter)) return letter;

    letter = s_change_char(letter, g_barrel_a);
    letter = s_conection(letter, g_barrel_a_modifier);

    letter = s_change_char(letter, g_barrel_b);
    letter = s_conection(letter, g_barrel_b_modifier);

    letter = s_change_char(letter, g_barrel_c);
    letter = s_conection(letter, g_barrel_c_modifier);

    letter = s_change_char(letter, g_reflector);

    letter = s_conection(letter, g_barrel_c_modifier);
    letter = s_change_char(letter, g_barrel_c);

    letter = s_conection(letter, g_barrel_b_modifier);
    letter = s_change_char(letter, g_barrel_b);

    letter = s_conection(letter, g_barrel_a_modifier);
    letter = s_change_char(letter, g_barrel_a);

    return letter;
}

char s_change_char(const char letter, const comb_t barrel[]){
    int i=0;

    while (barrel[i].input != letter && barrel[i].input != ' ')
        i++;

    return barrel[i].output;
}


char s_unchange_char(const char letter, const comb_t barrel[]){
    int i=0;

    while (barrel[i].output != letter && barrel[i].output != ' ')
        i++;

    return barrel[i].input;
}

char s_conection(char letter, const int move){
    if (letter == '\n' || letter == 0 || letter == 32)
        return letter;

    letter = (char)(letter + move);

    if (letter > 'Z')
        letter -= ALPHA_LEN-1;

    return letter;
}

char s_inverse_conection(char letter, const int move){
    if (letter == '\n' || letter == 0 || letter == 32)
        return letter;

    letter = (char)(letter - move);

    if (letter < 'A')
        letter += ALPHA_LEN-1;

    return letter;
}

void s_add_keys() {
    fputc((char)(g_barrel_a_modifier+64), g_output_file);
    fputc((char)(g_barrel_b_modifier+64), g_output_file);
    fputc((char)(g_barrel_c_modifier+64), g_output_file);
}

char s_decripter(char letter){
    if (!isalpha(letter)) return letter;

    letter = s_unchange_char(letter, g_barrel_a);
    letter = s_inverse_conection(letter, g_barrel_a_modifier);

    letter = s_unchange_char(letter, g_barrel_b);
    letter = s_inverse_conection(letter, g_barrel_b_modifier);

    letter = s_unchange_char(letter, g_barrel_c);
    letter = s_inverse_conection(letter, g_barrel_c_modifier);

    letter = s_change_char(letter, g_reflector);

    letter = s_inverse_conection(letter, g_barrel_c_modifier);
    letter = s_unchange_char(letter, g_barrel_c);

    letter = s_inverse_conection(letter, g_barrel_b_modifier);
    letter = s_unchange_char(letter, g_barrel_b);

    letter = s_inverse_conection(letter, g_barrel_a_modifier);
    letter = s_unchange_char(letter, g_barrel_a);

    return letter;
}

void upper(char arr[]){
    for(int i=0; arr[i]!='\0'; i++)
        arr[i] = (char)toupper(arr[i]);
}

int comprove_barrels(){
    int aux = 1;

    if(g_barrel_a_modifier > 26 || g_barrel_a_modifier < 1){
        printf("BARREL_A mal configurado");
        aux = 0;
    }

    if(g_barrel_b_modifier > 26 || g_barrel_b_modifier < 1){
        printf("BARREL_B mal configurado");
        aux = 0;
    }

    if(g_barrel_c_modifier > 26 || g_barrel_c_modifier < 1){
        printf("BARREL_C mal configurado");
        aux = 0;
    }

    return aux;
}

void s_lower_encrypt() {
    s_add_keys();

    int c;
    while ((c = fgetc(g_file)) != EOF)
        fputc(s_encrypter((char)toupper(c)), g_output_file);

    u_change_barrels();
}

void s_higher_encrypt() {
    int c;
    do{
        s_add_keys();
        while ((c = fgetc(g_file)) != EOF) {
            fputc(s_encrypter((char)toupper(c)), g_output_file);
            if (c == '\n')
                break;
        }

        u_change_barrels();
    }while (c != EOF);
}

void s_extreme_encrypt() {
    int c;
    do{
        s_add_keys();
        while ((c = fgetc(g_file)) != EOF) {
            fputc(s_encrypter((char)toupper(c)), g_output_file);
            if (isspace(c))
                break;
        }

        u_change_barrels();
    }while (c != EOF);
}

void s_lower_decrypt() {
    s_get_keys();
    int c;
    while ((c = fgetc(g_file)) != EOF)
        fputc(s_decripter((char)toupper(c)), g_output_file);
}

void s_higher_decrypt() {
    int c;
    do{
        s_get_keys();

        while ((c = fgetc(g_file)) != EOF) {
            fputc(s_decripter((char)toupper(c)), g_output_file);

            if (c == '\n')
                break;
        }
    } while (c != EOF);
}

void s_extreme_decrypt() {
    int c;
    do{
        s_get_keys();

        while ((c = fgetc(g_file)) != EOF) {
            fputc(s_decripter((char)toupper(c)), g_output_file);

            if (isspace(c))
                break;
        }
    } while (c != EOF);
}

void s_add_level() {
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

void s_get_level() {
    char level[2];

    level[0] = (char)fgetc(g_file);
    level[1] = (char)fgetc(g_file);

    if (strcmp(level, "LW") == 0) g_actual_level = LOW;
    if (strcmp(level, "HW") == 0) g_actual_level = HIGH;
    if (strcmp(level, "EX") == 0) g_actual_level = EXTREME;

}

void s_get_keys() {
    g_barrel_a_modifier = fgetc(g_file) - 64;
    g_barrel_b_modifier = fgetc(g_file) - 64;
    g_barrel_c_modifier = fgetc(g_file) - 64;
}
