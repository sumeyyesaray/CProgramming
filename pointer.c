#include <stdio.h>
#include <stdlib.h>

//use of pointers like arrays with dynamic memory management

int * combine(int *p1, int *p2, int n1, int n2) {
    int *p3= (int * ) malloc( (n1*n2)*sizeof(int));
    int *p = p3;
    int i;

    for (i=0;i<n1;i++) {
        *p3 = *p1;
        p3++;
        p1++;
    }

    for (i=0;i<n2;i++) {
        *p3 = *p2;
        p3++;
        p2++;
    }

    *p3= '\0';
    printf("Combine operating is done \n");
    return p;
}


int main() {
    int *p1 , *p2 , *p3;
    int n1 , n2;

    printf("Address of the first memory region : "); scanf("%d",&n1);
    printf("Address of the second memory region : "); scanf("%d",&n2);

    p1= (int * ) malloc(n1 * sizeof(int));
    p2= (int * ) malloc(n2 * sizeof(int));

    int i;
    printf("Enter data of the first memory region: \n");
    for (i=0;i<n1;i++) {
        printf("p1 [%d] :",i);scanf("%d", &p1[i]);
    }

    printf("Enter data of the second memory region: \n");
    for (i=0;i<n2;i++) {
        printf("p2 [%d] :",i);scanf("%d", &p2[i]);
    }

    p3= combine(p1,p2,n1,n2);
    int total = 0;

    while (*p3 != '\0') {
        total += *p3;
        printf("%d", *p3);
        p3++;
    }
    printf("\n Total result : %d", total);
    return 0;

}