#include "./functions.h"


void eratosfen(int arrayPrime[], int maxNumber){
    for (int i = 2; i * i < maxNumber; i++){
        if(arrayPrime[i] == 1){
            for (int k = i * i; k < maxNumber; k+=i){
                arrayPrime[k] = 0;
            }
        }
    }
}