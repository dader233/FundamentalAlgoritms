#include "./functions.h"


int main(){
    int base;
    scanf("%d", &base);
    if(base < 2 || base > 36){
        printf("WRONG NUMBERS BASE. BASE CANT BE LESS THAN 2 OR MORE THAN 36 \n");
        return WRONG_NUMBER_FORMAT;
    }
    printf("Enter numbers not more than 100 symbols each.    \n");
    int buffSize = 100;
    int numbLen = 0;
    char number[buffSize];
    char newNumber[buffSize];
    long long maxValue = 0;
    char maxNumber[buffSize];
    maxNumber[0] = '\0';
    long long value;
    long long status;
    do{
        scanf("%s", number);
        if (strcmp(number, "Stop") == 0) {
            break; 
        }
        removeZeros(number, newNumber);
        long long status = anyToDes(newNumber, strlen(newNumber), base, &value);
        if (status == WRONG_NUMBER_FORMAT) {
            fprintf(stderr, "Error: Wrong number format for '%s'\nContinue \n", newNumber);
            continue;
        } else if (status == WRONG_NUMBER_SIZE) {
            fprintf(stderr, "Error: Number too large '%s'\n", newNumber);
            continue;
        }

        if(llabs(value) >= llabs(maxValue)){
            maxValue = value;
            strcpy(maxNumber, newNumber);
        }

    } while(strcmp(number, "Stop") != 0);

    if (maxNumber[0] != '\0') {
        char *result9 = decToAny(maxValue, 9);
        if (!result9) {
            printf("Memory allocation error\n");
            return MALLOC_ERROR;
        }
        char *result18 = decToAny(maxValue, 18);
        if (!result18) {
            printf("Memory allocation error\n");
            free(result9);
            return MALLOC_ERROR;
        }
        char *result27 = decToAny(maxValue, 27);
        if (!result27) {
            printf("Memory allocation error\n");
            free(result9);
            free(result18);
            return MALLOC_ERROR;
        }
        char *result36 = decToAny(maxValue, 36);
        if (!result36) {
            printf("Memory allocation error\n");
            free(result9);
            free(result18);
            free(result27);
            return MALLOC_ERROR;
        }

        printf("Max number: %s\n", maxNumber);
        printf("Base 9: %s\n", result9);
        printf("Base 18: %s\n", result18);
        printf("Base 27: %s\n", result27);
        printf("Base 36: %s\n", result36);

        free(result9);
        free(result18);
        free(result27);
        free(result36);
    } else {
        printf("No numbers entered.\n");
}
    

}