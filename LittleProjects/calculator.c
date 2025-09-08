/*Now lets think how a calculator should work.
A calculator doesn't talk with the human, asking for prompts because human already opens it to calculate.
So we basically just need it to work. and by work I mean:
Get the number, get the operator, get another number
get a number, enter, get the operator, enter, get the other number, enter
give the answer.
if pressed an operator after that, get the answer as first number and get the second number he'll give
as second and recalculate. Let's make our calculator can make +, -, *, /, %. Thats all 
We'll add more if necessary...
Now I encountered a problem, how do I limit the input to only number? Because I just tried typing 'a' in the
double and I can't use the terminal anymore lmao...
Alright I found it out and I found out how to do the advanced calc I wanted but I won't do it here. 
It's above my paygrade xD. We'll stick to our basic calculator*/

#include <stdio.h>
#include <math.h>//I included this so I can use fmod, because % is not working on doubles...

double firstInput, secondInput, answer;
int keepGoing;
char operator = '+';

void calculator();
void calculate();

int main(){

    calculator();

    return 0;
}

void calculator(){
    do{
        printf("Give first number: \n");
        scanf("%lf", &firstInput);
        printf("Give second number: \n");
        scanf("%lf", &secondInput);

        
        printf("Give the operator:");
        scanf(" %c", &operator); //We have ' %c' instead of '%c' so that it doesn't read previous \n characters
        /*
        FOR FUCK SAKE WHY THIS DOESN'T WORK?????????????
        Alright bois it does work. The problem was I was running the wrong test file for the last 50 minutes ^^...
        */
        /*
        printf("Give the operator:");
        operator = getchar();
        Alright this doesn't work as well so there must be a problem in my functions.(Extra, no there wasn't)
        */
        calculate();
        printf("Answer = %.3lf\n", answer);
        printf("If you want to calculate again, tpye 1, if you want to quit type 0! \n");
        scanf("%d", &keepGoing);
    }while(keepGoing == 1);
}

void calculate(){
    if(operator == '+'){
        answer = firstInput + secondInput;
    }else if(operator == '-'){
        answer = firstInput - secondInput;
    }else if(operator == '*'){
        answer = firstInput * secondInput;
    }else if(operator == '/'){
        if(secondInput == 0){
            printf("Can't divide to 0!\n");
            answer = 0;
        }else{
            answer = firstInput / secondInput;
        }
    }else if(operator == '%'){
        if(secondInput == 0){
            printf("Can't modulate by 0!\n");
            answer = 0;
        }else{
            answer = fmod(firstInput, secondInput);
        }
    }else{
        printf("Please enter a valid operator. +, -, *, /, %% \n");
        answer = 0;
    }
}
