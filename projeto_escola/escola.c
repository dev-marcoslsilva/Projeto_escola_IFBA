#include <stdio.h>
#include "functions.h"
#define MAX_STR 502
#define TAM_VETOR 1024

//Structs 
typedef struct people
{
    int registration; 
    char name[MAX_STR];
    char sex;
    int day;
    int month;
    int year;
    int cpf;

}People;



typedef struct d{
    int code;
    char name[MAX_STR];
    int semester;
    int teacher_registration; 
} Disciplines;

typedef struct disciplines_and_students
{
    int registration;
    int code;
}Student_per_discipline;

People student[TAM_VETOR];
People teacher[TAM_VETOR];
Disciplines discipline[TAM_VETOR];    
int count_students = 0;    
int count_teachers;
int count_disciplines;
int count_students_per_disciplines;

int main(){

    main_screen();

    return 0;
}
