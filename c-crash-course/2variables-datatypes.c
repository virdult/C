#include <stdio.h>
#include <stdbool.h>

int main(){
    int a = 10;
    double b = 10.5; //64bit = 8bytes
    printf("%lu\n", sizeof(b));
    float c = 10.5; //32bit = 4bytes
    printf("%lu\n", sizeof(c));

    char d = 'a';
    char e[] = "char array"; //a string
    bool f = false; //You need to include stdbool.h

    int slices = 17;
    int person = 2;
    double slicesPerPerson = slices / person; //You'll get 8 because you are diving an integer to an integer.
    double slicesPerPerson2 = (double) slices / person; //Here you'll get 8.5 because you are typecasting, which makes 17 -> 17.0
    printf("Slice Per Person: %lf\n", slicesPerPerson);
    printf("Slices Per Person2: %lf\n", slicesPerPerson2);

    double test1 = 25 / 2 * 2; // = 24
    double test2 = 25 / 2 * 2.0; // = 24
    double test3 = 25.0 / 2 * 2; // = 25.0

    


    return 0;
}