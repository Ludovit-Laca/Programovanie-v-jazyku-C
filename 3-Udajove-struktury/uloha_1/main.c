/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lacal
 *
 * Created on Utorok, 2019, novembra 19, 9:21
 */

#include <stdio.h> 
#include <stdlib.h> // malloc, free


int **pole2d(int m, int n) {
    // pole smernikov na riadky
    int **p = (int**) malloc(m*sizeof(int*));
    if (p == NULL) {
        printf("Malo pamati!\n");
        exit(1);
    }
    for (int i = 0; i < m; i++) {
        if ((p[i] = (int*) malloc(n*sizeof(int))) == NULL) {
            printf("Malo pamati!\n");
            exit(1);
        }
        for (int j = 0; j < n; j++) {
            p[i][j] = 0;
        }
    }
    return p;
}

int main(int argc, char** argv) {
    int r = 5; // riadky
    int s = 4; // stlpce
    int **a = pole2d(r,s);
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < s; j++)  {
            printf("%d ", a[i][j]);
        }
         printf("\n");
    }
   return (EXIT_SUCCESS);
}
