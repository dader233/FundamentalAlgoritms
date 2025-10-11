#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./functions.h"

enum{
    SUCCESS,
    MEMORY_ALLOCATION_FAULT,
    NEGATIVE_ERROR,
    INPUT_ERROR
};

int main(){
    int T = 0;
    scanf("%d",&T);
    int * posNumbers = malloc(T * sizeof(int));
    if (!posNumbers){
        printf("Memory allocation failed (Malloc)");
        return MEMORY_ALLOCATION_FAULT;
    }
    for (int i = 0; i < T; i++){
        scanf("%d", &posNumbers[i]);
    }
    int maxRequest = 0;
    for(int i = 0; i < T; i++){
        if(posNumbers[i] > maxRequest){
            maxRequest = posNumbers[i];
        }
        else if(posNumbers[i] <= 0){
            printf("Number cant be negative \n");
            return NEGATIVE_ERROR;
        }
    }
    if (maxRequest > 10000000) { 
        printf("Requested number %d is too large\n", maxRequest);
        free(posNumbers);
        return INPUT_ERROR;
    }
    long long maxNumber;
    maxNumber = maxRequest * (log(maxRequest) + 5);
    int *numbersPrime = malloc(sizeof(int) * maxNumber);
    if (!numbersPrime){
        printf("Memory allocation failed (Malloc)");
        free(posNumbers);
        return MEMORY_ALLOCATION_FAULT;
    }
    for (int i = 0; i < maxNumber; i++){
        numbersPrime[i] = 1;
    }
    numbersPrime[0] = 0;
    numbersPrime[1] = 0;
    eratosfen(numbersPrime, maxNumber);
    long long * resultArray = malloc(maxRequest * sizeof(long long int));
    if (!resultArray){
        printf("Memory allocation failed (Malloc)");
        free(posNumbers);
        free(numbersPrime);
        return MEMORY_ALLOCATION_FAULT;
    }
    int counter = 0;
    for(int i = 2; i < maxNumber; i++ ){
        if (numbersPrime[i] == 1){
            resultArray[counter++] = i;
        }
    }
    printf("--------\n");
    for (int i = 0; i< T; i++){
        printf("The prime number at number %d is %lld\n",posNumbers[i], resultArray[posNumbers[i] - 1]);
        
    }
    free(posNumbers);
    free(numbersPrime);
    free(resultArray);
    return 0;
}