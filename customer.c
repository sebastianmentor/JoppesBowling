#include "customer.h"
#include <string.h>
#include <stdio.h>

#define MAX_CUSTOMERS 100

static Customer all_customers[MAX_CUSTOMERS];
static int total_customers = 0;

bool add_customer(const Customer *customer)
{   
    if(total_customers == MAX_CUSTOMERS)
    {
        return false;
    }

    if(check_id_exist(customer -> id))
    {
        return false;
    }

    all_customers[total_customers].id = customer -> id;
    strcpy(all_customers[total_customers].name, customer -> name);
    strcpy(all_customers[total_customers].address, customer -> address);
    all_customers[total_customers].total_games = customer -> total_games;
    all_customers[total_customers].regular = customer -> regular;

    total_customers ++;
    return true;
}

bool check_id_exist(int id)
{
    for(int i = 0; i < total_customers; i++)
    {
        if(all_customers[i].id == id)
        {
            return true;
        }
    }

    return false;
}

void print_customer(const Customer *customer)
{
    printf("\nCustomer:   \n");
    printf("ID      = %d\n", customer -> id);
    printf("Name    = %s\n", customer -> name);
    printf("Address = %s\n", customer -> address);
    printf("Games   = %d\n", customer -> total_games);
    printf("Regular = %s\n", customer -> regular == true?"Yes":"No");
}

void print_all_customers(void)
{
    for(int i = 0; i < total_customers; i++)
    {
        print_customer(&all_customers[i]);
    }
}

Customer get_customer(int customer_id)
{
    for(int i = 0; i < total_customers; i++)
    {
        if(all_customers[i].id == customer_id)
        {
            return all_customers[i];
        }
    }

    Customer c = {-1, "Jon Doe", "Hell", -1, false};
    return c;
}