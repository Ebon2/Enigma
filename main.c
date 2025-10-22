//
// Created by angelrojas on 21/10/25.
//

#include "constans/defines.h"
#include "constans/functions.h"

#include <stdio.h>
#include <string.h>


int main() {
    char work[MAXCHAR];
    char encriptedWork[MAXCHAR];
    char uncriptedWork[MAXCHAR];

    // ReSharper disable once CppDFAConstantConditions
    if (!comproveBarrels())
        return 0;

    printf("Enter the work: ");
    fgets(work, MAXCHAR, stdin);

    const int len = (int) strlen(work);

    upper(work);

    strcpy(encriptedWork, work);
    encripter(encriptedWork, len);

    strcpy(uncriptedWork, encriptedWork);
    uncripter(uncriptedWork, len);

    printf("Encripted work: %skey: %d-%d-%d\n", encriptedWork, BARREL_A, BARREL_B, BARREL_C);
    printf("Normal work: %s", uncriptedWork);

    return 0;
}
