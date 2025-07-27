#include <stdio.h>
#include <string.h>

int main() {
    char text[100] , length , i;

    fgets(text,sizeof(text),stdin); //it reads a line of text over Stdin and saves it in a string of characters called text.
    printf("%s" , text);
    length = strlen(text) -1;

    printf("%d \n", length);

    for (i=length -1 ; i>=0 ; i--) {
        printf("%c" , text[i]);
    }

    return 0;
}