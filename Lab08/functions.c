#include "./functions.h"

long long anyToDes(char * word, int length, int sysCalc){
    long long result = 0;
    int degree = 0;
    char c;
    int desC;
    int negativeFlag = 1;
    for (int i = 0; i < length; i++){
        c = word[i];
        if (c == '-' && i == 0){
            if (negativeFlag == -1 || length == 1 ){
                return WRONG_NUMBER_FORMAT;
            }
            else {
                negativeFlag = -1;
                continue;
            }
        } else if(c == '-' && i != 0){
            return WRONG_NUMBER_FORMAT;
        }
        if (c >= '0' && c <= '9'){
            desC = (c - '0');
        } else if (c >= 'a' && c <= 'z'){
            desC = (c - 'a') + 10;
        } else if (c >= 'A' && c <= 'Z'){
            desC = (c - 'A') + 10;
        }
        result = result * sysCalc + desC;
    }
    if (result < 0){
        return WRONG_NUMBER_SIZE;
    }
    return result * negativeFlag;
}

void printNumber(char *number, int length) {
    int flagNumber = -1;
    
    for(int i = 0; i < length; i++){
        if (number[i] != '0'){
            flagNumber = i;
            break; 
        }
    }
    
    if (flagNumber == -1){
        printf("0");
    }
    else{
        for(int i = flagNumber; i < length; i++){
            printf("%c", number[i]);
        }
    }
    printf("\n");
}

char* decToAny(long long num, int base) {
    if (num == 0) {
        char* result = malloc(2);
        strcpy(result, "0");
        return result;
    }
    
    int negative = 0;
    if (num < 0) {
        negative = 1;
        num = -num;
    }
    
    long long temp = num;
    int len = 0;
    while (temp > 0) {
        temp /= base;
        len++;
    }
    
    char* result = malloc(negative + len + 1);
    int index = 0;
    
    while (num > 0) {
        int digit = num % base;
        char c;
        if (digit < 10) {
            c = '0' + digit;
        } else {
            c = 'A' + (digit - 10);
        }
        
        result[negative + len - 1 - index] = c;
        num /= base;
        index++;
    }
    
    if (negative) {
        result[0] = '-';
    }
    result[negative + len] = '\0';
    
    return result;
}