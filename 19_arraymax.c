
#include <stdio.h>
int main() {
    int array[] = {3, 4, 12, 5, 67, 78, -223, -123, 23, 0};
    int i , demansion , max;
    max = array[0];
    demansion = sizeof(array)/sizeof(array[0]);
    for (i=0;i<demansion;i++) {
        if (array[i]>max) {
            max = array[i];
        }
    }
    printf("Maximum number in array:%d", max);
    return 0;
}

