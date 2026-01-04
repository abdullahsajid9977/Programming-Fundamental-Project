#include <stdio.h>
#include <string.h>

/* ================= SUPPLIER STRUCT ================= */

struct supplier
{
    int supplierid;
    char name[50];
    char contact[20];
    char address[50];
};

struct supplier suppliercollection[100];
int suppliercount = 0;

/* ================= FILE HANDLING ================= */

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

/* ================= SUPPLIER MENU ================= */

void suppliermenu()
{
    int choice;

    while (1)
    {
        printf("\n===== SUPPLIER MENU =====\n");
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

/* ================= MAIN ================= */

int main()
{
    loadSupplierFile();
    suppliermenu();
    storeSupplierFile();
    return 0;
}