#include <stdio.h>
#include "customer.h"
#include "safe_input.h"

void print_menu();
void print_customer(const Customer *customer);

int main(void)
{
    printf("Welcome to Joppes Bowling\n");

    int nr_of_users = 0;

    int user_choice;
    int run_program = true;

    while (run_program)
    {   
        print_menu();
        user_choice = get_int("Enter choice:", 0, 2);

        switch (user_choice)
        {
        case 1:
            Customer new_customer;
            new_customer.id = nr_of_users + 1;
            get_string("Enter name", new_customer.name, sizeof(new_customer.name));
            get_string("Enter address", new_customer.address, sizeof(new_customer.address));
            new_customer.total_games = 0;
            new_customer.regular = false;
            nr_of_users ++;

            print_customer(&new_customer);
            break;
        
        case 2:

            break;
        case 0:
            run_program = false;
            break;            
        default:
            printf("Invalid choice! Try again!\n");
            break;
        }
    }
    



    return 0;
}

void print_menu()
{
    printf("1. Create new customer\n");
    printf("2. Show all customer\n");
    printf("0. Quit\n");
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