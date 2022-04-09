/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** copy a string into another
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_malloc_strcpy(char const *src)
{
    char *result = malloc(sizeof(char) * (my_strlen(src) + 1));

    result[my_strlen(src)] = '\0';
    for (int i = 0; src[i]; i++)
        result[i] = src[i];
    return result;
}

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; src[i]; i++) {
        dest[i] = src[i];
        if (src[i + 1] == '\0')
            dest[i + 1] = '\0';
    }
    return dest;
}
