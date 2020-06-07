#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPZ 20
#define MAXPU 100

int n;

typedef struct {
    char id[MAXPZ + 1];
    int z;
    int k;
} TUdalost;

int nacitaj_subor(TUdalost u[], const char* subor);
void vypis(TUdalost u[], int n);
int podla_id(const void* u1, const void* u2);
int podla_trvania(const void* v1, const void* u2);
int prekryvajuSa(TUdalost *u1, TUdalost *u2) {
    return (u2->z <= u1->k && u2->k >= u1->z);
}

int main(int argc, char** argv) {
    TUdalost u[MAXPU];

    n = nacitaj_subor(u, "vstup.txt");
    printf("pocet udalosti: %d\n", n);
    vypis(u, n);
    printf("\n");
    qsort(u, n, sizeof(TUdalost), podla_id);
    vypis(u, n);
    printf("\n");
    qsort(u, n, sizeof(TUdalost), podla_trvania);
    vypis(u, n);

    /*
    //    printf("zvol jednu udalost (zadaj jej id): ");
    //    char zvolena[MAXPZ + 1];
    //    scanf("%s", zvolena);
    //
    //    int i = 0;
    //    while (i < n && strcmp(zvolena, u[i].id)) {
    //        i++;
    //    }
    //    if (i < n) {
    //        printf("zvolena: %s <%d, %d>\n", u[i].id, u[i].z, u[i].k);
    //        // hladanie prekryvajucich sa
    //        for (int j=0;j<n;j++) {
    //         if (i != j && (prekryvajuSa(&u[i], &u[j]))) {
    //                  printf("prekryv: %s <%d, %d>\n", u[j].id, u[j].z, u[j].k);
    //             }   
    //        }
    //    } else {
    //        printf("chyba!!! taka udalost nebola nacitana!\n");
    //    }  
     */

}

int nacitaj_subor(TUdalost u[], const char* subor) {
    FILE *fr;

    if ((fr = fopen(subor, "r")) == NULL) {
        printf("Subor sa nenasiel!\n");
        exit(1);
    }

    int i = 0;
    char id[MAXPZ + 1];
    int z, k;

    while (fscanf(fr, "%s %d %d", id, &z, &k) == 3) {
        strcpy(u[i].id, id);
        u[i].z = z;
        u[i].k = k;
        i++;
    }
    fclose(fr);
    return i;
}

void vypis(TUdalost u[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s, %d, %d", u[i].id, u[i].z, u[i].k);
        printf("\n");
    }
}

int podla_id(const void* u1, const void* u2) {
    TUdalost *prva = (TUdalost*) u1;
    TUdalost *druha = (TUdalost*) u2;
    
    return strcmp(prva->id, druha->id);
}

int podla_trvania(const void* v1, const void* v2) {
    TUdalost *prva = (TUdalost*) v1;
    TUdalost *druha = (TUdalost*) v2;
    
    if ((prva->k - prva->z) > (druha->k - druha->z)) return 0;
    else return 1;
}
