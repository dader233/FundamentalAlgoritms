#include "./functions.h"

int minSysCalc(char * word, int len){
    int answer = 2;
    char c;
    int curSysCalc = 2;
    for(int i = 0; i < len; i++){
        c = word[i];
        if (c >= '0' && c <= '9'){
            curSysCalc = (c - '0') + 1;
        } else if (c >= 'a' && c <= 'z'){
            curSysCalc = (c - 'a') + 11;
        } else if (c >= 'A' && c <= 'Z'){
            curSysCalc = (c - 'A') + 11;
        }
        else{
            return WRONG_NUMBER_FORMAT;
        }
        if (curSysCalc > answer){
            answer = curSysCalc;
        }
    }
    return answer;
}

long long anyToDes(char * word, int length, int sysCalc){
    long long result = 0;
    int degree = 0;
    char c;
    int desC;
    for (int i = 0; i < length; i++){
        c = word[i];
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
    return result;
}

void printNumber(char *number, int length, FILE *fileOutput) {
    fprintf(fileOutput, "Entered number: ");
    int flagNumber = -1;
    
    for(int i = 0; i < length; i++){
        if (number[i] != '0'){
            flagNumber = i;
            break; 
        }
    }
    
    if (flagNumber == -1){
        fprintf(fileOutput, "0\n");
    }
    else{
        for(int i = flagNumber; i < length; i++){
            fprintf(fileOutput, "%c", number[i]);
        }
        fprintf(fileOutput, "\n");
    }
}

int solution(FILE *fileInput, FILE *fileOutput){
    int buffLen = 100;
    char * buff = (char *) malloc(sizeof(char) * buffLen);
    int index = 0;
    int wordI = 0;
    char c;
    do{
        c = fgetc(fileInput);
        if (c == '\n' || c == ' ' || c == '\t'){
            if (index == 0){
                continue;
            }
            char * word = (char *) malloc(sizeof(char) * (index + 1));
            if (!word){
                printf("ERROR WITH ALLOCATION MEMORY: MALLOC \n");
                return MALLOC_ERROR;
            }

            wordI = 0;
            for(int i = 0; i < index; i++){
                word[wordI++] = buff[i];
            }

            printNumber(word, wordI, fileOutput);
            
            int sysCalc = minSysCalc(word,wordI);
            if (sysCalc == WRONG_NUMBER_FORMAT){
                fprintf(fileOutput, "WRONG NUMBER FORMAT \n");
                free(word);
                continue;
            }
            else{
                fprintf(fileOutput, "Min system of calculation: %d\n", sysCalc);
            }

            long long desNumber = anyToDes(word, wordI,sysCalc);
            fprintf(fileOutput, "In decimal system: %lld\n", desNumber);
            fprintf(fileOutput, "------------------------------\n");
            free(word);
            buffLen = 100;
            char * temp = realloc(buff, sizeof(char) * buffLen);
            if (!temp){
                printf("ERROR WITH ALLOCATION MEMORY: MALLOC \n");
                return MALLOC_ERROR;
            }
            buff = temp;
            index = 0;
            
            continue;
        }
        else{
            if (index == buffLen - 1){
                buffLen *= 2;
                char * temp = realloc(buff, sizeof(char) * buffLen);
                if (!temp){
                    printf("ERROR WITH ALLOCATION MEMORY: MALLOC \n");
                    return MALLOC_ERROR;
                }
                buff = temp;
            }
            buff[index++] = c;
        }
    } while (c != EOF);
    free(buff);
    return 0;
}   