#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void qFlagSolve(double eps, double a, double b, double c, double result[2]);
void printEquasion(double eps, double a, double b, double c, double result[3]);
int mFlag(int a, int b);
int tFlag(double eps, double a, double b, double c);

#endif