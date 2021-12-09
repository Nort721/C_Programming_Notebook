#include "stdlib.h"

void lol(int num[2])
{
    printf("address: %d value: %d\n", &num[0], num[0]);
}

int main(int argc, char const *argv[])
{

    //int *num = malloc(2 * sizeof(int));
    int num[2];

    num[0] = 12;
    num[1] = 13;

    printf("org-address: %d org-value: %d\n", &num[0], num[0]);

    lol(num);

    //free(num);

    return 0;
}