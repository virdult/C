//Pointer is basically a variable that stores another variable's address
#include <stdio.h>

int p = 1000;
int *a; //This is a pointer
a = &p; //Now, a points to p's address
//If I print a or &p, then I'll get the p's address as output.
//If I print *a, then I'll get the p's value. "Dereference"
//You can change p with a by using:
*a = 3;

//a is a pointer to an integer.
double *b; //b is a pointer to a double
char *c; //c is a pointer to a character

/*If you assign a char pointer to an integer, it will only link to the first byte. But you could set 4 different
characters for the full integer and use it as the output in some format. Then when deciphering, you can get the
4 characters side by side and check their binary and turn them into integers to see your secret password.
I don't think this is too safe but maybe could work in different places?*/

//Void pointer - Genric pointer
void *a0;
a0 = &p;
//You can use it only to point to the address but not the stored thing inside. I guess it's  used for security?

