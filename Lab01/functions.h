#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdbool.h>

int strInt(char *number);

bool numbFormat(char *number);

int hFlag(int* resultArray, const int number);
int pFlag(const int number);
int sFlag(char* resultArray, const int number);
void eFlag(long long **resultArray, const int number);
long long aFlag(const int number);
long long fFlag(const int number);
#endif