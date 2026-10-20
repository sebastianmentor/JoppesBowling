#include <stdio.h>
#include "customer.h"
#include "safe_input.h"

void print_menu();

int main(void)
{
    printf("Welcome to Joppes Bowling\n");

    int nr_of_users = 0;

    int user_choice;
    int run_program = true;

    while (run_program)
    {   
        print_menu();
        user_choice = get_int("Enter choice:", 0, 3);

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

            if(add_customer(&new_customer))
            {
                printf("Success, new customer createt and added to system!\n");
                print_customer(&new_customer);
            }
            else
            {
                printf("Something went south, better quit now when you are ahead!\n");
            }
            break;
        
        case 2:
            print_all_customers();
            break;

        case 3:
            int serch_id = get_int("Enter customer id: ", 1, 10000);
            Customer customer = get_customer(serch_id);

            if(customer.id == serch_id)
            {
                printf("We fount the dyde!\n");
            }
            else
            {
                printf("we did not found the magic customer! We got:\n");
            }

            print_customer(&customer);


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
    printf("3. Search customer\n");
    printf("0. Quit\n");
}

