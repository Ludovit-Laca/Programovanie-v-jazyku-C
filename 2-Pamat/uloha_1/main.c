/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lacal
 *
 * Created on Utorok, 2019, októbra 15, 9:24
 */

#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h> // time

void pozdrav(void);
double obvod_obdlznika(double a, double b);
int je_trojuholnik(int a, int b, int c);
void napln_pole_nahodne(int data[], int n, int a, int b);
void vypis_pole(int data[], int n);
void pomiesaj_pole(int data[], int n);

int main(int argc, char** argv) {
    srand((unsigned) time(NULL));

    int n = 5;
    int b[n];
    // otestovat ostatne funckie
    
    
    printf("Obvod obdlznika: %f\n", obvod_obdlznika(5,10));
    pozdrav();
    napln_pole_nahodne(b, n, 1, 9);
    vypis_pole(b, n);
    pomiesaj_pole(b, n);
    vypis_pole(b, n);


    return (EXIT_SUCCESS);
}

void pozdrav(void) {
    printf("Hlasi sa kapitan \n");
}

double obvod_obdlznika(double a, double b) {
    return 2 * a + 2 * b;
}

int je_trojuholnik(int a, int b, int c) {
    if (a + b > c && a + c > b && c + b > a) return 1;
    else return 0;
}

void napln_pole_nahodne(int data[], int n, int a, int b) {
    for (int i = 0; i < n; i++) {
        data[i] = (rand() % (b + 1 - a)) + a;
    }
}

void vypis_pole(int data[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void pomiesaj_pole(int data[], int n) {
    int pole[n];
    napln_pole_nahodne(pole, n, 0, n-1);
    for (int i = 0; i < n; i++) {
        int t = data[i];
        int pom = data[pole[i]];
        data[i] = pom;
        data[pole[i]] = t;
    }
}



