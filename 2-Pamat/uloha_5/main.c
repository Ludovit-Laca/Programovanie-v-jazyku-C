#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <stdbool.h>

#define DLZKA 25;


char* nahodne_slovo(int n) {
    char *slovo = (char *) malloc(sizeof(char) * (n*2 + 1)); // sizeof (char) == 1
    char samohlasky[] = {'a', 'e', 'i', 'y', 'o', 'u'}; 
    char spoluhlasky[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};
    bool keep_going = true; 
    int number;
    
    // naplnenie retazca znakmi aby to bolo nahodne slovo    
    for (int i = 0; i < n*2; i += 2) {
        number = (rand() % (20));
        slovo[i] = spoluhlasky[number];

        if (i+1 < n*2) { 
            number = (rand() % (6));
            slovo[i+1] = samohlasky[number];
        }
        else {
            break;        
        }
    }
    slovo[n*2+1] = '\0';
    return slovo;
}

int main(int argc, char** argv) {
    // random
    srand((unsigned)time(NULL));
    
    char *slovo = nahodne_slovo(5);
    puts(slovo);
    free(slovo);

    return (EXIT_SUCCESS);
}
