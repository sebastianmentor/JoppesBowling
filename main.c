#include <stdio.h>
#include "customer.h"

int main(void)
{
    printf("Welcome to Joppes Bowling\n");

    Customer seb = {1, "SebastianSebastianSebastianSebastianSebastianSebastiana", "Sebastian"};

    printf("We have that seb has id %d and name1 = %s and name2 = %s\n", seb.id, seb.name1, seb.name2);
    printf("sizeof(seb.id) = %zu\n", sizeof(seb.id));
    printf("sizeof(seb.name1) = %zu\n", sizeof(seb.name1));
    printf("sizeof(seb.name2) = %zu\n", sizeof(seb.name2));
    printf("sizeof(seb) = %zu\n", sizeof(seb));
    printf("seb is located at %p\n", (void *)&seb);
    printf("seb.id is located at %p\n", (void *)&seb.id);
    printf("&seb.name1 is located at %p\n", (void *)&seb.name1);
    printf("seb.name1 is located at %p\n", (void *)seb.name1);
    printf("seb.name1 first value %c\n", *seb.name1);
    printf("&seb.name2 is located at %p\n", (void *)&seb.name2);
    printf("seb.name2 is located at %p\n", (void *)seb.name2);

    return 0;
}