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
    WRONG_FORMAT_NUMBER,
    WRONG_FLAG
};

double trapezoidalIntegration(double (*func)(double), double eps);
double funcA(double x);
double funcB(double x);
double funcC(double x);
double funcD(double x);

#endif