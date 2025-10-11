#include "./functions.h"


int main(int argc, char * argv[]){
    int result;
    if (argc != 3){
        printf("Incorrect form. Must be 3 arguments: ./main [file input][file output].\n");
        return WRONG_ARGUMENTS;
    }

    char * nameInput = argv[1];
    FILE * fileInput = fopen(nameInput, "r");
    if (!fileInput){
        printf("Error opening file INPUT\n");
        return ERROR_FILE;
    }
    char * nameOutput = argv[2];
    FILE * fileOutput = fopen(nameOutput, "w");
    if (!fileOutput){
        printf("Error opening file Output\n");
        fclose(fileInput);
        return ERROR_FILE;
    }
    result = solution(fileInput, fileOutput);    
    fclose(fileInput);
    fclose(fileOutput);
    
    if (result != 0) {
        printf("Program finished with error code: %d\n", result);
        return result;
    }
    
    printf("Program completed successfully\n");
    return 0;
}