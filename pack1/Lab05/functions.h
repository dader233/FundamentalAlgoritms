#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

enum{
    SUCCESS,
    WRONG_ARGUMENTS,
    MALLOC_FAULT,
    WRONG_NUMBER_SIZE,
    ERROR_FILE,
    FLAG_ERROR
};

void dFlag(FILE* fileInput, FILE* fileOutput);
void iFlag(FILE* fileInput, FILE* fileOutput);
void sFlag(FILE* fileInput, FILE* fileOutput);
void aFlag(FILE* fileInput, FILE* fileOutput);
int asciiHex (int ascii, char * array, int maxSize);

#endif