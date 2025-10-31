#include "./include/func.h"



int main() {
    printf("=== ПРОВЕРКА КОНЕЧНОСТИ ПРЕДСТАВЛЕНИЯ ДРОБЕЙ ===\n\n");

    printf("1. ОСНОВНЫЕ ТЕСТЫ:\n");
    int count1 = 4;
    ReprStat* results1 = malloc(count1 * sizeof(ReprStat));
    if (!results1) {
        printf("Ошибка выделения памяти!\n");
        return MemoryAllocationError;
    }
    
    ReprStat status1 = checkFractions(results1, 2, count1, 0.5, 0.25, 0.125, 0.1);
    if (status1 == Success) {
        double fractions1[] = {0.5, 0.25, 0.125, 0.1};
        for (int i = 0; i < count1; i++) {
            printf(" Дробь %.3f в двоичной системе: %s\n", 
                   fractions1[i], reprString(results1[i]));
        }
    } else {
        printf("Ошибка: %s\n", reprString(status1));
    }
    free(results1);
    

    printf("\n2. РАЗНЫЕ СИСТЕМЫ СЧИСЛЕНИЯ:\n");
    int count2 = 3;
    ReprStat* results2 = malloc(count2 * sizeof(ReprStat));    
    ReprStat status2 = checkFractions(results2, 10, count2, 1.0/3.0, 1.0/2.0, 0.333);
    
    if (status2 == Success) {
        double fractions2[] = {1.0/3.0, 1.0/2.0, 0.333};
        for (int i = 0; i < count2; i++) {
            printf("Дробь %.3f в десятичной системе: %s\n", 
                   fractions2[i], reprString(results2[i]));
        }
    } else {
        printf("Jшибка: %s\n", reprString(status2));
    }
    free(results2);
    
    printf("\n3. ВОСЬМЕРИЧНАЯ СИСТЕМА:\n");
    int count3 = 2;
    ReprStat* results3 = malloc(count3 * sizeof(ReprStat));
    ReprStat status3 = checkFractions(results3, 8, count3, 0.125, 0.375);
    
    if (status3 == Success) {
        double fractions3[] = {0.125, 0.375};
        for (int i = 0; i < count3; i++) {
            printf("Дробь %.3f в восьмеричной системе: %s\n", 
                   fractions3[i], reprString(results3[i]));
        }
    } else {
        printf("Ошибка: %s\n", reprString(status3));
    }
    free(results3);
    
    printf("\n4. ТЕСТ ОШИБОК:\n");
    int count4 = 2;
    ReprStat* results4 = malloc(count4 * sizeof(ReprStat));
    if (results4 == NULL) {
        printf("Ошибка выделения памяти!\n");
        return MemoryAllocationError;
    }
    
    ReprStat status4 = checkFractions(results4, -5, count4, 0.5, 0.25);
    printf("   Основание -5: %s\n", reprString(status4));
    free(results4);
    
    int count5 = 2;
    ReprStat* results5 = malloc(count5 * sizeof(ReprStat));  
    ReprStat status5 = checkFractions(results5, 2, count5, 1.5, 0.25);
    printf("Дробь 1.5: %s\n", reprString(status5));
    free(results5);
    
    printf("\n=== ТЕСТИРОВАНИЕ ЗАВЕРШЕНО ===\n");
    return Success;
}