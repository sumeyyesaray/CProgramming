
#include <stdio.h>

int main() {
    int numbers[5], i, total = 0;
    float average;

    for (i = 0; i < 5; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    printf("You entered:");
    for (i = 0; i < 5; i++) {
        printf(" %d", numbers[i]);
        total += numbers[i];
    }

    average = (float)total / 5;
    printf("\nAverage: %.2f\n", average);

    return 0;
}
