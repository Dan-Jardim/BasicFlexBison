#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

char* concat_strings(const char* str1, const char* str2) {
    char* result = (char*) malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

void print_indent(int depth) {
    for (int i = 0; i < depth; ++i) {
        printf("  ");
    }
}

void print_branch(int depth) {
    int i;
    for (i = 1; i < depth; i++) {
        printf("|  ");
    }
    printf("+-- ");
}