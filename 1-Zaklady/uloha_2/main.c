/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Student
 *
 * Created on 1. októbra 2019, 10:10
 */

#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h> // time

/*
 * ROCK: 0
 * PAPER: 1
 * SCISSORS: 2
 */
int main(void) {
    int player1, player2, score1 = 0, score2 = 0, win;
    int i = 1;
    char mark[] = {'K', 'P', 'N'};
    srand((unsigned)time(NULL));
    
    while (1) {
        // generating for player1
        player1 = rand() % 3;
        // generating for player2
        player2 = rand()%3;
        // function call
        win = winner(player1, player2);
        
        if (win == 1) {
            score1++;
        } else if (win == 2) {
            score2++;
        }
        // output values
        printf("%d.kolo: %c x %c -> %d:%d\n", i, mark[player1], mark[player2], score1, score2);
        
        // checking for winner
        if (score1 >= 3) {
            printf("Vyhral 1. hrac!\n");
            break;
        } else if (score2 >= 3) {
            printf("Vyhral 2. hrac!\n");
            break;
        }
        i++;
    }
    return (EXIT_SUCCESS);
}

/**
 * 
 * @param a
 * @param b
 */
int winner(int a, int b) {
    // draw: 0
    // player1 : 1
    // player2 : 2
    if (a == b) {
        return 0;
    } else if (a + 1 == b) {
        return 2;
    } else if (a + 2 == b) {
        return 1;
    } else if (b + 1 == a) {
        return 1;
    } else if (b + 2 == a) {
        return 2;
    }
}

