/* 
 * File:   vektor.h
 * Author: lacal
 *
 * Created on Utorok, 2019, decembra 10, 9:37
 */

#ifndef VEKTOR_H
#define VEKTOR_H

#define ROZMER_VEKTORA 3
#define TYP_PRVKU double 

typedef TYP_PRVKU TVektor[ROZMER_VEKTORA];

extern void nacitajVektor(TVektor u);
extern void vypisVektor(TVektor u);
extern double velkostVektora(TVektor u);
extern void vynasobSkalarom(TVektor u, double koef);
extern double skalaranySucin(TVektor u, TVektor v);
extern int otestujKolmost(TVektor u, TVektor v);

#endif /* VEKTOR_H */

