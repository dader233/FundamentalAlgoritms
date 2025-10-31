#include "../include/functions.h"
#include "../include/strerror.h"

void *memchr(const void* str, int c, size_t n){
    const unsigned char* strC = (unsigned char*) str;
    const unsigned char charC = (unsigned char) c;
    const unsigned char* res = NULL;
    for(size_t i = 0; i < n; i++){
        if (strC[i] == charC){
            res = i + strC;
            break;
        } 
    }
    return (void*)res;
}

int memcmp(const void* str1, const void *str2, size_t n){
    const unsigned char* str1C = (unsigned char*) str1;
    const unsigned char* str2C = (unsigned char*) str2;
    for(size_t i = 0; i < n; i++){
        if (str1C[i] > str2C[i]){
            return 1;
        }
        else if (str1C[i] < str2C[i]){
            return -1;
        }
    }
    return 0;
}

void *memcpy(void *dest, const void* src, size_t n){
    unsigned const char* srcC = (unsigned char*)src;
    unsigned char* destC = (unsigned char*)dest;
    for(size_t i = 0; i < n; i++){
        destC[i] = srcC[i];
    }
    dest =(void *)destC;
    return dest;
}

void* memset(void* str, int c, size_t n){
    unsigned char* strC = (unsigned char*)str;
    const unsigned char charC = (unsigned char)c;
    for(size_t i = 0; i < n; i++){
        strC[i] = charC;
    }
    str = (void *)strC;
    return str; 
}

char *strncat(char *dest, const char* src, size_t n){
    size_t len1 = strlen(dest);
    size_t lenSrc = strlen(src);
    size_t i = 0;
    while(i < n && i <lenSrc){
        dest[len1 + i] = src[i];
        ++i;
    }
    dest[len1 + i] = '\0';
    return dest;
}

char* strchr(const char* str, int c){
    const unsigned char* strC = (unsigned char*) str;
    const unsigned char charC = (unsigned char)c;
    const unsigned char* res = NULL;
    for(size_t i = 0; strC[i] != '\0'; i++){
        if (strC[i] == charC){
            res = strC + i;
            break;
        }
    }
    if (charC == '\0'){
        return (char*)(str + strlen((const char *)strC));
    }
    return (char*)res;
}

int strncmp(const char *str1, const char *str2, size_t n){
    size_t len1 = strlen(str1) + 1;
    size_t len2 = strlen(str2) + 1;
    if (len1 > len2){
        len1 = len2;
    }
    for(size_t i = 0; i < n && i < len1; i++){
        if (str1[i] > str2[i]){
            return 1;
        } else if( str1[i] < str2[i]){
            return -1;
        }
    }
    return 0;
}

char *strncpy(char *dest, const char* src, size_t n){
    unsigned char* destC = (unsigned char*) dest;
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++){
        destC[i] = src[i];
    }
    for (; i < n; i++){
        destC[i] = '\0';
    }
    dest = (char *)destC;
    return dest;
}

size_t strcspn(const char *str1, const char *str2){
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t i = 0;
    while(i < len1){
        const unsigned char c = (unsigned char) str1[i];
        for (size_t j = 0; j < len2; j++){
            if (c == (unsigned char)str2[j]){
                return i;
            }
        }
        i++;
    }
    return (size_t)len1;
}

char *strerror(int errnum){
   
    if(errnum < 0 || errnum > MAX_ERROR_NUM){
        return "Unknown error";
    }
    return (char*) error_messages[errnum];
}

size_t strlen(const char *str){
    size_t i = 0;
    while(str[i] != '\0'){
        ++i;
    }
    return i;
}

char *strpbrk(const char *str1, const char *str2){
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char c;
    for(size_t i = 0; i < len1; i++){
        c = str1[i];
        for(size_t j = 0; j < len2; j++){
            if (str2[j] == c){
                return (char *)(str1 + i);
            }
        }
    }
    return NULL;
}

char *strrchr(const char *str, int c) {
    const unsigned char* strC = (const unsigned char*)str;
    unsigned char charC = (unsigned char)c;
    size_t len = strlen(str);

    if (charC == '\0') {
        return (char*)(str + len);
    }
    for (size_t i = len; i > 0; i--) {
        if (strC[i - 1] == charC) {
            return (char*)(str + i - 1);
        }
    }
    
    return NULL;
}

char *strstr(const char *haystack, const char *needle){
    const size_t len1 = strlen(haystack);
    const size_t len2 = strlen(needle);
    if(!*needle){
        return (char*)haystack;
    }
    if (len2 > len1){
        return NULL;
    }
    
    for(size_t i = 0;haystack[i] != '\0'; i++){
        size_t j = 0;
        if (haystack[i] == needle[0]){
            for (; needle[j] != '\0' && haystack[i+j] != '\0'; j++){
                if (haystack[i+j] != needle[j]){
                    break;
                }
            }
            if (needle[j] == '\0'){
                return (char*)(haystack + i);
            }
        }
    }
    return NULL;
}

char *strtok(char *str, const char* delim){
    static char* strC  = NULL;
    if(str != NULL){
        strC = str;
    }
    if (strC == NULL || delim == NULL || !*strC){
        return NULL;
    }
    char *start;
    char *delimPos;
    while(*strC != '\0'){
        const char* d = delim;
        int isDelim = 0;
        while(*d != '\0'){
            if(*strC == *d){
                isDelim = 1;
                break;
            }
            d++;
        }
        if(!isDelim){
            break;
        }
        strC++;
    }
    if(*strC == '\0'){
        return NULL;
    }
    start = strC;
    delimPos = strpbrk(strC, delim);
    if(delimPos != NULL){
        *delimPos = '\0';
        strC = delimPos + 1;
    }else{
        strC = NULL;
    }
    return start;
}