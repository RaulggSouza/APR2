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

T_STUDENT* create_student(char* id, char* name, float* grades);
T_STUDENT_LIST* create_student_list(int max);
int is_empty(T_STUDENT_LIST* list);
int is_full(T_STUDENT_LIST* list);
int search_student(T_STUDENT_LIST* list, char *id);
int add_student(T_STUDENT_LIST* list, T_STUDENT *student);
int free_student(T_STUDENT *student);
int free_student_list(T_STUDENT_LIST* list);
int remove_student(T_STUDENT_LIST* list, char* id);
int len(T_STUDENT_LIST *students);
T_STUDENT* collect_student_info(T_STUDENT_LIST* list);
int print_student(T_STUDENT_LIST* students, char* id);
int print_all_students(T_STUDENT_LIST* list);
int menu();