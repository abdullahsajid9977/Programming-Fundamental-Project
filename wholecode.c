#include<stdio.h>
#include<string.h>

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

void storesalefile()
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

void loadsalefile()
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
        printf("\nSALE MENU \n");
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
        printf("\n PURCHASE MENU \n");
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


struct supplier
{
    int supplierid;
    char name[50];
    char contact[20];
    char address[50];
};

struct supplier suppliercollection[100];
int suppliercount = 0;

void storeSupplierFile()
{
    FILE *fp = fopen("supplierfile.txt", "w");
    if (fp == NULL) return;

    fprintf(fp, "%d\n", suppliercount);
    for (int i = 0; i < suppliercount; i++)
    {
        fprintf(fp, "%d %s %s %s\n",
                suppliercollection[i].supplierid,
                suppliercollection[i].name,
                suppliercollection[i].contact,
                suppliercollection[i].address);
    }
    fclose(fp);
}

void loadSupplierFile()
{
    FILE *fp = fopen("supplierfile.txt", "r");
    if (fp == NULL) return;

    fscanf(fp, "%d", &suppliercount);
    for (int i = 0; i < suppliercount; i++)
    {
        fscanf(fp, "%d %s %s %s",
               &suppliercollection[i].supplierid,
               suppliercollection[i].name,
               suppliercollection[i].contact,
               suppliercollection[i].address);
    }
    fclose(fp);
}


void suppliermenu()
{
    int choice;

    while (1)
    {
        printf("\n SUPPLIER MENU\n");
        printf("1. Enter Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Delete Supplier\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter Supplier ID: ");
            scanf("%d", &suppliercollection[suppliercount].supplierid);

            printf("Enter Name: ");
            scanf("%s", suppliercollection[suppliercount].name);

            printf("Enter Contact: ");
            scanf("%s", suppliercollection[suppliercount].contact);

            printf("Enter Address: ");
            scanf("%s", suppliercollection[suppliercount].address);

            suppliercount++;
        }
        else if (choice == 2)
        {
            for (int i = 0; i < suppliercount; i++)
            {
                printf("\nSupplier ID: %d", suppliercollection[i].supplierid);
                printf("\nName: %s", suppliercollection[i].name);
                printf("\nContact: %s", suppliercollection[i].contact);
                printf("\nAddress: %s\n", suppliercollection[i].address);
            }
        }
        else if (choice == 3)
        {
            int searchChoice;
            printf("\n1. Search by ID\n2. Search by Name\nEnter choice: ");
            scanf("%d", &searchChoice);

            if (searchChoice == 1)
            {
                int id;
                printf("Enter Supplier ID: ");
                scanf("%d", &id);

                for (int i = 0; i < suppliercount; i++)
                    if (id == suppliercollection[i].supplierid)
                        printf("%d %s %s %s\n",
                               suppliercollection[i].supplierid,
                               suppliercollection[i].name,
                               suppliercollection[i].contact,
                               suppliercollection[i].address);
            }
            else if (searchChoice == 2)
            {
                char name[50];
                printf("Enter Name: ");
                scanf("%s", name);

                for (int i = 0; i < suppliercount; i++)
                    if (strcmp(name, suppliercollection[i].name) == 0)
                        printf("%d %s %s %s\n",
                               suppliercollection[i].supplierid,
                               suppliercollection[i].name,
                               suppliercollection[i].contact,
                               suppliercollection[i].address);
            }
        }
        else if (choice == 4)
        {
            int id;
            printf("Enter Supplier ID to delete: ");
            scanf("%d", &id);

            for (int i = 0; i < suppliercount; i++)
            {
                if (id == suppliercollection[i].supplierid)
                {
                    for (int j = i; j < suppliercount - 1; j++)
                        suppliercollection[j] = suppliercollection[j + 1];
                    suppliercount--;
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
    productmenu();
else if (choice == 2)
    suppliermenu();
else if (choice == 3)
    purchasemenu();
else if (choice == 4)
    salemenu();
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
    loadsalefile();
    loadPurchaseFile();
    loadSupplierFile();
    loadfile();
    storefile();
    storeSupplierFile();
    storePurchaseFile();
    storesalefile();
}