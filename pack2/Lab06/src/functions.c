#include "../include/functions.h"

// Принты

void printInfo(){
    printf("Proper usage: ./main.out <input file> <output file>\n");
}

void printStudent(FILE *fileOut,Student* student, error* err){
    if (*err != SUCCESS){
        return;
    }
    if (fileOut == NULL || student == NULL) {
        *err = ERROR_FUNC;
        return;
    }
    fprintf(fileOut, "Student %hhu:\n name: %s, surname: %s\n", student->id, student->name, student->surname);
        fprintf(fileOut, "Group: %s\n",student ->group);
    if (fileOut == stdout){
        double average = averageM(student->marks, err);
        fprintf(fileOut, "Average score: %.3f\n", average);
    } else{
        fprintf(fileOut, "Marks: %hhu %hhu %hhu %hhu %hhu\n", student->marks[0],student->marks[1],
            student->marks[2],student->marks[3],student->marks[4]);

    }
    fprintf(fileOut, "-------------------\n");
}

void printMenu(){
    printf("\n==Main Menu==\n");
    printf("1.Search student\n");
    printf("2.Sort students\n");
    printf("3.Print all students\n");
    printf("4.Find students with above AVG marks\n");
    printf("5.Exit\n");
    printf("Enter your choice: ");
}

void printSearchMenu() {
    printf("\n== Search Menu ==\n");
    printf("1. By ID\n");
    printf("2. By surname\n");
    printf("3. By name\n");
    printf("4. By group\n");
    printf("5. Back to main menu\n");
    printf("Enter type: ");
}

void printSortMenu() {
    printf("\n== Sort Menu ==\n");
    printf("1. By ID\n");
    printf("2. By surname\n");
    printf("3. By name\n");
    printf("4. By group\n");
    printf("5. Back to main menu\n");
    printf("Enter type: ");
}

void handleSearchChoice(Student** students, int counter, FILE* fileOut, int choice, error* err) {
    if (*err != SUCCESS){
        return;
    }
    
    switch(choice) {
        case 1:
            printf("\nSearch by ID\n");
            searchID(students, counter, fileOut, err);
            break;
        case 2:
            printf("\nSearch by surname\n");
            searchSRNM(students, counter, fileOut, err);
            break;
        case 3:
            printf("\nSearch by name\n");
            searchNM(students, counter, fileOut, err);
            break;
        case 4:
            printf("\nSearch by group\n");
            searchGRP(students, counter, fileOut, err);
            break;
        case 5:
            printf("Returning to main menu\n");
            break;
        default:
            printf("Error: Invalid choice. Please try again.\n");
            *err = ERROR_FUNC;
    }
}

void handleSortChoice(Student** students, int counter, int choice, error* err) {
    if (*err != SUCCESS){
        return;
    }
    switch(choice) {
        case 1:
            printf("\nSorting by ID...\n");
            handleSortID(students, counter, err);
            break;
        case 2:
            printf("\nSorting by surname...\n");
            handleSortSRNM(students, counter, err);
            break;
        case 3:
            printf("\nSorting by name...\n");
            handleSortNM(students, counter, err);
            break;
        case 4:
            printf("\nSorting by group...\n");
            handleSortGRP(students, counter, err);
            break;
        case 5:
            printf("Returning to main menu\n");
            break;
        default:
            printf("Error: Invalid choice. Please try again.\n");
            *err = ERROR_FUNC;
    }
}

void start(Student** students, int counter, FILE* fileOut, error* err) {
    if (*err != SUCCESS) {
        printf("Error before starting: %d\n", *err);
        return;
    }
    if (counter == 0) {
        printf("No students to work with\n");
        *err = ERROR_FUNC;
        return;
    }

    printf("\nStarting\n");
    printf("Students loaded: %d\n", counter);
    int choice;
    bool running = true;
    while (running && *err == SUCCESS) {
        printMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Error: Invalid input. Please enter a number.\n");
            *err = ERROR_READ;
            while (getchar() != '\n'){
                continue;
            }
        }
        
        switch (choice) {
            case 1: {
                int searchChoice;
                printSearchMenu();
                if (scanf("%d", &searchChoice) == 1) {
                    handleSearchChoice(students, counter, fileOut, searchChoice, err);
                } else {
                    *err = ERROR_READ;
                }
                break;
            }
            case 2: {
                int sortChoice;
                printSortMenu();
                if (scanf("%d", &sortChoice) == 1) {
                    handleSortChoice(students, counter, sortChoice, err);
                } else {
                    *err = ERROR_READ;
                }
                break;
            }
            case 3:
                printf("\nALL STUDENTS (%d):\n", counter);
                for (int i = 0; i < counter && *err == SUCCESS; i++) {
                    printf("Student %d/%d:\n", i+1, counter);
                    printStudent(stdout, students[i], err);
                }
                if (*err == SUCCESS) {
                    printf("Printed all students: %d\n", counter);
                }
                break;
                
            case 4:
                printf("\nFinding students with above average marks\n");
                searchAVG(students, counter, fileOut, err);
                break;
                
            case 5:
                printf("\nExiting program\n");
                running = false;
                break;
                
            default:
                printf("Error: Invalid choice. Please select 1-5.\n");
                *err = ERROR_FUNC;
        }
        
        if (running && *err == SUCCESS && choice != 5) {
            printf("\nPress Enter to continue...");
            while (getchar() != '\n'){
                getchar();
            }
        }
    }
    if (*err != SUCCESS) {
        printf("Error in programm: %d\n", *err);
    }
    fflush(fileOut);
}

// функции
double averageALL(Student** students, int counter, error *err){
    if (*err != SUCCESS){
        return 0.0;
    }
    if(counter == 0){
        *err = ERROR_FUNC;
        return 0.0;
    }
    double sum = 0;
    for(int i = 0; i < counter; i++){
        sum += averageM(students[i]->marks, err);
    }
    return (double)(sum / counter);
}

double averageM(unsigned char *marks, error* err) {
    if (*err != SUCCESS){
        return 0.0;
    }
    int sum = 0;
    int count = 0;
    for (int i = 0; i < 5; i++) {
        sum += (int)marks[i];
        count++;
    }
    if(count == 0){
        *err = ERROR_FUNC;
        return 0.0;
    }
    return (double)sum / count;
}
Student** readStudents(FILE * fileIn, int* counter, error* err){
    if (*err != SUCCESS){
        return NULL;
    }
    int capacity = 10;
    Student **students = (Student**)malloc(sizeof(Student*) * capacity);
    if(!students){
        *err = ERROR_MALLOC;
        return NULL;
    }
    int len = 0;
    while(!feof(fileIn)){
        Student * student = readPerson(fileIn, err);
        if (student == NULL) {
            if (*err != ERROR_READ) { 
                for (int i = 0; i < len; i++) {
                    free(students[i]->name);
                    free(students[i]->surname);
                    free(students[i]->group);
                    free(students[i]->marks);
                    free(students[i]);
                }
                free(students);
                return NULL;
            }
            break;
        }
        if(len >= capacity){
            capacity *= 2;
            Student **newStudents = (Student**)realloc(students, capacity * sizeof(Student *));
            if (!newStudents){
                *err = ERROR_MALLOC;
                for (int i = 0; i < len; i++) {
                    free(students[i]->name);
                    free(students[i]->surname);
                    free(students[i]->group);
                    free(students[i]->marks);
                    free(students[i]);
                }
                free(students);
                return NULL;
            }
            students = newStudents;
        }
        students[len++] = student;
    }
    *counter = len;
    return students;
}

Student * readPerson(FILE * fileIn, error* err){
    if (*err != SUCCESS){
        return NULL;
    }
    unsigned int id = 0;
    int capacity = 100;
    int readed = 0;
    char * name = (char*) malloc(sizeof(char) * capacity);
    char * surname = (char*) malloc(sizeof(char) * capacity);
    char * group =  (char*) malloc(sizeof(char) * capacity);
    unsigned char * marks =  (unsigned char*) malloc(sizeof(unsigned int) * 5);
    if (!name || !surname || !group || !marks){
        free(name);
        free(surname);
        free(group);
        free(marks);
        *err = ERROR_MALLOC;
        return NULL;
    }
    readed = fscanf(fileIn, "%u %s %s %s %hhu %hhu %hhu %hhu %hhu\n", &id, name, surname, group, &marks[0], &marks[1],&marks[2], &marks[3], &marks[4]);
    if (readed != 9){
        if (feof(fileIn)) {
            *err = ERROR_EOF;
        } else {
            *err = ERROR_READ;
        }
        free(name);
        free(surname);
        free(group);
        free(marks);
        return NULL;
    }
    Student * student = (Student *) malloc(sizeof(Student));
    if(!student){
        *err = ERROR_MALLOC;
        free(name);
        free(surname);
        free(group);
        free(marks);
        return NULL;
    }
    student -> id = id;
    student -> name = name;
    student -> surname = surname;
    student -> group = group;
    student -> marks = marks;
    return student;
}

void searchAVG(Student **students, int counter, FILE * fileOut, error *err){
    if (*err != SUCCESS){
        return;
    }
    if (counter == 0) {
        fprintf(fileOut, "No students to process.\n");
        *err = ERROR_FUNC;
        return;
    }
    double avg = averageALL(students, counter,err);
    fprintf(fileOut, "Name + Surname of students with point > AVG_point: \n");
    for(int i = 0; i < counter; i++){
        if(*err == SUCCESS && averageM(students[i]->marks,err) > avg){
            printStudent(fileOut, students[i],err);
        }
    }
    if (*err == SUCCESS){
        printf("All students with points more than AVG written \n");
    }
}

//поиск
void searchID(Student** students, int counter, FILE * fileOut, error* err){
    if (*err != SUCCESS){
        return;
    }
    unsigned int id;
    int flag  = 0;
    printf("Enter ID of student: ");
    if (scanf("%u",&id) != 1){
        *err = ERROR_READ;
        return;
    }
    int answer;
    printf("\nWrite in trace file? 1/0\n");
    if (scanf("%d",&answer) != 1){
        *err = ERROR_READ;
        return;
    }
    while(answer != 0 && answer != 1){
        printf("Enter 1 or 0.\n");
        if (scanf("%d", &answer) != 1) {
            *err = ERROR_READ;
            return;
        }
    }
    if (answer == 0){
        flag = 0;
    } else{
        flag = 1;
    }
    bool done = false;
    for(int i = 0; i < counter; i++){
        if(students[i]->id == id){
            Student* student = students[i];
            done = true;
            printStudent(stdout, student, err);
            if(flag){
                printStudent(fileOut, student, err);
            }
        }
    }
    if (!done){
        fprintf(stdout, "No student with such id: %u \n", id);
        if (flag){
            fprintf(fileOut, "No student with such id: %u \n", id);
        }
    }
    
}

void searchSRNM(Student** students, int counter, FILE * fileOut, error* err){
    if (*err != SUCCESS){
        return;
    }
    char surname[100];
    int flag  = 0;
    printf("Enter surname of student: ");
    if (scanf("%99s", surname) != 1) {
        *err = ERROR_READ;
        return;
    }
    int answer;
    printf("\nWrite in trace file? 1/0\n");
    if (scanf("%d", &answer) != 1) {
        *err = ERROR_READ;
        return;
    }
    while(answer != 0 && answer != 1){
        printf("Enter 1 or 0.\n");
        if (scanf("%d", &answer) != 1) {
            *err = ERROR_READ;
            return;
        }
    }
    if (answer == 0){
        flag = 0;
    } else{
        flag = 1;
    }
    bool done = false;
    for(int i = 0; i < counter; i++){
        if(strcmp(students[i]->surname, surname) == 0){
            Student* student = students[i];
            done = true;
            printStudent(stdout, student, err);
            if(flag){
                printStudent(fileOut, student, err);
            }
        }
    }
    if (!done){
        fprintf(stdout, "No student with such surname: %s \n", surname);
        if (flag){
            fprintf(fileOut, "No student with such surname: %s \n", surname);
        }
    }
}
void searchNM(Student** students, int counter, FILE * fileOut, error *err){
    if (*err != SUCCESS){
        return;
    }
    char name[100];
    int flag  = 0;
    printf("Enter name of student: ");
    if (scanf("%99s", name) != 1) {
        *err = ERROR_READ;
        return;
    }
    int answer;
    printf("\nWrite in trace file? 1/0\n");
    if (scanf("%d", &answer) != 1) {
        *err = ERROR_READ;
        return;
    }
    while(answer != 0 && answer != 1){
        printf("Enter 1 or 0.\n");
        if (scanf("%d", &answer) != 1) {
            *err = ERROR_READ;
            return;
        }
    }
    if (answer == 0){
        flag = 0;
    } else{
        flag = 1;
    }
    bool done = false;
    for(int i = 0; i < counter; i++){
        if(strcmp(students[i]->name, name) == 0){
            Student* student = students[i];
            done = true;
            printStudent(stdout, student, err);
            if(flag){
                printStudent(fileOut, student, err);
            }
        }
    }
    if (!done){
        fprintf(stdout, "No student with such name: %s \n", name);
        if (flag){
            fprintf(fileOut, "No student with such name: %s \n", name);
        }
    }
}

void searchGRP(Student** students, int counter, FILE * fileOut,  error* err){
    if (*err != SUCCESS){
        return;
    }
    char group[100];
    int flag  = 0;
    printf("Enter group of student: ");
    if (scanf("%99s", group) != 1) {
        *err = ERROR_READ;
        return;
    }
    int answer;
    printf("\nWrite in trace file? 1/0\n");
    if (scanf("%d", &answer) != 1) {
        *err = ERROR_READ;
        return;
    }
    while(answer != 0 && answer != 1){
        printf("Enter 1 or 0.\n");
        if (scanf("%d", &answer) != 1) {
            *err = ERROR_READ;
            return;
        }
    }
    if (answer == 0){
        flag = 0;
    } else{
        flag = 1;
    }
    bool done = false;
    for(int i = 0; i < counter; i++){
        if(strcmp(students[i]->group, group) == 0){
            Student* student = students[i];
            done = true;
            printStudent(stdout, student, err);
            if(flag){
                printStudent(fileOut, student, err);
            }
        }
    }
    if (!done){
        fprintf(stdout, "No student with such group: %s \n", group);
        if (flag){
            fprintf(fileOut, "No student with such group: %s \n", group);
        }
    }
}

//Компараторы для qsort
int cmpID(const void* stud1, const void* stud2){
    const Student *student1 = *(Student **)stud1;
    const Student *student2 = *(Student **)stud2;
    if (student1->id < student2 ->id){
        return -1;
    } else if (student1->id > student2 -> id){
        return 1;
    }else{
        return 0;
    }
}
int cmpSRNM(const void *stud1, const void* stud2){
    const Student *student1 = *(Student **)stud1;
    const Student *student2 = *(Student **)stud2;
    return strcmp(student1->surname, student2->surname);
}
int cmpNM(const void *stud1, const void* stud2){
    const Student *student1 = *(Student **)stud1;
    const Student *student2 = *(Student **)stud2;
    return strcmp(student1->name, student2->name);
}
int cmpGRP(const void *stud1, const void* stud2){
    const Student *student1 = *(Student **)stud1;
    const Student *student2 = *(Student **)stud2;
    return strcmp(student1->group, student2->group);
}


//сортировка Хэндлеры
void handleSortID(Student** students, int counter, error* err){
    if (*err != SUCCESS){
        return;
    }
    if (students == NULL || counter <= 0) {
        *err = ERROR_FUNC;
        return;
    }
    qsort(students, counter, sizeof(Student*), cmpID);
    printf("\nSorted by id\n");
}
void handleSortSRNM(Student** students, int counter, error* err){
    if (*err != SUCCESS){
        return;
    }
    if (students == NULL || counter <= 0) {
        *err = ERROR_FUNC;
        return;
    }
    qsort(students, counter, sizeof(Student*), cmpSRNM);
    printf("\nSorted by surname\n");
}
void handleSortNM(Student** students, int counter, error* err){
    if (*err != SUCCESS){
        return;
    }
    if (students == NULL || counter <= 0) {
        *err = ERROR_FUNC;
        return;
    }
    qsort(students, counter, sizeof(Student*), cmpNM);
    printf("\nSorted by name\n");
}
void handleSortGRP(Student** students, int counter, error* err){
    if (*err != SUCCESS){
        return;
    }
    if (students == NULL || counter <= 0) {
        *err = ERROR_FUNC;
        return;
    }
    qsort(students, counter, sizeof(Student*), cmpGRP);
    printf("\nSorted by group\n");
}

//Деструктор
void freeStudents(Student** students, int counter, error* err) {
    if (students == NULL){
        return;
    }
    printf("\nKILLING STUDENTS...\n");
    for (int i = 0; i < counter; i++) {
        if (students[i] != NULL) {
            free(students[i]->name);
            free(students[i]->surname);
            free(students[i]->group);
            free(students[i]->marks);
            free(students[i]);
        }
    }
    free(students);
    printf("STUDENTS KILLED SUCCESS\n");
}
