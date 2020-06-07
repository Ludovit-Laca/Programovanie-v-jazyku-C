/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lacal
 *
 * Created on Utorok, 2019, novembra 5, 9:24
 */

#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>


int my_strlen(const char *s);
void my_gets(char *s, int n); // n je maximalny pocet znakov citanych zo vstupu
void my_puts(const char *s);


int main(int argc, char** argv) {
    
    int pocet = 0;
    const char s[] = "Nitra";
    pocet = my_strlen(s);
    printf("my_strlen: %d\n", pocet);
    
    my_puts(s);
    
    int n = 10;
    char p[n];
    my_gets(p,n);
    my_puts(p);

    return (EXIT_SUCCESS);
}

void my_puts(const char *s) {
    while (*s) {
        putchar(*s);
        s++;
    }
    putchar('\n');
}

int my_strlen(const char *s) {
    int pocet_znakov = 0;
    while (*s) {
        pocet_znakov++;
        s++;
    }
    return pocet_znakov;
}

void my_gets(char *s, int n) {
    char *pom = s;
    while ((*s = getchar()) != '\n') {
        s++;
        if ((s - pom) == n) break;
        
    }
    *s = '\0';
}



