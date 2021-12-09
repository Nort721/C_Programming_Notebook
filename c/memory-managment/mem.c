#include "stdlib.h"
#include <stdio.h>

struct movie
{
    char *name;
    int length;
} m1;


int main(int argc, char const *argv[])
{
    m1.name = malloc(4 * sizeof(char));
    m1.name[0] = 'n';
    m1.name[1] = 'o';
    m1.name[2] = 'r';
    m1.name[3] = 't';

    for (int i = 0; i < 4; i++)
    {
        printf("%c", m1.name[i]);
    }

    free(m1.name);
    free(m1.length);

    return 0;
}