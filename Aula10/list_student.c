#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_student.h"

T_STUDENT* create_student(char* id, char* name, float* grades){
    T_STUDENT* student = malloc(sizeof(T_STUDENT));
    strcpy(student->id, id);
    strcpy(student->name, name);
    student->grades = malloc(sizeof(float)*4);
    memcpy(student->grades, grades, sizeof(float)*4);
    return student;
}

T_STUDENT_LIST* create_student_list(int max){
    T_STUDENT_LIST* list;
    list = malloc(sizeof(T_STUDENT_LIST));
    list->max = max;
    list->size = 0;
    list->students = malloc(sizeof(T_STUDENT*) * max); //Alocates at the heap memory a number of spaces (an array) equal to the size of a T_STUDENT pointer * the max of students in that course
    return list;
}

int is_empty(T_STUDENT_LIST* list){
    if(list->size == 0){
        return 1;
    }
    return 0;
}

int is_full(T_STUDENT_LIST* list){
    if(list->size == list->max){
        return 1;
    }
    return 0;
}

int search_student(T_STUDENT_LIST* list, char *id){
    for (int i = 0; i < list->size; i++){
        if (strcmp(id, list->students[i]->id) == 0){
            return i;
        }
    }
    return -1;
}

int add_student(T_STUDENT_LIST* list, T_STUDENT *student){
    int i = list->size;
    if (!is_full(list)){
        list->students[i] = student;
        (list->size)++;
        return 1;
    }
    return 0;
}

int free_student(T_STUDENT *student){
    free(student->grades);
    free(student);
}

int free_student_list(T_STUDENT_LIST* list){
    for (int i = 0; i < list->size; i++){
        free_student(list->students[i]);
    }
    free(list);
}

int remove_student(T_STUDENT_LIST* list, char* id){
    int start_removing;
    if(!is_empty(list)){
        for(int i = 0; i < list->size; i++){
            if (list->students[i]->id == id){
                start_removing = 1;
                free_student(list->students[i]);
            }
            if (start_removing){
                list->students[i] = list->students[i+1];
            }
        }
        (list->size)--;
    }
}

int len(T_STUDENT_LIST *students){
    return students->size;
}

T_STUDENT* collect_student_info(T_STUDENT_LIST* list){
    char id[16];
    char name[128];
    float grades[4];
    
    getchar(); //Clean buffer
    printf("Insert the student id: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0'; //Remove from the answer the character \0

    int student_exists = search_student(list, id);
    if (student_exists == -1){
        printf("Insert the student name: ");
        fgets(name, sizeof(name), stdin);
        id[strcspn(id, "\n")] = '\0';

        for (int i = 0; i < 4; i++){
            printf("Insert the grade number %d: ", i+1);
            scanf("%f", &(grades[i]));
        }
        return create_student(id, name, grades);
    }
    return NULL;
}

int print_student(T_STUDENT_LIST* students, char* id){
    int index = search_student(students, id);
    T_STUDENT* student = students->students[index];
    if (index > -1){
        printf("ID: %s\n", student->id);
        printf("NAME: %s", student->name);
        for (int i = 0; i < 4; i++){
            printf("GRADE NUMBER %d: %.2f\n", i, student->grades[i]);
        }
    }else{
        printf("Student don't exist\n");
    }
}

int print_all_students(T_STUDENT_LIST* list){
    for (int i = 0; i < list->size; i++){
        printf("-----------------------------\n");
        print_student(list, list->students[i]->id);
    }
    printf("-----------------------------\n");
}

int menu(){
    int option;
    printf("STUDENT FUNCTIONS:\n");
    printf("1. Create Student \n");
    printf("2. Size of Course's student list\n");
    printf("3. Print a Student\n");
    printf("4. Print all Students\n");
    printf("5. Remove Student\n");
    printf("6. Terminate Program\n");
    do{
        printf("Type the function you want to execute: ");
        scanf("%d", &option);
    }while(option < 1 || option > 6);
    return option;
}