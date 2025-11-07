//
// Created by angelrojas on 21/10/25.
//

#ifndef structures_H
#define structures_H

typedef enum {
    ENCRYPT,
    DECRYPT,
} mod_t;

typedef enum {
    NONE = -1,
    LOW = 1,
    HIGH = 2,
    EXTREME = 3,
} level_t;

typedef struct {
    char input;
    char output;
} comb_t;

typedef struct {
    int input;
    int output;
} int_comb_t;

#endif
