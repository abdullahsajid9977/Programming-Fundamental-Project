#include <stdio.h>

struct saledate
{
    int day;
    int month;
    int year;
};

struct sale
{
    int saleid;
    int productid;
    int quantity;
    struct saledate date;
    int amount;
};

struct sale salecollection[100];
int salecount = 0;


void storefile()
{
    FILE *fp = fopen("salefile.txt", "w");
    if (fp == NULL) return;

    fprintf(fp, "%d\n", salecount);
    for (int i = 0; i < salecount; i++)
    {
        fprintf(fp, "%d %d %d %d %d %d %d\n",
                salecollection[i].saleid,
                salecollection[i].productid,
                salecollection[i].quantity,
                salecollection[i].date.day,
                salecollection[i].date.month,
                salecollection[i].date.year,
                salecollection[i].amount);
    }
    fclose(fp);
}

void loadfile()
{
    FILE *fp = fopen("salefile.txt", "r");
    if (fp == NULL) return;

    fscanf(fp, "%d", &salecount);
    for (int i = 0; i < salecount; i++)
    {
        fscanf(fp, "%d %d %d %d %d %d %d",
               &salecollection[i].saleid,
               &salecollection[i].productid,
               &salecollection[i].quantity,
               &salecollection[i].date.day,
               &salecollection[i].date.month,
               &salecollection[i].date.year,
               &salecollection[i].amount);
    }
    fclose(fp);
}


void salemenu()
{
    int choice;

    while (1)
    {
        printf("\n===== SALE MENU =====\n");
        printf("1. Enter Sale\n");
        printf("2. Display Sale\n");
        printf("3. Search Sale\n");
        printf("4. Delete Sale\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter Sale ID: ");
            scanf("%d", &salecollection[salecount].saleid);

            printf("Enter Product ID: ");
            scanf("%d", &salecollection[salecount].productid);

            printf("Enter Quantity: ");
            scanf("%d", &salecollection[salecount].quantity);

            printf("Enter Day: ");
            scanf("%d", &salecollection[salecount].date.day);

            printf("Enter Month: ");
            scanf("%d", &salecollection[salecount].date.month);

            printf("Enter Year: ");
            scanf("%d", &salecollection[salecount].date.year);

            printf("Enter Amount: ");
            scanf("%d", &salecollection[salecount].amount);

            salecount++;
        }
        else if (choice == 2)
        {
            for (int i = 0; i < salecount; i++)
            {
                printf("\nSale ID: %d", salecollection[i].saleid);
                printf("\nProduct ID: %d", salecollection[i].productid);
                printf("\nQuantity: %d", salecollection[i].quantity);
                printf("\nDate: %d/%d/%d",
                       salecollection[i].date.day,
                       salecollection[i].date.month,
                       salecollection[i].date.year);
                printf("\nAmount: %d\n", salecollection[i].amount);
            }
        }
        else if (choice == 3)
        {
            int id;
            printf("Enter Sale ID: ");
            scanf("%d", &id);

            for (int i = 0; i < salecount; i++)
            {
                if (id == salecollection[i].saleid)
                {
                    printf("\nSale ID: %d", salecollection[i].saleid);
                    printf("\nProduct ID: %d", salecollection[i].productid);
                    printf("\nQuantity: %d", salecollection[i].quantity);
                    printf("\nDate: %d/%d/%d",
                           salecollection[i].date.day,
                           salecollection[i].date.month,
                           salecollection[i].date.year);
                    printf("\nAmount: %d\n", salecollection[i].amount);
                }
            }
        }
        else if (choice == 4)
        {
            int id;
            printf("Enter Sale ID to delete: ");
            scanf("%d", &id);

            for (int i = 0; i < salecount; i++)
            {
                if (id == salecollection[i].saleid)
                {
                    for (int j = i; j < salecount - 1; j++)
                        salecollection[j] = salecollection[j + 1];
                    salecount--;
                    break;
                }
            }
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
}


int main()
{
    loadfile();
    salemenu();
    storefile();
    return 0;
}