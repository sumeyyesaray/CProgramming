

#include <stdio.h>

int main() {
    int number, i;
    long long t1 = 0, t2 = 1, nextterm;

    printf("How many Fibonacci numbers do you want? ");
    scanf("%d", &number);

    printf("Fibonacci Series: ");

    for (i = 0; i < number; i++) {
        printf("%lld ", t1);
        nextterm = t1 + t2;
        t1 = t2;
        t2 = nextterm;
    }

    printf("\n");

    return 0;
}
