#include <stdio.h>
#include <math.h>
#include "vektor.h"

void nacitajVektor(TVektor u) {
    for (int i = 0; i < ROZMER_VEKTORA; i++) {
        scanf("%lf", &u[i]);
    }
}

void vypisVektor(TVektor u) {
    printf("Vektor: ( %lf , %lf , %lf )\n", u[0], u[1], u[2]);
}

double velkostVektora(TVektor u) {
    return sqrt( pow(u[0], 2) + pow(u[1], 2) + pow(u[2], 2) );
}

void vynasobSkalarom(TVektor u, double koef) {
    for (int i = 0; i < ROZMER_VEKTORA; i++) {
        u[i] = u[i] * koef;
    }
}

double skalaranySucin(TVektor u, TVektor v) {
    double pom = 0;
    for (int i = 0; i < ROZMER_VEKTORA; i++) {
        pom = pom + u[i] * v[i];
    }
    return pom;
}

int otestujKolmost(TVektor u, TVektor v) {
    if (!skalaranySucin(u,v)) return 1;
    else return 0;
}