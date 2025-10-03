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
    char teacher[MAX_STR]; 
} Disciplines;


int main(){
    
    People student[TAM_VETOR];
    People teacher[TAM_VETOR];
    Disciplines discipline[TAM_VETOR];
    int count = 0;    



    main_screen();

    return 0;
}
