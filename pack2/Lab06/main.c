#include "./include/functions.h"


int main(int argc, char* argv[]){
    error err = SUCCESS;
    if(argc != 3){
        printInfo();
        err = WRONG_ARGS;
        return err;
    }

    FILE * fileIn = fopen(argv[1], "r");
    if(!fileIn){
        printf("Cant' open fileIn\n");
        printInfo();
        err = ERROR_FILE;
        return ERROR_FILE;
    }
    FILE * fileOut = fopen(argv[2], "w");
    if(!fileOut){
        printf("Cant' open fileOut\n");
        printInfo();
        fclose(fileIn);
        err = ERROR_FILE;
        return err;
    }
    int counter = 0;
    Student** students = readStudents(fileIn, &counter, &err);
    if(err != SUCCESS){
        fclose(fileIn);
        fclose(fileOut);
        printf("Error with reading.\n");
        return err;
    }
    start(students, counter, fileOut, &err);

    freeStudents(students, counter, &err);
    fclose(fileIn);
    fclose(fileOut);


    return err;
}
