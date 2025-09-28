#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

typedef struct student
{
    char name[20];
    int age;
    char department[10];
    int id;
    float point;
    char SF[30];
    struct student *next;
} student;

void gotoxy(int x, int y)
{
    COORD CRD;
    CRD.X = x;
    CRD.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void textcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printChar(char ch, int n)
{
    while (n--)
    {
        putchar(ch);
    }
}

void title()
{
    system("cls");
    system("COLOR 03");
    printf("\n\n\t\t\t\t\t\t\t\t");
    printChar('=', 19);
    printf(" Student Management System ");
    printChar('=', 19);
    printf("\n");
}

void pointcolor(float point);
void resultcolor(float point);
void changestudents();
void delet_student();

int main()
{
    struct student *head = NULL;
    int choice, m = 0;
    FILE *file;
    char password[20], ch;
    char user_input[20];
    SetConsoleTitle("Student Management System | DIU");

    file = fopen("password.txt", "r");

    if (file == NULL)
    {
        textcolor(1);
        gotoxy(42, 3);
        printf("please enter the your password: ");
        gotoxy(75, 3);
        scanf("%s", password);

        file = fopen("password.txt", "w");

        if (file == NULL)
        {
            printf("error creating file! \n");
            return 1;
        }
        fprintf(file, "%s", password);
        fclose(file);
        gotoxy(40, 4);
        textcolor(2);
        printf("password has been successful saved, restart the program! \n");
        return 0;
    }
    else
    {
        fscanf(file, "%s", password);
        fclose(file);

        // printf("enter the password: ");
        // scanf("%s",user_input);

        system("color 06");
        gotoxy(42, 8);
        printf("LOGIN(If 1st login press ENTER)");
        gotoxy(42, 10);
        printf("____________________________________");
        gotoxy(42, 11);
        printf("|\tenter the password:          |");
        gotoxy(42, 12);
        printf("|__________________________________|");
        gotoxy(68, 11);
        while (1)
        {
            ch = getch();
            if (ch == 13)
            {
                user_input[m] = '\0';
                break;
            }
            else if (ch == 8)
            {
                if (m > 0)
                {
                    m--;
                    printf("\b \b");
                }
            }
            else if (m < sizeof(user_input) - 1)
            {
                user_input[m++] = ch;
                printf("*");
            }
        }
        printf(" \n\n\n\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
        printf("\n\n\t\t\t\t\t     *                    *");
        printf("\n\n\t\t\t\t\t     *       Welcome      *");
        printf("\n\n\t\t\t\t\t     *                    *");
        printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
        do
        {
            printf("\n\n\n\n\n\t\t\t\t\tPlease press the Enter key");
            for (int i = 0; i < 6; i++)
            {
                printf(".");
                Sleep(500);
            }
            ch = getch();
        } while (ch != 13);

        if (strcmp(user_input, password) == 0)
        {
            system("cls");
            gotoxy(10, 3);
            printf("<<<< Loading Please Wait >>>>");
            for (int i = 0; i < 5; i++)
            {
                printf("\t(*_*)");
                Sleep(500);
            }
            gotoxy(15, 5);
            printf("Please press the Enter key.\n");
            gotoxy(45, 5);
            do
            {
                ch = getch();
            } while (ch != 13);
            printf("\n");
            printf("\n");
            do
            {
                printf("\033[44;97m\t\t\t\tplease choose what you want to do\033[0m\n");
                printf("\n");
                printf("\033[44;97m\t\t\t\t\t\t1: create a student list.\033[0m\n");
                printf("\033[44;97m\t\t\t\t\t\t2: view students.\033[0m\n");
                printf("\033[44;97m\t\t\t\t\t\t3: add students.\033[0m\n");
                printf("\033[44;97m\t\t\t\t\t\t4: change student information.\033[0m\n");
                printf("\033[44;97m\t\t\t\t\t\t5: delete student.\033[0m\n");
                printf("\033[44;97m\t\t\t\t\t\t6: exit the menu.\033[0m\n");
                printf("\033[1;97m\t\t\t\t\t\tplease enter your choice: \033[0m");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                {
                    title();
                    system("color 09");
                    FILE *f = fopen("student_information.csv", "w");
                    if (f == NULL)
                    {
                        printf("The file is not found!\n");
                        return 0;
                    }
                    else
                    {
                        head = malloc(sizeof(struct student));
                        struct student *students = head;
                        int num;
                        gotoxy(20, 3);
                        printf("Please enter the number of students: ");
                        scanf("%d", &num);

                        // كتابة رؤوس الأعمدة في الملف
                        fprintf(f, "NAME;AGE;DEPARTMENT;ID;POINT;RESULT\n");

                        for (int i = 1; i <= num; i++)
                        {
                            printf("\t\t\t\t\tEnter the name[%d]: ", i);
                            scanf(" %[^\n]", students->name);
                            printf("\n");
                            printf("\t\t\t\t\tEnter the age[%d]: ", i);
                            scanf("%d", &students->age);
                            printf("\n");
                            printf("\t\t\t\t\tEnter the department[%d]: ", i);
                            scanf("%s", students->department);
                            printf("\n");
                            srand(time(NULL));
                            int random_number = 100000 + rand() % 900000;
                            students->id = random_number;

                            printf("\t\t\t\t\tEnter the point[%d]: ", i);
                            scanf("%f", &students->point);

                            if (students->point >= 10.0)
                            {
                                strcpy(students->SF, "PASSED");
                            }
                            else
                            {
                                strcpy(students->SF, "FAILED");
                            }

                            fprintf(f, "%s;%d;%s;%d;%.2f;%s\n",
                                    students->name, students->age, students->department, students->id, students->point, students->SF);

                            if (i < num)
                            {
                                students->next = malloc(sizeof(struct student));
                                students = students->next;
                            }
                            else
                            {
                                students->next = NULL;
                            }
                        }
                        fclose(f);
                        printf("\033[40;92m\t\t\t\t\t\t\t Data was written successfully \033[0m\n");
                        printf("\n");
                    }
                }
                break;
                case 2:
                {
                    title();
                    FILE *f = fopen("student_information.csv", "r");
                    if (f == NULL)
                    {
                        printf("The file is not found!\n");
                        return 0;
                    }
                    else
                    {
                        struct student temp;
                        char line[256];

                        while (fgets(line, sizeof(line), f))
                        {
                            if (sscanf(line, "%[^;];%d;%[^;];%d;%f;%s", temp.name, &temp.age, temp.department, &temp.id, &temp.point, temp.SF) == 6)
                            {
                                printf("\t\t\t\t\t\tNAME: %s\t AGE: %d\t DEPARTMENT: %s\t ID: %d\t POINT:", temp.name, temp.age, temp.department, temp.id);
                                pointcolor(temp.point);
                                printf("\t\t\t\t\t\t\t\tRESULT:");
                                resultcolor(temp.point);
                            }
                        }
                    }
                    fclose(f);
                }
                break;
                case 3:
                {
                    title();
                    system("color 09");
                    FILE *f = fopen("student_information.csv", "a");
                    if (f == NULL)
                    {
                        printf("The file is not found!\n");
                        return 0;
                    }
                    else
                    {
                        head = malloc(sizeof(struct student));
                        struct student *students = head;
                        int num;
                        printf("Please enter the number of students: ");
                        scanf("%d", &num);

                        for (int i = 1; i <= num; i++)
                        {
                            printf("\t\t\t\t\t\tEnter the name[%d]: ", i);
                            scanf(" %[^\n]", students->name);
                            printf("\n");
                            printf("\t\t\t\t\t\tEnter the age[%d]: ", i);
                            scanf("%d", &students->age);
                            printf("\n");
                            printf("\t\t\t\t\t\tEnter the department[%d]: ", i);
                            scanf("%s", students->department);
                            printf("\n");
                            srand(time(NULL));
                            int random_number = 100000 + rand() % 900000;
                            students->id = random_number;

                            printf("Enter the point[%d]: ", i);
                            scanf("%f", &students->point);

                            if (students->point >= 10.0)
                            {
                                strcpy(students->SF, "PASSED");
                            }
                            else
                            {
                                strcpy(students->SF, "FAILED");
                            }

                            fprintf(f, "%s;%d;%s;%d;%.2f;%s\n",
                                    students->name, students->age, students->department, students->id, students->point, students->SF);

                            if (i < num)
                            {
                                students->next = malloc(sizeof(struct student));
                                students = students->next;
                            }
                            else
                            {
                                students->next = NULL;
                            }
                        }
                        fclose(f);
                        printf("\033[42;97m\t\t\t\t\t\t\tData was written successfully \033[0m\n");
                    }
                }
                break;
                case 4:
                {
                    system("color 09");
                    changestudents();
                }
                break;
                case 5:
                {
                    system("color 09");
                    delet_student();
                }
                break;
                case 6:
                {
                    system("color 09");
                    printf("SEE YOU SOON!");
                }
                break;
                default:
                {
                    system("color 09");
                    printf("The number you entered does not exist.");
                }
                break;
                }

            } while (choice != 6);

            return 0;
        }
        else
        {
            printf("\t\t\t\t\t\\033[40;91m\nThe password is incorrect, try again\033[0m\n");
            return 1;
        }
    }
}

void pointcolor(float point)
{
    if (point < 10)
    {
        printf("\033[0;31m%.2f\033[0m\n", point); 
    }
    else
    {
        printf("\033[0;32m%.2f\033[0m\n", point); 
    }
}

void resultcolor(float point)
{
    if (point < 10)
    {
        printf("\033[0;31m%s\033[0m\n", "FAILED");
    }
    else
    {
        printf("\033[0;32m%s\033[0m\n", "PASSED");
    }
}

void changestudents()
{
    title();
    FILE *f = fopen("student_information.csv", "r");
    if (f == NULL)
    {
        printf("The file is not found!\n");
        return;
    }
    student students[100];
    int count = 0;
    char line[256];

    fgets(line, sizeof(line), f);

    while (fgets(line, sizeof(line), f))
    {
        if (sscanf(line, "%[^;];%d;%[^;];%d;%f;%s",
                   students[count].name,
                   &students[count].age,
                   students[count].department,
                   &students[count].id,
                   &students[count].point,
                   students[count].SF) == 6)
        {
            count++;
        }
    }
    fclose(f);

    int ID, choice, found = 0;
    printf("\t\t\t\t\t\tplease enter the student ID: ");
    scanf("%d", &ID);

    for (int i = 0; i < count; i++)
    {
        if (students[i].id == ID)
        {
            found = 1;
            printf("\n\t\t\t\t\t\t1. change name.\n");
            printf("\t\t\t\t\t\t2. change age.\n");
            printf("\t\t\t\t\t\t3. change department.\n");
            printf("\t\t\t\t\t\t4. change point.\n");
            printf("\t\t\t\t\t\t5. change SF.\n");
            printf("\t\t\t\t\t\t6. exit.\n");
            printf("\t\t\t\t\t\tWHAT DO YOU WANT TO CHANGE: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("\t\t\t\t\tEnter the new name: ");
                scanf(" %[^\n]", students[i].name);
                break;
            case 2:
                printf("\t\t\t\t\tEnter the new age: ");
                scanf("%d", &students[i].age);
                break;
            case 3:
                printf("\t\t\t\t\tEnter the new department: ");
                scanf("%s", students[i].department);
                break;
            case 4:
                printf("\t\t\t\t\tEnter the new point: ");
                scanf("%f", &students[i].point);
                break;
            case 5:
                printf("\t\t\t\t\tEnter the new SF: ");
                scanf("%s", students[i].SF);
                break;
            case 6:
                printf("\t\t\t\t\t\tNo changes made.\n");
                return;
            default:
                printf("\t\t\t\t\t\tInvalid choice.\n");
                return;
            }
            break;
        }
    }
    if (found)
    {
        FILE *f = fopen("student_information.csv", "w");
        if (f == NULL)
        {
            printf("\t\t\t\t\t\tUnable to open file for writing.\n");
            return;
        }

        fprintf(f, "NAME;AGE;DEPARTMENT;ID;POINT;RESULT\n");

        for (int i = 0; i < count; i++)
        {
            fprintf(f, "%s;%d;%s;%d;%.2f;%s\n",
                    students[i].name,
                    students[i].age,
                    students[i].department,
                    students[i].id,
                    students[i].point,
                    students[i].SF);
        }

        fclose(f);
        printf("\033[40;92m\t\t\t\t\t\tStudent information updated successfully.\033[0m\n");
    }
}

void delet_student()
{
    title();
    FILE *f = fopen("student_information.csv", "r");
    if (f == NULL)
    {
        printf("The file is not found!\n");
        return;
    }

    student students[100];
    int count = 0;
    char line[256];

    fgets(line, sizeof(line), f);
    while (fgets(line, sizeof(line), f))
    {
        if (sscanf(line, "%[^;];%d;%[^;];%d;%f;%s",
                   students[count].name,
                   &students[count].age,
                   students[count].department,
                   &students[count].id,
                   &students[count].point,
                   students[count].SF) == 6)
        {
            count++;
        }
    }
    fclose(f);

    int id_s, found = 0;
    printf("\t\t\t\t\tPlease enter the student ID to delete: ");
    scanf("%d", &id_s);

    FILE *fw = fopen("student_information.csv", "w");
    if (fw == NULL)
    {
        printf("\t\t\t\t\tUnable to open file for writing.\n");
        return;
    }
    fprintf(fw, "NAME;AGE;DEPARTMENT;ID;POINT;RESULT\n");

    for (int i = 0; i < count; i++)
    {
        if (students[i].id != id_s)
        {
            fprintf(fw, "%s;%d;%s;%d;%.2f;%s\n",
                    students[i].name,
                    students[i].age,
                    students[i].department,
                    students[i].id,
                    students[i].point,
                    students[i].SF);
        }
        else
        {
            found = 1;
        }
    }
    fclose(fw);

    if (found)
    {
        printf("\033[40;92m\t\t\t\t\tStudent deleted successfully.\033[0m\n");
    }
    else
    {
        printf("\033[40;91m\t\t\t\t\tStudent with ID %d not found.\033[0m\n", id_s);
    }
}