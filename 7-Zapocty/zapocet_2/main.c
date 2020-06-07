/* 
 * File:   main.c
 * Author: Ludovit Laca, Vladimir Ondruska
 *
 * Created on 17. decembra 2019, 9:08
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXPZ 100

typedef struct {
    char mesto[MAXPZ + 1];
    int pocet_obyvatelov;
    double rozloha;
} TMesto;


int pocetRiadkov(const char *subor);
void nacitajSubor(TMesto *mesto, const char *subor);
void vypis(TMesto *mesto, int n);
int podla_obyvatelov(const void* u1, const void* u2);
int podla_hustoty(const void* u1, const void* u2);
void zapisSubor(TMesto *mesto, int pocet, const char *subor, int n);

int main(int argc, char** argv) {

    //uloha 1
    int n = pocetRiadkov("mesto.txt");
    TMesto* mesto = (TMesto*) malloc(n * sizeof (TMesto));

    nacitajSubor(mesto, "mesto.txt");
    vypis(mesto, n);
    printf("\n");

    //uloha 2
    qsort(mesto, n, sizeof (TMesto), podla_obyvatelov);
    vypis(mesto, n);
    printf("\n");

    qsort(mesto, n, sizeof (TMesto), podla_hustoty);
    vypis(mesto, n);
    printf("\n");

    //uloha 3
    TMesto h;
    scanf("%d", &h.pocet_obyvatelov);

    TMesto *item = (TMesto*)bsearch(&h, mesto, n, sizeof (TMesto), podla_obyvatelov);
    printf("hladany prvok: %d sa nachadza na pozicii: %d", h.pocet_obyvatelov, item - mesto);
    
    //uloha 4
    int pozicia = -1;
    for(int i = 0; i < n; i++){
        if(strcmp(item->mesto, mesto[i].mesto) == 0){
            pozicia = i;
            break;
        }
    }
    printf("pozicia hladaneho prvku: %d", pozicia);
    
    //uloha 5
    int pznakov = 0;
    scanf("%d", &pznakov);

    zapisSubor(mesto, pznakov, "novy.txt", n);

    return (EXIT_SUCCESS);
}

int pocetRiadkov(const char *subor) {
    FILE *fr;
    if ((fr = fopen(subor, "r")) == NULL) {
        printf("subor nenajdeny");
        exit(1);
    }
    int n = 0;
    fscanf(fr, "%d", &n);
    fclose(fr);
    return n;

}

void nacitajSubor(TMesto *mesto, const char *subor) {
    FILE *fr;
    if ((fr = fopen(subor, "r")) == NULL) {
        printf("subor sa nenasiel");
        exit(1);
    }

    int i = 0;

    char m[MAXPZ + 1];
    int p;
    double r;
    int temp;
    fscanf(fr, "%d", &temp);
    while ((fscanf(fr, "%s %d %lf", m, &p, &r)) == 3) {

        strcpy(mesto[i].mesto, m);
        mesto[i].pocet_obyvatelov = p;
        mesto[i].rozloha = r;

        i++;

    }

    fclose(fr);
}

void vypis(TMesto *mesto, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s, %d, %lf\n", mesto[i].mesto, mesto[i].pocet_obyvatelov, mesto[i].rozloha);
    }
    printf("\n");
}

int podla_obyvatelov(const void* u1, const void* u2) {
    TMesto *prva = (TMesto*) u1;
    TMesto *druha = (TMesto*) u2;
    return prva->pocet_obyvatelov - druha->pocet_obyvatelov;
}

int podla_hustoty(const void* u1, const void* u2) {
    TMesto *prva = (TMesto*) u1;
    TMesto *druha = (TMesto*) u2;
    return (prva->pocet_obyvatelov / prva->rozloha) - (druha->pocet_obyvatelov / druha->rozloha);
}

void zapisSubor(TMesto *mesto, int pocet, const char *subor, int n) {
    FILE *fr;
    if ((fr = fopen(subor, "w")) == NULL) {
        printf("subor nenajdeny");
        exit(1);
    }

    scanf(fr, "%d");
    for (int i = 0; i < n; i++) {
        int b = strlen(mesto[i].mesto);
        if (b < pocet) {
            fprintf(fr, "%s\n", mesto[i].mesto);
        }
    }
    fclose(fr);
}

