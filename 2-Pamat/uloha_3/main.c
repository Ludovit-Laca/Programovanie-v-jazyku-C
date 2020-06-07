/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lacal
 *
 * Created on Utorok, 2019, októbra 22, 9:22
 */

#include <stdio.h>
#include <stdlib.h>

#include <string.h> // strlen
#include <ctype.h> // islower, isupper ...

int main(int argc, char** argv) {    
    char sprava[] = "VeLkkER";
    int m = 0, v = 0;
    if (male_velke(sprava, &m, &v)) {
        printf("male pismena: %d \n", m);
        printf("velke pismena: %d \n", v);
    } else {
        printf("Retazec bol prazdny\n");
    }
    return (EXIT_SUCCESS);
}

int male_velke(char *ret, int *male, int *velke) {
    int i = 0;
    if (strlen(ret) > 0) {
        while (ret[i] != '\0') {
            if (isupper(ret[i])) *velke += 1;
            if (islower(ret[i])) *male += 1;
            i++;
        }
        return 1;
    } else return 0;
}

