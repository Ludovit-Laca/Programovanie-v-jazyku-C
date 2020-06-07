/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lacal
 *
 * Created on Utorok, 2019, októbra 22, 10:02
 */

#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>

#define DLZKA 25

int main(int argc, char** argv) {
    
    char odp[DLZKA+1];
    
    puts("Ahoj, ako sa mas?");
    
//    // scanf, gets, fgets
//    scanf("%25s", odp); // po najblizsi biely znak scanuje
//    printf("%s", odp);
    
//    gets(odp);
//    odp[strlen(odp)] = '\0';
//    puts(odp);
    
    fgets(odp, DLZKA, stdin);
    odp[strlen(odp)-1] = '\0';
    
    if (!strcmp(odp, "dobre")) {
        puts("To je super! Tesim sa :)");
    } else {
        puts(":(");
    }
    return (EXIT_SUCCESS);
}

