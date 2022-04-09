/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** fonction that return a number sent as a string
*/

int verif_num(char c)
{
    if (c == '-' || c == '+') {
        return (2);
    } else if ('0' <= c && c <= '9') {
        return (0);
    }
    return (1);
}

int verif_signe(char c)
{
    if (c == '-')
        return (-1);
    return (1);
}

int verif_taille(long int nb)
{
    if (nb < -2147483648 || 2147483647 < nb)
        return (0);
    return (1);
}

int my_getnbr(char const *str)
{
    long int nb = 0;
    int signe = 1;
    int i = 0;

    while (verif_num(str[i]) == 2) {
        signe = signe * verif_signe(str[i]);
        i += 1;
    }
    while (verif_num(str[i]) == 0) {
        nb = nb * 10 + (str[i] - 48);
        if (verif_taille(nb * signe) == 0)
            return (0);
        i += 1;
    }
    return (nb * signe);
}
