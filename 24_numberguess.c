#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(0));
    int rn = rand() % 101;
    int guess;
    int left = rand() % 8 + 3;

    printf("\nI kept a number between 1 and 100, guess! (you have %d rights)\n", left);

    do {
        scanf("%d", &guess);
        left--;

        if (guess == rn) {
            printf("True, congrats!\n");
            break;
        }

        if (left > 0) {
            printf("You have %d rights left!\n", left);
            if (guess > rn) {
                printf("The number I hold is smaller, try again!\n");
            } else {
                printf("The number I hold is bigger, try again!\n");
            }
        }
    } while (left > 0);

    if (guess != rn) {
        printf("No rights left! The correct number was %d\n", rn);
    }

    return 0;
}
