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

int parseFlag(char* flag);
int strInt(char *number);
bool numbFormat(char *number);
int qFlagHandle(int argc, char* argv[]);
void qFlagSolve(double eps, double a, double b, double c, double result[3]);
void printEquasion(double eps, double a, double b, double c, double result[3]);
int mFlagHandle(int argc, char* argv[]);
int mFlag(int a, int b);
int tFlagHandle(int argc, char* argv[]);
int tFlag(double eps, double a, double b, double c);
int parseArguments(int argc, char* argv[], double* eps, double* a, double* b, double* c);

#endif