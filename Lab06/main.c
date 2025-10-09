#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./functions.h"
#include <string.h>



int main(int argc, char * argv[]){

    if (argc != 2){
        printf("WRONG ARGUMENTS. usage: ./main.out [eps]\n");
        return WRONG_ARGUMENTS;
    }
    double eps;
    char * errorChar;    
    eps = strtod(argv[1], &errorChar);
    if (eps < 0){
        printf("Wrong EPS, can't be less than zero\n");
        return WRONG_ARGUMENTS;
    }
    printf("Epsilon = %.6f\n", eps);
    printf("Result for ex. a: %.4f\n", trapezoidalIntegration(funcA, eps));
    printf("Result for ex. b: %.4f\n", trapezoidalIntegration(funcB, eps));
    printf("Result for ex. c: %.4f\n", trapezoidalIntegration(funcC, eps));
    printf("Result for ex. d: %.4f\n", trapezoidalIntegration(funcD, eps));
    
    

}