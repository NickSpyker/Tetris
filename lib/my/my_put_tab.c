/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-clarisse.eynard
** File description:
** my_put_tab.c
*/

#include <unistd.h>
int my_strlen(char const *str);

void my_put_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
    }
}
