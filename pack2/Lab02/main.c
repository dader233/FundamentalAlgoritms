#include <stdio.h>
#include "./include/functions.h"

int main(){
    printf("=== Testing string functions ===\n");
    
    // memchr
    char str1[] = "Hello World";
    char *found = memchr(str1, 'W', 11);
    printf("memchr: Found 'W' at position %ld\n", found - str1);
    
    // memcmp
    char str2[] = "abc";
    char str3[] = "abd";
    int cmp_result = memcmp(str2, str3, 3);
    printf("memcmp: 'abc' vs 'abd' = %d\n", cmp_result);
    
    // memcpy
    char src[] = "Source";
    char dest[10];
    memcpy(dest, src, 6);
    dest[6] = '\0';
    printf("memcpy: %s\n", dest);
    
    // memset
    char buffer[10];
    memset(buffer, 'A', 9);
    buffer[9] = '\0';
    printf("memset: %s\n", buffer);
    
    // strncat
    char dest1[30] = "Hello";
    strncat(dest1, " World!", 7);
    printf("strncat: %s\n", dest1);
    
    // strchr
    char *first_r = strchr("Hello World", 'r');
    printf("strchr: First 'r' at %ld\n", first_r - "Hello World");
    
    // strncmp
    int cmp2 = strncmp("abc", "abd", 3);
    printf("strncmp: 'abc' vs 'abd' = %d\n", cmp2);
    
    // strncpy
    char dest2[10];
    strncpy(dest2, "Hello", 5);
    dest2[5] = '\0';
    printf("strncpy: %s\n", dest2);
    
    // strcspn
    size_t span = strcspn("Hello World", " ");
    printf("strcspn: First space at position %zu\n", span);
    
    // strerror
    printf("strerror: %s\n", strerror(0));
    
    // strlen
    printf("strlen: 'Hello' = %zu\n", strlen("Hello"));
    
    // strpbrk
    char *any_match = strpbrk("Hello World", "aeiou");
    printf("strpbrk: First vowel '%c'\n", *any_match);
    
    // strrchr
    char *last_l = strrchr("Hello World", 'l');
    printf("strrchr: Last 'l' at position %ld\n", last_l - "Hello World");
    
    // strstr
    char *substr = strstr("Hello World", "World");
    printf("strstr: Found 'World' at position %ld\n", substr - "Hello World");
    
    // strtok
    char text[] = "Hello,World,Test";
    char *token = strtok(text, ",");
    printf("strtok tokens: ");
    while(token) {
        printf("[%s] ", token);
        token = strtok(NULL, ",");
    }
    printf("\n");
    
    return 0;
}