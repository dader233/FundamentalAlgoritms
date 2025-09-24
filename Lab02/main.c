#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./functions.h"



int main(){
    int T;
    scanf("%d",&T);
    int posNumbers[T];
    for (int i = 0; i < T; i++){
        scanf("%d", &posNumbers[i]);
    }
    int maxRequest = 0;
    int maxNumber;
    for(int i = 0; i < T; i++){
        if(posNumbers[i] > maxRequest){
            maxRequest = posNumbers[i];
        }
        else if(posNumbers[i] < 0){
            printf("Number cant be negative \n");
            return -1;
        }
    }
    maxNumber = maxRequest * (log(maxRequest) + 5);
    int numbersPrime[maxNumber];
    for (int i = 0; i < maxNumber; i++){
        numbersPrime[i] = 1;
    }
    numbersPrime[0] = 0;
    numbersPrime[1] = 0;
    eratosfen(numbersPrime, maxNumber);
    int resultArray[maxNumber];
    int counter = 0;
    for(int i = 2; i < maxNumber; i++ ){
        if (numbersPrime[i] == 1){
            resultArray[counter++] = i;
        }
    }
    printf("--------\n");
    for (int i = 0; i< T; i++){
        printf("The prime number at number %d is %d\n",posNumbers[i], resultArray[posNumbers[i] - 1]);
    }

}