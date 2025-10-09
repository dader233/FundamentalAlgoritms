#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum ErrorCodes {
    MALLOC_ERROR = -1,
    WRONG_NUMBER_FORMAT = -2,
    WRONG_NUMBER_SIZE = -3,
    WRONG_ARGUMENTS = -4,
    ERROR_FILE = -5
};

void removeZeros(char* input, char* output);
long long anyToDes(char *word, int length, int sysCalc, long long *result);
void printNumber(char *number, int length);
char* decToAny(long long num, int base);

#endif