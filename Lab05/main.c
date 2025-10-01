#include "./functions.h"


int main(int argc, char* argv[]){
    if (argc < 3 || argc >= 5){
        printf("Incorrect form. Must be 2  or 3 arguments: [flagName][input file][optional: output file]\n");
        return -1;
    }

    char * nameInput = argv[1];
    FILE * fileInput = fopen(nameInput, "r");
    if (!fileInput){
        printf("Error opening file INPUT\n");
        return ERROR_FILE;
    }

    char * flagName = argv[2];
    char flag;
    if (flagName[0] != '-' && flagName[0] != '/'){
        printf("WRONG FLAG/n");
        fclose(fileInput);
        return FLAG_ERROR;
    }

    char * nameOutput = NULL;
    int mallocFlag = 0;
    if (flagName[1] == 'n'){
        if (argc == 4){
            nameOutput = argv[3];
        }
        else{
            printf("WRONG QUANTITY ARGUMENTS. Enter file output name.\n");
            fclose(fileInput);
            return WRONG_ARGUMENTS;
        }
    }
    else{
        int size = strlen(nameInput) + 5;
        nameOutput = (char *)malloc(sizeof(char) * size);
        mallocFlag = 1;
        if (!nameOutput){
            printf("Memorry Error (malloc).\n");    
            fclose(fileInput);
            return MALLOC_FAULT;
        }
        strcpy(nameOutput, "out_");
        strcat(nameOutput, nameInput);
    }

    FILE * fileOutput = fopen(nameOutput,"w");
    if (!fileOutput){
        printf("Error opening file Output.\n");
        fclose(fileInput);
        if (mallocFlag == 1){
            free(nameOutput);
        }
        return ERROR_FILE;
    }
    int lenFlag = strlen(flagName);
    if(lenFlag == 3){
        if (flagName[1] != 'n'){
            printf("WRONG FLAG.\n");
            fclose(fileInput);
            fclose(fileOutput);
            if (mallocFlag == 1){
                free(nameOutput);
            }
            return FLAG_ERROR;
        }
        if (argc != 4){
            printf("WRONG QUANTITY ARGUMENTS. Enter file output name.\n");
            fclose(fileInput);
            fclose(fileOutput);
            if (mallocFlag == 1){
                free(nameOutput);
            }
            return WRONG_ARGUMENTS;
        }
        flag = flagName[2];
    }else if (lenFlag == 2){
        if (argc > 3){
            printf("WRONG QUANTITY ARGUMENTS.\n");
            fclose(fileInput);
            fclose(fileOutput);
            if (mallocFlag == 1){
                free(nameOutput);
            }
            return WRONG_ARGUMENTS;
        }
        flag = flagName[1]; 
    }
    else{
        printf("WRONG FLAG.\n");
        fclose(fileInput);
        fclose(fileOutput);
        if (mallocFlag == 1){
            free(nameOutput);
        }
        return FLAG_ERROR;
    }

    if (flag == 'd'){
        dFlag(fileInput, fileOutput);
    } else if(flag == 'i'){
        iFlag(fileInput, fileOutput);
    } else if (flag == 's'){
        sFlag(fileInput, fileOutput);
    } else if(flag == 'a'){
        aFlag(fileInput, fileOutput);
    }else{
        printf("WRONG FLAG.\n");
        fclose(fileInput);
        fclose(fileOutput);
        if (mallocFlag == 1){
            free(nameOutput);
        }
        return FLAG_ERROR;
    }
    if (mallocFlag == 1){
        free(nameOutput);
    }
    fclose(fileInput);
    fclose(fileOutput);
    return SUCCESS;
}