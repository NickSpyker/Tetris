/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-clarisse.eynard
** File description:
** my_intlen.c
*/

int my_intlen(long long int nb)
{
    int count = 0;

    if (nb < 0)
        count += 1;
    while (nb / 10 != 0) {
        count += 1;
        nb = nb / 10;
    }
    return (count + 1);
}
