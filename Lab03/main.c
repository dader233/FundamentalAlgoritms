#include "./functions.h"




int main(int argc, char* argv[]){
    if(argc <= 2){
        printf("Wrong quantity arguments\n");
        return WRONG_ARGUMENTS;
    }
    int flag = parseFlag(argv[1]);
    if (flag == 1){
        return qFlagHandle(argc, argv);
    }
    else if (flag == 2){
        return mFlagHandle(argc, argv);
    }
    else if (flag == 3){
        return tFlagHandle(argc, argv);
    }
    else{
        printf("WRONG FLAG!\n");
        return WRONG_FLAG;
    }
    return SUCCESS;
}