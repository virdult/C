/*I could do a full good version with struct but I yet to know it very well so we'll keep this simple.*/
/*Grade calculator: Asks for 3 inputs: "Homework 0-100", "Midterm 0-100", "Final 0-100"
Homework is %30, Midterm is %30, Final is %40
Display a numeric final grade with following scale:
86-100 -> A ; 71-85 -> B ; 56-70 -> C ; 40-55 -> D ; Below 40 -> F*/

#include <stdio.h>

float calculateGrade(float x, float y, float z);
char calculateNote(float grade);

int main(){
    float homework, midterm, final;
    do{
    printf("Enter your homework score: \n");
    scanf("%f", &homework);
    }while(homework > 100 || homework < 0);

    do{
    printf("Enter your midterm score: \n");
    scanf("%f", &midterm);
    }while(midterm > 100 || midterm < 0);

    do{
    printf("Enter your final score: \n");
    scanf("%f", &final);
    }while(final > 100 || final < 0);

    float grade = calculateGrade(homework, midterm, final);
    char note = calculateNote(grade);

    if(note == 'I'){//I put barricades on note entries so this is not necessary anymore, but I'll not delete.
        printf("Invalid entry! \n");
    }else{
        printf("Your grade: %.2f ; You note: %c \n", grade, note);
    }
    
    return 0;
}

float calculateGrade(float x, float y, float z){
    float finalGrade = (x * 3 / 10) + (y * 3 / 10) + (z * 4 / 10);
    //float finalGrade = (x * 0.3f) + (y * 0.3f) + (z * 0.4f); //I guess this works as well
    return finalGrade;
}

char calculateNote(float grade){
    if(grade > 85 && grade <= 100){
        return 'A';
    }else if(grade > 70 && grade < 86){
        return 'B';
    }else if(grade > 55 && grade < 71){
        return 'C';
    }else if(grade >= 40 && grade < 56){
        return 'D';
    }else if(grade >= 0 && grade < 40){
        return 'F';
    }else{
        return 'I';
    }
}