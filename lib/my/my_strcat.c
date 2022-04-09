/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** concatenates two strings
*/

#include <stdlib.h>
int my_strlen (char const *str);

char *my_strcat(char const *deb, char const *end)
{
    char *dest = malloc(sizeof(char) * (my_strlen(deb) + my_strlen(end) + 1));
    int i = 0;

    for (; deb[i] != '\0'; i++)
        dest[i] = deb[i];
    for (int j = 0; end[j] != '\0'; j++)
        dest[i++] = end[j];
    dest[i] = '\0';
    return (dest);
}
