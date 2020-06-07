/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Student
 *
 * Created on 1. októbra 2019, 9:27
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * 
 * @param a
 * @param b
 * @param c
 */
float max(float a, float b, float c) {
    // more ez solution
    // white = r>g?r:g
    // white = b>white?b:white
    float max;
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    if (max < c) {
        max = c;
    }
    return max;
}

int main(void) {
    int red, green, blue;
    float white, cyan, magenta, black, yellow;
    // asking for values
    scanf("%d %d %d", &red, &green, &blue);
    if (red == 0 && green == 0 && blue == 0) {
        // if 0 0 0 then 0 0 0 1
        printf("Cyan: 0\nMagenta: 0\nYellow: 0\nBlack: 1\n");
    } else if (red > 255 || green > 255 || blue > 255) {
        printf("All values must be less than a 256\n");
    } else {
        // calculation
        white = max(red / 255.0, green / 255.0, blue / 255.0);
        cyan = (white - (red / 255.0)) / white;
        magenta = (white - (green / 255.0)) / white;
        yellow = (white - (blue / 255.0)) / white;
        black = (1 - white);

        // output values
        printf("white: %.2f\nCyan: %.2f\nMagenta: %.2f\nYellow: %.2f\nBlack: %.2f\n", white, cyan, magenta, yellow, black);
    }
    return (EXIT_SUCCESS);
}