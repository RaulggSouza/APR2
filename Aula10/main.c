#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_student.h"


int main(int argc, char const *argv[]){
    T_STUDENT_LIST* course;
    course = create_student_list(10);
    int option;
    do{
        option = menu();
        if(option == 1){
            T_STUDENT* student = collect_student_info(course);
            if (student == NULL){
                printf("A STUDENT WITH THIS ID ALREADY EXISTS\n");    
            }else{
                if (add_student(course, student) == 1){
                    printf("STUDENT ADDED SUCCESSFULLY\n");
                }else{
                    printf("COURSE ALREADY FULL\n");
                }
            }
        }else if(option == 2){
            printf("Length of the students list: %d\n", len(course));
        }else if(option == 3){
            getchar();
            char print_id[16];
            fgets(print_id, sizeof(print_id), stdin);
            print_id[strcspn(print_id, "\n")] = '\0';
            print_student(course, print_id);
        }else if(option == 4){
            print_all_students(course);
        }else if (option == 5){
            getchar();
            char remove_id[16];
            fgets(remove_id, sizeof(remove_id), stdin);
            remove_id[strcspn(remove_id, "\n")] = '\0';
            remove_student(course, remove_id);
        }else{
            free_student_list(course);
            printf("Ending program...");
        }
    }while(option != 6);
    return 0;
}
