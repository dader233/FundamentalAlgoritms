#include "../include/func.h"


int gcd(int a, int b){
    while (b!= 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool primeDividers(int number, int base){
    if (number == 1){
        return true;
    }
    int temp = number;
    int tempBase = base;

    for (int i = 2; i <= tempBase && temp > 1; i++){
        if(tempBase % i == 0){
            while(tempBase % i == 0){
                tempBase /= i;
            }
            while(temp % i == 0){
                temp /= i;
            }
        }
    }
    return temp == 1;
}

ReprStat checker(double fraction, int base){
    const double eps = 1e-10;
    if(base < 2){
        return InvalidBase;
    }
    
    if (fraction <= eps || fraction >= 1 - eps){
        return InvalidArgument;
    }

    for(int power = 1; power <= 10; power++){
        long long denominator = (long long)pow(10, power);
        long long numerator = (long long)round(fraction * denominator);

        if (fabs(fraction - (double)numerator / denominator) < eps){
            int a = gcd(numerator, denominator);
            int b = denominator / a;
            bool res = primeDividers(b, base);
            if(res){
                return Finite;
            } else{
                return Infinite;
            }
        }
    }

    return Infinite;

}

ReprStat checkFractions(ReprStat* result, int base, int count, ...){
    if (base < 2){
        return InvalidBase;
    }
    const double eps = 1e-10;
    if (!result){
        printf("Error: MallocError \n");
        return MemoryAllocationError;
    }
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++){
        double fraction = va_arg(args, double);
        if (fraction < eps || fraction - 1 > eps){
            va_end(args);
            return InvalidArgument;
        }
        result[i] = checker(fraction, base);

    }
    va_end(args);
    return Success;
}

const char* reprString(ReprStat status) {
    switch (status) {
        case Finite: return "FINITE";
        case Infinite: return "INFINITE";
        case InvalidBase: return "INVALID_BASE";
        case InvalidArgument: return "INVALID_ARGUMENT";
        case Success: return "SUCCESS";
        case MemoryAllocationError: return "MEMORY_ERROR";
        default: return "UNKNOWN";
    }
}