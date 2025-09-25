#include "./functions.h"


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

int mFlag(int a, int b){
    if(a % b == 0){
        return 1;
    }
    else{
        return 0;
    }
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

