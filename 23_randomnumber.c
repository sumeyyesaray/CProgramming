#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); //it will work completely randomly
    int random;
    random = rand();
    printf("Random number :%d \n", random);
    random = random % 100;
    printf("Remain :%d" , random);

    return 0;
}