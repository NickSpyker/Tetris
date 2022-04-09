/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-clarisse.eynard
** File description:
** my_malloc_tab.c
*/

#include <stdlib.h>

char **my_array_alloc(int x, int y)
{
    char **new = malloc(sizeof(char *) * (y + 1));

    for (int i = 0; i < y; i++) {
        new[i] = malloc(sizeof(char) * (x + 1));
        for (int j = 0; j != x + 1; j++)
            new[i][j] = '\0';
    }
    new[y] = NULL;
    return new;
}
