#include "./functions.h"
#include <stdio.h>



int strInt(char *number){
    bool negative = false;
    int value = 0;
    if (*number == '-'){
        if (negative){
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

int hFlag(int* resultArray, const int number){
    if (number > 100 || number == 0){
        return 0;
    }
    int index = 0;
    for (int i = 1; i <= 100; ++i){
        if(i % number == 0){
            resultArray[index++] = i;
        }
    }
    return index;
}

int pFlag(const int number){
    if (number > 1){
        for (int i = 2; i * i <= number; ++i){
            if (number % i == 0){
                return 0;
        }
    }
    return 1;    
    }
    else if (number >= 0){
        return -1;
    }
    else{
       return pFlag(number * -1);
    }
   
}

int sFlag(char* resultArray, const int number){
    int copyNumber = number;
    int posArray = 9;
    int index = 16;
    int division;
    while (copyNumber != 0){
        division = copyNumber % index;
        if (division > 9){
            resultArray[posArray--] = (division - 10) +'A';
        } else{
            resultArray[posArray--] = division  +'0';
        }
        copyNumber /= index;
    }
    return posArray + 1;
}
    
void eFlag(long long **resultArray, const int number){
    long long temp;
    for (int i = 0; i<10; i++){
        temp = 1;
        for (int j = 0; j < number; j++){
            temp *= (i + 1);
            resultArray[i][j] = temp;
        }
    }
}

long long aFlag(const int number){
    long long result = (1 + number) * number / 2;
    return result;
}

long long fFlag(const int number){
    long long result = 1;
    for (int i = 2; i <= number; i++){
        result *= i;
    }
    return result;
}