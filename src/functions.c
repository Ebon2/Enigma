//
// Created by angelrojas on 21/10/25.
//

#include "../imports/functions.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "../imports/barrels.h"
#include "../imports/defines.h"
#include "../imports/structures.h"

inline char changeChar(const char letter, const Comb barrel[]){
    int i=0;

    while (barrel[i].input != letter && barrel[i].input != ' ')
        i++;

    return barrel[i].output;
}

inline char unchangeChar(const char letter, const Comb barrel[]){
    int i=0;

    while (barrel[i].output != letter && barrel[i].output != ' ')
        i++;

    return barrel[i].input;
}


inline char conection(char letter, const int move){
    if (letter == '\n' || letter == 0 || letter == 32)
        return letter;

    letter = (char)(letter + move);

    if (letter > 'Z')
        letter -= 26;

    return letter;
}

inline char inverseConection(char letter, const int move){
    if (letter == '\n' || letter == 0 || letter == 32)
        return letter;

    letter = (char)(letter - move);

    if (letter < 'A')
        letter += 26;

    return letter;
}


inline void encripter(char work[], const int len){
    for(int i=0; i<len; i++){
        if (work[i] == '\0' || work[i] == '\n') break;

        work[i] = changeChar(work[i], barrelA);
        work[i] = conection(work[i], BARREL_A);

        work[i] = changeChar(work[i], barrelB);
        work[i] = conection(work[i], BARREL_B);

        work[i] = changeChar(work[i], barrelC);
        work[i] = conection(work[i], BARREL_C);

        work[i] = changeChar(work[i], reflector);

        work[i] = conection(work[i], BARREL_C);
        work[i] = changeChar(work[i], barrelC);

        work[i] = conection(work[i], BARREL_B);
        work[i] = changeChar(work[i], barrelB);

        work[i] = conection(work[i], BARREL_A);
        work[i] = changeChar(work[i], barrelA);
    }
    addKeys(work);
}

inline void addKeys(char work[]) {
    char aux[2];
    aux[1] = '\0';

    aux[0] = (char)(BARREL_A+64);
    strcat(work, aux);

    aux[0] = (char)(BARREL_B+64);
    strcat(work, aux);

    aux[0] = (char)(BARREL_C+64);
    strcat(work, aux);
}

int* getKeys(char work[], const int len) {
    static int keys[3];

    keys[2] = (int)work[len+2] - 64;
    work[len+2] = '\0';

    keys[1] = (int)work[len+1] - 64;
    work[len+1] = '\0';

    keys[0] = (int)work[len] - 64;
    work[len] = '\0';

    return keys;
}

inline void uncripter(char work[], int len){
    int *keys = getKeys(work, len);

    for(int i=0; i<len; i++){
        if (work[i] == '\0' || work[i] == '\n') break;

        work[i] = unchangeChar(work[i], barrelA);
        work[i] = inverseConection(work[i], keys[0]);
        work[i] = unchangeChar(work[i], barrelB);

        work[i] = inverseConection(work[i], keys[1]);
        work[i] = unchangeChar(work[i], barrelC);

        work[i] = inverseConection(work[i], keys[2]);
        work[i] = unchangeChar(work[i], reflector);

        work[i] = inverseConection(work[i], keys[2]);
        work[i] = unchangeChar(work[i], barrelC);

        work[i] = inverseConection(work[i], keys[1]);
        work[i] = unchangeChar(work[i], barrelB);

        work[i] = inverseConection(work[i], keys[0]);
        work[i] = unchangeChar(work[i], barrelA);
    }
}


inline void upper(char arr[]){
    for(int i=0; arr[i]!='\0'; i++)
        arr[i] = (char)toupper(arr[i]);
}

int comproveBarrels(){
    int aux = 1;

    if(BARREL_A>26||BARREL_A<1){
        printf("BARREL_A mal configurado");
        aux = 0;
    }

    if(BARREL_B>26||BARREL_B<1){
        printf("BARREL_B mal configurado");
        aux = 0;
    }

    if(BARREL_C>26||BARREL_C<1){
        printf("BARREL_C mal configurado");
        aux = 0;
    }

    return aux;
}