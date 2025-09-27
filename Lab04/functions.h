#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

double eLim(const double precision);
double eRyad(const double precision);
double eEquation(const double precision);
double piLim(const double precision);
double piRyad(const double precision);
double piEquation(const double precision);
double ln2Lim(const double precision);
double ln2Ryad(const double precision);
double ln2Equasion(const double precision);
double sqrLim(const double precision);
double sqrProizv(const double precision);
double sqrEquasion(const double precision);
double yLim(const double precision);
double yRyad(const double precision);
double yEquasion(const double precision);

void eratosfen(int arrayPrime[], int maxNumber);
#endif