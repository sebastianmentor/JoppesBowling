#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <stdbool.h>

typedef struct{
    int id;
    char name[30];
    char address[50];
    int total_games;
    bool regular;

}Customer;

bool add_customer(const Customer *customer);
bool check_id_exist(int id);
void print_customer(const Customer *customer);
void print_all_customers(void);
Customer get_customer(int customer_id);

#endif