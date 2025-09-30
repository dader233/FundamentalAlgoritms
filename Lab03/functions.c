#include "./functions.h"

int parseFlag(char* flag){
    if (strcmp(flag, "-q") == 0 || strcmp(flag, "/q") == 0){
        return 1;
    }
    else if (strcmp(flag, "-m") == 0 || strcmp(flag, "/m") == 0){
        return 2;
    }
    else if (strcmp(flag, "-t") == 0 || strcmp(flag, "/t") == 0){
        return 3;
    }
    else{
        return 0;
    }
}

int strInt(char *number){
    bool negative = false;
    int value = 0;
    if (*number == '-'){
        if (!negative){
            negative = true;
            ++number;
        }
        else{
            return 0;
        }
    }
    while(*number){
        value = value * 10 + (*number - '0');
        ++number;
    }
    if (negative){
        value *= -1;
    }

    return value;

}
bool numbFormat(char *number){
    if (*number == '-'){
        ++number;
    }
    while (*number){
        if (!((*number >= '0') && (*number <='9'))){
            return false;
        }
        ++number;
    }
    return true;
}

int qFlagHandle(int argc, char* argv[]){
    if(argc != 6){
        printf("Wrong quantity arguments\n");
        return WRONG_ARGUMENTS;
    }
    
    double eps, a, b, c;
    if(parseArguments(argc, argv, &eps, &a, &b, &c) != SUCCESS){
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
    
    return SUCCESS;
}

void qFlagSolve(double eps, double a, double b, double c, double result[3]){
    double d;
    if(fabs(a) < eps){
        //Линейный
        if (fabs(b) < eps){
            //Вырожденные
            if(fabs(c) < eps){
                result[0] = INFINITY;
                result[1] = INFINITY;
                result[2] = INFINITY;
            }
            else{
                result[0] = 0;
                result[1] = NAN;
                result[2] = NAN;
            }
        }
        else{
            //bx + c = 0
            result[0] = 1;
            result[1] = -c / b;
            result[2] = NAN;
        }
    }
    else{
        d = b * b - 4 * a * c;
        if(fabs(d) < eps){
            result[0] = 1;
            result[1] = -b / (2 * a);
            result[2] = NAN;
        }
        else if(d > eps){
            result[0] = 2;
            result[1] = (-b + sqrt(d)) / (2 * a);
            result[2] = (-b - sqrt(d)) / (2 * a);
        }
        else{
            result[0] = 0;
            result[1] = NAN;
            result[2] = NAN;
        }
    }
}
void printEquasion(double eps, double a, double b, double c, double result[3]){
    printf("Equasion: (%.4f)x^2 + (%.4f)x + (%.4f) = 0, eps = %.4f\n", a, b, c, eps);
    printf("Solutions: count=%.0f, x1=%.4f, x2=%.4f\n\n", result[0], result[1], result[2]);
}

int mFlagHandle(int argc, char* argv[]){
    if(argc != 4){
        printf("Wrong quantity arguments\n");
        return WRONG_ARGUMENTS;
    }
    
    int a1, b1, result;
    for(int i = 2; i < 4; i++){
        if (!numbFormat(argv[i])){
            printf("WRONG FORMAT NUMBER\n");
            return WRONG_FORMAT_NUMBER;
        }
    }
    a1 = strInt(argv[2]);
    b1 = strInt(argv[3]);
    result = mFlag(a1, b1);
    
    if(result == 1){
        printf("%d is a multiple of %d\n", a1, b1);
    }
    else if(result == 0){
        printf("%d isn't a multiple of %d\n", a1, b1);
    }
    else{
        printf("Division by zero.\n");
    }
    
    return SUCCESS;
}

int mFlag(int a, int b){
    if (b == 0){
        return -1;
    }
    if(a % b == 0){
        return 1;
    }
    else{
        return 0;
    }
}
int tFlagHandle(int argc, char* argv[]){
    if(argc != 6){
        printf("Wrong quantity arguments\n");
        return WRONG_ARGUMENTS;
    }
    
    double eps, a, b, c;
    if(parseArguments(argc, argv, &eps, &a, &b, &c) != SUCCESS){
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
    
    return SUCCESS;
}

int tFlag(double eps, double a, double b, double c){
    if(fabs(a) < eps || fabs(b) < eps || fabs(c) < eps){
        return -1;
    }
    else if( a > eps && b > eps && c > eps){
        if(fabs(c * c - (a*a + b*b)) < eps || fabs(b * b - (a*a + c*c)) < eps || fabs(a * a - (c*c + b*b)) < eps){
            return 1;
        }
    }
    return -1;
}

int parseArguments(int argc, char* argv[], double* eps, double* a, double* b, double* c){
    char *errorChar;
    *eps = strtod(argv[2], &errorChar);
    if (*eps < 0){
        printf("Wrong EPS, can't be less than zero\n");
        return WRONG_ARGUMENTS;
    }

    *a = strtod(argv[3], &errorChar);
    *b = strtod(argv[4], &errorChar);
    *c = strtod(argv[5], &errorChar);
    
    if (*errorChar != '\0'){
        printf("Error in double format of EPS, A, B, C\n");
        return WRONG_FORMAT_NUMBER;
    }
    
    return SUCCESS;
}