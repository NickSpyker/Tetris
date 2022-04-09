/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-bsminishell1-clarisse.eynard
** File description:
** my_arraylen.c
*/

int my_arraylen(char **array)
{
    int x = 0;

    while (array[x])
        x++;
    return (x);
}
