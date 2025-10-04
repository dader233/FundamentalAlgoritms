#include "./functions.h"

double trapezoidalIntegration(double (*func)(double), double eps) {
    double result = 0.0;
    double previous;
    int n = 2;
    double h;
    double x;
    
    do {
        previous = result;
        result = (func(0.0) + func(1.0)) / 2.0;
        h = 1.0 / n;
        
        for (int i = 1; i < n; i++) {
            x = i * h;
            result += func(x);
        }
        
        result *= h;
        n *= 2;
    } while (fabs(result - previous) > eps);
    
    return result;
}

double funcA(double x) {
    return (log(1 + x) / x);
}

double funcB(double x) {
    return exp(-pow(x, 2)/2.0);
}

double funcC(double x) {
    return log(1.0 / (1 - x));
}

double funcD(double x) {
    return pow(x, x);
}

