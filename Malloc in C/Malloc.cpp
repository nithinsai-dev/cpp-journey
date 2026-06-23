//
// Created by NITHIN SAI on 23-06-2026.
//

#include "Malloc.h"
#include <cstdio>
#include <cstdlib>

int main() {
    int number = 0;
    printf("Enter the number of grades: ");
    scanf("%d", &number);

    char* grades = (char*) malloc(number * sizeof(char));

    if (grades == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < number; i++) {
        printf("Enter grade %d: ", i + 1);
        scanf(" %c", &grades[i]);
    }

    for (int i = 0; i < number; i++) {
        printf(" %c ", grades[i]);
    }

    printf("\n");
    free(grades);
    return 0;
}