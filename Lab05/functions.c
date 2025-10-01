#include "./functions.h"


void dFlag(FILE* fileInput, FILE* fileOutput){
    char c;
    while( (c = fgetc(fileInput)) != EOF){
        if (c >= '0' && c <= '9'){
            continue;
        }
        fputc(c, fileOutput);
    }
}
void iFlag(FILE* fileInput, FILE* fileOutput){
    char c;
    int sum = 0;
    while( (c = fgetc(fileInput)) != EOF){
        if (c =='\n'){
            fprintf(fileOutput, "%d\n", sum);
            sum = 0;
        }
        else if( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
            sum++;
        }
    }
    fprintf(fileOutput, "%d\n", sum);
}
void sFlag(FILE* fileInput, FILE* fileOutput){
    char c;
    int sum = 0;
    while( (c = fgetc(fileInput)) != EOF){
        if (c =='\n'){
            fprintf(fileOutput, "%d\n", sum);
            sum = 0;
        }
        else if( !((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == ' ')){
            sum++;
        }
    }
    fprintf(fileOutput, "%d\n", sum);
}

void aFlag(FILE* fileInput, FILE* fileOutput){
    char c;
    int ascii = 0;
    int index;
    int maxSize = 20;
    char hexArray[maxSize]; 
    while( (c = fgetc(fileInput)) != EOF){
        if (!((c == '\n') || (c >= '0' && c <= '9') || c == ' ')){
            ascii = c;
            index = asciiHex(ascii,hexArray, maxSize);
            for (int i = index; i < maxSize; i++){
                fputc(hexArray[i], fileOutput);
            }  
        } else{
            fputc(c, fileOutput);
        }
    }
}

int asciiHex (int ascii, char * array, int maxSize){
    int index = maxSize - 1;
    int x = 0; 
    while(ascii != 0){
        x = ascii % 16;
        if (x > 9){
            array[index--] = (x - 10) + 'A';
        }
        else{
            array[index--] = x +'0';
        }
        ascii /= 16;
        
    }
    return ++index;

}
