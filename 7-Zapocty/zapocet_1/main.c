/* 
 * File:   main.c
 * Author: Ludovit Laca, Vlado Ondruska
 *
 * Created on 29. októbra 2019, 8:20
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
 * Pocet experimentov : 100 000
 * testovane pocty krokov: 5, 50, 100, 1000, 10 000
 * priemerna vzdialenost pre 5 = 2,02
 * priemerna vzdialenost pre 50 = 6,27
 * priemerna vzdialenost pre 100 = 8,85
 * priemerna vzdialenost pre 1000 = 28,25
 * priemerna vzdialenost pre 10000 = 85,13
 * 
 * Celkova priemerna vzdialenost experimentov je: 26,104
 * 
 * Po experimentoch sme zistili že funkcia ktorá opisuje rýchlost stupania vzdialenosti je n (linearna)
 */
int main(int argc, char** argv) {

    srand((unsigned) (time(NULL)));
    //n = pocet krokov; t = pocet experimentov
    int x = 0, y = 0, n = 0, t = 0;
    double priemer = 0;

    //zadanie krokov a experimentov pouzivatelom
    printf("zadaj pocet krokov: ");
    scanf("%d", &n);
    printf("\nzadaj pocet experimentov: ");
    scanf("%d", &t);
    printf("\n");

    // cyklus pre pocet experimentov
    for (int j = 0; j < t; j++) {
        x = 0;
        y = 0;

        // cyklus pre pocet krokov
        for (int i = 0; i < n; i++) {

            int number = (1 + rand() % (4 - 1 + 1));
            switch (number) {

                case 1:
                    y += 1;
                    break;
                case 2:
                    x += 1;
                    break;
                case 3:
                    y -= 1;
                    break;
                case 4:
                    x -= 1;
                    break;
            }

            printf("[%d,%d]\n", x, y);

        }
        double vysledok = sqrt(pow(x, 2) + pow(y, 2));
        printf("vzdialenost %lf\n", vysledok);
        priemer += vysledok;
    }
    priemer = priemer / t;
    printf("priemerna vzdialenost: %f", priemer);


    return (EXIT_SUCCESS);
}

