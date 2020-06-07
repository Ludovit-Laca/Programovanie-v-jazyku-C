/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lacal
 *
 * Created on Sobota, 2019, októbra 12, 17:02
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    for (int i = 1; i <= 255; i++) {
        printf("ASCII value of character %c is %d \n",i,i);
        if (i % 10 == 0) {
            getchar();
        }
    }
    return (EXIT_SUCCESS);
}

