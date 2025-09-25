#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./functions.h"
#include <string.h>

enum{
    WRONG_ARGUMENTS,
    WRONG_FORMAT_NUMBER,
    ERROR
};

int main(int argc, char* argv[]){
    if(argc <= 2){
        printf("Wrong quantity arguments\n");
        return WRONG_ARGUMENTS;
    }
    if (strcmp(argv[1], "-q") == 0 || strcmp(argv[1], "/q") == 0){
        if(argc != 6){
            printf("Wrong quantity arguments\n");
            return WRONG_ARGUMENTS;
        }
        double eps;
        char *errorChar;
        eps = strtod(argv[2], &errorChar);
        if (eps < 0){
            printf( "Wrong EPS, can't be less than zero\n");
            return WRONG_ARGUMENTS;
        }

        double a;
        a = strtod(argv[3], &errorChar);
        double b;
        b = strtod(argv[4], &errorChar);
        double c;
        c = strtod(argv[5], &errorChar);
        if (*errorChar != '\0'){
            printf("Error in double format of EPS, A, B, C\n");
            return WRONG_FORMAT_NUMBER;
        }
        double result_1[3];
        double result_2[3];
        double result_3[3];
        double result_4[3];
        double result_5[3];
        double result_6[3];

        qFlagSolve(eps, a, b, c, result_1);
        qFlagSolve(eps, a, c, b, result_2);
        qFlagSolve(eps, b, a, c, result_3);
        qFlagSolve(eps, b, c, a, result_4);
        qFlagSolve(eps, c, a, b, result_5);
        qFlagSolve(eps, c, b, a, result_6);  

        printEquasion(eps, a, b, c, result_1);
        printEquasion(eps, a, c, b, result_2);
        printEquasion(eps, b, a, c, result_3);
        printEquasion(eps, b, c, a, result_4);
        printEquasion(eps, c, a, b, result_5);
        printEquasion(eps, c, b, a, result_6);  
    }
    else if (strcmp(argv[1], "-m") == 0 || strcmp(argv[1], "/m") == 0){
        if(argc != 4){
            printf("Wrong quantity arguments\n");
            return WRONG_ARGUMENTS;
        }
        int a1, b1, result;
        a1 = atoi(argv[2]);
        b1 = atoi(argv[3]);
        result = mFlag(a1, b1);
        if(result == 1){
            printf("%d is a multiple of %d\n", a1, b1);
        }
        else{
            printf("%d isn't a multiple of %d\n", a1, b1);
        }
    }
    else if (strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "/t") == 0){
        if(argc != 6){
            printf("Wrong quantity arguments\n");
            return WRONG_ARGUMENTS;
        }
        double eps;
        char *errorChar;
        eps = strtod(argv[2], &errorChar);
        if (eps < 0){
            printf( "Wrong EPS, can't be less than zero\n");
            return WRONG_ARGUMENTS;
        }

        double a;
        a = strtod(argv[3], &errorChar);
        double b;
        b = strtod(argv[4], &errorChar);
        double c;
        c = strtod(argv[5], &errorChar);
        if (*errorChar != '\0'){
            printf("Error in double format of EPS, A, B, C\n");
            return WRONG_FORMAT_NUMBER;
        }
        int result = tFlag(eps, a, b, c); 
        if (result == 1){
            printf("The sides %.3f %.3f %.3f are suitable for a right triangle.\n", a, b, c);
            printf("The accuracy is equal to epsilon = %.3f\n", eps);
        }
        else{
            printf("The sides %.3f %.3f %.3f are NOT suitable for a right triangle.\n", a, b, c);
            printf("The accuracy is equal to epsilon = %.3f\n", eps);
        }

    }
    return 0;
}