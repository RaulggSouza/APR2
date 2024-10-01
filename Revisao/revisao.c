#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char id[16];
    char name[128];
    float* grades; // vetor de notas - armazena 4 notas - deve ser alocado dinamicamente
}T_STUDENT;

typedef struct{
    int max; // quantidade alocada na 'lista'
    int size; // quantidade de alunos inseridos na 'lista'
    T_STUDENT** students; // vetor de ponteiros para T_STUDENT.
}T_STUDENT_LIST;

T_STUDENT* create_student(char* id, char* name, float* grades){
    T_STUDENT* student;
    student = malloc(sizeof(T_STUDENT));
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
    list->students = malloc(sizeof(T_STUDENT*) * max);
    return list;
}

int is_empty(T_STUDENT_LIST* list){
    return list->size == 0;
}

int is_full(T_STUDENT_LIST* list){
    return list->size == list->max;
}

int search_student(T_STUDENT_LIST* list, char *id){
    for(int i = 0; i < list->size; i++){
        if (strcmp(list->students[i]->id, id) == 0){
            return i;
        }
    }
    return -1;
}

int add_student(T_STUDENT_LIST* list, T_STUDENT *student){
    if (!is_full(list)){
        list->students[list->size] = student;
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
    for(int i = 0; i < list->size; i++){
        free_student(list->students[i]);
    }
    free(list);
}

int remove_student(T_STUDENT_LIST* list, char* id){
    int student_found = search_student(list,id);
    if (!is_empty(list) && student_found >= 0){
        free_student(list->students[student_found]);
        for (int i = student_found; i < list->size; i++){
            list->students[i] = list->students[i+1];
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
    T_STUDENT* student;

    getchar();
    printf("Student id: ");
    fgets(id,16,stdin);
    id[strcspn(id, "\n")] = '\0';

    if (search_student(list,id) == -1){
        printf("Student name: ");
        fgets(name,128,stdin);
        name[strcspn(name, "\n")] = '\0';

        for (int i = 0; i < 4; i++){
            printf("Student grade number %d: ",i+1);
            scanf("%f",&grades[i]);
        }
        return create_student(id,name,grades);
    }
    return NULL;

}

int print_student(T_STUDENT_LIST* students, char* id){
    int student_found = search_student(students, id);
    if (student_found != -1){
        printf("id: %s\n", students->students[student_found]->id);
        printf("name: %s\n", students->students[student_found]->name);
        for (int i = 0; i < 4; i++){
            printf("grade number %d: %.2f\n", i+1, students->students[student_found]->grades[i]);    
        }
        printf("--------------------------------\n");
    }
}

int print_all_students(T_STUDENT_LIST* list){
    printf("--------------------------------\n");
        for (int i = 0; i < list->size; i++){
        print_student(list, list->students[i]->id);
    }
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

int main(int argc, char const *argv[]){
    T_STUDENT_LIST* course;
    course = create_student_list(10);
    int option;
    do{
        option = menu();
        if(option == 1){
            T_STUDENT* student = collect_student_info(course);
            if (student != NULL){
                if(add_student(course, student)){
                    printf("Student added successfully\n");
                }else{
                    printf("Fail adding new student\n");
                }
            }else{
                printf("Student already exists!\n");
            }
        }else if(option == 2){
            printf("Lenght of student's list: %d\n", len(course));
        }else if(option == 3){
            if (!is_empty(course)){
                char id[16];
                getchar();
                printf("Insert the id of the student who will be printed: ");
                fgets(id, sizeof(id),stdin);
                id[strcspn(id, "\n")] = '\0';
                printf("--------------------------------\n");
                print_student(course,id);
            }
        }else if(option == 4){
            if(!is_empty(course)){
                print_all_students(course);
            }
        }else if (option == 5){
            char id[16];
            getchar();
            printf("Insert the id of the student who will be removed: ");
            fgets(id, sizeof(id),stdin);
            id[strcspn(id, "\n")] = '\0';
            remove_student(course,id);
        }else{
            free_student_list(course);
            printf("Terminating program...");
        }
    }while(option != 6);
    return 0;
}
