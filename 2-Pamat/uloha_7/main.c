/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lacal
 *
 * Created on Utorok, 2019, novembra 5, 10:30
 */

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

char* my_strcpy(char *str1, const char *str2);
char* my_strcat(char *str1, const char *str2);
void my_reverse(char *str);

int main(int argc, char** argv) {

    const char str2[] = "nitra";
    char str1[strlen(str2)];

    my_strcpy(str1, str2);
    printf("First string: %s\n", str1);
    printf("Second string: %s\n", str2);
    
    my_reverse(str2);
    printf("Reverse string: %s\n", str2);

    char append_string[] = "jeSuper";
    my_strcat(append_string, str2);
    printf("Append string: %s\n", append_string);

    return (EXIT_SUCCESS);
}

char* my_strcpy(char *str1, const char *str2) {
    char *s = str1;
    while (*str2) {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
    return s;
}

char* my_strcat(char *str1, const char *str2) {
    char *s = str1 + strlen(str1);
    while (*str2 != '\0') {
        *s++ = *str2++;
    }
    *s = '\0';
    return str1;
}

void my_reverse(char *str) {
    char *p1, *p2;

    if (!str || ! *str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}