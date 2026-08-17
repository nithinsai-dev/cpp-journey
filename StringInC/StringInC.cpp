//
// Created by NITHIN SAI on 16-08-2026.
//

#include "StringInC.h"
#include <cstdio>
#include <cstring>

int main() {

    char a[50] = "Hello";
    char b[] = "World";
    char c[50];

    printf("%zu",strlen(a));\
    strcpy(c,b);
    strncpy(c,b,3);
    c[8] = '\0';
    strcat(a,b);
    strncat(a,b,2);
    int result = strcmp(a,b);
    int r2 = strncmp(a,b,3);
    char *p1 = strchr(a,'l');
    char *p2 = strstr(a,b);

    return 0;
}
