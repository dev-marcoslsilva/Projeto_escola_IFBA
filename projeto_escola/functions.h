#pragma once
#include "escola.c"
#define MAX_STR 1024


void main_screen();
void new_student(People student[], 
                int *count, 
                int registration, 
                char name[MAX_STR], 
                char sex,
                int day,
                int month,
                int year,
                int cpf
);

void new_teacher(People teacher[], 
                int *count, 
                int registration, 
                char name[MAX_STR], 
                char sex,
                int day,
                int month,
                int year,
                int cpf
);

void new_discipline(Disciplines discipline[], int *count, int code, char name[], int semester, int teacher[]);

void alphabetic(People a[], int *count);