#include "./functions.h"


double eLim(const double precision){
    double previous = 0;
    double current = 0;
    int n = 1;

    do{
        previous = current;
        current = pow(1.0 + 1.0/n, n);
        n++;
    } while(fabs(current - previous) > precision);

    return current;
}

double eRyad(const double precision){
    double summa = 1.0; 
    double previous = 0.0;
    double factorial = 1;
    int n = 1;
    do{
        factorial *= n;
        previous = summa;
        summa += (1.0 / factorial);
        n++;
    } while(fabs(summa - previous) > precision);
    return summa;
}

double eEquation(const double precision){
    double result = 0.0;
    double lSide = 2.0;
    double rSide = 3.0;
    while (fabs(log(result) - 1) > precision){
        result = (lSide + rSide) / 2.0;
        if (log(result) - 1 > 0){
            rSide = result;
        }
        else{
            lSide = result;
        }
    }
    return result;
}

double piLim(const double precision){
    double previous = 0;
    double current = 0;
    int n = 1;
    double factorialN = 1;
    double factorial2N = 1;
    do{
        previous = current;
        factorialN *= n;
        factorial2N *= (2*n - 1) * (2 * n);
        current = pow(pow(2.0, n) * factorialN, 4) / (n * pow(factorial2N, 2));
        n+=1;
        if (n == 20){ 
            break;
        }
    } while(fabs(current - previous) > precision);

    return current;
}

double piRyad(const double precision){
    double summa = 0.0; 
    double previous = 0.0;
    int n = 1;
    do{
        previous = summa;
        summa += (pow(-1, n - 1)) / (2 * n - 1);
        n++;
    } while(fabs(summa - previous) > precision);
    return 4 * summa;
}

double piEquation(const double precision){
    double result = 3.0;
    double temp;
    while(true){
        temp = result - (cos(result) + 1) / (-1 *sin(result));
        if(fabs(temp - result) < precision){
            break;
        }
        result = temp;
    }
    
    return result;
}

double ln2Lim(const double precision){
    double previous = 0;
    double current = 0;
    int n = 1;

    do{
        previous = current;
        current = n * (pow(2, 1.0/n) - 1);
        n++;
    } while(fabs(current - previous) > precision);

    return current;
}
double ln2Ryad(const double precision){
    double summa = 0.0;
    double previous = 0.0;
    int n = 1;
    do{
        previous = summa;
        summa += pow(-1.0, n - 1.0) / n;
        n++;
    } while(fabs(summa - previous) > precision);
    return summa;
} 

double ln2Equasion(const double precision){
    double result = 0.0;
    double lSide = 0.0;
    double rSide = 1.0;
    while (fabs(result - log(2)) > precision){
        result = (lSide + rSide) / 2.0;
        if (result - log(2) > 0){
            rSide = result;
        }
        else{
            lSide = result;
        }
    }
    return result;
}
double sqrLim(const double precision){
    double previous = -0.5;
    double current = -0.5;
    
    do{
        previous = current;
        current = previous - pow(previous, 2) / 2 + 1;
        
    } while(fabs(current - previous) > precision);
    
    return current;    
}

double sqrProizv(const double precision){
    double previous = 1;
    double proizv = 1;
    int k = 2;
    do{
        previous = proizv;
        proizv *= pow(2,pow(2, -k));
        k++;
        
    } while(fabs(proizv - previous) > precision);
    
    return proizv;
}

double sqrEquasion(const double precision){
    double result = 0.0;
    double lSide = 1.0;
    double rSide = 2.0;
    while (fabs(pow(result,2) - 2) > precision){
        result = (lSide + rSide) / 2.0;
        if (pow(result,2) - 2 > 0){
            rSide = result;
        }
        else{
            lSide = result;
        }
    }
    return result;
}

double factorial(double n) {
    double result = 1.0;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}



double yLim(const double precision){
    double previous = 0.0;
    double current = 0.0;
    int m = 2;
    double term;
    

    do {
        if (m > 40){
            break;
        }
        previous = current;
        current = 0.0;
    
        
        for (double k = 1.0; k <= m; k++) {
            double cmk = factorial(m) / (factorial(k) * factorial(m-k));
            double term = cmk * (pow(-1.0, k) / k) * log(factorial(k));
            current += term;
        }
        
        m++;
        
    } while(fabs(current - previous) > precision);
    
    return current;
}

double yRyad(const double precision){
    double summa_1 = -1 * pow(M_PI, 2) / 6.0;
    double previous = 0.0;
    double prevprev = 0.0;
    int k = 2;
    double summa_2 = 0.0;
    int denominator;
    do{ 
        prevprev = previous;
        previous = summa_2;
        denominator = (int)sqrt(k);
        denominator *= denominator;
        summa_2 += 1.0 /denominator - 1.0/k;
        k++;
    } while(fabs(summa_2 - previous) >= precision || fabs(prevprev - previous) >= precision );
    return summa_1 + summa_2;
} 

void eratosfen(int arrayPrime[], int maxNumber){
    for (int i = 2; i < maxNumber; i++) {
        arrayPrime[i] = 1;
    }
    for (int i = 2; i * i < maxNumber; i++){
        if(arrayPrime[i] == 1){
            for (int k = i * i; k < maxNumber; k+=i){
                arrayPrime[k] = 0;
            }
        }
    }
}

double yEquasion(const double precision){
    double result = 0;
    double lSide = 0.0;
    double rSide = 1.0;


    int maxT = 1000000 ;
    double limRes = 0.0;
    int arrayPrime[1000000];
    double proizv = 1.0;
    eratosfen(arrayPrime, maxT);
    for (int p = 2.0; p < maxT; p++){
        if (arrayPrime[p] == 1){
            proizv *= ((p - 1.0) / (double)p);
            
        }
        
    }
    limRes = log(maxT) * proizv;
    while (fabs(exp(-1 * result) - limRes) > precision){
        result = (lSide + rSide) / 2.0;
        if ((exp( -1 * result) - limRes) > precision){
            lSide = result;
        }
        else{
            rSide = result;
        }
    }
    return result;
}

