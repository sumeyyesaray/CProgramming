#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//use of pointers like arrays with dynamic memory management
//&phone gibi char[] değişkenlerde & işareti kullanılmaz
//Format: %s\t%s\t%s\t\n--> 3 alan ifade etti , 3 alan okunur.


char name[20] ;
char surname[20];
char phone[11];
char address[20];

FILE *file;
FILE *temp;

void add_customer() {
    system("cls");
    if ((file = fopen("customerInfo.txt","a")) != NULL ) {
        printf("Enter the customer information : \n");
        printf("Name         : "); scanf("%s",&name);
        printf("Surname      : "); scanf("%s",&surname);
        printf("Phone        : "); scanf("%s",&phone);
        printf("Address      : "); scanf("%s",&address);

        fprintf(file, "%s\t%s\t%s\t%s\t\n", name, surname, phone, address);
        fclose(file);
        printf("Registration is complete ");
    }
}

void list_customer() {
    system("cls");

    if ((file = fopen("customerInfo.txt", "r")) == NULL) {
        printf("No customer records found.\n");
        return;
    }

    printf("Registered customer information\n");
    printf("********************************\n");
    printf("Name\tSurname\tPhone\tAddress\n");


    while (fscanf(file, "%s\t%s\t%s\t%s", name, surname, phone, address) == 4) {
        printf("%s\t%s\t%s\t%s\n", name, surname, phone, address);
    }

    fclose(file);
}


void search_customer() {
    system("cls");

    char name1[50];
    char name[50], surname[50], phone[50], address[50];
    int result = 0;

    file = fopen("customerInfo.txt", "r");
    if (file == NULL) {
        printf("No customer records found.\n");
        return;
    }

    printf("Enter the name of the customer to search: ");
    scanf("%s", name1);

    printf("\nSearch Results:\n");
    printf("*******************************\n");
    printf("Name\tSurname\tPhone\t\tAddress\n");

    // Doğru sayıda veri okunduğunda karşılaştır
    while (fscanf(file, "%s %s %s %s", name, surname, phone, address) == 4) {
        if (strcmp(name, name1) == 0) {
            printf("%s\t%s\t%s\t%s\n", name, surname, phone, address);
            result = 1;
            break; 
        }
    }

    fclose(file);

    if (!result) {
        printf("Customer named '%s' was not found.\n", name1);
    }
}


void backup() {
    if ((temp = fopen("temp.txt","w")) != NULL) {
        if ((file = fopen("customerInfo.txt","r")) != NULL) {
            while (!feof(file)) {
                fscanf(file,"%s\t%s\t%s\t\n",name,surname,&phone,address);
                fprintf(temp,"%s\t%s\t%s\t\n",name,surname,phone,address);
            }
        }
        remove("customerInfo.txt");
        fclose(file);
        fclose(temp);
    }
}

void update(char *ptr) {
    if ( (file = fopen("customerInfo.txt","w")) != NULL) {
        if ((temp = fopen("temp.txt","r")) != NULL) {
            while (!feof(temp)) {
                fscanf(temp,"%s\t%s\t%s\t\n",name,surname,&phone,address);
                if (strcmp(ptr,name) == 0)
                    continue;
                    fprintf(file,"%s\t%s\t%s\t\n",name,surname,phone,address);
                }
            }
                 remove("temp.txt");
            fclose(file);
            fclose(temp);
            rewind(file);

    }
}

void delete(){
    system("cls");
    char name2[20];
    int result=0;
    if ((file = fopen("customerInfo.txt","r")) != NULL) {
        printf("The name of the customer you want to delete : "); scanf("%s",name2);
        printf("Sought customer information \n");
        printf("**************************\n");
        printf("Name\tSurname\tPhone\tAddress\n");

        while (!feof(file)) {
            fscanf(file,"%s\t%s\t%s\t\n",name,surname,&phone,address);
            if (strcmp(name,name2) == 0) {
                fclose(file);

                backup();
                update(name2);
                result = 1;
                break;
            }
        }
        printf("*************************\n");
        fclose(file);
    }

    if (result == 0)
        printf("The customer named %s  is not on the list.",name2);
    else
        printf("Deletion successful!");

}

int main() {
    int choice = -1;
    while (choice != 0) {
        printf("\n1-New registration \n");
        printf("\n2-List \n");
        printf("\n3-Research \n");
        printf("\n4-Delete \n");
        printf("\n0-Exit \n");
        printf("\nYour choice : \n"); scanf("%d", &choice);

        if (choice == 1)
            add_customer();
        else if (choice == 2)
            list_customer();
        else if (choice == 3)
            search_customer();
        else if (choice == 4)
            delete();
        else if (choice == 0)
            printf("Logged out!");
        else
            printf("Wrong choice!! \n");
    }
    return 0;
}