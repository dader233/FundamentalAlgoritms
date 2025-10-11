#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>

enum{
    WRONG_NUMBER_FORMAT,
    MALLOC_FAULT,
    WRONG_NUMBER_SIZE,
    FLAG_ERROR
};

int strInt(char *number);
bool numbFormat(char *number);
int hFlag(int* resultArray, const int number);
int pFlag(const int number);
int sFlag(char* resultArray, const int number);
void eFlag(long long **resultArray, const int number);
long long aFlag(const int number);
long long fFlag(const int number);
int hFlagHandle(const int number);
int pFlagHandle(const int number);
int sFlagHandle(const int number);
int eFlagHandle(const int number);
int aFlagHandle(const int number);
int fFlagHandle(const int number);
int parseFlag(char* flag);

#endif