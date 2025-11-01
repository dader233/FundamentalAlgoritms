#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    unsigned int id;
    char* name;
    char* surname;
    char* group;
    unsigned char* marks;
} Student;

typedef enum{
    SUCCESS,
    WRONG_ARGS,
    ERROR_FILE,
    ERROR_MALLOC,
    ERROR_FUNC,
    ERROR_READ,
    ERROR_EOF
}error;

void printInfo();
void printStudent(FILE *fileOut, Student* student, error* err);
double averageALL(Student** students, int counter, error* err);
double averageM(unsigned char *marks, error* err);
Student** readStudents(FILE *fileIn, int* counter, error* err);
Student* readPerson(FILE *fileIn, error* err);

// Функции поиска
void searchAVG(Student** students, int counter, FILE *fileOut, error* err);
void searchID(Student** students, int counter, FILE *fileOut, error* err);
void searchSRNM(Student** students, int counter, FILE *fileOut, error* err);
void searchNM(Student** students, int counter, FILE *fileOut, error* err);
void searchGRP(Student** students, int counter, FILE *fileOut, error* err);

// Функции сортировки
void handleSortID(Student** students, int counter, error* err);
void handleSortSRNM(Student** students, int counter, error* err);
void handleSortNM(Student** students, int counter, error* err);
void handleSortGRP(Student** students, int counter, error* err);

// Компараторы для qsort
int cmpID(const void* stud1, const void* stud2);
int cmpSRNM(const void *stud1, const void* stud2);
int cmpNM(const void *stud1, const void* stud2);
int cmpGRP(const void *stud1, const void* stud2);

// Интерактивные функции
void printMenu();
void printSearchMenu();
void printSortMenu();
void start(Student** students, int counter, FILE* fileOut, error* err);
void freeStudents(Student** students, int counter, error* err);

#endif


