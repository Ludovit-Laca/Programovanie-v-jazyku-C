/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Student
 *
 * Created on 2. decembra 2019, 14:12
 */

#include <stdio.h>
#include <stdlib.h>

#define nadruhu(x) (x)*(x)

#define max(a,b) ((a)>(b) ? (a) : (b))
#define jeVelke(c) (c >= 'A' && c <= 'Z')

int main(int argc, char** argv) {
    int a = 5;
    char znak = 'a';
    printf("%d\n", nadruhu(a+3)); // a+3*a+3 .. treba davat zatvorky!!!
    printf("maximum je %d\n", max(12,10));
    printf("je pismeno '%c' velke ? : %d\n", znak, jeVelke(znak));
    return (EXIT_SUCCESS);
}

