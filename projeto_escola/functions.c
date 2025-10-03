#include <stdio.h>
#include "functions.h"
#include "escola.c"

//Main Screen
void main_screen(){
    
    int awnser = -1;
    while (awnser != 29)
    {
        printf("Digite o que você gostaria de fazer: \n");
        printf("\n");
        printf("------------------REGISTROS---------------------- \n");
        printf("1 - Registrar novo aluno \n");
        printf("2 - Registrar novo professor \n");
        printf("3 - Registrar nova disciplina \n");
        printf("\n");
        printf("--------------------BUSCAS---------------------- \n");
        printf("Alunos: \n");
        printf("4 - Listar alunos \n");
        printf("8 - Listar alunos a partir do sexo\n");
        printf("9 - Listar alunos ordenados por nome\n");
        printf("10 - Listar alunos ordenados por data de nascimento\n");
        printf("11 -Listar relatório de alunos\n");
        printf("Professores: \n");
        printf("12 - Listar professores \n");
        printf("13 - Listar professores a partir do sexo\n");
        printf("14 - Listar professores ordenados por nome\n");
        printf("15 - Listar professores ordenados por data de nascimento\n");
        printf("Listar relatório de professores\n");
        printf("Disciplinas: \n");
        printf("16 - Listar disciplinas \n");
        printf("17 - Listar disciplinas e seus respectivos alunos\n");
        printf("18 - Listar alunos matriculados em menos de 3 disciplinas\n");
        printf("19 - Listar disciplinas que extrapolam 40 vagas\n");
        printf("Listar relatório de disciplinas\n");
        printf("Geral: \n");
        printf("20 - Buscar aluno ou professor específico \n");
        printf("21 - Listar aniversariantes do mês \n");
        printf("-------------------MODIFICAÇÕES---------------------- \n");
        printf("22 - Atualizar dados de aluno \n");
        printf("23 - Atualizar dados de professor \n");
        printf("24 - Atualizar dados de disciplinas \n");
        printf("--------------------EXCLUSÕES---------------------- \n");
        printf("25 - Excluir aluno \n");
        printf("26 - Excluir professor \n");
        printf("27 - Excluir disciplina \n");
        printf("28 - Excluir aluno de uma disciplina \n");
        printf("29 - Sair");
        
        scanf("%d", &awnser);

        switch (awnser)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;
        case 8:
            /* code */
            break;
        case 9:
            /* code */
            break;
        case 10:
            /* code */
            break;
        case 11:
            /* code */
            break;
        case 12:
            /* code */
            break;
        case 13:
            /* code */
            break;
        case 14:
            /* code */
            break;
        case 15:
            /* code */
            break;
        case 16:
            /* code */
            break;
        case 17:
            /* code */
            break;
        case 18:
            /* code */
            break;
        case 19:
            /* code */
            break;
        case 20:
            /* code */
            break;
        case 21:
            /* code */
            break;
        case 22:
            /* code */
            break;
        case 23:
            /* code */
            break;
        case 24:
            /* code */
            break;
        case 25:
            /* code */
            break;
        case 26:
            /* code */
            break;
        case 27:
            /* code */
            break;
        case 28:
            /* code */
            break;
        case 29:
            /* code */
            break;
        
        default:
            printf("Resposta inválida! Digite novamente");
            break;
        }
    }
    
}

//Crud

void new_student(People student[], 
                int *count, 
                int registration, 
                char name[MAX_STR], 
                char sex,
                int day,
                int month,
                int year,
                int cpf
){
    student[*count].registration = registration;
    
    while (name != '\0')
    {
        int i = 0;
        student[*count].name[i] = name[i];
        i++;
    }
    
    student[*count].sex = sex;
    student[*count].day = day;
    student[*count].month = month;
    student[*count].year = year;
    student[*count].cpf = cpf;
    
}
void new_teacher(People teacher[], 
                int *count, 
                int registration, 
                char name[MAX_STR], 
                char sex,
                int day,
                int month,
                int year,
                int cpf
){
    teacher[*count].registration = registration;
    int i = 0;
    
    while (name[i] != '\0')
    {
        teacher[*count].name[i] = name[i];
        i++;
    }
    
    teacher[*count].sex = sex;
    teacher[*count].day = day;
    teacher[*count].month = month;
    teacher[*count].year = year;
    teacher[*count].cpf = cpf;
    
}

void new_discipline(Disciplines discipline[], int *count,  int code, char name[], int semester, char teacher[]){
    
    int i = 0;
    
    
    discipline[*count].code = code;

    while (name[i] != '\0')
    {
        discipline[*count].name[i] = name[i];
        i++;
    }

    discipline[*count].semester = semester;

    i = 0;

    while (teacher[i] != '\0')
    {
        discipline[*count].teacher[i] = teacher[i];
        i++;
    }
        
    
}