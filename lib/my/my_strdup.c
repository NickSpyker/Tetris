/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** allocates memory and copies the str given as argument
*/

#include <stdlib.h>
int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (int i = 0; i <= my_strlen(src); i += 1) {
        str[i] = src[i];
    }
    return (str);
}
