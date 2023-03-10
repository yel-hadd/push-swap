#include "pushswap.h"

int main(void)
{
    char *str = {"Hello"};
    char **tmp;

    tmp = ft_split(str, ' ');
    while (*tmp)
        printf("%s\n", *tmp++);
}