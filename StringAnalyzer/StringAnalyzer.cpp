//
// Created by NITHIN SAI on 16-08-2026.
//

#include "StringAnalyzer.h"
#include <stdio.h>
#include <string.h>

int calculateTotal(int marks[], int n);
void analyzeName(char name[]);
int factorial(int n);

int main()
{
    char name[50];
    int marks[5];
    int i, total, choice;

    printf("Enter student name: ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    printf("Enter marks for 5 subjects:\n");

    for (i = 0; i < 5; i++)
    {
        scanf("%d", &marks[i]);
    }

    total = calculateTotal(marks, 5);

    printf("\nStudent: %s\n", name);
    printf("Total: %d\n", total);
    printf("Average: %.2f\n", total / 5.0);

    if (total >= 450)
        printf("Grade: A\n");
    else if (total >= 350)
        printf("Grade: B\n");
    else if (total >= 250)
        printf("Grade: C\n");
    else
        printf("Grade: F\n");

    analyzeName(name);

    printf("Factorial of 5 = %d\n", factorial(5));

    return 0;
}

int calculateTotal(int marks[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total += marks[i];
    }

    return total;
}

void analyzeName(char name[])
{
    printf("\nName: %s\n", name);
    printf("Length: %lu\n", strlen(name));

    if (strstr(name, "a") != NULL)
        printf("The name contains 'a'.\n");
    else
        printf("The name does not contain 'a'.\n");
}

int factorial(int n)
{
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}