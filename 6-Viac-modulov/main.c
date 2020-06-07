/* 
 * File:   main.c
 * Author: lacal
 *
 * Created on Utorok, 2019, decembra 10, 9:30
 */

#include <stdio.h>
#include <stdlib.h>
#include "vektor.h"

/*
 * 
 */
int main(int argc, char** argv) {
    TVektor u, v;
    
    nacitajVektor(u);
    nacitajVektor(v);
    vypisVektor(u);
    vypisVektor(v);
    printf("Velkost: %f\n", velkostVektora(u));
    // vynasobSkalarom(u, 2.0);
    vypisVektor(u);
    printf("Skalarny sucin: %f\n", skalaranySucin(u,v));
    printf("Su kolme? : %d", otestujKolmost(u,v));
    
    return (EXIT_SUCCESS);
}

