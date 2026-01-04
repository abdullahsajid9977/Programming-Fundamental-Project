#include <stdio.h>
#include <string.h>

struct product
{
    int productid;
    char productname[50];
    int price;
    int quantity;
};

struct product productcollection[100];
int productcount = 0;

void storefile()
{
    FILE *fp = fopen("productfile.txt", "w");
    if (fp == NULL) return;

    fprintf(fp, "%d\n", productcount);
    for (int i = 0; i < productcount; i++)
    {
        fprintf(fp, "%d %s %d %d\n",
                productcollection[i].productid,
                productcollection[i].productname,
                productcollection[i].price,
                productcollection[i].quantity);
    }

    fclose(fp);
}

void loadfile()
{
    FILE *fp = fopen("productfile.txt", "r");
    if (fp == NULL) return;

    fscanf(fp, "%d", &productcount);
    for (int i = 0; i < productcount; i++)
    {
        fscanf(fp, "%d %s %d %d",
               &productcollection[i].productid,
               productcollection[i].productname,
               &productcollection[i].price,
               &productcollection[i].quantity);
    }

    fclose(fp);
}

void productmenu()
{
    while (1)
    {
        int choice1;
        printf("\n1.Enter Product\n");
        printf("2.Display Product\n");
        printf("3.Search Product\n");
        printf("4.Delete Product\n");
        printf("5.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice1);

        if (choice1 == 1)
        {
            printf("Enter Product ID: ");
            scanf("%d", &productcollection[productcount].productid);

            printf("Enter Product Name: ");
            scanf("%s", productcollection[productcount].productname);

            printf("Enter Price: ");
            scanf("%d", &productcollection[productcount].price);

            printf("Enter Quantity: ");
            scanf("%d", &productcollection[productcount].quantity);

            productcount++;
        }
        else if (choice1 == 2)
        {
            for (int i = 0; i < productcount; i++)
            {
                printf("\nProduct ID: %d", productcollection[i].productid);
                printf("\nProduct Name: %s", productcollection[i].productname);
                printf("\nPrice: %d", productcollection[i].price);
                printf("\nQuantity: %d\n", productcollection[i].quantity);
            }
        }
        else if (choice1 == 3)
        {
            int searchid;
            printf("Enter Product ID: ");
            scanf("%d", &searchid);

            for (int i = 0; i < productcount; i++)
                if (searchid == productcollection[i].productid)
                    printf("%d %s %d %d\n",
                           productcollection[i].productid,
                           productcollection[i].productname,
                           productcollection[i].price,
                           productcollection[i].quantity);
        }
        else if (choice1 == 4)
        {
            int productid;
            printf("Enter Product ID to Delete: ");
            scanf("%d", &productid);

            for (int i = 0; i < productcount; i++)
            {
                if (productid == productcollection[i].productid)
                {
                    for (int j = i; j < productcount - 1; j++)
                        productcollection[j] = productcollection[j + 1];
                    productcount--;
                    break;
                }
            }
        }
        else if (choice1 == 5)
            break;
    }
}

int main()
{
    loadfile();
    productmenu();
    storefile();
    return 0;
}