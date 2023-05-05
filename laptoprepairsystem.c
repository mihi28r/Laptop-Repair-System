#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

struct customer
{
    int id;
    char customername[50];
    char customeraddress[50];
    char Issue[50];
    char expert[50];
    char date[12];
} p;

struct laptop
{
    int id;
    char name[50];
    char issue[50];
    char recive[50];
    char date[12];
} d;


FILE *fp;



void addcustomer()
{ 
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(p.date, myDate);

    fp = fopen("customer.txt", "ab");

    printf("Enter Customer id: ");
    scanf("%d", &p.id);

    printf("Enter Customer name: ");
    fflush(stdin);
    gets(p.customername);

    printf("Enter Customer Address: ");
    fflush(stdin);
    gets(p.customeraddress);

    printf("Enter Customer Issue with Laptop: ");
    fflush(stdin);
    gets(p.Issue);

    printf("Enter Expert Name: ");
    fflush(stdin);
    gets(p.expert);

    printf("\nCustomer Added Successfully");

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
}

void updatecustomer()
{
    int id, found = 0;
    FILE *fp, *lemp;
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    fp = fopen("customer.txt", "rb");
    lemp = fopen("lemp.txt", "wb");

    printf("Enter Customer id to update: ");
    scanf("%d", &id);

    while(fread(&p, sizeof(p), 1, fp) == 1)
    {
        if(p.id == id)
        {
            found = 1;
            printf("Enter updated Customer name: ");
            fflush(stdin);
            gets(p.customername);

            printf("Enter updated Customer Address: ");
            fflush(stdin);
            gets(p.customeraddress);

            printf("Enter updated Customer Laptop issue: ");
            fflush(stdin);
            gets(p.Issue);

            printf("Enter the Expert for New Issue: ");
            fflush(stdin);
            gets(p.expert);

            strcpy(p.date, myDate);
        }
        fwrite(&p, sizeof(p), 1, lemp);
    }
    fclose(fp);
    fclose(lemp);
    remove("customer.txt");
    rename("lemp.txt", "customer.txt");

    if(found == 0)
        printf("Customer not found!\n");
    else
        printf("Customer updated successfully!\n");
}

    


void customerlist()
{

    system("cls");
    printf("<== Customer List ==>\n\n");
    printf("%-10s %-30s %-30s %-20s %-20s %s\n", "Id", "Customer Name", "Address", "Issue", "Expert","Date");
    printf("--------------------------------------------------------------------------------------------------------------------------\n");

    fp = fopen("customer.txt", "rb");
    while (fread(&p, sizeof(p), 1, fp) == 1)
    {
        printf("%-10d %-30s %-30s %-20s %-20s %s\n", p.id, p.customername, p.customeraddress, p.Issue, p.expert,p.date);
    }

    fclose(fp);
}

void deletecustomer()
{
    int id, found = 0;
    printf("<== Delete Customer ==>\n\n");
    printf("Enter Customer id to delete: ");
    scanf("%d", &id);

    FILE *fp, *ft;

    fp = fopen("customer.txt", "rb");
    if(fp == NULL)
    {
        printf("Error opening customer.txt file for reading!\n");
        return;
    }

    ft = fopen("temp.txt", "wb");
    if(ft == NULL)
    {
        printf("Error opening temp.txt file for writing!\n");
        fclose(fp);
        return;
    }

    while (fread(&p, sizeof(p), 1, fp) == 1)
    {
        if (id == p.id)
        {
            found = 1;
        }
        else
        {
            fwrite(&p, sizeof(p), 1, ft);
        }
    }

    fclose(fp);
    fclose(ft);

    if (found == 1)
    {
        remove("customer.txt");
        rename("temp.txt", "customer.txt");
        printf("\n\nCustomer with ID %d deleted successfully.\n", id);
    }
    else
    {
        printf("\n\nCustomer with ID %d not found in the file.\n", id);
    }
}


void addlaptop()
{  


    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(d.date, myDate);

    int f = 0;

    system("cls");
    printf("<== Add Laptop ==>\n\n");

    fp = fopen("laptop.txt", "ab");

    printf("Enter Laptop id: ");
    scanf("%d", &d.id);

    printf("Enter Company Name: ");
    fflush(stdin);
    gets(d.name);

    printf("Enter Laptop Issue: ");
    fflush(stdin);
    gets(d.issue);

    printf("Enter Laptop recive Date: ");
    fflush(stdin);
    gets(d.recive);

    printf("Laptop Added Successfully\n\n");

    fwrite(&d, sizeof(d), 1, fp);
    fclose(fp);
}
 void updatelaptop()
{
    int id, found = 0;
    FILE *fp, *lemp;
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    fp = fopen("laptop.txt", "rb");
    lemp = fopen("lemp.txt", "wb");

    printf("Enter Laptop id to update: ");
    scanf("%d", &id);

    while(fread(&d, sizeof(d), 1, fp) == 1)
    {
        if(d.id == id)
        {
            found = 1;
            printf("Enter updated laptop name: ");
            fflush(stdin);
            gets(d.name);

            printf("Enter updated laptop issue: ");
            fflush(stdin);
            gets(d.issue);

            printf("Enter updated Laptop recive date: ");
            fflush(stdin);
            gets(d.recive);

            strcpy(d.date, myDate);
        }
        fwrite(&d, sizeof(d), 1, lemp);
    }
    fclose(fp);
    fclose(lemp);
    remove("laptop.txt");
    rename("lemp.txt", "laptop.txt");

    if(found == 0)
        printf("Laptop not found!\n");
    else
        printf("Laptop updated successfully!\n");
}




void laptopList()
{
    system("cls");
    printf("<== Laptop List ==>\n\n");

    printf("%-10s %-30s %-30s %-30s %s\n", "id", "Name", "Issue", "Recive Date", "Date");
    printf("-------------------------------------------------------------------------------------------------------------------\n");

    fp = fopen("laptop.txt", "rb");
    while (fread(&d, sizeof(d), 1, fp) == 1)
    {
        printf("%-10d %-30s %-30s %-30s %s\n", d.id, d.name, d.issue, d.recive, d.date);
    }

    fclose(fp);
}

    
void deletelaptop()
{
    int id, found = 0;
    printf("<== Delete Laptop ==>\n\n");
    printf("Enter Laptop id to delete: ");
    scanf("%d", &id);

    FILE *fp, *ft;

    fp = fopen("laptop.txt", "rb");
    if(fp == NULL)
    {
        printf("Error opening laptop.txt file for reading!\n");
        return;
    }

    ft = fopen("temp.txt", "wb");
    if(ft == NULL)
    {
        printf("Error opening temp.txt file for writing!\n");
        fclose(fp);
        return;
    }

    while (fread(&d, sizeof(d), 1, fp) == 1)
    {
        if (id == d.id)
        {
            found = 1;
        }
        else
        {
            fwrite(&d, sizeof(d), 1, ft);
        }
    }

    fclose(fp);
    fclose(ft);

    if (found == 1)
    {
        remove("laptop.txt");
        rename("temp.txt", "laptop.txt");
        printf("\n\nLaptop with ID %d deleted successfully.\n", id);
    }
    else
    {
        printf("\n\nLaptop with ID %d not found in the file.\n", id);
    }
}

int main()
{

    int ch;

    while (1)
    {
        system("cls");
        printf("<==Laptop Repair System==>\n");
        printf("1.Add record of client\n");
        printf("2.Customer List\n");
        printf("3.Update Customer\n");
        printf("4.Delete record of client\n");
        printf("5.Add details of laptop\n");
        printf("6.Laptop List\n");
        printf("7.Update Laptop\n");
        printf("8.Delete Laptop\n");
        printf("0.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
            exit(0);

        case 1:
            addcustomer();
            break;

        case 2:
            customerlist();
            break;
        case 3:
            updatecustomer();
            break;

        case 4:
            deletecustomer();
            break;

        case 5:
            addlaptop();
            break;

        case 6:
            laptopList();
            break;
        case 7:
            updatelaptop();
            break;
        case 8:
            deletelaptop();
            break;

        default:
            printf("Invalid Choice...\n\n");
        }
        printf("\n\nPress Any Key To Continue...");
        getch();
    }

    return 0;
}
