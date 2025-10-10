#include <stdio.h>
#include <time.h>
#include "functions.h"
#include "escola.c"

#define TRUE 1
#define FALSE 0
#define CURRENT_YEAR 2025

// Main Screen
void main_screen()
{

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
            int registration, day, month, year, cpf;
            char name, sex;
            printf("Digite, na respectiva ordem, os dados do aluno (Matrícula, nome, sexo, dia mês e ano de nascimento, cpf: \n)");
            scanf("%d %s %c %d %d %d %d", &registration, &name, &sex, &day, &month, &year, &cpf);
            new_student(&student, &count_students, registration, name, sex, day, month, year, cpf);
            sleep(3);
            system('clear' || 'cls');
            main_screen();
            break;
        case 2:
            int registration, day, month, year, cpf;
            char name[MAX_STR], sex;
            printf("Digite, na respectiva ordem, os dados do professor (Matrícula, nome, sexo, dia mês e ano de nascimento, cpf: \n)");
            scanf("%d %s %c %d %d %d %d", &registration, &name, &sex, &day, &month, &year, &cpf);
            new_student(teacher, &count_teachers, registration, name, sex, day, month, year, cpf);
            sleep(3);
            system('clear' || 'cls');
            main_screen();
            break;
        case 3:
            int code, semester, teacher_registration;
            char name[MAX_STR];
            printf("Digite, na respectiva ordem, os dados da disciplina: código, nome, semestre, matrícula do professor responsável");
            scanf("%d %s %d %d", code, name, semester, teacher_registration);
            new_discipline(discipline, teacher, &count_disciplines, &count_teachers, code, name, semester, teacher_registration);
            sleep(3);
            system('clear' || 'cls');
            main_screen();
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
            printf("Obrigado por utilizar o programa!");
            break;

        default:
            printf("Resposta inválida! Digite novamente");
            break;
        }
    }
}

// Crud

void new_student(People student[],
                 int *count,
                 int registration,
                 char name[MAX_STR],
                 char sex,
                 int day,
                 int month,
                 int year,
                 int cpf)
{
    // validação

    if (sizeof(student) >= 1023)
    {
        printf("Não foi possível cadastrar o novo aluno devido a falta de armazenamento");
        return;
    }

    for (int i = 0; i < *count; i++)
    {
        if (registration == student[i].registration)
        {
            printf("Esse aluno já existe! Favor inserir outra matrícula.");
            return;
        }

        while (name[i] != '\0')
        {
            if (name[i] > 'z' || name[i] < 'a' && name[i] > 'Z' || name[i] < 'A')
            {
                printf("Por favor, digite apenas letras ao informar o nome!");
                return;
            }

            if (name[i] > 'a')
            {
                name[i] = name[i] - 'a' + 'A';
            }
        }

        if (sex != 'M' || sex != 'm' || sex != 'F' || sex != 'f')
        {
            printf("Sexo inválido!");
            return;
        }

        if (day > 31 || day < 0)
        {
            printf("Dia inválido!");
            return;
        }

        if (month == 1 || month == 4 || month == 6 || month == 9 || month == 11 && day > 30 || month == 2 && day > 28)
        {
            printf("Dia inválido");
            return;
        }

        if (year < CURRENT_YEAR)
        {
            printf("Ano inválido");
            return;
        }

        if (sizeof(cpf) != 11)
        {
            printf("CPF inválido");
            return;
        }
    }

    // inserção

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

    printf("Aluno registrado com sucesso!");
}
void new_teacher(People teacher[],
                 int *count,
                 int registration,
                 char name[MAX_STR],
                 char sex,
                 int day,
                 int month,
                 int year,
                 int cpf)
{

    // validação

    if (sizeof(teacher) >= 1023)
    {
        printf("Não foi possível cadastrar o novo professor devido a falta de armazenamento");
        return;
    }

    for (int i = 0; i < *count; i++)
    {
        if (registration == teacher[i].registration)
        {
            printf("Esse professor já existe! Favor inserir outra matrícula.");
            return;
        }
    }

    int i = 0;

    while (name[i] != '\0')
    {
        if (name[i] > 'z' || name[i] < 'a' && name[i] > 'Z' || name[i] < 'A')
        {
            printf("Por favor, digite apenas letras ao informar o nome!");
            return;
        }

        if (name[i] > 'a')
        {
            name[i] = name[i] - 'a' + 'A';
        }

        i++;
    }

    if (sex != 'M' || sex != 'm' || sex != 'F' || sex != 'f')
    {
        printf("Sexo inválido!");
        return;
    }

    if (day > 31 || day < 0)
    {
        printf("Dia inválido!");
        return;
    }

    if (month == 1 || month == 4 || month == 6 || month == 9 || month == 11 && day > 30 || month == 2 && day > 28)
    {
        printf("Data de nascimento inválida");
        return;
    }

    if (year < CURRENT_YEAR)
    {
        printf("Ano inválido");
        return;
    }

    if (sizeof(cpf) != 11)
    {
        printf("CPF inválido");
        return;
    }

    // inserção

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

    printf("Professor registrado com sucesso!");
}

void new_discipline(Disciplines discipline[], People teacher[], int *count_disciplines, int *count_teachers, int code, char name[], int semester, int teacher_registration)
{
    // validação

    int control = FALSE;

    if (sizeof(discipline) >=1023)
    {
        printf("Não foi possível adicionar a disciplina devido a falta de armazenamento");
        return;
    }
    

    for (int i = 0; i < *count_disciplines; i++)
    {
        if (code == discipline[i].code)
        {
            printf("Essa disciplina já existe! Favor inserir outro código.");
            return;
        }
    }

    int i = 0;

    while (name[i] != '\0')
    {
        if (name[i] > 'z' || name[i] < 'a' && name[i] > 'Z' || name[i] < 'A')
        {
            printf("Por favor, digite apenas letras ao informar o nome da disciplina!");
            return;
        }

        if (name[i] > 'a')
        {
            name[i] = name[i] - 'a' + 'A';
        }

        i++;
    }

    for (int i = 0; i < *count_teachers; i++)
    {
        if (teacher[i].registration == teacher_registration)
        {
            control = TRUE;
        }
        
    }
    
    if (control == FALSE)
    {
        printf("Professor não encontrado! Por favor, corrija a matrícula informada");
        return;
    }
    

    i = 0;

    discipline[*count_disciplines].code = code;

    while (name[i] != '\0')
    {
        discipline[*count_disciplines].name[i] = name[i];
        i++;
    }

    discipline[*count_disciplines].semester = semester;

    discipline[*count_disciplines].teacher_registration = teacher;
}

// aux é a variável que conta quantos nomes com a mesma letra há no vetor
// position é a variável que guarda a posição da próxima cadeia de nomes com a mesma inicial

void alphabetic(People a[], int *count)
{
    int i, j, aux = 0, position = 0;
    int l = 1;
    char temp;

    for (i = 0; i < *count; i++)
    {
        for (j = 1; j <= *count; j++)
        {
            if (a[i].name[0] > a[j].name[0])
            {
                temp = a[j].name[0];
                a[j].name[0] = a[i].name[0];
                a[i].name[0] = temp;
            }
        }
    }

    for (i = 0; i < *count; i++)
    {
        while (a[position].name[0] == a[position + 1].name[0])
        {
            aux++;
        }

        for (j = 0; j < aux; j++)
        {
            for (int k = j + 1; k <= aux; k++)
            {
                while (a[aux].name[l] == a[aux + 1].name[l] || a[aux].name[l] == '\0')
                {
                    l++;
                }

                if (a[i].name[l] > a[j].name[l])
                {
                    temp = a[j].name[1];
                    a[j].name[1] = a[i].name[1];
                    a[i].name[1] = temp;
                }
            }
        }

        position += aux;
        aux = 0;
    }
}

void insert_student(Student_per_discipline s_and_d[], People s[], Disciplines d[], int registration, int code, int *count)
{

    s_and_d[*count].code = code;
    s_and_d[*count].registration = registration;
}

void delete_student_in_discipline(Student_per_discipline a[], int registration, int code, int *count)
{
    int control = FALSE;
    int aux;

    for (int i = 0; i < *count; i++)
    {
        if (a[i].code == code && a[i].registration == registration)
        {

            a[*count + 1].code = a[i].code;
            a[*count + 1].registration = a[i].registration;

            aux = *count - i;

            while (aux != 0)
            {
                int j = 0;
                a[i + j].code = a[i + j + 1].code;
                a[i + j].registration = a[i + j + 1].registration;

                j++;
                aux--;
            }

            control = TRUE;
        }
    }

    if (control == FALSE)
    {
        printf("O aluno não está matriculado nessa disciplina, ou ela não existe!");
    }
    else
    {
        *count--;
    }
}

void students_in_three_disciplines(Student_per_discipline a[], People s[], int *count_s_p_d, int *count_s)
{

    int disciplines = 0;

    for (int i = 0; i < *count_s_p_d; i++)
    {
        for (int j = 0; j <= *count_s_p_d; j++)
        {

            if (a[i].registration == a[j].registration)
            {
                disciplines++;
            }
        }

        if (disciplines < 3)
        {
            for (int k = 0; k < *count_s; k++)
            {
                if (s[k].registration == a[i].registration)
                {
                    printf("%s, Matrícula: %d, matriculado em %d disciplinas \n", s[k].name, a[i].registration, disciplines);
                }
            }
        }

        disciplines = 0;
    }
}

void overcharge_disciplines(Student_per_discipline s_p_d[], Disciplines d[], People t[], int *count_s_p_d, int *count_t)
{
    int students = 0;

    for (int i = 0; i < *count_s_p_d; i++)
    {
        for (int j = 0; j <= *count_s_p_d; j++)
        {

            if (s_p_d[i].code == s_p_d[j].code)
            {
                students++;
            }
        }

        if (students > 40)
        {
            for (int k = 0; k < *count_t; k++)
            {
                if (d[k].code == d[i].code)
                {
                    int teacher = d[k].teacher_registration;

                    for (int l = 0; l < *count_t; l++)
                    {
                        if (t[l].registration == teacher)
                        {
                            printf("%s, Matrícula: %d, cuja disciplina (%s, código: %d) possui %d vagas \n", t[l].name, t[l].registration, d[k].name, d[k].code, students);
                        }
                    }
                }
            }
        }

        students = 0;
    }
}

void str_research(People t[], People s[], char str[], int *count_t, int *count_s)
{
    // validação
    int checker = sizeof(str);

    if (checker < 3)
    {
        printf("É necessário pelo menos 3 palavras para realizar a busca!");
        return;
    }

    // função

    int same_char = 0;

    printf("Professores: \n");

    for (int i = 0; i <= *count_t; i++)
    {
        int j = 0;
        int k = 0;

        while (t[i].name[j] != '\0' || str[k] != '\0')
        {
            if (t[i].name[j] == str[k])
            {
                k++;
                same_char++;
            }

            if (t[i].name[j] != str[k])
            {
                k = 0;
                same_char = 0;
            }

            j++;
        }

        if (same_char == checker)
        {
            printf("%s \n", t[i].name);
        }

        same_char = 0;
    }

    printf("Alunos: \n");

    for (int i = 0; i <= *count_s; i++)
    {
        int j = 0;
        int k = 0;

        while (s[i].name[j] != '\0' || str[k] != '\0')
        {
            if (s[i].name[j] == str[k])
            {
                k++;
                same_char++;
            }

            if (s[i].name[j] != str[k])
            {
                k = 0;
                same_char = 0;
            }

            j++;
        }

        if (same_char == checker)
        {
            printf("%s \n", s[i].name);
        }

        same_char = 0;
    }
}

void birthday_order(People a[], int *count)
{
    int temp, aux = 0, position = 0;
    int i, j, k, l, m, n;

    for (i = 0; i < *count; i++)
    {
        for (j = 1; j <= *count; j++)
        {
            if (a[i].year > a[j].year)
            {
                temp = a[i].year;
                a[i].year = a[j].year;
                a[j].year = temp;
            }
        }
    }

    for (int i = 0; i < *count; i++)
    {
        while (a[position].year == a[position + 1].year)
        {
            aux++;
        }

        for (k = 0; k < aux; k++)
        {
            for (l = 1; l <= aux; l++)
            {
                if (a[k].month > a[l].month)
                {
                    temp = a[k].month;
                    a[k].month = a[l].month;
                    a[l].month = temp;
                }
            }
        }

        position += aux;
        aux = 0;
    }

    position = 0;

    for (int i = 0; i < *count; i++)
    {
        while (a[position].month == a[position + 1].month)
        {
            aux++;
        }

        for (m = 0; m < aux; m++)
        {
            for (n = 1; n <= aux; n++)
            {
                if (a[m].day < a[n].day)
                {
                    temp = a[m].day;
                    a[m].day = a[n].day;
                    a[n].day = temp;
                }
            }
        }
        position += aux;
        aux = 0;
    }

    for (int i = 0; i < *count; i++)
    {
    }
}