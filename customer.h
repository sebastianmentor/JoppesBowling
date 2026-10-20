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

#endif