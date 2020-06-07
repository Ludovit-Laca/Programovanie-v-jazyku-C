/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lacal
 *
 * Created on Utorok, 2019, novembra 26, 9:25
 * 
 * a) Neusporiadané pole celých čísel usporiadajte pomocou funkcie qsort() z hlavičkového súboru stdlib.h.
 * b) Od používateľa prečítajte hodnotu, pomocou funkcie bsearch() ju v poli nájdite (alebo vypíšte, že sa v poli nenachádza).
 * c) Upravte predchádzajúci program tak, aby vypísal počet výskytov hľadanej hodnoty. Využite pri tom smerníkovú aritmetiku!
 */

#include <stdio.h>
#include <stdlib.h> // qsort, bsearch
#include <time.h>

#define N 15

void vypisPole(int pole[]) {
    for (int i = 0; i < N; i++) {
        printf("%d, ", pole[i]);
    }
    printf("\n");
}

int cmpfunc(const void * a, const void * b) {
    return (*(int*) a - *(int*) b);
}

int main(int argc, char** argv) {
    srand((unsigned) time(NULL));
    int a = 1;
    int b = 15;
    // naplnme pole a nahodne cislami a vypisme jeho obsah
    int pole[N];
    for (int i = 0; i < N; i++) {
        pole[i] = (rand() % (a + 1 - b)) + a;
    }

    vypisPole(pole);
    qsort(pole, N, sizeof (int), cmpfunc);
    vypisPole(pole);

    // Od používateľa prečítajte hodnotu, pomocou funkcie bsearch() ju v poli 
    // nájdite (alebo vypíšte, že sa v poli nenachádza).
    int h;
    scanf("%d", &h);

    int *item = (int*) bsearch(&h, pole, N, sizeof (int), cmpfunc);
    if (item != NULL) {
        printf("Item %d found at position: %d \n", h, (int) (item - pole));

        // Upravte predchádzajúci program tak, aby vypísal počet výskytov hľadanej hodnoty.
        int pocet = 1;

        // pozrieme sa doprava
        int *q = item + 1;
        while ((q < pole + N)&& (*q == h)) {
            pocet++;
            q += 1;
        }

        // pozrieme sa dolava;
        q = item - 1;
        while ((q >= pole) && (*q == h)) {
            pocet++;
            q -= 1;
        }
        printf("Pocet: %d \n", pocet);
    } else {
        printf("Item could not be found\n");
    }
    return (EXIT_SUCCESS);
}

