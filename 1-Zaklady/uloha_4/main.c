/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lacal
 *
 * Created on Utorok, 2019, októbra 8, 10:08
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h> // srand, rand
#include <time.h> // time

int main(int argc, char** argv) {
    
    // Pole
    int n;
    scanf("%d", &n);
    int pole[n];
    
    // Interval
    int a,b;
    scanf("%d %d", &a, &b);
    
    // random
    srand((unsigned)time(NULL));
    
    for (int i = 0; i < n; i++) {
        pole[i] = (rand() % (b + 1 - a)) + a;
        printf("%d ", pole[i]);
    }
    
    int pocet = 0;
    for (int i = 1; i < n - 1; i++) {
        if (pole[i-1] > pole[i] && pole[i+1] > pole[i] ) {
            pocet++;
        }
    }
    printf("\nPocet mensich prvkov ako jeho susedia su: %d \n", pocet);
    return (EXIT_SUCCESS);
}

