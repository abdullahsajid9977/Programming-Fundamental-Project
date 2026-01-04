#include<stdio.h>
void title()
{
    printf("***************************************\n");
    printf("WELCOME TO INVENTORY MANAGEMENT SYSTEM\n");
    printf("***************************************\n");
}

void inventorymenu()
{
int choice;
    while (1)
{
    printf("\n");
    printf("1.Product Details\n");
    printf("2.Supplier Details\n");
    printf("3.Purchase Details\n");
    printf("4.Sale Details\n");
    printf("5.Exit\n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);

if (choice == 1)
    printf("IN PROCESS");
else if (choice == 2)
    printf("IN PROCESS");
else if (choice == 3)
    printf("IN PROCESS");
else if (choice == 4)
    printf("IN PROCESS");
else if (choice == 5)
    break;
else
    printf("Invalid Entry\n");
    }
}
int main()
{
    title();
    inventorymenu();
}