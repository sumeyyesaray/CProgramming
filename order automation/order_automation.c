#include <stdio.h>
#include <stdlib.h>
#include "customer.h"
#include "product.h"
#include "order.h"

int menu() {
    int choice;
    printf("\n\tORDER AUTOMATION \n\n");
    printf("\t1-Customer Operations \n");
    printf("\t2-Product Operations \n");
    printf("\t3-Order Operations \n");
    printf("\t0-Exit \n");
    printf("\n\tYour Choice  :  "); scanf("%d",&choice);
    system("cls");
    return choice;
}

int main(int argc , char *argv[]) {
    int choice = menu();

    while (choice != 0) {
        switch (choice) {
            case 1: customerOperations() ; break;
            case 2: productOperations(); break;
            case 3: orderOperations(); break;
            case 0: break;
            default:printf("Wrong operation!! \n") ; break;
        }

        choice = menu();
    }
}