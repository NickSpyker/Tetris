/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** counts and return the number of characters in a string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}
