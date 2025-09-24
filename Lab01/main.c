#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "./functions.h"


enum{
    WRONG_NUMBER_FORMAT,
    MALLOC_FAULT
};

int main(int argc, char* argv[]){
    if (argc != 3){
        printf("Incorrect form. Must be 2 arguments: [number][flag]\n");
        return -1;
    }

    char* numberChar = argv[1];
    char* flag = argv[2];

    if (!numbFormat(numberChar)){
        printf("WRONG NUMBER FORMAT");
        return WRONG_NUMBER_FORMAT;
    }
    
    const int number = strInt(numberChar);

    if (strcmp(flag,"-h") == 0 || strcmp(flag, "/h") == 0){
        
        int * massInt = (int*)malloc(sizeof(int) * 100);
        if (!massInt){
            printf("Memory allocation error in malloc\n");
            return MALLOC_FAULT;
        }
        int quantity = hFlag(massInt, number);
        if (quantity != 0){
            for (int i = 0; i<quantity; ++i){
                printf("%d ", massInt[i]);
            }

        }
        else{
            printf("No such numbers");
        }
        printf("\n");
        free(massInt);
    }
    else if(strcmp(flag,"-p") == 0 || strcmp(flag, "/p") == 0){
    
        int result = pFlag(number);
        if (result == -1){
            printf("0 or 1 was entered. Not prime and not composite number.\n");
        }
        else if(result == 0){
            printf("%d is composite number.\n", number);

        }
        else{
            printf("%d is prime number.\n", number);
        }
    }
    else if(strcmp(flag,"-s") == 0 || strcmp(flag, "/s") == 0){
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
    }

    return 0;
}