#include "./functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    else if (number <= 1){
        return -1;
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
    if (number > 20){
        return -1;
    }
    if (number >= 2){    
        for (int i = 2; i <= number; i++){
            result *= i;
        }
    }
    return result;
}

int hFlagHandle(const int number){
    int * massInt = (int*)malloc(sizeof(int) * 100);
    if (!massInt){
        printf("Memory allocation error in malloc\n");
        return MALLOC_FAULT;
    }
    int quantity = hFlag(massInt, number);
    if (quantity != 0){
        printf("Natural numbers: ");
        for (int i = 0; i<quantity; ++i){
            printf("%d ", massInt[i]);
        }
    }
    else{
        printf("No such numbers.\n");
    }
    printf("\n");
    free(massInt);
    return 0;
}

int pFlagHandle(const int number){
    int result = pFlag(number);
    if (result == -1){
        printf("1 or below was entered. Not prime and not composite number.\n");
    }
    else if(result == 0){
        printf("%d is composite number.\n", number);
    }
    else{
        printf("%d is prime number.\n", number);
    }
    return 0;
}

int sFlagHandle(const int number){
    if( number < 0){
        printf("Negative number error.");
        return WRONG_NUMBER_FORMAT;
    }
    const int maxHexInt = 10;
    char * intHex = (char* )malloc(sizeof(char) * maxHexInt);
    if(!intHex){
        printf("Memory allocation error in malloc\n");
        return MALLOC_FAULT;
    }
    int result = sFlag(intHex, number);
    for (int i = result; i <=maxHexInt; ++i){
        printf("%c ", intHex[i]);
    }
    printf("\n");
    free(intHex);
    return 0;
}

int eFlagHandle(const int number){
    if (number > 10 || number < 1){
        printf("The entered number can't be more than 10 or less than 1.\n");
        return WRONG_NUMBER_SIZE;
    }
    long long ** result = malloc(sizeof(long long *) * 10);
    if(!result){
        printf("Memory allocation error in malloc\n");
        return MALLOC_FAULT;
    }
    for (int i = 0; i< 10; i++){
        result[i] = (long long *)malloc(sizeof(long long) * number);
        if(!result[i]){
            printf("Memory allocation error in malloc\n");
            return MALLOC_FAULT;
        }    
    }
    eFlag(result, number);
    
    for (int i = 0; i< 10; i++){
        for (int j = 0; j<number; j++){
            printf("%12lld", result[i][j]);
        }
        printf("\n");
        free(result[i]);
    }
    free(result);
    return 0;
}

int aFlagHandle(const int number){
    if (number < 0){
        printf("0 or below was entered.\n");
        return WRONG_NUMBER_SIZE;
    }
    long long int result = aFlag(number);
    printf("%lld\n", result);
    return 0;
}

int fFlagHandle(const int number){
    if (number < 0){
        printf("Negative number was entered.\n");
        return WRONG_NUMBER_SIZE;
    }
    long long int result = fFlag(number);
    if(result <= 0){
        printf("Size too big to count.\n");
        return WRONG_NUMBER_SIZE;
    }
    
    printf("%lld\n", result);
    return 0;
}

int parseFlag(char* flag){
    if (strcmp(flag,"-h") == 0 || strcmp(flag, "/h") == 0) return 1;
    if (strcmp(flag,"-p") == 0 || strcmp(flag, "/p") == 0) return 2;
    if (strcmp(flag,"-s") == 0 || strcmp(flag, "/s") == 0) return 3;
    if (strcmp(flag,"-e") == 0 || strcmp(flag, "/e") == 0) return 4;
    if (strcmp(flag,"-a") == 0 || strcmp(flag, "/a") == 0) return 5;
    if (strcmp(flag,"-f") == 0 || strcmp(flag, "/f") == 0) return 6;
    return 0;
}