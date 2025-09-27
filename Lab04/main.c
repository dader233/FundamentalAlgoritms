#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./functions.h"
#include <string.h>

enum{
    SUCCESS,
    WRONG_FORMAT_NUMBER,
    WRONG_ARGUMENTS
};

int main(){
    const double precision = 0.0000001;
    double e1;
    double e2;
    double e3;
    double pi1;
    double pi2;
    double pi3;
    double ln1;
    double ln2;
    double ln3;
    double sqr1;
    double sqr2;
    double sqr3;
    double y1;
    double y2;
    double y3;
    e1 = eRyad(precision); //точность достигается только от precision = 1 * 10^-9
    e2 = eLim(precision);
    e3 = eEquation(precision);
    pi1 = piLim(precision);
    pi2 = piRyad(precision);
    pi3 = piEquation(precision);
    ln1 = ln2Lim(precision);
    ln2 = ln2Ryad(precision);
    ln3 = ln2Equasion(precision);
    sqr1 = sqrLim(precision);
    sqr2 = sqrProizv(precision);
    sqr3 = sqrEquasion(precision);
    y1 = yLim(precision);
    y2 = yRyad(precision);
    y3 = yEquasion(precision);
    printf("Epsilon = %.7f \n", precision);
    printf("Exponent with limit: %.4f\n", e1);
    printf("Exponent with ryad: %.4f\n", e2);
    printf("Exponent with equation: %.4f\n", e3);
    printf("Pi with limit: %.4f\n", pi1);
    printf("Pi with ryad: %.4f\n", pi2);
    printf("Pi with equation: %.4f\n", pi3);
    printf("LN2 with limit:%.4f\n", ln1);
    printf("LN2 with ryad: %.4f\n", ln2);
    printf("LN2 with equation: %.4f\n", ln3);
    printf("sqrt2 with limit: %.4f\n", sqr1);
    printf("sqrt2 with ryad: %.4f\n", sqr2);
    printf("sqrt2 with equation %.4f\n", sqr3);
    printf("gamma with limit: %.4f\n", y1);
    printf("gamma wirh ryad: %.4f\n", y2);
    printf("gamma with equation: %.4f\n", y3);
    return SUCCESS;
}

