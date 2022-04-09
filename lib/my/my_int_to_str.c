/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-clarisse.eynard
** File description:
** my_int_to_str.c
*/

#include <stdlib.h>
int my_intlen(long long int nb);
char *my_revstr(char *str);

char *my_int_to_str(int nb)
{
    int x = my_intlen(nb);
    char *str = malloc(sizeof(char) * (x + 1));

    str[x] = '\0';
    if (nb < 0) {
        nb *= -1;
        str[x - 1] = '-';
        x--;
    }
    for (int i = 0; x != 0; i++) {
        str[i] = nb % 10 + 48;
        nb /= 10;
        x--;
    }
    str = my_revstr(str);
    return (str);
}
