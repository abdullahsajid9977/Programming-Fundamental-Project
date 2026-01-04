#include <stdio.h>

struct purchasedate
{
    int day;
    int month;
    int year;
};

struct purchase
{
    int purchaseid;
    int supplierid;
    int totalamount;
    struct purchasedate date;
};

struct purchase purchasecollection[100];
int purchasecount = 0;

void storePurchaseFile()
{
    FILE *fp = fopen("purchasefile.txt", "w");
    if (fp == NULL) return;

    fprintf(fp, "%d\n", purchasecount);
    for (int i = 0; i < purchasecount; i++)
    {
        fprintf(fp, "%d %d %d %d %d %d\n",
                purchasecollection[i].purchaseid,
                purchasecollection[i].supplierid,
                purchasecollection[i].date.day,
                purchasecollection[i].date.month,
                purchasecollection[i].date.year,
                purchasecollection[i].totalamount);
    }
    fclose(fp);
}

void loadPurchaseFile()
{
    FILE *fp = fopen("purchasefile.txt", "r");
    if (fp == NULL) return;

    fscanf(fp, "%d", &purchasecount);
    for (int i = 0; i < purchasecount; i++)
    {
        fscanf(fp, "%d %d %d %d %d %d",
               &purchasecollection[i].purchaseid,
               &purchasecollection[i].supplierid,
               &purchasecollection[i].date.day,
               &purchasecollection[i].date.month,
               &purchasecollection[i].date.year,
               &purchasecollection[i].totalamount);
    }
    fclose(fp);
}

void purchasemenu()
{
    int choice;

    while (1)
    {
        printf("\n===== PURCHASE MENU =====\n");
        printf("1. Enter Purchase\n");
        printf("2. Display Purchase\n");
        printf("3. Search Purchase\n");
        printf("4. Delete Purchase\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter Purchase ID: ");
            scanf("%d", &purchasecollection[purchasecount].purchaseid);

            printf("Enter Supplier ID: ");
            scanf("%d", &purchasecollection[purchasecount].supplierid);

            printf("Enter Day: ");
            scanf("%d", &purchasecollection[purchasecount].date.day);

            printf("Enter Month: ");
            scanf("%d", &purchasecollection[purchasecount].date.month);

            printf("Enter Year: ");
            scanf("%d", &purchasecollection[purchasecount].date.year);

            printf("Enter Total Amount: ");
            scanf("%d", &purchasecollection[purchasecount].totalamount);

            purchasecount++;
        }
        else if (choice == 2)
        {
            for (int i = 0; i < purchasecount; i++)
            {
                printf("\nPurchase ID: %d", purchasecollection[i].purchaseid);
                printf("\nSupplier ID: %d", purchasecollection[i].supplierid);
                printf("\nDate: %d/%d/%d",
                       purchasecollection[i].date.day,
                       purchasecollection[i].date.month,
                       purchasecollection[i].date.year);
                printf("\nTotal Amount: %d\n", purchasecollection[i].totalamount);
            }
        }
        else if (choice == 3)
        {
            int id;
            printf("Enter Purchase ID or Supplier ID: ");
            scanf("%d", &id);

            for (int i = 0; i < purchasecount; i++)
            {
                if (id == purchasecollection[i].purchaseid ||
                    id == purchasecollection[i].supplierid)
                {
                    printf("\nPurchase ID: %d", purchasecollection[i].purchaseid);
                    printf("\nSupplier ID: %d", purchasecollection[i].supplierid);
                    printf("\nDate: %d/%d/%d",
                           purchasecollection[i].date.day,
                           purchasecollection[i].date.month,
                           purchasecollection[i].date.year);
                    printf("\nTotal Amount: %d\n", purchasecollection[i].totalamount);
                }
            }
        }
        else if (choice == 4)
        {
            int id;
            printf("Enter Purchase ID to delete: ");
            scanf("%d", &id);

            for (int i = 0; i < purchasecount; i++)
            {
                if (id == purchasecollection[i].purchaseid)
                {
                    for (int j = i; j < purchasecount - 1; j++)
                        purchasecollection[j] = purchasecollection[j + 1];
                    purchasecount--;
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
    loadPurchaseFile();
    purchasemenu();
    storePurchaseFile();
    return 0;
}
