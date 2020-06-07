/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lacal
 *
 * Created on Utorok, 2019, októbra 15, 10:12
 */

#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>

int skontroluj_heslo();

int main(int argc, char** argv) {

    //    char ret[] = "Nitra";
    //    char ret2[100]; // Najviac 99, posledny bajt je nulovy ukoncovaci znak
    //
    //    scanf("%s", ret2); // & netreba, ret2 je adresa zaciatku retazca
    //    printf("%s ma dlzku %d \n", ret2, strlen(ret2));
    //
    //    strcpy(ret2, "Praha"); // ret2 = "Praha" (takto v jave)

    int vysledok;
    vysledok = skontroluj_heslo();
    printf("Vysledok: %d \n", vysledok);

    return (EXIT_SUCCESS);
}

int skontroluj_heslo() {
    // nacitame
    char pole[100];
    int kontrola[4] = {0};
    scanf("%s", pole);
    
    // skontrolujeme dlzku hesla
    if (strlen(pole) <= 10) {
        printf("Heslo je prilis kratke!\n");
        return 0;
    }
    
    // ukladame do pola pocet znakov
    for (int i = 0; i < strlen(pole); i++) {
        if (isupper(pole[i])) {
            kontrola[0]++;
        } 
        if (islower(pole[i])) {
            kontrola[1]++;
        } 
        if (isdigit(pole[i])) {
            kontrola[2]++;
        } 
         if (ispunct(pole[i])) {
            kontrola[3]++;
        }
    }
    
    // skontrolujeme ci heslo obsahuje cislice
    if (kontrola[2] < 2) {
        printf("Heslo obsahuje malo cislic!\n");
        return 0;
    }
    
    // skontrolujeme zvysne znaky
    for (int i = 0; i < 4; i++) {
        if (i != 2) {
            if (kontrola[i] < 1) {
                printf("Heslo neobsahuje aspon jedno male, aspon jedno velke pismeno, aspon jeden iny znak\n");
                return 0;
            }
        }
    }
    printf("Heslo je dobre\n");
    return 1;
}

