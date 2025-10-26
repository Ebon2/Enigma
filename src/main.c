//
// Created by angelrojas on 21/10/25.
//

#include "../imports/defines.h"
#include "../imports/functions.h"

#include <stdio.h>
#include <string.h>


int main() {
    char work[MAXCHAR];
    char encriptedWork[MAXCHAR];
    char uncriptedWork[MAXCHAR];

    // ReSharper disable once CppDFAConstantConditions
    if (!comproveBarrels())
        return 1;

    printf("Enter the work: ");
    fgets(work, MAXCHAR, stdin);
    work[strlen(work) - 1] = '\0';

    const int len = (int) strlen(work);

    upper(work);

    strcpy(encriptedWork, work);
    encripter(encriptedWork, len);

    strcpy(uncriptedWork, encriptedWork);
    uncripter(uncriptedWork, len);

    printf("Encripted work: %s\n", encriptedWork);
    printf("Normal work: %s", uncriptedWork);

    return 0;
}
