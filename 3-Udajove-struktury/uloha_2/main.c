/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lacal
 *
 * Created on Utorok, 2019, novembra 19, 9:53
 * 
 * a) či sa konkrétna udalosť zadaná používateľom (zadáme jej názov) prekrýva s niektorou inou udalosťou uloženou v poli
 *
 * b) ak je to možné, naplánujte udalosti tak, aby sa v trvaní neprekrývali (naplánovať = usporiadať pole udalostí)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPZ 10
#define MAXPU 10

typedef struct {
    char id[MAXPZ];
    int z, k;
} TUdalost;

TUdalost u[MAXPU] = {
    {"a", 2, 8},
    {"b", 3, 6},
    {"c", 10, 20},
    {"d", 9, 12},
    {"e", 4, 13}};

int prekryvaju_sa(TUdalost *p, TUdalost *q) {
    int prekryvaju = 0;
    
    if ((p->z > q->z) && (p->z > q->k));
    else if ((p->k < q->z) && (p->k < q->k));
    else {
        prekryvaju = 1;
    }
    return prekryvaju;
}

int main(int argc, char** argv) {
    char hladana[MAXPZ];
    scanf("%s", &hladana);

    // zistime ci je taka v poli alebo nie
    // budeme porovnavat char
    int nachadza = -1;
    for (int i = 0; i < sizeof (u) / sizeof (u[0]); i++) {
        if (strcmpi(hladana, u[i].id) == 0) {
            nachadza = i;
        }
    }
    
    if (nachadza > -1) {
        printf("Prvky s ktorymi sa zadana hodnota prekryva su: ");
        for (int i = 0; i < sizeof (u) / sizeof (u[0]); i++) {
            if (i != nachadza) {
                if (prekryvaju_sa(&u[nachadza], &u[i]) == 1) {
                    printf("%c ", u[i]);
                }
            }
        }
        printf("\n");
    } else {
        printf("Prvok sa v poli nenachadza!");
        exit(1);
    }

    return (EXIT_SUCCESS);
}

