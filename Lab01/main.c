#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "./functions.h"

int main(int argc, char* argv[]){
    if (argc != 3){
        printf("Incorrect form. Must be 2 arguments: [number][flag]\n");
        return -1;
    }

    char* numberChar = argv[1];
    char* flag = argv[2];

    if (!numbFormat(numberChar)){
        printf("WRONG NUMBER FORMAT\n");
        return WRONG_NUMBER_FORMAT;
    }
    
    const int number = strInt(numberChar);
    
    int flagType = parseFlag(flag);
    
    if (flagType == 1){
        return hFlagHandle(number);
    }
    else if (flagType == 2){
        return pFlagHandle(number);
    }
    else if (flagType == 3){
        return sFlagHandle(number);
    }
    else if (flagType == 4){
        return eFlagHandle(number);
    }
    else if (flagType == 5){
        return aFlagHandle(number);
    }
    else if (flagType == 6){
        return fFlagHandle(number);
    }
    else{
        printf("Enter correct flag.\n");
        return FLAG_ERROR;
    }
}