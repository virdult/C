/*
Simple betting game. "Jack Queen King."
Player inputs the bet amount.
Computer shuffles these cards.
Player has to guess the position of the Queen.
If he wins, he takes 3*bet. 
If he loses, he loses the bet amount.
Player has $100 initially.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash = 100;

void play();

int main(){
    int bet, queenPos;
    printf("Welcome to Virdult Casino!\n");
    printf("Total Cash: $%d\n", cash);
    while(cash > 0){
        do
        {        
            printf("How much would you like to bet?: \n");
            scanf("%d", &bet);
        }while(bet > cash);
        if(bet == 0){
            printf("You've left the game!"); 
            break;
        }
        play(bet);
    }
    if(cash == 0){
        printf("You've lost all your money! Thanks for playing with us ^^\n");
    }else{
        printf("You've left the game. Thanks for playing with us!\n");
    }
    
    return 0;
}

void play(int bet){
    char C[3] = {'J', 'K', 'Q'};
    printf("Shuffling...\n");
    srand(time(NULL));
    for(int i = 0; i < 5; i++){
        int x = rand() % 3; //Randomly picking 2 positions
        int y = rand() % 3;
        int temp = C[x]; //Shuffling with those 2 random picked positions
        C[x] =  C[y];
        C[y] =  temp;
    }
    int guessPos;
    printf("Guess the position of the queen: 1, 2 or 3?\n");
    scanf("%d", &guessPos);
    if(C[guessPos - 1] == 'Q'){
        cash += 3*bet;
        printf("You win! Result = 1:%c, 2:%c, 3:%c -> Total Cash =  %d\n", C[0], C[1], C[2], cash);
    }else{
        cash -= bet;
        printf("You lost! Result = 1:%c, 2:%c, 3:%c -> Total Cash = %d\n", C[0], C[1], C[2], cash);
    }
}