#ifndef FUNC_H
#define FUNC_H

#include <stdbool.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

typedef enum{
    Finite,
    Infinite,
    InvalidBase,
    InvalidArgument,
    Success,
    MemoryAllocationError
} ReprStat;

ReprStat checker(double fraction, int base);
int gcd (int a, int b);
const char* reprString(ReprStat Status);
ReprStat checkFractions(ReprStat* results, int base, int count, ...);
bool primeDividers(int number, int base);

#endif