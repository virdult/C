//string length -> strlen()

#include <stdio.h>
#include <string.h>

void print(char* c){ //This is basically same with putting in (char c[])
    int i = 0;
    while(c[i] != '\0'){ //instead of checking with c[i] you can also use *c directly to reach it's address and check 
        printf("%c", c[i]); //Also here, you can use *c instead of c[i]
        i++;
    }
    printf("\n");
}

int main(){
    char arr[20] = "Hello";
    print(arr);

    return 0;
}